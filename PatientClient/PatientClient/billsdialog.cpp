#include "billsdialog.h"
#include "ui_billsdialog.h"
#include "paymentdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QCheckBox>

BillsDialog::BillsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BillsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("我的账单");

    ui->billsTableWidget->setColumnCount(4);
    ui->billsTableWidget->setHorizontalHeaderLabels({" ", "费用项目", "金额 (¥)", "状态"});
    ui->billsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->billsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

BillsDialog::~BillsDialog()
{
    delete ui;
}

void BillsDialog::loadBills(int patientId)
{
    m_patientId = patientId;
    // 阻止信号触发，防止在填充数据过程中不必要的计算
    ui->billsTableWidget->blockSignals(true);
    ui->billsTableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT id, item_name, amount, status FROM payment WHERE patient_id = :patientId ORDER BY status, created_at DESC");
    query.bindValue(":patientId", m_patientId);

    if (!query.exec()) {
        qDebug() << "加载账单失败: " << query.lastError().text();
        ui->billsTableWidget->blockSignals(false); // 恢复信号
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->billsTableWidget->insertRow(row);

        int billId = query.value(0).toInt();
        QString itemName = query.value(1).toString();
        double amount = query.value(2).toDouble();
        QString status = query.value(3).toString();

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        if (status == "待支付") {
            checkItem->setCheckState(Qt::Unchecked);
        } else {
            checkItem->setCheckState(Qt::Checked);
            checkItem->setFlags(Qt::NoItemFlags); // 已支付的完全不可交互
        }
        checkItem->setData(Qt::UserRole, billId);
        ui->billsTableWidget->setItem(row, 0, checkItem);

        ui->billsTableWidget->setItem(row, 1, new QTableWidgetItem(itemName));
        ui->billsTableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(amount, 'f', 2)));
        ui->billsTableWidget->setItem(row, 3, new QTableWidgetItem(status));
        row++;
    }
    ui->billsTableWidget->resizeColumnsToContents();
    // 数据填充完毕后，恢复信号
    ui->billsTableWidget->blockSignals(false);
    updateTotals(); // 最后手动更新一次总额
}

// ============== 这里是崩溃的根源所在，我们加固它 ==============
void BillsDialog::updateTotals()
{
    double total = 0.0;
    int checkedCount = 0;
    for (int i = 0; i < ui->billsTableWidget->rowCount(); ++i) {
        // --- 添加【必须的】安全检查 ---
        QTableWidgetItem *checkItem = ui->billsTableWidget->item(i, 0);
        QTableWidgetItem *statusItem = ui->billsTableWidget->item(i, 3);
        QTableWidgetItem *amountItem = ui->billsTableWidget->item(i, 2);

        // 如果任何一个单元格是空的，就跳过这一行，防止崩溃
        if (!checkItem || !statusItem || !amountItem) {
            qDebug() << "警告：在 updateTotals 中遇到空的单元格，行号：" << i;
            continue;
        }
        // --- 安全检查结束 ---

        if (checkItem->checkState() == Qt::Checked) {
            if (statusItem->text() == "待支付") {
                total += amountItem->text().toDouble();
                checkedCount++;
            }
        }
    }
    ui->totalAmountLabel->setText(QString("待支付总额：¥ %1").arg(QString::number(total, 'f', 2)));
    ui->payButton->setEnabled(checkedCount > 0);
}

void BillsDialog::on_billsTableWidget_itemChanged(QTableWidgetItem *item)
{
    // 只在用户操作第一列的复选框时才更新总额
    if (item && item->column() == 0) {
        updateTotals();
    }
}

// on_payButton_clicked 和 on_closeButton_clicked 保持不变
void BillsDialog::on_payButton_clicked()
{
    QList<int> billsToPayIds;
    double totalAmount = 0.0;

    for (int i = 0; i < ui->billsTableWidget->rowCount(); ++i) {
        QTableWidgetItem *checkItem = ui->billsTableWidget->item(i, 0);
        QTableWidgetItem *statusItem = ui->billsTableWidget->item(i, 3);
        QTableWidgetItem *amountItem = ui->billsTableWidget->item(i, 2);

        // 这里也加上同样的安全检查
        if (!checkItem || !statusItem || !amountItem) continue;

        if (checkItem->checkState() == Qt::Checked && statusItem->text() == "待支付") {
            billsToPayIds.append(checkItem->data(Qt::UserRole).toInt());
            totalAmount += amountItem->text().toDouble();
        }
    }

    if (billsToPayIds.isEmpty()) {
        QMessageBox::information(this, "提示", "请至少选择一个待支付项目。");
        return;
    }

    PaymentDialog paymentDialog(this);
    paymentDialog.setPaymentInfo(totalAmount, billsToPayIds);

    if (paymentDialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "支付成功", "您的账单已支付成功！");
        loadBills(m_patientId);
    }
}

void BillsDialog::on_closeButton_clicked()
{
    this->accept();
}
