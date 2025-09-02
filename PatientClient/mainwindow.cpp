#include "mainwindow.h"
#include "ui_mainwindow.h"

// --- 包含所有需要的头文件 (已合并去重) ---
#include "patientinfodialog.h"
#include "myappointmentsdialog.h"
#include "doctorselectiondialog.h"
#include "doctordetailsdialog.h"
#include "timeselectiondialog.h"
#include "billsdialog.h"
#include "emrdialog.h"
#include "Aidialog.h"
#include "chatdialog.h"
#include "relaxationdialog.h"
#include "healthcheckindialog.h" // 新增的功能

#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <QGridLayout>
#include <QToolButton>
#include <QVBoxLayout>
#include <QIcon>

// --- 构造函数 ---
// 合并了两个版本的初始化逻辑
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // 初始化UI界面

    // 设置当前登录用户的ID，这是后续很多功能的基础
    m_loggedInUserId = 101;

    // 调用初始化函数
    setupHomeGrid();      // 创建主页的功能按钮网格
    loadWelcomeMessage(); // 加载欢迎语和患者姓名
    setDailyTip();        // 设置每日健康小贴士
}

// --- 析构函数 ---
MainWindow::~MainWindow()
{
    delete ui;
}

// --- 槽函数实现 (Slots Implementation) ---
// 下面是所有按钮点击事件的实现，已合并去重

// “个人资料”按钮
void MainWindow::on_patientInfoButton_clicked()
{
    PatientInfoDialog dialog(this);
    dialog.exec();
}

// “医生信息”按钮
void MainWindow::on_doctorInfoButton_clicked()
{
    DoctorSelectionDialog docDialog(this);
    docDialog.setWindowTitle("第一步：选择要查看的医生");

    connect(&docDialog, &DoctorSelectionDialog::doctorSelected, this,
            [this](int doctorId, const QString &doctorName) {
                qDebug() << "查看医生详情 ID=" << doctorId << " 姓名=" << doctorName;

                DoctorDetailsDialog detailsDialog(this);
                detailsDialog.loadDoctorDetails(doctorId);
                detailsDialog.exec();
            });

    docDialog.exec();
}

// “AI助手”按钮
void MainWindow::on_aiButton_clicked()
{
    Aidialog *dlg = new Aidialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动销毁，避免内存泄漏
    dlg->resize(900, 640);
    dlg->show(); // 非模态显示，不阻塞主窗口
}

// “电子病历”按钮
void MainWindow::on_emrButton_clicked()
{
    EmrDialog dialog(this);
    dialog.loadPatientRecords(m_loggedInUserId);
    dialog.exec();
}

// “支付”按钮
void MainWindow::on_paymentButton_clicked()
{
    BillsDialog dialog(this);
    dialog.loadBills(m_loggedInUserId);
    dialog.exec();
}

// “聊天消息”按钮
void MainWindow::on_chatButton_clicked()
{
    ChatDialog dialog(this);
    dialog.setup(m_loggedInUserId);
    dialog.exec();
}

// “我的预约”按钮
void MainWindow::on_myAppointmentsButton_clicked()
{
    MyAppointmentsDialog dialog(this);
    dialog.loadAppointments(m_loggedInUserId);
    dialog.exec();
}

// “在线问诊/预约挂号”按钮
void MainWindow::on_consultationButton_clicked()
{
    DoctorSelectionDialog docDialog(this);

    connect(&docDialog, &DoctorSelectionDialog::doctorSelected, this,
            [this](int doctorId, const QString &doctorName) {
                qDebug() << "预约医生 ID=" << doctorId << " 姓名=" << doctorName;

                TimeSelectionDialog timeDialog(this);
                timeDialog.setAppointmentInfo(doctorId, doctorName, m_loggedInUserId);
                timeDialog.exec();
            });

    docDialog.exec();
}

// “放松小岛”按钮
void MainWindow::on_relaxationButton_clicked()
{
    RelaxationDialog dialog(this);
    dialog.exec();
}

// “亲子打卡”按钮的槽函数 (这个可能需要你手动在UI设计器中连接)
// 如果你的UI文件里有 checkinButton, 这个函数就会被触发
void MainWindow::on_checkinButton_clicked() {
    onCheckin();
}

