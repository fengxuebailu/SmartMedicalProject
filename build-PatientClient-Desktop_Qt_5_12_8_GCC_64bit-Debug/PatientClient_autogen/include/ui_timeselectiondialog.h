/********************************************************************************
** Form generated from reading UI file 'timeselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESELECTIONDIALOG_H
#define UI_TIMESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimeSelectionDialog
{
public:
    QFormLayout *formLayout;
    QLabel *doctorInfoLabel;
    QHBoxLayout *horizontalLayout;
    QCalendarWidget *calendarWidget;
    QListWidget *timeSlotsListWidget;
    QPushButton *confirmButton;

    void setupUi(QDialog *TimeSelectionDialog)
    {
        if (TimeSelectionDialog->objectName().isEmpty())
            TimeSelectionDialog->setObjectName(QString::fromUtf8("TimeSelectionDialog"));
        TimeSelectionDialog->resize(512, 444);
        formLayout = new QFormLayout(TimeSelectionDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        doctorInfoLabel = new QLabel(TimeSelectionDialog);
        doctorInfoLabel->setObjectName(QString::fromUtf8("doctorInfoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, doctorInfoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        calendarWidget = new QCalendarWidget(TimeSelectionDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        horizontalLayout->addWidget(calendarWidget);

        timeSlotsListWidget = new QListWidget(TimeSelectionDialog);
        timeSlotsListWidget->setObjectName(QString::fromUtf8("timeSlotsListWidget"));

        horizontalLayout->addWidget(timeSlotsListWidget);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);

        confirmButton = new QPushButton(TimeSelectionDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, confirmButton);


        retranslateUi(TimeSelectionDialog);

        QMetaObject::connectSlotsByName(TimeSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeSelectionDialog)
    {
        TimeSelectionDialog->setWindowTitle(QApplication::translate("TimeSelectionDialog", "Dialog", nullptr));
        doctorInfoLabel->setText(QApplication::translate("TimeSelectionDialog", "TextLabel", nullptr));
        confirmButton->setText(QApplication::translate("TimeSelectionDialog", "\347\241\256\350\256\244\351\242\204\347\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeSelectionDialog: public Ui_TimeSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESELECTIONDIALOG_H
