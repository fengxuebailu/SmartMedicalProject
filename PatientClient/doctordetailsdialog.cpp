#include "doctordetailsdialog.h"
#include "ui_doctordetailsdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPixmap>

DoctorDetailsDialog::DoctorDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorDetailsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("医生详细信息");
}

DoctorDetailsDialog::~DoctorDetailsDialog()
{
    delete ui;
}

void DoctorDetailsDialog::loadDoctorDetails(int doctorId)
{
    QSqlQuery query;
    // 确保这里的表名和字段名与你的新数据库匹配
    query.prepare("SELECT d.full_name, d.title, d.gender, d.photo_path, d.bio, d.department "
                  "FROM doctors d "
                  "WHERE d.user_id = :doctorId");
    query.bindValue(":doctorId", doctorId);

    if (!query.exec() || !query.next()) {
        qDebug() << "查询医生详情失败: " << query.lastError().text();
        return;
    }

    QString name = query.value("full_name").toString();
    QString title = query.value("title").toString();
    QString gender = query.value("gender").toString();
    QString photoPath = query.value("photo_path").toString();
    QString bio = query.value("bio").toString();
    QString department = query.value("department").toString();

    ui->nameLabel->setText(name);
    ui->titleLabel->setText(title);
    ui->genderLabel->setText("性别：" + gender);
    ui->departmentLabel->setText("科室：" + department);
    ui->bioTextBrowser->setText(bio);

    if (!photoPath.isEmpty()) {
        QPixmap photo(photoPath);
        if (!photo.isNull()) {
            ui->photoLabel->setPixmap(photo.scaled(ui->photoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            ui->photoLabel->setText("图片加载失败");
        }
    } else {
        ui->photoLabel->setText("暂无照片");
    }
}

void DoctorDetailsDialog::on_closeButton_clicked()
{
    this->accept();
}
