/********************************************************************************
** Form generated from reading UI file 'paymentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTDIALOG_H
#define UI_PAYMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaymentDialog
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *amountLabel;
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QPushButton *confirmPaymentButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *PaymentDialog)
    {
        if (PaymentDialog->objectName().isEmpty())
            PaymentDialog->setObjectName(QString::fromUtf8("PaymentDialog"));
        PaymentDialog->resize(400, 300);
        widget = new QWidget(PaymentDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 60, 270, 136));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        amountLabel = new QLabel(widget);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, amountLabel);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        confirmPaymentButton = new QPushButton(widget);
        confirmPaymentButton->setObjectName(QString::fromUtf8("confirmPaymentButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, confirmPaymentButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cancelButton);


        retranslateUi(PaymentDialog);

        QMetaObject::connectSlotsByName(PaymentDialog);
    } // setupUi

    void retranslateUi(QDialog *PaymentDialog)
    {
        PaymentDialog->setWindowTitle(QApplication::translate("PaymentDialog", "Dialog", nullptr));
        amountLabel->setText(QApplication::translate("PaymentDialog", "\346\224\257\344\273\230\351\207\221\351\242\235\357\274\232\302\245 0.00", nullptr));
        label->setText(QApplication::translate("PaymentDialog", "\350\257\267\350\276\223\345\205\245\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", nullptr));
        confirmPaymentButton->setText(QApplication::translate("PaymentDialog", "\347\241\256\350\256\244\346\224\257\344\273\230", nullptr));
        cancelButton->setText(QApplication::translate("PaymentDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaymentDialog: public Ui_PaymentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTDIALOG_H
