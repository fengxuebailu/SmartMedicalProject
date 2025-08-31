#include "patientinfodialog.h"
#include "ui_patientinfodialog.h"

// 包含所有需要的Qt SQL和调试头文件
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QDate>

PatientInfoDialog::PatientInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientInfoDialog)
{
    ui->setupUi(this);
    m_isEditMode = false;

//    // --- 数据库连接 ---
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "patient_info_connection"); // 使用命名连接
//    db.setHostName("127.0.0.1");      // 主机地址
//    db.setDatabaseName("smart_clinic"); // 数据库名
//    db.setUserName("root");              // 数据库用户名
//    db.setPassword("@Aa1146978345");     // !!! 替换成你自己的MySQL root密码 !!!

//    if (!db.open()) {
//        qDebug() << "数据库连接失败:" << db.lastError().text();
//        QMessageBox::critical(this, "数据库错误", "无法连接到数据库，请检查配置。");
//    } else {
//        qDebug() << "数据库连接成功!";
//        // 假设我们现在要加载ID为1的患者信息
//        // 在真实项目中，这个ID应该来自登录信息
        loadPatientData(1);
//    }
}

PatientInfoDialog::~PatientInfoDialog()
{
    delete ui;
    // 关闭数据库连接
    QSqlDatabase::removeDatabase("patient_info_connection");
}

void PatientInfoDialog::loadPatientData(int patientId)
{
    m_patientId = patientId; // <-- 添加这一行，记住ID以便后续更新

    // 使用我们创建的连接
    QSqlDatabase db = QSqlDatabase::database("patient_info_connection");
    QSqlQuery query(db);

    query.prepare("SELECT full_name, date_of_birth, photo_path, id_number, phone, email FROM patients WHERE user_id = :id");
    query.bindValue(":id", patientId);

    if (!query.exec()) {
        qDebug() << "查询失败:" << query.lastError().text();
        return;
    }

    // 如果查询到数据
    if (query.next()) {
        ui->nameLineEdit->setText(query.value("full_name").toString());
        ui->dobLineEdit->setText(query.value("date_of_birth").toDate().toString("yyyy-MM-dd"));
        ui->idCardLineEdit->setText(query.value("id_number").toString());
        ui->phoneLineEdit->setText(query.value("phone").toString());
        ui->emailLineEdit->setText(query.value("email").toString());
        QDate dob = query.value("date_of_birth").toDate();
        ui->dobLineEdit->setText(dob.toString("yyyy-MM-dd"));

        // 计算年龄：当前日期 - 出生日期
        QDate today = QDate::currentDate();
        int age = dob.daysTo(today) / 365;  // 粗略计算
        // 更准确的算法：考虑月份和日子
        int realAge = today.year() - dob.year();
        if (today.month() < dob.month() || (today.month() == dob.month() && today.day() < dob.day())) {
            realAge--;
        }

        // 加载并显示照片
        QString photoPath = query.value("photo_path").toString();
        if (!photoPath.isEmpty()) {
            QPixmap photo(photoPath);
            if (!photo.isNull()) {
                // 让图片适应Label大小
                ui->photoLabel->setPixmap(photo.scaled(ui->photoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                ui->photoLabel->setText("图片加载失败");
            }
        } else {
            ui->photoLabel->setText("暂无照片");
        }
    }
}

// 实现“关闭”按钮的功能
void PatientInfoDialog::on_closeButton_clicked()
{
    this->close(); // close()会关闭对话框
}

void PatientInfoDialog::on_editSaveButton_clicked()
{
    // 检查当前的模式
    if (m_isEditMode == false) {
        // --- 当前是“浏览模式”，我们要切换到“编辑模式” ---

        // 1. 让所有输入框变为可编辑
        ui->nameLineEdit->setReadOnly(false);
        ui->ageLineEdit->setReadOnly(false);
        ui->dobLineEdit->setReadOnly(false);
        // 身份证号通常不允许修改，所以保持只读
        // ui->idCardLineEdit->setReadOnly(false);
        ui->phoneLineEdit->setReadOnly(false);
        ui->emailLineEdit->setReadOnly(false);

        // 2. 更改按钮的文本为“保存”
        ui->editSaveButton->setText("保存");

        // 3. 更新状态标志
        m_isEditMode = true;

    } else {
        // --- 当前是“编辑模式”，我们要保存数据并切换回“浏览模式” ---

        // 1. 从界面获取用户输入的数据
        QString name = ui->nameLineEdit->text();
        int age = ui->ageLineEdit->text().toInt();
        QString dob = ui->dobLineEdit->text();
        QString phone = ui->phoneLineEdit->text();
        QString email = ui->emailLineEdit->text();

        // 2. 准备并执行SQL UPDATE语句
        QSqlDatabase db = QSqlDatabase::database("patient_info_connection");
        QSqlQuery query(db);

        query.prepare("UPDATE patients SET full_name = :full_name, date_of_birth = :date_of_birth, "
                      "phone = :phone, email = :email WHERE user_id = :id");
        query.bindValue(":full_name", name);

        query.bindValue(":date_of_birth", dob);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":id", m_patientId);
        // 使用我们之前保存的ID

        if (query.exec()) {
            // 如果执行成功
            QMessageBox::information(this, "成功", "资料更新成功！");

            // 3. 将界面切换回“浏览模式”
            ui->nameLineEdit->setReadOnly(true);
            ui->ageLineEdit->setReadOnly(true);
            ui->dobLineEdit->setReadOnly(true);
            ui->phoneLineEdit->setReadOnly(true);
            ui->emailLineEdit->setReadOnly(true);

            // 4. 更改按钮文本
            ui->editSaveButton->setText("修改资料");

            // 5. 更新状态标志
            m_isEditMode = false;

        } else {
            // 如果执行失败
            QMessageBox::critical(this, "失败", "资料更新失败，数据库错误: " + query.lastError().text());
        }
    }
}
