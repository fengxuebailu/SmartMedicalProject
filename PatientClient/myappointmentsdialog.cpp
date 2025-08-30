#include "myappointmentsdialog.h"
#include "ui_myappointmentsdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate> // 确保包含了 QDate 头文件

MyAppointmentsDialog::MyAppointmentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyAppointmentsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("我的预约记录");

    // UI 表格的配置保持不变，但我们可以增加一列来显示状态
    ui->appointmentsTableWidget->setColumnCount(5);
    ui->appointmentsTableWidget->setHorizontalHeaderLabels({"预约医生", "所属科室", "预约时间", "状态", "预约原因"});
    ui->appointmentsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->appointmentsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->appointmentsTableWidget->verticalHeader()->setVisible(false);
}

MyAppointmentsDialog::~MyAppointmentsDialog()
{
    delete ui;
}

// 函数签名和实现都已完全重写
void MyAppointmentsDialog::loadAppointments(int userId)
{
    QSqlQuery query;
    // --- 这是新的、适配新数据库的 SQL 查询语句 ---
    // 我们需要 JOIN doctors 表来获取医生的详细信息
    query.prepare("SELECT d.full_name, d.department, a.scheduled_at, a.status, a.reason "
                  "FROM appointments a "
                  "JOIN doctors d ON a.doctor_id = d.user_id "
                  "WHERE a.patient_id = :userId "
                  "ORDER BY a.scheduled_at DESC");
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "查询预约记录失败: " << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法加载您的预约记录。");
        return;
    }

    ui->appointmentsTableWidget->setRowCount(0); // 每次加载前先清空表格
    int row = 0;
    while (query.next()) {
        ui->appointmentsTableWidget->insertRow(row);

        // 从查询结果中按新的字段名和顺序取出数据
        QString doctorName = query.value("full_name").toString();
        QString departmentName = query.value("department").toString();
        // scheduled_at 是 DATETIME 类型，需要格式化
        QString scheduledAt = query.value("scheduled_at").toDateTime().toString("yyyy-MM-dd HH:mm");
        QString status = query.value("status").toString();
        QString reason = query.value("reason").toString();

        // 将数据填充到表格的单元格中
        ui->appointmentsTableWidget->setItem(row, 0, new QTableWidgetItem(doctorName));
        ui->appointmentsTableWidget->setItem(row, 1, new QTableWidgetItem(departmentName));
        ui->appointmentsTableWidget->setItem(row, 2, new QTableWidgetItem(scheduledAt));
        ui->appointmentsTableWidget->setItem(row, 3, new QTableWidgetItem(status));
        ui->appointmentsTableWidget->setItem(row, 4, new QTableWidgetItem(reason));
        row++;
    }

    // 根据内容自动调整列的宽度
    ui->appointmentsTableWidget->resizeColumnsToContents();
}

void MyAppointmentsDialog::on_closeButton_clicked()
{
    this->accept();
}
