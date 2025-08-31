#ifndef MYAPPOINTMENTSDIALOG_H
#define MYAPPOINTMENTSDIALOG_H

#include <QDialog>

namespace Ui {
class MyAppointmentsDialog;
}

class MyAppointmentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyAppointmentsDialog(QWidget *parent = nullptr);
    ~MyAppointmentsDialog();

    // 函数签名已修改：接收通用的用户ID (userId)
    void loadAppointments(int userId);

private slots:
    void on_closeButton_clicked();

private:
    Ui::MyAppointmentsDialog *ui;
};

#endif // MYAPPOINTMENTSDIALOG_H
