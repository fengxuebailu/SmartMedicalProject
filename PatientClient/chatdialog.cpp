#include "chatdialog.h"
#include "ui_chatdialog.h"

// --- 包含所有需要的头文件 ---
#include "chatmessagewidget.h" // 必须包含自定义气泡控件的头文件
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <algorithm> // for std::min/max
#include <QGridLayout>
#include <QWidgetAction>
#include <QToolButton>
#include <QMessageBox>
#include <QJsonDocument> // for AI
#include <QJsonObject>   // for AI
#include <QJsonArray>    // for AI

// ==========================================================
// ===================== 构造与析构 =======================
// ==========================================================
ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("智能沟通");
    m_currentUserId = -1;
    m_currentContactId = -1; // -1 代表未选择, -2 代表AI

    // 初始状态下禁用所有聊天相关控件
    ui->messageTextEdit->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->emojiButton->setEnabled(false);
    ui->emotionButton->setEnabled(false);

    // --- 初始化表情菜单 ---
    m_emojiMenu = new QMenu(this);
    QWidget *emojiPanelWidget = new QWidget(this);
    QGridLayout *emojiGridLayout = new QGridLayout(emojiPanelWidget);
    emojiGridLayout->setSpacing(5);
    emojiGridLayout->setContentsMargins(5, 5, 5, 5);
    const int emojisPerRow = 6;
    const int totalEmojis = 22;
    for (int i = 1; i <= totalEmojis; ++i) {
        QString emojiAlias = QString("EMOJI_%1.png").arg(i);
        QString emojiPath = QString(":/emojis/%1").arg(emojiAlias);
        QToolButton *button = new QToolButton(emojiPanelWidget);
        button->setIcon(QIcon(emojiPath));
        button->setIconSize(QSize(32, 32));
        button->setAutoRaise(true);
        button->setCursor(Qt::PointingHandCursor);
        connect(button, &QToolButton::clicked, this, [this, emojiPath]() {
            onEmojiSelected(emojiPath);
        });
        int row = (i - 1) / emojisPerRow;
        int col = (i - 1) % emojisPerRow;
        emojiGridLayout->addWidget(button, row, col);
    }
    emojiPanelWidget->setLayout(emojiGridLayout);
    QWidgetAction *emojiAction = new QWidgetAction(this);
    emojiAction->setDefaultWidget(emojiPanelWidget);
    m_emojiMenu->addAction(emojiAction);

    // --- 初始化情绪菜单 ---
    m_emotionMenu = new QMenu(this);
    QWidget *emotionPanelWidget = new QWidget(this);
    QGridLayout *emotionGridLayout = new QGridLayout(emotionPanelWidget);
    emotionGridLayout->setSpacing(5);
    emotionGridLayout->setContentsMargins(5, 5, 5, 5);
    // 假设你的资源文件中有这些情绪表情
    QStringList emotionFiles = {"emotion_happy.png", "emotion_pain.png", "emotion_sad.png", "emotion_scared.png"};
    for(int i = 0; i < emotionFiles.count(); ++i) {
         QString emotionPath = QString(":/emojis/%1").arg(emotionFiles[i]);
         QToolButton *button = new QToolButton(emotionPanelWidget);
         button->setIcon(QIcon(emotionPath));
         button->setIconSize(QSize(32, 32));
         button->setAutoRaise(true);
         button->setCursor(Qt::PointingHandCursor);
         connect(button, &QToolButton::clicked, this, [this, emotionPath]() {
            onEmotionSelected(emotionPath);
         });
         emotionGridLayout->addWidget(button, 0, i);
    }
    emotionPanelWidget->setLayout(emotionGridLayout);
    QWidgetAction *emotionAction = new QWidgetAction(this);
    emotionAction->setDefaultWidget(emotionPanelWidget);
    m_emotionMenu->addAction(emotionAction);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

// ==========================================================
// ==================== 核心逻辑与流程控制 ==================
// ==========================================================

// 公共入口函数，由 MainWindow 调用
void ChatDialog::setup(int currentUserId)
{
    m_currentUserId = currentUserId;
    loadDoctorContacts();
}

