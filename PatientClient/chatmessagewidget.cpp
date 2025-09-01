#include "chatmessagewidget.h"
#include "ui_chatmessagewidget.h"
#include <QDebug>
#include <QMovie>
#include <QHBoxLayout>

ChatMessageWidget::ChatMessageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatMessageWidget)
{
    ui->setupUi(this);
}

ChatMessageWidget::~ChatMessageWidget()
{
    delete ui;
}

void ChatMessageWidget::setMessage(const QString &content, MessageDirection direction, const QString &messageType)
{
    if (messageType == "text") {
           ui->messageContentLabel->setText(content);
       } else if (messageType == "emoji") {
           // 清除可能存在的文本，防止重叠
           ui->messageContentLabel->setText("");

           QMovie *movie = new QMovie(content, QByteArray(), this); // 将 this 作为 parent
           QSize emojiSize(48, 48); // 定义一个表情尺寸
           movie->setScaledSize(emojiSize);

           // 【关键修复 1】: 给 Label 设置固定大小以显示表情
           ui->messageContentLabel->setFixedSize(emojiSize);

           ui->messageContentLabel->setMovie(movie);
           movie->start();
       }
    // --- 动态布局和样式设置 ---
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 5, 10, 5); // 设置边距

    if (direction == Sent) {
        // 已发送的消息：气泡在左，头像在右
        // 样式：绿色气泡
        ui->messageContentLabel->setStyleSheet(
            "background-color: #95EC69;"
            "border-radius: 10px;"
            "padding: 8px;"
        );
        // 布局：添加一个弹簧把内容挤到右边
        layout->addStretch();
        layout->addWidget(ui->messageContentLabel);
        layout->addWidget(ui->avatarLabel);

    } else { // Received
        // 已接收的消息：头像在左，气泡在右
        // 样式：白色气泡
        ui->messageContentLabel->setStyleSheet(
            "background-color: white;"
            "border-radius: 10px;"
            "padding: 8px;"
        );
        // 布局：
        layout->addWidget(ui->avatarLabel);
        layout->addWidget(ui->messageContentLabel);
        layout->addStretch();
    }

    setLayout(layout);
}
