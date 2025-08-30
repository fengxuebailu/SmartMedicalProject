#include "emrdialog.h"
#include "ui_emrdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>

EmrDialog::EmrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmrDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("电子病历查看");
}

EmrDialog::~EmrDialog()
{
    delete ui;
}

// 核心函数1：加载左侧的就诊列表
void EmrDialog::loadPatientRecords(int patientId)
{
    m_patientId = patientId;
    ui->visitsListWidget->clear();
    m_recordIdMap.clear();
    clearDetails();

    QSqlQuery query;
    // 查询该患者的所有病历，并关联医生表以获取医生姓名
    query.prepare("SELECT mr.id, mr.visit_date, d.name "
                  "FROM medical_records mr "
                  "JOIN appointments a ON mr.appointment_id = a.id "
                  "JOIN doctors d ON a.doctor_id = d.id "
                  "WHERE mr.patient_id = :patientId "
                  "ORDER BY mr.visit_date DESC");
    query.bindValue(":patientId", m_patientId);

    if (!query.exec()) {
        qDebug() << "加载病历列表失败: " << query.lastError().text();
        return;
    }

    if (query.size() == 0) {
        ui->visitsListWidget->addItem("暂无就诊记录");
        ui->visitsListWidget->setEnabled(false);
        return;
    }

    while (query.next()) {
        int recordId = query.value(0).toInt();
        QDate visitDate = query.value(1).toDate();
        QString doctorName = query.value(2).toString();

        // 创建一个列表项，显示对用户友好的信息
        QString itemText = QString("%1 - %2").arg(visitDate.toString("yyyy-MM-dd"), doctorName);
        QListWidgetItem *item = new QListWidgetItem(itemText);
        ui->visitsListWidget->addItem(item);

        // 将列表项指针和病历ID关联起来存入Map
        m_recordIdMap[item] = recordId;
    }

    // 默认选中第一条记录并显示其详情
    if (ui->visitsListWidget->count() > 0) {
        ui->visitsListWidget->setCurrentRow(0);
        // 手动触发 itemClicked 信号来加载第一条记录的详情
        on_visitsListWidget_itemClicked(ui->visitsListWidget->item(0));
    }
}

// 核心函数2：当用户点击左侧列表中的某一项时，加载右侧的详细信息
void EmrDialog::on_visitsListWidget_itemClicked(QListWidgetItem *item)
{
    if (!item || !m_recordIdMap.contains(item)) {
        clearDetails();
        return;
    }

    int recordId = m_recordIdMap.value(item);
    displayRecordDetails(recordId);
}

// 辅助函数：根据病历ID查询并显示所有详细信息
void EmrDialog::displayRecordDetails(int recordId)
{
    QSqlQuery query;
    // 这是一个更复杂的查询，需要关联4张表才能获取所有信息
    query.prepare("SELECT mr.visit_date, d.name, dep.name, mr.chief_complaint, "
                  "mr.diagnosis, mr.treatment_plan, mr.doctor_notes "
                  "FROM medical_records mr "
                  "JOIN appointments a ON mr.appointment_id = a.id "
                  "JOIN doctors d ON a.doctor_id = d.id "
                  "JOIN departments dep ON d.department_id = dep.id "
                  "WHERE mr.id = :recordId");
    query.bindValue(":recordId", recordId);

    if (!query.exec()) {
        qDebug() << "查询病历详情失败: " << query.lastError().text();
        clearDetails();
        return;
    }

    if (query.next()) {
        ui->dateLineEdit->setText(query.value(0).toDate().toString("yyyy-MM-dd"));
        ui->doctorLineEdit->setText(query.value(1).toString());
        ui->departmentLineEdit->setText(query.value(2).toString());
        ui->complaintTextEdit->setText(query.value(3).toString());
        ui->diagnosisTextEdit->setText(query.value(4).toString());
        ui->planTextEdit->setText(query.value(5).toString());
        ui->notesTextEdit->setText(query.value(6).toString());
    }
}

// 辅助函数：清空右侧所有详情
void EmrDialog::clearDetails()
{
    ui->dateLineEdit->clear();
    ui->doctorLineEdit->clear();
    ui->departmentLineEdit->clear();
    ui->complaintTextEdit->clear();
    ui->diagnosisTextEdit->clear();
    ui->planTextEdit->clear();
    ui->notesTextEdit->clear();
}

void EmrDialog::on_closeButton_clicked()
{
    this->accept();
}
