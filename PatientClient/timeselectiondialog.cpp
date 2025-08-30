#include "timeselectiondialog.h"
#include "ui_timeselectiondialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

TimeSelectionDialog::TimeSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSelectionDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("第二步：选择预约时间");

    ui->calendarWidget->setMinimumDate(QDate::currentDate());
}

TimeSelectionDialog::~TimeSelectionDialog()
{
    delete ui;
}

void TimeSelectionDialog::setAppointmentInfo(int doctorId, const QString &doctorName, int patientId)
{
    m_doctorId = doctorId;
    m_patientId = patientId;
    ui->doctorInfoLabel->setText(QString("您正在为【%1】医生进行预约").arg(doctorName));

    // 初始加载当天的时间段
    on_calendarWidget_clicked(QDate::currentDate());
}

// ============== 核心修改部分 1 ==============
void TimeSelectionDialog::on_calendarWidget_clicked(const QDate &date)
{
    ui->timeSlotsListWidget->clear();
    ui->confirmButton->setEnabled(false);

    QSqlQuery query;
    // 查询指定医生、指定日期、并且尚未被预约（is_booked = FALSE）的所有时间段
    query.prepare("SELECT time_slot FROM doctor_schedules "
                  "WHERE doctor_id = :doctorId AND schedule_date = :scheduleDate AND is_booked = FALSE "
                  "ORDER BY time_slot ASC");
    query.bindValue(":doctorId", m_doctorId);
    query.bindValue(":scheduleDate", date);

    if (!query.exec()) {
        qDebug() << "查询排班失败: " << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法加载医生排班信息。");
        return;
    }

    if (query.size() > 0) {
        while (query.next()) {
            ui->timeSlotsListWidget->addItem(query.value(0).toString());
        }
    } else {
        // 如果查询结果为空，说明当天没有可用的排班
        ui->timeSlotsListWidget->addItem("本日无可用排班");
        ui->timeSlotsListWidget->setEnabled(false);
    }
}

void TimeSelectionDialog::on_timeSlotsListWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() != "本日无可用排班") {
        ui->confirmButton->setEnabled(true);
    }
}


// ============== 核心修改部分 2 ==============
// 我们需要使用“数据库事务”来确保数据的一致性
void TimeSelectionDialog::on_confirmButton_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    if (!ui->timeSlotsListWidget->currentItem()) {
        QMessageBox::warning(this, "提示", "请选择一个预约时间段。");
        return;
    }
    QString selectedTime = ui->timeSlotsListWidget->currentItem()->text();

    // 获取数据库连接
    QSqlDatabase db = QSqlDatabase::database(); // 获取默认连接
    // 开始一个事务
    if (!db.transaction()) {
        qDebug() << "开启事务失败: " << db.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法处理您的请求。");
        return;
    }

    bool success = true;

    // 步骤1：在 doctor_schedules 表中将该时间段标记为“已预定”
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE doctor_schedules SET is_booked = TRUE "
                        "WHERE doctor_id = :doctorId AND schedule_date = :appDate AND time_slot = :appTime AND is_booked = FALSE");
    updateQuery.bindValue(":doctorId", m_doctorId);
    updateQuery.bindValue(":appDate", selectedDate);
    updateQuery.bindValue(":appTime", selectedTime);

    if (!updateQuery.exec() || updateQuery.numRowsAffected() != 1) {
        // 如果更新失败，或者影响的行数不等于1 (可能意味着在你点击确认的瞬间，这个时间段被别人抢了)
        success = false;
        qDebug() << "锁定排班失败或时间段已被预约: " << updateQuery.lastError().text();
    }

    // 步骤2：如果锁定成功，则在 appointments 表中插入新的预约记录
    if (success) {
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO appointments (patient_id, doctor_id, appointment_date, appointment_time) "
                           "VALUES (:patientId, :doctorId, :appDate, :appTime)");
        insertQuery.bindValue(":patientId", m_patientId);
        insertQuery.bindValue(":doctorId", m_doctorId);
        insertQuery.bindValue(":appDate", selectedDate);
        insertQuery.bindValue(":appTime", selectedTime);
        if (!insertQuery.exec()) {
            success = false;
            qDebug() << "插入预约记录失败: " << insertQuery.lastError().text();
        }
    }

    // 步骤3：根据成功或失败，提交或回滚事务
    if (success) {
        db.commit(); // 提交事务，所有更改生效
        QMessageBox::information(this, "预约成功",
                                 QString("您已成功预约！\n\n日期: %1\n时间: %2\n\n您可以在“我的预约”中查看详情。")
                                 .arg(selectedDate.toString("yyyy-MM-dd"), selectedTime));
        this->accept();
    } else {
        db.rollback(); // 回滚事务，所有更改被撤销
        QMessageBox::critical(this, "预约失败", "无法完成预约，该时间段可能已被他人预约，请刷新后重试。");
        // 刷新当前日期的时间段列表
        on_calendarWidget_clicked(selectedDate);
    }
}
