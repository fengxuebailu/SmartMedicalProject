#include "chatdialog.h"
#include "ui_chatdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <algorithm> // for std::min/max
#include <QGridLayout>
#include <QWidgetAction>
#include <QToolButton>

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("医患沟通");
    m_currentUserId = -1;
    m_currentContactId = -1;

    // 初始状态下禁用输入和发送
    ui->messageTextEdit->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->emojiButton->setEnabled(false);

    // --- 初始化表情菜单 ---
        m_emojiMenu = new QMenu(this);
        QWidget *emojiWidget = new QWidget(this); // 创建一个容器 widget
        QGridLayout *gridLayout = new QGridLayout(emojiWidget); // 使用网格布局
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);

        // 遍历资源文件，动态加载所有表情
        // 我们假设表情的别名是 EMOJI_1.png, EMOJI_2.png, ...
        for (int i = 1; i <= 22; ++i) { // 假设你有22个表情
            QString emojiAlias = QString("EMOJI_%1.png").arg(i);
            QString emojiPath = QString(":/emojis/%1").arg(emojiAlias);

            QToolButton *button = new QToolButton(emojiWidget);
            button->setIcon(QIcon(emojiPath));
            button->setIconSize(QSize(32, 32));
            button->setAutoRaise(true);
            button->setCursor(Qt::PointingHandCursor);

            // 使用 Lambda 表达式来连接点击信号，并传递表情路径
            connect(button, &QToolButton::clicked, this, [this, emojiPath]() {
                onEmojiSelected(emojiPath);
            });

            // 将按钮添加到网格布局中 (假设每行放6个)
            gridLayout->addWidget(button, (i - 1) / 6, (i - 1) % 6);
        }

        emojiWidget->setLayout(gridLayout);
        QWidgetAction *action = new QWidgetAction(this);
        action->setDefaultWidget(emojiWidget);
        m_emojiMenu->addAction(action);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::setup(int currentUserId)
{
    m_currentUserId = currentUserId;
    loadContacts();
}

void ChatDialog::loadContacts()
{
    ui->contactsListWidget->clear();
    QSqlQuery query;

    // --- 添加调试信息 ---
    qDebug() << "--- 开始加载联系人 ---";
    qDebug() << "当前登录的用户ID (m_currentUserId):" << m_currentUserId;

    // 准备 SQL 语句
    QString sql = "SELECT DISTINCT u.id, d.full_name FROM users u JOIN doctors d ON u.id = d.user_id WHERE u.id IN ("
                  "SELECT sender_id FROM messages WHERE receiver_id = :userId "
                  "UNION "
                  "SELECT receiver_id FROM messages WHERE sender_id = :userId"
                  ") AND u.role = 'doctor'";

    qDebug() << "将要执行的 SQL 语句:" << sql;

    query.prepare(sql);
    query.bindValue(":userId", m_currentUserId);

    if (!query.exec()) {
        qDebug() << "!!! 加载联系人失败: " << query.lastError().text();
        return;
    }

    // --- 检查查询结果 ---
    int count = 0;
    while (query.next()) {
        count++;
        int contactId = query.value(0).toInt();
        QString contactName = query.value(1).toString();
        qDebug() << "找到联系人:" << contactName << " (ID:" << contactId << ")";

        QListWidgetItem *item = new QListWidgetItem(contactName);
        item->setData(Qt::UserRole, contactId);

        // 设置图标 (可选，但能让界面更好看)
        item->setIcon(QIcon(":/icons/icon_home_doctor1.png")); // 假设你有一个医生图标

        ui->contactsListWidget->addItem(item);
    }

    if (count == 0) {
        qDebug() << "查询成功，但没有找到任何与该用户聊过天的医生。";
        ui->contactsListWidget->addItem("暂无联系人");
        ui->contactsListWidget->setEnabled(false);
    } else {
         qDebug() << "--- 成功加载了" << count << "个联系人 ---";
    }
}
void ChatDialog::on_contactsListWidget_itemClicked(QListWidgetItem *item)
{
    if (!item) return;
    m_currentContactId = item->data(Qt::UserRole).toInt();
    ui->messageTextEdit->setEnabled(true);
    ui->sendButton->setEnabled(true);
    ui->emojiButton->setEnabled(true);
    loadMessages(m_currentContactId);
}

