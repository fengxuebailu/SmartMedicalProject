#include "paymentdialog.h"
#include "ui_paymentdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDateTime>

PaymentDialog::PaymentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("模拟支付");
}

PaymentDialog::~PaymentDialog()
{
    delete ui;
}

void PaymentDialog::setPaymentInfo(double amount, const QList<int> &billIds)
{
    m_amount = amount;
    m_billIds = billIds;
    ui->amountLabel->setText(QString("支付金额：¥ %1").arg(QString::number(m_amount, 'f', 2)));
}

void PaymentDialog::on_confirmPaymentButton_clicked()
{
    // 模拟密码验证
    if (ui->passwordLineEdit->text() != "123456") { // 假设支付密码是 "123456"
        QMessageBox::warning(this, "密码错误", "支付密码不正确，请重试。");
        ui->passwordLineEdit->clear();
        return;
    }

    // 使用数据库事务来更新所有账单
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        QMessageBox::critical(this, "数据库错误", "无法开始处理您的支付。");
        return;
    }

    QSqlQuery query;
    bool all_success = true;
    for (int billId : m_billIds) {
        query.prepare("UPDATE bills SET status = '已支付', paid_at = :paidAt WHERE id = :billId");
        query.bindValue(":paidAt", QDateTime::currentDateTime());
        query.bindValue(":billId", billId);
        if (!query.exec()) {
            all_success = false;
            break; // 一旦有任何一个更新失败，就中断循环
        }
    }

    if (all_success) {
        db.commit();
        this->accept(); // 关闭对话框并返回成功状态
    } else {
        db.rollback();
        QMessageBox::critical(this, "支付失败", "更新账单状态时发生错误，支付已取消。");
        this->reject(); // 关闭对话框并返回失败状态
    }
}

void PaymentDialog::on_cancelButton_clicked()
{
    this->reject();
}
