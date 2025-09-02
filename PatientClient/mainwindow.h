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
    // 构造函数和析构函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// 使用 private slots: 是一种良好的实践，
// Qt的元对象系统可以发现并连接它们。
private slots:
    // --- UI 按钮点击事件对应的槽函数 ---
    void on_patientInfoButton_clicked();
    void on_consultationButton_clicked(); // 预约挂号
    void on_doctorInfoButton_clicked();
    void on_emrButton_clicked();
    void on_paymentButton_clicked();
    void on_chatButton_clicked();
    void on_myAppointmentsButton_clicked();
    void on_relaxationButton_clicked();
    void on_aiButton_clicked();
    void on_checkinButton_clicked();      // “亲子打卡”按钮（如果UI里有的话）

    // --- 自定义的功能槽函数 ---
    // 这个函数被 setupHomeGrid 中的按钮直接连接
    void onCheckin();

private:
    // --- 私有成员变量 ---
    Ui::MainWindow *ui;
    int m_loggedInUserId; // 用于存储当前登录用户的ID

    // --- 私有辅助函数 ---
    // 这些函数在构造函数中被调用，用于初始化界面
    void setupHomeGrid();
    void loadWelcomeMessage();
    void setDailyTip();
};

#endif // MAINWINDOW_H
