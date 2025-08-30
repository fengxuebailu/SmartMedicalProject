#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QDialog>
#include <QList>

namespace Ui {
class PaymentDialog;
}

class PaymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentDialog(QWidget *parent = nullptr);
    ~PaymentDialog();

    void setPaymentInfo(double amount, const QList<int> &billIds);

private slots:
    void on_confirmPaymentButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::PaymentDialog *ui;
    double m_amount;
    QList<int> m_billIds;
};

#endif // PAYMENTDIALOG_H