// “亲子打卡”功能的具体实现 (被 setupHomeGrid 和 on_checkinButton_clicked 调用)
// 记得在 mainwindow.h 中声明: void onCheckin();
void MainWindow::onCheckin()
{
    HealthCheckinDialog dialog(this);
    dialog.setUserId(m_loggedInUserId);
    dialog.exec();
}

// --- 辅助函数 (Helper Functions) ---

// 加载欢迎信息
void MainWindow::loadWelcomeMessage()
{
    QSqlQuery query;
    query.prepare("SELECT full_name FROM patients WHERE user_id = :userId");
    query.bindValue(":userId", m_loggedInUserId);

    if (query.exec() && query.next()) {
        ui->welcomeLabel->setText("欢迎您,");
        ui->patientNameLabel->setText(query.value(0).toString());
    } else {
        ui->welcomeLabel->setText("欢迎您,");
        ui->patientNameLabel->setText("家长");
    }
}

// 设置每日提示
void MainWindow::setDailyTip()
{
    QStringList tips;
    tips << "天气转凉，记得及时给宝宝增添衣物哦！"
         << "多带宝宝去户外活动，晒晒太阳有助于钙的吸收。"
         << "你知道吗？宝宝的第一次牙科检查应该在第一颗牙萌出后进行。"
         << "鼓励宝宝多喝水，而不是含糖饮料，对牙齿和身体都好。"
         << "每天给宝宝读一个绘本故事，是最好的亲子时光！"
         << "今天你和宝宝一起大笑了吗？好心情是最好的免疫力！";

    int dayOfYear = QDate::currentDate().dayOfYear();
    int tipIndex = dayOfYear % tips.size();

    ui->tipsLabel->setText(tips.at(tipIndex));
}

// 创建主页网格布局 (采用版本一的实现方式，更灵活)
void MainWindow::setupHomeGrid()
{
    // 创建一个新的网格布局
    QGridLayout* grid = new QGridLayout;
    grid->setSpacing(20);
    grid->setContentsMargins(30, 30, 30, 30);

    // 使用 Lambda 表达式简化按钮的创建过程
    auto addTile = [&](int row, int col, const QString& label, const QString& iconPath, const QObject* receiver, const char* slot) {
        QToolButton* btn = new QToolButton;
        btn->setText(label);
        btn->setIcon(QIcon(iconPath));
        btn->setIconSize(QSize(64, 64));
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btn->setFixedSize(120, 100);
        connect(btn, SIGNAL(clicked()), receiver, slot);
        grid->addWidget(btn, row, col);
    };

    // 添加所有功能按钮
    addTile(0, 0, tr("个人资料"),     ":/icons/icon_home_psndt.png",       this, SLOT(on_patientInfoButton_clicked()));
    addTile(0, 1, tr("聊天消息"),     ":/icons/icon_home_chat.png",          this, SLOT(on_chatButton_clicked()));
    addTile(0, 2, tr("医生信息"),     ":/icons/icon_home_doctor3.png",       this, SLOT(on_doctorInfoButton_clicked()));

    addTile(1, 0, tr("电子病历"),     ":/icons/icon_home_mdcrcd.png",           this, SLOT(on_emrButton_clicked()));
    addTile(1, 1, tr("放松小岛"),     ":/icons/icon_home_island.png",         this, SLOT(on_relaxationButton_clicked()));
    addTile(1, 2, tr("亲子打卡"),     ":/icons/icon_home_parternity.png",            this, SLOT(onCheckin()));

    // 注意: “我的预约” 和 “费用账单” 的名字也做了对应修改
    addTile(2, 0, tr("我的预约"),     ":/icons/icon_home_list.png",  this, SLOT(on_myAppointmentsButton_clicked()));
    addTile(2, 1, tr("费用账单"),     ":/icons/icon_home_wallet.png",       this, SLOT(on_paymentButton_clicked()));
    addTile(2, 2, tr("AI助手"),       ":/icons/icon_home_ai1.png",            this, SLOT(on_aiButton_clicked()));

    // 将创建好的网格布局设置到UI设计器中的 homeGridContainer 控件上
    // 这样做可以让你在设计器里调整 homeGridContainer 的位置和大小，非常方便
    if (ui->homeGridContainer->layout())
        delete ui->homeGridContainer->layout();  // 如果已有布局，先删除，防止内存泄漏

    ui->homeGridContainer->setLayout(grid); // 设置新布局
}
