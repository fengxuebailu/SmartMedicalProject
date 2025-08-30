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

    // 公共方法，用于从外部（如MainWindow）调用以加载数据
    void loadAppointments(int patientId);

private slots:
    void on_closeButton_clicked();

private:
    Ui::MyAppointmentsDialog *ui;
};

#endif // MYAPPOINTMENTSDIALOG_H