// 加载联系人列表（包含AI和真人医生）
void ChatDialog::loadDoctorContacts()
{
    ui->contactsListWidget->clear();

    // 1. 添加一个特殊的“AI医生”联系人
    QListWidgetItem *aiItem = new QListWidgetItem("AI智能医生");
    aiItem->setIcon(QIcon(":/icons/icon_home_ai1.png"));
    aiItem->setData(Qt::UserRole, -2); // 使用特殊ID -2 来代表AI
    ui->contactsListWidget->addItem(aiItem);

    // 2. 从数据库加载真人医生联系人
    QSqlQuery query;
    query.prepare("SELECT DISTINCT u.id, d.full_name FROM users u JOIN doctors d ON u.id = d.user_id WHERE u.id IN ("
                  "SELECT sender_id FROM messages WHERE receiver_id = :userId "
                  "UNION "
                  "SELECT receiver_id FROM messages WHERE sender_id = :userId"
                  ") AND u.role = 'doctor'");
    query.bindValue(":userId", m_currentUserId);
    if (!query.exec()) {
        qDebug() << "加载联系人失败: " << query.lastError().text();
        return;
    }
    while (query.next()) {
        int contactId = query.value(0).toInt();
        QString contactName = query.value(1).toString();
        QListWidgetItem *item = new QListWidgetItem(contactName);
        item->setData(Qt::UserRole, contactId);
        ui->contactsListWidget->addItem(item);
    }
}

// 当点击左侧联系人列表时触发
void ChatDialog::on_contactsListWidget_itemClicked(QListWidgetItem *item)
{
    if (!item) return;
    int contactId = item->data(Qt::UserRole).toInt();
    QString contactName = item->text();
    switchToContact(contactId, contactName);
}

// 切换聊天对象的辅助函数
void ChatDialog::switchToContact(int contactId, const QString &contactName)
{
    m_currentContactId = contactId;
    ui->messagesListWidget->clear();
    ui->messageTextEdit->setEnabled(true);
    ui->sendButton->setEnabled(true);

    if (m_currentContactId == -2) { // 如果是和AI聊天
        setWindowTitle("与 AI智能医生 沟通中");
        ui->emojiButton->setEnabled(false);
        ui->emotionButton->setEnabled(false);
        addMessageToView("您好，我是您的AI智能医生，有什么可以帮助您？", "text", ChatMessageWidget::Received);
    } else { // 如果是和真人医生聊天
        setWindowTitle(QString("与 %1 沟通中").arg(contactName));
        ui->emojiButton->setEnabled(true);
        ui->emotionButton->setEnabled(true);
        loadMessages(m_currentContactId);
    }
}

// 点击发送按钮的总控逻辑
void ChatDialog::on_sendButton_clicked()
{
    QString message = ui->messageTextEdit->toPlainText().trimmed();
    if (message.isEmpty() || m_currentContactId == -1) return;

    // 先在界面上显示自己发送的消息
    addMessageToView(message, "text", ChatMessageWidget::Sent);
    ui->messageTextEdit->clear();

    // 根据当前聊天对象，决定下一步操作
    if (m_currentContactId == -2) {
        // 调用AI发送逻辑
        sendAiMessage(message);
    } else {
        // 调用医患聊天发送逻辑（存入数据库）
        QString conversationId = generateConversationId(m_currentUserId, m_currentContactId);
        QSqlQuery query;
        query.prepare("INSERT INTO messages (conversation_id, sender_id, receiver_id, message_type, content) "
                      "VALUES (:convId, :senderId, :receiverId, 'text', :content)");
        query.bindValue(":convId", conversationId);
        query.bindValue(":senderId", m_currentUserId);
        query.bindValue(":receiverId", m_currentContactId);
        query.bindValue(":content", message);
        if (!query.exec()) {
            qDebug() << "发送消息失败: " << query.lastError().text();
        }
    }
}

// ==========================================================
// ================== AI 聊天功能实现 =======================
// ==========================================================

