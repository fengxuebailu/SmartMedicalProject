#include "mainwindow.h"
#include <QApplication>

// --- 包含数据库和消息框所需的头文件 ---
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

/**
 * @brief 初始化应用程序的数据库连接
 *
 * 这是一个更健壮的版本，它会先检查默认连接是否已存在，
 * 避免重复添加连接导致的警告。
 *
 * @return true 如果连接成功或已存在并可用，否则返回 false。
 */
bool initDatabase()
{
    QSqlDatabase db;

    // 检查名为 "qt_sql_default_connection" 的默认连接是否已经存在
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        // 如果存在，就获取该连接的实例
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        // 如果不存在，则添加一个新的数据库连接作为默认连接
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");         // 数据库服务器地址 (本地主机)
        db.setDatabaseName("smart_clinic");    // 数据库名称
        db.setUserName("qtuser");              // 数据库用户名
        db.setPassword("A_Secure_Password_For_Qt!123"); // 数据库密码
    }

    // 尝试打开数据库连接
    if (!db.open()) {
        // 如果连接失败，弹出一个严重错误对话框，并打印错误日志
        QMessageBox::critical(nullptr, QObject::tr("数据库连接失败"),
                              db.lastError().text(), QMessageBox::Cancel);
        qDebug() << "数据库连接失败:" << db.lastError().text();
        return false; // 返回 false 表示初始化失败
    }

    // 如果一切顺利，打印成功日志
    qDebug() << "数据库连接成功!";
    return true; // 返回 true 表示初始化成功
}

/**
 * @brief 应用程序主入口函数
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 在创建任何窗口之前，首先尝试初始化数据库连接
    if (!initDatabase()) {
        // 如果数据库初始化失败，程序无法正常运行，直接退出
        qDebug() << "因数据库初始化失败，应用程序即将退出。";
        return -1; // 返回一个非零值表示程序异常退出
    }

    // 数据库连接成功后，创建并显示主窗口
    MainWindow w;
    w.show();

    // 进入Qt应用程序的事件循环
    return a.exec();
}