void ChatDialog::loadMessages(int contactId)
{
    ui->messagesListWidget->clear();
    QString conversationId = generateConversationId(m_currentUserId, contactId);

    QSqlQuery query;
    query.prepare("SELECT sender_id, message_type, content FROM messages "
                  "WHERE conversation_id = :convId ORDER BY sent_at ASC");
    query.bindValue(":convId", conversationId);

    if (!query.exec()) {
        qDebug() << "加载消息记录失败: " << query.lastError().text();
        return;
    }
    while (query.next()) {
        int senderId = query.value("sender_id").toInt();
        ChatMessageWidget::MessageDirection direction = (senderId == m_currentUserId) ? ChatMessageWidget::Sent : ChatMessageWidget::Received;
         addMessageToView(query.value("content").toString(), query.value("message_type").toString(), direction);
    }
}

void ChatDialog::on_sendButton_clicked()
{
    QString message = ui->messageTextEdit->toPlainText().trimmed();
    if (message.isEmpty() || m_currentContactId == -1) return;

    QString conversationId = generateConversationId(m_currentUserId, m_currentContactId);

    QSqlQuery query;
    query.prepare("INSERT INTO messages (conversation_id, sender_id, receiver_id, message_type, content) "
                  "VALUES (:convId, :senderId, :receiverId, 'text', :content)");
    query.bindValue(":convId", conversationId);
    query.bindValue(":senderId", m_currentUserId);
    query.bindValue(":receiverId", m_currentContactId);
    query.bindValue(":content", message);

    if (query.exec()) {
        addMessageToView(message, "text", ChatMessageWidget::Sent);
        ui->messageTextEdit->clear();
    } else {
        qDebug() << "发送消息失败: " << query.lastError().text();
    }
}

void ChatDialog::on_emojiButton_clicked()
{
    // 在 emojiButton 按钮的左下角，弹出我们的表情菜单
    // mapToGlobal 将按钮的局部坐标转换为屏幕的全局坐标
    m_emojiMenu->popup(ui->emojiButton->mapToGlobal(QPoint(0, ui->emojiButton->height())));
}

// 核心辅助函数：在界面上添加一个聊天气泡
void ChatDialog::addMessageToView(const QString &content, const QString &messageType, ChatMessageWidget::MessageDirection direction)
{
    // 创建一个空的 QListWidgetItem，并将其添加到 ListWidget 中
    QListWidgetItem *item = new QListWidgetItem(ui->messagesListWidget);

    // 创建我们的自定义气泡 widget
    ChatMessageWidget *widget = new ChatMessageWidget(this);
    widget->setMessage(content, direction, messageType);
    // 【关键修复 2】: 确保 item 的尺寸 hint 和 widget 匹配
    // 尤其是对于表情，widget 的尺寸是固定的，item 必须知道
    item->setSizeHint(widget->sizeHint());

    // 将自定义 widget 设置到 item 上
    ui->messagesListWidget->setItemWidget(item, widget);

    // 自动滚动到底部
    ui->messagesListWidget->scrollToBottom();
}
// 核心辅助函数：生成统一的会话ID
QString ChatDialog::generateConversationId(int userId1, int userId2)
{
    // 确保小的ID总是在前面，这样无论谁是发送方，会话ID都一样
    if (userId1 < userId2) {
        return QString("%1_%2").arg(userId1).arg(userId2);
    } else {
        return QString("%1_%2").arg(userId2).arg(userId1);
    }
}

// 这个函数是新添加的
void ChatDialog::onEmojiSelected(const QString &emojiPath)
{
    // 1. 首先，关闭弹出的表情菜单
    m_emojiMenu->close();

    // 2. 检查是否已选中一个联系人，如果没有则不发送
    if (m_currentContactId == -1) {
        return;
    }

    // 3. 生成会话ID
    QString conversationId = generateConversationId(m_currentUserId, m_currentContactId);

    // 4. 准备 SQL 语句，将表情消息写入数据库
    QSqlQuery query;
    query.prepare("INSERT INTO messages (conversation_id, sender_id, receiver_id, message_type, content) "
                  "VALUES (:convId, :senderId, :receiverId, 'emoji', :content)");
    query.bindValue(":convId", conversationId);
    query.bindValue(":senderId", m_currentUserId);
    query.bindValue(":receiverId", m_currentContactId);
    query.bindValue(":content", emojiPath); // 将被点击的表情的路径存入数据库

    // 5. 执行查询，并在界面上显示新发送的表情
    if (query.exec()) {
        addMessageToView(emojiPath, "emoji", ChatMessageWidget::Sent);
    } else {
        qDebug() << "发送表情失败: " << query.lastError().text();
    }
}
