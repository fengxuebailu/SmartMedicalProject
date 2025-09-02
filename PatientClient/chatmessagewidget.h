#ifndef CHATMESSAGEMIDGET_H
#define CHATMESSAGEMIDGET_H

#include <QWidget>

namespace Ui {
class ChatMessageWidget;
}

class ChatMessageWidget : public QWidget
{
    Q_OBJECT

public:
    enum MessageDirection {
        Sent,
        Received
    };

    explicit ChatMessageWidget(QWidget *parent = nullptr);
    ~ChatMessageWidget();

    void setMessage(const QString &content, const QString &avatarPath, MessageDirection direction, const QString &messageType = "text");

private:
    Ui::ChatMessageWidget *ui;
    MessageDirection m_direction; // 添加成员变量来存储方向
};

#endif // CHATMESSAGEMIDGET_H
