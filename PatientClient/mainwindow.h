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
    void on_paymentButton_clicked();
    void on_chatButton_clicked();
    void on_myAppointmentsButton_clicked();

protected:
    // 添加 paintEvent 的声明
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::MainWindow *ui;
    int m_loggedInUserId;
    QPixmap m_backgroundPixmap;

    void loadWelcomeMessage(); // <-- 添加声明
    void setDailyTip();        // <-- 添加声明
};
#endif // MAINWINDOW_H
