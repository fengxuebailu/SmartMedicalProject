#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // 用于显示简单的消息框
#include "patientinfodialog.h"
#include "myappointmentsdialog.h"
#include "doctorselectiondialog.h"
#include "doctordetailsdialog.h"
#include "timeselectiondialog.h"
#include "billsdialog.h"
#include "emrdialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_loggedInPatientId = 1; // <-- 添加这一行，为了测试，我们假设ID为1的患者已登录

//    QPixmap testPixmap(":/icons/icon_home_profile.png"); // <-- 替换成你的正确路径
//     if (testPixmap.isNull()) {
//         qDebug() << "致命错误：无法从资源文件加载图标 :/icons/icon_home_profile.png";
//     } else {
//         qDebug() << "成功：从资源文件加载了图标，尺寸为：" << testPixmap.size();
//     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 以下是每个按钮点击事件的实现
// 在实际项目中，您会在这里创建并显示新的窗口或执行相应的功能

void MainWindow::on_patientInfoButton_clicked()
{
    // 创建并以模态方式显示个人资料对话框
    PatientInfoDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_doctorInfoButton_clicked()
{
    // 步骤1：打开医生选择对话框，这和预约挂号的第一步完全一样
       DoctorSelectionDialog docDialog(this);
       docDialog.setWindowTitle("第一步：选择要查看的医生"); // 可以给它一个不同的标题

       // 步骤2：连接其 doctorSelected 信号到一个新的逻辑
       // 当用户在 docDialog 中选择完医生并点击“下一步”后，下面的 Lambda 函数会被执行
       connect(&docDialog, &DoctorSelectionDialog::doctorSelected, this,
               [this](int doctorId, const QString &doctorName) {

           qDebug() << "准备查看医生详情，ID=" << doctorId << "，姓名=" << doctorName;

           // 步骤3：创建并显示医生详情对话框
           DoctorDetailsDialog detailsDialog(this);
           // 调用它的公共方法，传入选定的医生ID来加载数据
           detailsDialog.loadDoctorDetails(doctorId);
           // 以模态方式显示
           detailsDialog.exec();
       });

       // 启动医生选择流程
       docDialog.exec();
}

void MainWindow::on_emrButton_clicked()
{
    EmrDialog dialog(this);
    dialog.loadPatientRecords(m_loggedInPatientId); // 传入已登录的患者ID
    dialog.exec();
}

void MainWindow::on_healthRecordButton_clicked()
{
    QMessageBox::information(this, "健康档案管理", "这里将打开健康档案管理界面。");
}

void MainWindow::on_medicationReminderButton_clicked()
{
    QMessageBox::information(this, "用药提醒", "这里将打开用药提醒设置界面。");
}

void MainWindow::on_paymentButton_clicked()
{
    BillsDialog dialog(this);
    dialog.loadBills(m_loggedInPatientId); // 传入已登录的患者ID
    dialog.exec();
}

void MainWindow::on_chatButton_clicked()
{
    QMessageBox::information(this, "聊天/消息通知", "这里将打开聊天和消息通知中心。");
}

// --- 实现“我的预约”按钮的槽函数 ---
// 这个槽函数需要你手动去创建，或者在UI设计器里右键按钮 "Go to slot..."
void MainWindow::on_myAppointmentsButton_clicked()
{
    // 创建“我的预约”对话框实例
    MyAppointmentsDialog dialog(this);
    // 调用它的公共方法，传入当前登录的患者ID来加载数据
    dialog.loadAppointments(m_loggedInPatientId);
    // 以模态方式显示对话框
    dialog.exec();
}

// --- 修改“在线问诊/预约挂号”按钮的槽函数 ---
void MainWindow::on_consultationButton_clicked()
{
    // 步骤1：创建并显示医生选择对话框
    DoctorSelectionDialog docDialog(this);

    // 步骤2：将 docDialog 的 doctorSelected 信号连接到一个处理逻辑上
    // 这里我们使用 C++11 的 Lambda 表达式，这是现代 Qt 中处理信号槽非常优雅的方式。
    // 当 docDialog 发射 doctorSelected 信号时，花括号 {} 中的代码就会被执行。
    connect(&docDialog, &DoctorSelectionDialog::doctorSelected, this,
            [this](int doctorId, const QString &doctorName) {

        // 这里的代码会在用户选择完医生并点击“下一步”之后执行
        qDebug() << "从主窗口接收到信号：医生ID=" << doctorId << "，医生姓名=" << doctorName;

        // 步骤3：创建并显示时间选择对话框
        TimeSelectionDialog timeDialog(this);
        // 将从上一步获取的医生信息，以及当前登录的患者信息，传递给时间选择对话框
        timeDialog.setAppointmentInfo(doctorId, doctorName, m_loggedInPatientId);
        // 以模态方式显示对话框
        timeDialog.exec();
    });

    // 以模态方式显示医生选择对话框。代码会在这里暂停，直到用户关闭 docDialog。
    docDialog.exec();
}
