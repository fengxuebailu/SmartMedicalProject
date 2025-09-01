#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include "chatmessagewidget.h" // 包含气泡控件的头文件
#include <QMenu> // 包含头文件s

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

    // 公共入口函数
    void setup(int currentUserId);

private slots:
    void on_contactsListWidget_itemClicked(QListWidgetItem *item);
    void on_sendButton_clicked();
    void on_emojiButton_clicked();
    void onEmojiSelected(const QString &emojiPath);

private:
    // 辅助函数
    void loadContacts();
    void loadMessages(int contactId);
    void addMessageToView(const QString &content, const QString &messageType, ChatMessageWidget::MessageDirection direction);
    QString generateConversationId(int userId1, int userId2);
    QMenu *m_emojiMenu;

    Ui::ChatDialog *ui;
    int m_currentUserId;
    int m_currentContactId;
};

#endif // CHATDIALOG_H
