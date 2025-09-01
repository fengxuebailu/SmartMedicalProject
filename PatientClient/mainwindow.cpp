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
#include "chatdialog.h"
#include <QDebug>
#include <QSqlQuery> // 需要包含，以便查询患者姓名
#include <QDate>     // 需要包含，以便使用日期功能
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_loggedInUserId = 2; ; // <-- 添加这一行，为了测试，我们假设ID为1的患者已登录

    // --- 加载并设置欢迎语 ---
    loadWelcomeMessage();

    // --- 动态设置每日提示 ---
    setDailyTip();

    // --- 在构造函数中加载并预处理背景图 ---
    QPixmap originalPixmap(":/backgrounds/bg_main_window.jpg");
    if (!originalPixmap.isNull()) {
        // 将图片预先缩放到一个常见的大尺寸，比如 1280x720
        // 使用 SmoothTransformation 可以获得更好的缩放质量
        m_backgroundPixmap = originalPixmap.scaled(1280, 720, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    } else {
        qDebug() << "警告：无法加载背景图片，paintEvent 将不会绘制背景。";
    }

//    // --- 添加以下验证代码 ---
//        QPixmap testPixmap(":/icons/bg_main_window.png");
//        if (testPixmap.isNull()) {
//            qDebug() << "【验证失败】: 无法从资源路径 ':/backgrounds/bg_main_window.png' 加载图片。请检查 .qrc 文件中的前缀和文件名。";
//        } else {
//            qDebug() << "【验证成功】: 成功从资源路径 ':/backgrounds/bg_main_window.png' 加载了图片！尺寸为：" << testPixmap.size();
//        }

//        // 我们再试一个图标路径
//        QPixmap testIcon(":/icons/icon_home_doctor1.png"); // 假设这是你的一个图标
//        if (testIcon.isNull()) {
//             qDebug() << "【验证失败】: 无法从资源路径 ':/icons/icon_home_profile.png' 加载图标。";
//        } else {
//             qDebug() << "【验证成功】: 成功从资源路径 ':/icons/icon_home_profile.png' 加载了图标！";
//        }
//        // -----------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 以下是每个按钮点击事件的实现
// 在实际项目中，您会在这里创建并显示新的窗口或执行相应的功能

// 我们将加载欢迎语的逻辑也封装成一个函数
void MainWindow::loadWelcomeMessage()
{
    QSqlQuery query;
    query.prepare("SELECT full_name FROM patients WHERE user_id = :userId");
    query.bindValue(":userId", m_loggedInUserId);
    if (query.exec() && query.next()) {
        ui->patientNameLabel->setText(query.value(0).toString());
    } else {
        ui->patientNameLabel->setText("家长");
    }
}

// 设置每日提示的函数
void MainWindow::setDailyTip()
{
    // 创建一个提示语列表
    QStringList tips;
    tips << "天气转凉，记得及时给宝宝增添衣物哦！"
         << "多带宝宝去户外活动，晒晒太阳有助于钙的吸收。"
         << "你知道吗？宝宝的第一次牙科检查应该在第一颗牙萌出后进行。"
         << "鼓励宝宝多喝水，而不是含糖饮料，对牙齿和身体都好。"
         << "每天给宝宝读一个绘本故事，是最好的亲子时光！"
         << "今天你和宝宝一起大笑了吗？好心情是最好的免疫力！";

    // 根据当天的日期，从列表中选择一条提示
    // 这样可以确保每天的提示都是固定的，而不是每次启动都变
    int dayOfYear = QDate::currentDate().dayOfYear();
    int tipIndex = dayOfYear % tips.size(); // 使用取余运算来循环选择

    ui->tipsLabel->setText(tips.at(tipIndex));
}

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
    dialog.loadPatientRecords(m_loggedInUserId); // 传入已登录的患者ID
    dialog.exec();
}


void MainWindow::on_paymentButton_clicked()
{
    BillsDialog dialog(this);
    dialog.loadBills(m_loggedInUserId); // 传入已登录的患者ID
    dialog.exec();
}

// --- 实现“我的预约”按钮的槽函数 ---
// 这个槽函数需要你手动去创建，或者在UI设计器里右键按钮 "Go to slot..."
void MainWindow::on_myAppointmentsButton_clicked()
{
    // 创建“我的预约”对话框实例
    MyAppointmentsDialog dialog(this);
    // 调用它的公共方法，传入当前登录的患者ID来加载数据
    dialog.loadAppointments(m_loggedInUserId);
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
        timeDialog.setAppointmentInfo(doctorId, doctorName, m_loggedInUserId);
        // 以模态方式显示对话框
        timeDialog.exec();
    });

    // 以模态方式显示医生选择对话框。代码会在这里暂停，直到用户关闭 docDialog。
    docDialog.exec();
}

void MainWindow::on_chatButton_clicked()
{
    // 创建并显示聊天对话框
    ChatDialog dialog(this);
    // 将当前登录的用户ID传递进去
    dialog.setup(m_loggedInUserId);
    dialog.exec();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event); // 首先调用基类的 paintEvent

    if (!m_backgroundPixmap.isNull()) {
        QPainter painter(this);
        // 将预处理过的 Pixmap 绘制到窗口上，自动拉伸以填满整个窗口
        painter.drawPixmap(this->rect(), m_backgroundPixmap);
    }
}
