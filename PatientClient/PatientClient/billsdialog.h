#ifndef BILLSDIALOG_H
#define BILLSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QList>

namespace Ui {
class BillsDialog;
}

class BillsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BillsDialog(QWidget *parent = nullptr);
    ~BillsDialog();

    void loadBills(int patientId);

private slots:
    void on_billsTableWidget_itemChanged(QTableWidgetItem *item);
    void on_payButton_clicked();
    void on_closeButton_clicked();

private:
    void updateTotals();

    Ui::BillsDialog *ui;
    int m_patientId;
};

#endif // BILLSDIALOG_H
