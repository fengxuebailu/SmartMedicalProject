#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMenu>
#include <QNetworkAccessManager> // <-- 为AI功能添加
#include <QNetworkReply>       // <-- 为AI功能添加
#include "chatmessagewidget.h"

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

    void setup(int currentUserId);

private slots:
    // --- 通用槽函数 ---
    void on_contactsListWidget_itemClicked(QListWidgetItem *item);
    void on_sendButton_clicked();

    // --- 医患聊天功能槽函数 ---
    void on_emojiButton_clicked();
    void on_emotionButton_clicked();
    void onEmojiSelected(const QString &emojiPath);
    void onEmotionSelected(const QString &emotionPath);

    // --- AI聊天功能槽函数 ---
    void handleAiReply(); // 用于处理AI返回结果

private:
    // --- 医患聊天功能函数 ---
    void loadDoctorContacts();
    void loadMessages(int contactId);
    QString generateConversationId(int userId1, int userId2);

    // --- AI聊天功能函数 ---
    QByteArray buildAiBody(const QString &userText);
    void sendAiMessage(const QString &text);

    // --- 通用辅助函数 ---
    void addMessageToView(const QString &content, const QString &messageType, ChatMessageWidget::MessageDirection direction);
    void switchToContact(int contactId, const QString &contactName);


    Ui::ChatDialog *ui;

    // --- 通用状态变量 ---
    int m_currentUserId;
    int m_currentContactId; // 如果是AI，可以设为-1或其他特殊值

    // --- 医患聊天成员 ---
    QMenu *m_emojiMenu;
    QMenu *m_emotionMenu;

    // --- AI聊天成员 ---
    QNetworkAccessManager m_networkManager; // 网络管理器
};

#endif // CHATDIALOG_H
