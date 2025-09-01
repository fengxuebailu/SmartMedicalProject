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
    // 定义消息方向的枚举
    enum MessageDirection {
        Sent,       // 已发送 (显示在右边)
        Received    // 已接收 (显示在左边)
    };

    explicit ChatMessageWidget(QWidget *parent = nullptr);
    ~ChatMessageWidget();

    // 核心函数：设置消息内容和方向
    void setMessage(const QString &content, MessageDirection direction, const QString &messageType = "text");

private:
    Ui::ChatMessageWidget *ui;
};

#endif // CHATMESSAGEMIDGET_H
