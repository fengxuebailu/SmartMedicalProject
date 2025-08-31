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

    m_selectedDoctorId = -1;

    // UI配置保持不变
    ui->doctorsTableWidget->setColumnCount(3);
    ui->doctorsTableWidget->setHorizontalHeaderLabels({"医生姓名", "职称", "个人简介"});
    ui->doctorsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->doctorsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->doctorsTableWidget->verticalHeader()->setVisible(false);
    ui->doctorsTableWidget->horizontalHeader()->setStretchLastSection(true);

    loadDepartments();
}

DoctorSelectionDialog::~DoctorSelectionDialog()
{
    delete ui;
}

void DoctorSelectionDialog::loadDepartments()
{
    ui->departmentsListWidget->clear();

    // 新的查询逻辑：从 doctors 表中提取不重复的科室名称
    QSqlQuery query("SELECT DISTINCT department FROM doctors WHERE department IS NOT NULL AND department != '' ORDER BY department");
    if (!query.exec()) {
        qDebug() << "加载科室列表失败: " << query.lastError().text();
        return;
    }
    while (query.next()) {
        ui->departmentsListWidget->addItem(query.value(0).toString());
    }
}

// 函数签名和实现都已修改
void DoctorSelectionDialog::loadDoctors(const QString &departmentName)
{
    ui->doctorsTableWidget->setRowCount(0);
    m_selectedDoctorId = -1;
    ui->nextButton->setEnabled(false);

    QSqlQuery query;
    // 新的查询逻辑：根据科室名称查询
    query.prepare("SELECT user_id, full_name, title, bio FROM doctors WHERE department = :deptName");
    query.bindValue(":deptName", departmentName);

    if (!query.exec()) {
        qDebug() << "加载医生列表失败: " << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->doctorsTableWidget->insertRow(row);

        QString doctorName = query.value("full_name").toString();
        QString title = query.value("title").toString();
        QString bio = query.value("bio").toString();

        // 我们将 user_id 存储在第一项的用户数据中，以便后续获取
        QTableWidgetItem *nameItem = new QTableWidgetItem(doctorName);
        nameItem->setData(Qt::UserRole, query.value("user_id").toInt());

        ui->doctorsTableWidget->setItem(row, 0, nameItem);
        ui->doctorsTableWidget->setItem(row, 1, new QTableWidgetItem(title));
        ui->doctorsTableWidget->setItem(row, 2, new QTableWidgetItem(bio));
        row++;
    }
    ui->doctorsTableWidget->resizeColumnsToContents();
}


void DoctorSelectionDialog::on_departmentsListWidget_itemClicked(QListWidgetItem *item)
{
    // 直接使用 item 的文本作为科室名称
    loadDoctors(item->text());
}

void DoctorSelectionDialog::on_doctorsTableWidget_cellClicked(int row, int column)
{
    Q_UNUSED(column);

    // 从表格第一列的用户数据中安全地获取医生 user_id
    if (ui->doctorsTableWidget->item(row, 0)) {
        m_selectedDoctorId = ui->doctorsTableWidget->item(row, 0)->data(Qt::UserRole).toInt();
        m_selectedDoctorName = ui->doctorsTableWidget->item(row, 0)->text();
        ui->nextButton->setEnabled(true);
    } else {
        m_selectedDoctorId = -1;
        ui->nextButton->setEnabled(false);
    }
}

void DoctorSelectionDialog::on_nextButton_clicked()
{
    if (m_selectedDoctorId > 0) {
        emit doctorSelected(m_selectedDoctorId, m_selectedDoctorName);
        this->accept();
    } else {
        QMessageBox::warning(this, "提示", "请先选择一位医生。");
    }
}
