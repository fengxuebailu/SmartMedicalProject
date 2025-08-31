/********************************************************************************
** Form generated from reading UI file 'billsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLSDIALOG_H
#define UI_BILLSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BillsDialog
{
public:
    QPushButton *closeButton;
    QWidget *widget;
    QFormLayout *formLayout;
    QTableWidget *billsTableWidget;
    QLabel *totalAmountLabel;
    QPushButton *payButton;

    void setupUi(QDialog *BillsDialog)
    {
        if (BillsDialog->objectName().isEmpty())
            BillsDialog->setObjectName(QString::fromUtf8("BillsDialog"));
        BillsDialog->resize(400, 300);
        closeButton = new QPushButton(BillsDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(300, 250, 80, 31));
        widget = new QWidget(BillsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 267, 231));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        billsTableWidget = new QTableWidget(widget);
        billsTableWidget->setObjectName(QString::fromUtf8("billsTableWidget"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, billsTableWidget);

        totalAmountLabel = new QLabel(widget);
        totalAmountLabel->setObjectName(QString::fromUtf8("totalAmountLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, totalAmountLabel);

        payButton = new QPushButton(widget);
        payButton->setObjectName(QString::fromUtf8("payButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, payButton);


        retranslateUi(BillsDialog);

        QMetaObject::connectSlotsByName(BillsDialog);
    } // setupUi

    void retranslateUi(QDialog *BillsDialog)
    {
        BillsDialog->setWindowTitle(QApplication::translate("BillsDialog", "Dialog", nullptr));
        closeButton->setText(QApplication::translate("BillsDialog", "\345\205\263\351\227\255", nullptr));
        totalAmountLabel->setText(QApplication::translate("BillsDialog", "\345\276\205\346\224\257\344\273\230\346\200\273\351\242\235\357\274\232\302\245 0.00", nullptr));
        payButton->setText(QApplication::translate("BillsDialog", "\345\220\210\345\271\266\346\224\257\344\273\230\351\200\211\344\270\255\351\241\271\347\233\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BillsDialog: public Ui_BillsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLSDIALOG_H
