/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *welcomeLabel;
    QLabel *patientNameLabel;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QToolButton *chatButton;
    QToolButton *paymentButton;
    QToolButton *patientInfoButton;
    QToolButton *doctorInfoButton;
    QToolButton *emrButton;
    QToolButton *aiButton;
    QToolButton *myAppointmentsButton;
    QToolButton *consultationButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/* ---- \344\270\273\347\252\227\345\217\243\346\240\267\345\274\217 ---- */\n"
"QMainWindow {\n"
"    background-color: #f5f7fa; /* \350\256\276\347\275\256\344\270\200\344\270\252\346\237\224\345\222\214\347\232\204\346\265\205\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"}\n"
"\n"
"/* ---- \346\254\242\350\277\216\350\257\255\346\240\207\347\255\276 ---- */\n"
"QLabel#welcomeLabel {\n"
"    font-size: 16px;\n"
"    color: #555;\n"
"    padding-left: 10px;\n"
"}\n"
"QLabel#patientNameLabel {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"/* ---- \346\240\270\345\277\203\345\212\237\350\203\275\346\214\211\351\222\256 (\351\242\204\347\272\246\346\214\202\345\217\267) ---- */\n"
"QPushButton#mainAppointmentButton {\n"
"    background-color: #3498db; /* \344\270\273\351\242\230\350\223\235\350\211\262 */\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 12px; /* \345\234\206\350\247\222 */"
                        "\n"
"    padding: 10px;\n"
"    margin: 15px;\n"
"}\n"
"QPushButton#mainAppointmentButton:hover {\n"
"    background-color: #2980b9; /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"QPushButton#mainAppointmentButton:pressed {\n"
"    background-color: #1f618d; /* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\351\242\234\350\211\262\345\206\215\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"/* ---- \346\254\241\350\246\201\345\212\237\350\203\275\347\275\221\346\240\274\346\214\211\351\222\256 (QToolButton) ---- */\n"
"QToolButton {\n"
"    background-color: white;\n"
"    color: #333;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    font-size: 13px;\n"
"}\n"
"QToolButton:hover {\n"
"    background-color: #ecf5ff; /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\267\241\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border: 1px solid #3498db;\n"
"}\n"
""
                        "QToolButton:pressed {\n"
"    background-color: #d9ecff; /* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266 */\n"
"}"));
        MainWindow->setIconSize(QSize(48, 48));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));

        horizontalLayout->addWidget(welcomeLabel);

        patientNameLabel = new QLabel(centralwidget);
        patientNameLabel->setObjectName(QString::fromUtf8("patientNameLabel"));

        horizontalLayout->addWidget(patientNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chatButton = new QToolButton(centralwidget);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icon_home_chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        chatButton->setIcon(icon);
        chatButton->setIconSize(QSize(48, 48));
        chatButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(chatButton, 1, 0, 1, 1);

        paymentButton = new QToolButton(centralwidget);
        paymentButton->setObjectName(QString::fromUtf8("paymentButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(paymentButton->sizePolicy().hasHeightForWidth());
        paymentButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icon_home_wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        paymentButton->setIcon(icon1);
        paymentButton->setIconSize(QSize(48, 48));
        paymentButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(paymentButton, 0, 1, 1, 1);

        patientInfoButton = new QToolButton(centralwidget);
        patientInfoButton->setObjectName(QString::fromUtf8("patientInfoButton"));
        sizePolicy.setHeightForWidth(patientInfoButton->sizePolicy().hasHeightForWidth());
        patientInfoButton->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icon_home_psndt.png"), QSize(), QIcon::Normal, QIcon::Off);
        patientInfoButton->setIcon(icon2);
        patientInfoButton->setIconSize(QSize(48, 48));
        patientInfoButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(patientInfoButton, 0, 0, 1, 1);

        doctorInfoButton = new QToolButton(centralwidget);
        doctorInfoButton->setObjectName(QString::fromUtf8("doctorInfoButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icon_home_doctor3.png"), QSize(), QIcon::Normal, QIcon::Off);
        doctorInfoButton->setIcon(icon3);
        doctorInfoButton->setIconSize(QSize(48, 48));
        doctorInfoButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(doctorInfoButton, 1, 1, 1, 1);

        emrButton = new QToolButton(centralwidget);
        emrButton->setObjectName(QString::fromUtf8("emrButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icon_home_mdcrcd.png"), QSize(), QIcon::Normal, QIcon::Off);
        emrButton->setIcon(icon4);
        emrButton->setIconSize(QSize(48, 48));
        emrButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(emrButton, 2, 0, 1, 1);

        aiButton = new QToolButton(centralwidget);
        aiButton->setObjectName(QString::fromUtf8("aiButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icon_home_ai1.png"), QSize(), QIcon::Normal, QIcon::Off);
        aiButton->setIcon(icon5);
        aiButton->setIconSize(QSize(60, 48));
        aiButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(aiButton, 3, 0, 1, 1);

        myAppointmentsButton = new QToolButton(centralwidget);
        myAppointmentsButton->setObjectName(QString::fromUtf8("myAppointmentsButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icon_home_list.png"), QSize(), QIcon::Normal, QIcon::Off);
        myAppointmentsButton->setIcon(icon6);
        myAppointmentsButton->setIconSize(QSize(48, 48));
        myAppointmentsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(myAppointmentsButton, 3, 1, 1, 1);

        consultationButton = new QToolButton(centralwidget);
        consultationButton->setObjectName(QString::fromUtf8("consultationButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icon_home_calender.png"), QSize(), QIcon::Normal, QIcon::Off);
        consultationButton->setIcon(icon7);
        consultationButton->setIconSize(QSize(48, 48));
        consultationButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(consultationButton, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\346\202\250", nullptr));
        patientNameLabel->setText(QApplication::translate("MainWindow", "\346\202\243\350\200\205\345\247\223\345\220\215", nullptr));
        chatButton->setText(QApplication::translate("MainWindow", "\350\201\212\345\244\251/\346\266\210\346\201\257", nullptr));
        paymentButton->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\346\224\257\344\273\230", nullptr));
        patientInfoButton->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        doctorInfoButton->setText(QApplication::translate("MainWindow", "\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        emrButton->setText(QApplication::translate("MainWindow", "\347\224\265\345\255\220\347\227\205\345\216\206", nullptr));
        aiButton->setText(QApplication::translate("MainWindow", "ai\350\257\212\346\226\255", nullptr));
        myAppointmentsButton->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\351\242\204\347\272\246", nullptr));
        consultationButton->setText(QApplication::translate("MainWindow", "\351\242\204\347\272\246\346\214\202\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
