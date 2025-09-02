#include "healthcheckindialog.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QDate>

HealthCheckinDialog::HealthCheckinDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("亲子健康打卡"));

    cbDiet_     = new QCheckBox(tr("今天饮食达标"));
    cbExercise_ = new QCheckBox(tr("今天有运动"));
    cbMed_      = new QCheckBox(tr("按时服药"));

    noteEdit_ = new QLineEdit;
    noteEdit_->setPlaceholderText(tr("备注（可空）"));

    tip_ = new QLabel(tr("勾选越多，获得的⭐越多；三项全中额外+1⭐"));

    auto* btnSave   = new QPushButton(tr("保存打卡"));
    auto* btnCancel = new QPushButton(tr("取消"));

    connect(btnSave,   &QPushButton::clicked, this, &HealthCheckinDialog::onSave);
    connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);

    auto* v = new QVBoxLayout;
    v->addWidget(cbDiet_);
    v->addWidget(cbExercise_);
    v->addWidget(cbMed_);
    v->addWidget(noteEdit_);
    v->addWidget(tip_);

    auto* h = new QHBoxLayout;
    h->addStretch();
    h->addWidget(btnSave);
    h->addWidget(btnCancel);
    v->addLayout(h);
    setLayout(v);
}

int HealthCheckinDialog::calculateStars(bool diet, bool exercise, bool med) const
{
    int s = (diet?1:0) + (exercise?1:0) + (med?1:0);
    if (s == 3) s += 1; // 三项全中加成
    return s;
}

void HealthCheckinDialog::onSave()
{
    if (userId_ == 0) {
        QMessageBox::warning(this, tr("未登录"), tr("当前没有可用的用户 ID。"));
        return;
    }

    const bool diet = cbDiet_->isChecked();
    const bool ex   = cbExercise_->isChecked();
    const bool med  = cbMed_->isChecked();
    const int stars = calculateStars(diet, ex, med);
    const QString note = noteEdit_->text().trimmed();
    const QDate today = QDate::currentDate();

    QSqlDatabase db = QSqlDatabase::database(); // 默认连接
    if (!db.isOpen()) {
        QMessageBox::critical(this, tr("数据库错误"), tr("数据库未连接"));
        return;
    }

    db.transaction();

    // 1) 插入/更新当天打卡（若你允许一天多条，删掉表里的 UNIQUE，并把这段改成普通 INSERT）
    {
        QSqlQuery q(db);
        q.prepare(R"SQL(
            INSERT INTO health_checkins (user_id, date, diet_ok, exercise_ok, med_ok, stars, note)
            VALUES (:uid, :d, :diet, :ex, :med, :stars, :note)
            ON DUPLICATE KEY UPDATE
              diet_ok=VALUES(diet_ok),
              exercise_ok=VALUES(exercise_ok),
              med_ok=VALUES(med_ok),
              stars=VALUES(stars),
              note=VALUES(note)
        )SQL");
        q.bindValue(":uid",   QVariant::fromValue<qulonglong>(userId_));
        q.bindValue(":d",     today);
        q.bindValue(":diet",  diet);
        q.bindValue(":ex",    ex);
        q.bindValue(":med",   med);
        q.bindValue(":stars", stars);
        q.bindValue(":note",  note);
        if (!q.exec()) {
            db.rollback();
            QMessageBox::critical(this, tr("保存失败"), q.lastError().text());
            return;
        }
    }

    // 2) 累加总星星（示例：同时维护 user_rewards）
    {
        QSqlQuery q(db);
        q.prepare(R"SQL(
            INSERT INTO user_rewards (user_id, total_stars, last_badge)
            VALUES (:uid, :add, NULL)
            ON DUPLICATE KEY UPDATE
              total_stars = total_stars + VALUES(total_stars)
        )SQL");
        q.bindValue(":uid", QVariant::fromValue<qulonglong>(userId_));
        q.bindValue(":add", stars);
        if (!q.exec()) {
            db.rollback();
            QMessageBox::critical(this, tr("积分更新失败"), q.lastError().text());
            return;
        }
    }

    db.commit();

    QMessageBox::information(this, tr("成功"),
                             tr("今日打卡成功，获得 %1 颗⭐！").arg(stars));
    emit checkinSaved();
    accept();
}