void ChatDialog::sendAiMessage(const QString &text)
{
    ui->sendButton->setEnabled(false); // 发送期间禁用按钮

    const QString apiKey = qgetenv("BIGMODEL_API_KEY");
    if (apiKey.isEmpty()) {
        QMessageBox::warning(this, "API Key未设置", "请先设置 BIGMODEL_API_KEY 环境变量。");
        ui->sendButton->setEnabled(true);
        return;
    }

    QNetworkRequest request(QUrl("https://open.bigmodel.cn/api/paas/v4/chat/completions"));
    request.setRawHeader("Authorization", "Bearer " + apiKey.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray body = buildAiBody(text);
    QNetworkReply *reply = m_networkManager.post(request, body);
    connect(reply, &QNetworkReply::finished, this, &ChatDialog::handleAiReply);
}

QByteArray ChatDialog::buildAiBody(const QString &userText)
{
    QJsonArray messages;
    messages.append(QJsonObject{{"role", "user"}, {"content", userText}});
    QJsonObject body{{"model", "glm-3-turbo"}, {"messages", messages}};
    return QJsonDocument(body).toJson();
}

void ChatDialog::handleAiReply()
{
    ui->sendButton->setEnabled(true); // 恢复发送按钮
    auto *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject obj = doc.object();
        QString aiResponse = obj["choices"].toArray()[0].toObject()["message"].toObject()["content"].toString();
        addMessageToView(aiResponse, "text", ChatMessageWidget::Received);
    } else {
        QString errorString = "AI回复错误: " + reply->errorString();
        qDebug() << errorString;
        addMessageToView(errorString, "text", ChatMessageWidget::Received);
    }
    reply->deleteLater();
}

// ==========================================================
// ============== 医患聊天功能实现 =========================
// ==========================================================

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

void ChatDialog::on_emojiButton_clicked()
{
    m_emojiMenu->popup(ui->emojiButton->mapToGlobal(QPoint(0, ui->emojiButton->height())));
}

void ChatDialog::on_emotionButton_clicked()
{
    m_emotionMenu->popup(ui->emotionButton->mapToGlobal(QPoint(0, ui->emotionButton->height())));
}

void ChatDialog::onEmojiSelected(const QString &emojiPath)
{
    m_emojiMenu->close();
    if (m_currentContactId <= 0) return; // 小于等于0的ID都不是真人医生

    QString conversationId = generateConversationId(m_currentUserId, m_currentContactId);
    QSqlQuery query;
    query.prepare("INSERT INTO messages (conversation_id, sender_id, receiver_id, message_type, content) "
                  "VALUES (:convId, :senderId, :receiverId, 'emoji', :content)");
    query.bindValue(":convId", conversationId);
    query.bindValue(":senderId", m_currentUserId);
    query.bindValue(":receiverId", m_currentContactId);
    query.bindValue(":content", emojiPath);
    if (query.exec()) {
        addMessageToView(emojiPath, "emoji", ChatMessageWidget::Sent);
    } else {
        qDebug() << "发送表情失败: " << query.lastError().text();
    }
}

void ChatDialog::onEmotionSelected(const QString &emotionPath)
{
    m_emotionMenu->close();
    if (m_currentContactId <= 0) return;

    QString conversationId = generateConversationId(m_currentUserId, m_currentContactId);
    QSqlQuery query;
    query.prepare("INSERT INTO messages (conversation_id, sender_id, receiver_id, message_type, content) "
                  "VALUES (:convId, :senderId, :receiverId, 'emotion', :content)");
    query.bindValue(":convId", conversationId);
    query.bindValue(":senderId", m_currentUserId);
    query.bindValue(":receiverId", m_currentContactId);
    query.bindValue(":content", emotionPath);
    if (query.exec()) {
        addMessageToView(emotionPath, "emotion", ChatMessageWidget::Sent);
    } else {
        qDebug() << "发送情绪表情失败: " << query.lastError().text();
    }
}

// ==========================================================
// ================== 通用辅助函数 ========================
// ==========================================================

void ChatDialog::addMessageToView(const QString &content, const QString &messageType, ChatMessageWidget::MessageDirection direction)
{
    QListWidgetItem *item = new QListWidgetItem(ui->messagesListWidget);
    ChatMessageWidget *widget = new ChatMessageWidget(this);
    widget->setMessage(content, direction, messageType);
    item->setSizeHint(widget->sizeHint());
    ui->messagesListWidget->setItemWidget(item, widget);
    ui->messagesListWidget->scrollToBottom();
}

QString ChatDialog::generateConversationId(int userId1, int userId2)
{
    if (userId1 < userId2) {
        return QString("%1_%2").arg(userId1).arg(userId2);
    } else {
        return QString("%1_%2").arg(userId2).arg(userId1);
    }
}
