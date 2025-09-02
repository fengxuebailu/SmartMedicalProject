#include "chatmessagewidget.h"
#include "ui_chatmessagewidget.h"
#include <QPixmap>
#include <QMovie>
#include <QHBoxLayout>
#include <QDebug>

ChatMessageWidget::ChatMessageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatMessageWidget)
{
    ui->setupUi(this);
    // 设置整个 widget 背景透明, 以便 QListWidget 的样式能透出来
    this->setAttribute(Qt::WA_TranslucentBackground);
}

ChatMessageWidget::~ChatMessageWidget()
{
    delete ui;
}

void ChatMessageWidget::setMessage(const QString &content, const QString &avatarPath, MessageDirection direction, const QString &messageType)
{
    // 1. 设置头像
    QPixmap avatar(avatarPath);
    if (!avatar.isNull()) {
        ui->avatarLabel->setPixmap(avatar.scaled(ui->avatarLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // 2. 设置消息内容
    // 恢复控件的尺寸策略，允许它们自由伸缩
    ui->bubbleFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->messageContentLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    // 恢复可能被固定的尺寸
    ui->messageContentLabel->setFixedSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

    if (messageType == "text") {
        ui->messageContentLabel->setText(content);
    } else if (messageType == "emoji" || messageType == "emotion") {
        ui->messageContentLabel->setText(""); // 清空文本以显示动画
        QMovie *movie = new QMovie(content, QByteArray(), this);
        QSize iconSize = (messageType == "emoji") ? QSize(48, 48) : QSize(64, 64);
        movie->setScaledSize(iconSize);
        // Label设为固定尺寸以显示完整的动画
        ui->messageContentLabel->setFixedSize(iconSize);
        ui->messageContentLabel->setMovie(movie);
        movie->start();
    }

    // 3. 根据方向，动态调整弹簧和样式
    if (direction == Sent) {
        // 我方消息 (居右)
        ui->leftSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Preferred);
        ui->rightSpacer->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Preferred);

        // 设置绿色气泡样式
        ui->bubbleFrame->setStyleSheet(
            "QFrame#bubbleFrame {"
            "  background-color: #95EC69;"
            "  border-radius: 10px;"
            "}"
        );
        // 将头像移动到最右边
        ui->horizontalLayout->removeWidget(ui->avatarLabel);
        ui->horizontalLayout->insertWidget(3, ui->avatarLabel); // 插入到右弹簧之前

    } else { // Received
        // 对方消息 (居左)
        ui->leftSpacer->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Preferred);
        ui->rightSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Preferred);

        // 设置白色气泡样式
        ui->bubbleFrame->setStyleSheet(
            "QFrame#bubbleFrame {"
            "  background-color: white;"
            "  border: 1px solid #e0e0e0;"
            "  border-radius: 10px;"
            "}"
        );
        // 将头像移动到最左边
        ui->horizontalLayout->removeWidget(ui->avatarLabel);
        ui->horizontalLayout->insertWidget(1, ui->avatarLabel); // 插入到左弹簧之后
    }

    // 【关键】强制更新整个 widget 的尺寸以适应内容
    this->adjustSize();
    this->updateGeometry(); // 通知父控件（QListWidgetItem）我的尺寸建议变了
}

// sizeHint() 函数不再需要了，可以删除或注释掉
/*
QSize ChatMessageWidget::sizeHint() const
{
    // ...
}
*/
