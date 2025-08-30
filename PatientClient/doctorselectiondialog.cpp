#include "doctorselectiondialog.h"
#include "ui_doctorselectiondialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

DoctorSelectionDialog::DoctorSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorSelectionDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("第一步：选择科室和医生");

    m_selectedDoctorId = -1; // 初始化为无效ID

    // 配置医生表格
    ui->doctorsTableWidget->setColumnCount(3);
    ui->doctorsTableWidget->setHorizontalHeaderLabels({"医生姓名", "职称", "擅长领域"});
    ui->doctorsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->doctorsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->doctorsTableWidget->verticalHeader()->setVisible(false);
    ui->doctorsTableWidget->horizontalHeader()->setStretchLastSection(true); // 让最后一列自动拉伸

    loadDepartments();
}

DoctorSelectionDialog::~DoctorSelectionDialog()
{
    delete ui;
}

void DoctorSelectionDialog::loadDepartments()
{
    QSqlQuery query("SELECT id, name FROM departments ORDER BY id");
    if (!query.exec()) {
        qDebug() << "加载科室列表失败: " << query.lastError().text();
        return;
    }
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->departmentsListWidget->addItem(name);
        m_departmentIdMap[name] = id; // 存储科室名和ID的映射关系
    }
}

void DoctorSelectionDialog::loadDoctors(int departmentId)
{
    ui->doctorsTableWidget->setRowCount(0); // 清空医生列表
    m_selectedDoctorId = -1; // 重置已选医生
    ui->nextButton->setEnabled(false); // 禁用下一步按钮

    QSqlQuery query;
    query.prepare("SELECT id, name, title, specialty FROM doctors WHERE department_id = :deptId");
    query.bindValue(":deptId", departmentId);

    if (!query.exec()) {
        qDebug() << "加载医生列表失败: " << query.lastError().text();
        return;
    }
    int row = 0;
    while (query.next()) {
        ui->doctorsTableWidget->insertRow(row);
        // 注意：我们把ID存储在第一列，但这一列是隐藏的
        ui->doctorsTableWidget->setItem(row, 0, new QTableWidgetItem(query.value(1).toString())); // name
        ui->doctorsTableWidget->setItem(row, 1, new QTableWidgetItem(query.value(2).toString())); // title
        ui->doctorsTableWidget->setItem(row, 2, new QTableWidgetItem(query.value(3).toString())); // specialty

        // 把医生的数据库ID存储在表格项的用户数据中，这是一个非常有用的技巧
        ui->doctorsTableWidget->item(row, 0)->setData(Qt::UserRole, query.value(0).toInt());
        row++;
    }
    ui->doctorsTableWidget->resizeColumnsToContents();
}


void DoctorSelectionDialog::on_departmentsListWidget_itemClicked(QListWidgetItem *item)
{
    QString departmentName = item->text();
    int departmentId = m_departmentIdMap.value(departmentName, -1);
    if (departmentId != -1) {
        loadDoctors(departmentId);
    }
}

void DoctorSelectionDialog::on_doctorsTableWidget_cellClicked(int row, int column)
{
    // 通过用户数据获取之前存入的医生ID
    m_selectedDoctorId = ui->doctorsTableWidget->item(row, 0)->data(Qt::UserRole).toInt();
    m_selectedDoctorName = ui->doctorsTableWidget->item(row, 0)->text();

    if (m_selectedDoctorId > 0) {
        ui->nextButton->setEnabled(true); // 只有成功获取ID后才启用按钮
    }
}

void DoctorSelectionDialog::on_nextButton_clicked()
{
    if (m_selectedDoctorId > 0) {
        // 发射信号，将选中的医生信息传递出去
        emit doctorSelected(m_selectedDoctorId, m_selectedDoctorName);
        this->accept(); // 关闭对话框
    } else {
        QMessageBox::warning(this, "提示", "请先选择一位医生。");
    }
}
