#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 为每个按钮声明一个槽函数
    void on_patientInfoButton_clicked();
    void on_consultationButton_clicked();
    void on_doctorInfoButton_clicked();
    void on_emrButton_clicked();
    void on_healthRecordButton_clicked();
    void on_medicationReminderButton_clicked();
    void on_paymentButton_clicked();
    void on_chatButton_clicked();
    void on_myAppointmentsButton_clicked();
    void on_aiButton_clicked();


private:
    Ui::MainWindow *ui;
    int m_loggedInUserId;
};
#endif // MAINWINDOW_H
