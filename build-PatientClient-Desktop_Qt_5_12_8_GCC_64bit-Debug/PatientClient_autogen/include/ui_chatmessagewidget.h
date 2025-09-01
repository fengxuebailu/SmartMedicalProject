/********************************************************************************
** Form generated from reading UI file 'chatmessagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMESSAGEWIDGET_H
#define UI_CHATMESSAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMessageWidget
{
public:
    QLabel *avatarLabel;
    QLabel *messageContentLabel;

    void setupUi(QWidget *ChatMessageWidget)
    {
        if (ChatMessageWidget->objectName().isEmpty())
            ChatMessageWidget->setObjectName(QString::fromUtf8("ChatMessageWidget"));
        ChatMessageWidget->resize(350, 70);
        avatarLabel = new QLabel(ChatMessageWidget);
        avatarLabel->setObjectName(QString::fromUtf8("avatarLabel"));
        avatarLabel->setGeometry(QRect(10, 10, 40, 40));
        avatarLabel->setStyleSheet(QString::fromUtf8("background-color: #ccc; border-radius: 20px;"));
        messageContentLabel = new QLabel(ChatMessageWidget);
        messageContentLabel->setObjectName(QString::fromUtf8("messageContentLabel"));
        messageContentLabel->setGeometry(QRect(80, 10, 250, 50));
        messageContentLabel->setStyleSheet(QString::fromUtf8("background-color: white; border-radius: 10px; padding: 8px;"));
        messageContentLabel->setWordWrap(true);

        retranslateUi(ChatMessageWidget);

        QMetaObject::connectSlotsByName(ChatMessageWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatMessageWidget)
    {
        ChatMessageWidget->setWindowTitle(QApplication::translate("ChatMessageWidget", "Form", nullptr));
        avatarLabel->setText(QApplication::translate("ChatMessageWidget", "TextLabel", nullptr));
        messageContentLabel->setText(QApplication::translate("ChatMessageWidget", "\346\266\210\346\201\257\345\206\205\345\256\271\345\215\240\344\275\215\347\254\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatMessageWidget: public Ui_ChatMessageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMESSAGEWIDGET_H
