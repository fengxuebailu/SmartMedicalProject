/********************************************************************************
** Form generated from reading UI file 'myappointmentsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYAPPOINTMENTSDIALOG_H
#define UI_MYAPPOINTMENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyAppointmentsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *appointmentsTableWidget;
    QPushButton *closeButton;

    void setupUi(QDialog *MyAppointmentsDialog)
    {
        if (MyAppointmentsDialog->objectName().isEmpty())
            MyAppointmentsDialog->setObjectName(QString::fromUtf8("MyAppointmentsDialog"));
        MyAppointmentsDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(MyAppointmentsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        appointmentsTableWidget = new QTableWidget(MyAppointmentsDialog);
        if (appointmentsTableWidget->columnCount() < 4)
            appointmentsTableWidget->setColumnCount(4);
        appointmentsTableWidget->setObjectName(QString::fromUtf8("appointmentsTableWidget"));
        appointmentsTableWidget->setColumnCount(4);

        verticalLayout->addWidget(appointmentsTableWidget);

        closeButton = new QPushButton(MyAppointmentsDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(MyAppointmentsDialog);

        QMetaObject::connectSlotsByName(MyAppointmentsDialog);
    } // setupUi

    void retranslateUi(QDialog *MyAppointmentsDialog)
    {
        MyAppointmentsDialog->setWindowTitle(QApplication::translate("MyAppointmentsDialog", "Dialog", nullptr));
        closeButton->setText(QApplication::translate("MyAppointmentsDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyAppointmentsDialog: public Ui_MyAppointmentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYAPPOINTMENTSDIALOG_H
