#include "mainwindow.h"
#include <QApplication>

// --- 添加以下头文件 ---
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
// --------------------

// --- 创建一个用于初始化数据库连接的函数 ---
bool initDatabase()
{
    // 添加一个数据库连接。由于我们没有指定第二个参数（连接名），
    // 它将成为整个应用程序的“默认连接”。
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");         // 主机地址
    db.setDatabaseName("smart_clinic");    // 数据库名
    db.setUserName("root");                 // 数据库用户名
    db.setPassword("@Aa1146978345"); // !!! 替换成你设置的那个强密码 !!!

    if (!db.open()) {
        // 如果连接失败，通过 QMessageBox 显示一个致命错误对话框
        QMessageBox::critical(nullptr, QObject::tr("数据库连接失败"),
                              db.lastError().text(), QMessageBox::Cancel);
        qDebug() << "数据库连接失败:" << db.lastError().text();
        return false; // 返回 false 表示初始化失败
    }

    qDebug() << "数据库连接成功!";
    return true; // 返回 true 表示初始化成功
}
// ----------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- 在创建主窗口之前，调用数据库初始化函数 ---
    if (!initDatabase()) {
        // 如果数据库初始化失败，则不显示主窗口，直接退出程序
        return -1;
    }
    // ------------------------------------------

    MainWindow w;
    w.show();

    return a.exec();
}
