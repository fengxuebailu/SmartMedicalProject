/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QListWidget *contactsListWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *messagesListWidget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *emojiButton;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *messageTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QString::fromUtf8("ChatDialog"));
        ChatDialog->resize(555, 479);
        horizontalLayout_4 = new QHBoxLayout(ChatDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contactsListWidget = new QListWidget(ChatDialog);
        contactsListWidget->setObjectName(QString::fromUtf8("contactsListWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contactsListWidget->sizePolicy().hasHeightForWidth());
        contactsListWidget->setSizePolicy(sizePolicy);
        contactsListWidget->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(contactsListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        messagesListWidget = new QListWidget(ChatDialog);
        messagesListWidget->setObjectName(QString::fromUtf8("messagesListWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(messagesListWidget->sizePolicy().hasHeightForWidth());
        messagesListWidget->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(messagesListWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        emojiButton = new QToolButton(ChatDialog);
        emojiButton->setObjectName(QString::fromUtf8("emojiButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/emojis/EMOJI_8.png"), QSize(), QIcon::Normal, QIcon::Off);
        emojiButton->setIcon(icon);

        horizontalLayout_2->addWidget(emojiButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        messageTextEdit = new QTextEdit(ChatDialog);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        sizePolicy1.setHeightForWidth(messageTextEdit->sizePolicy().hasHeightForWidth());
        messageTextEdit->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(messageTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sendButton = new QPushButton(ChatDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_3->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 12);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(3, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_4->addLayout(horizontalLayout);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Dialog", nullptr));
        emojiButton->setText(QApplication::translate("ChatDialog", "...", nullptr));
        sendButton->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
