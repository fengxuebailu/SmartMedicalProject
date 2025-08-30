#include "myappointmentsdialog.h"
#include "ui_myappointmentsdialog.h"

// 包含数据库操作和调试所需的头文件
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>

MyAppointmentsDialog::MyAppointmentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyAppointmentsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("我的预约记录");

    // 设置表格控件的基本属性
    ui->appointmentsTableWidget->setColumnCount(4);
    ui->appointmentsTableWidget->setHorizontalHeaderLabels({"预约医生", "所属科室", "预约日期", "预约时间段"});
    ui->appointmentsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
    ui->appointmentsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
    ui->appointmentsTableWidget->verticalHeader()->setVisible(false); // 隐藏行号
}

MyAppointmentsDialog::~MyAppointmentsDialog()
{
    delete ui;
}

void MyAppointmentsDialog::loadAppointments(int patientId)
{
    QSqlQuery query;
    // 准备一条复杂的 SQL JOIN 查询语句，这样可以一次性从三个表中获取我们需要的所有信息
    query.prepare("SELECT d.name, dep.name, a.appointment_date, a.appointment_time "
                  "FROM appointments a "
                  "JOIN doctors d ON a.doctor_id = d.id "
                  "JOIN departments dep ON d.department_id = dep.id "
                  "WHERE a.patient_id = :patientId ORDER BY a.appointment_date DESC, a.appointment_time ASC");
    query.bindValue(":patientId", patientId);

    if (!query.exec()) {
        qDebug() << "查询预约记录失败: " << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法加载预约记录。");
        return;
    }

    ui->appointmentsTableWidget->setRowCount(0); // 每次加载前先清空表格
    int row = 0;
    while (query.next()) {
        ui->appointmentsTableWidget->insertRow(row);
        // 从查询结果中按顺序取出每一列的数据
        QString doctorName = query.value(0).toString();
        QString departmentName = query.value(1).toString();
        QString appointmentDate = query.value(2).toDate().toString("yyyy-MM-dd");
        QString appointmentTime = query.value(3).toString();

        // 将数据填充到表格的单元格中
        ui->appointmentsTableWidget->setItem(row, 0, new QTableWidgetItem(doctorName));
        ui->appointmentsTableWidget->setItem(row, 1, new QTableWidgetItem(departmentName));
        ui->appointmentsTableWidget->setItem(row, 2, new QTableWidgetItem(appointmentDate));
        ui->appointmentsTableWidget->setItem(row, 3, new QTableWidgetItem(appointmentTime));
        row++;
    }

    // 根据内容自动调整列的宽度，使显示效果更好
    ui->appointmentsTableWidget->resizeColumnsToContents();
}

void MyAppointmentsDialog::on_closeButton_clicked()
{
    this->accept(); // accept() 是一个标准的关闭对话框并返回 QDialog::Accepted 的方法
}
