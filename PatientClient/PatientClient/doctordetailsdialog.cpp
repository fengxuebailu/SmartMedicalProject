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
    // 关联 doctors 和 departments 表，一次性获取所有需要的信息
    query.prepare("SELECT d.name, d.title, d.gender, d.photo_path, d.bio, dep.name "
                  "FROM doctors d "
                  "JOIN departments dep ON d.department_id = dep.id "
                  "WHERE d.id = :doctorId");
    query.bindValue(":doctorId", doctorId);

    if (!query.exec() || !query.next()) {
        qDebug() << "查询医生详情失败: " << query.lastError().text();
        // 可以显示一个错误提示
        return;
    }

    // 从查询结果中取出数据
    QString name = query.value(0).toString();
    QString title = query.value(1).toString();
    QString gender = query.value(2).toString();
    QString photoPath = query.value(3).toString();
    QString bio = query.value(4).toString();
    QString department = query.value(5).toString();

    // 将数据填充到UI控件中
    ui->nameLabel->setText(name);
    ui->titleLabel->setText(title);
    ui->genderLabel->setText("性别：" + gender);
    ui->departmentLabel->setText("科室：" + department);
    ui->bioTextBrowser->setText(bio);

    // 加载并显示医生照片
    if (!photoPath.isEmpty()) {
        QPixmap photo(photoPath);
        if (!photo.isNull()) {
            // 让图片适应 Label 大小，并保持宽高比
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
