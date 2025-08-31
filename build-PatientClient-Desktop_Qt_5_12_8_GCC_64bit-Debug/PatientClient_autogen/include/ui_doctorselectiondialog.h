/********************************************************************************
** Form generated from reading UI file 'doctorselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORSELECTIONDIALOG_H
#define UI_DOCTORSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoctorSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *departmentsListWidget;
    QTableWidget *doctorsTableWidget;
    QPushButton *nextButton;

    void setupUi(QDialog *DoctorSelectionDialog)
    {
        if (DoctorSelectionDialog->objectName().isEmpty())
            DoctorSelectionDialog->setObjectName(QString::fromUtf8("DoctorSelectionDialog"));
        DoctorSelectionDialog->resize(538, 430);
        verticalLayout = new QVBoxLayout(DoctorSelectionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        departmentsListWidget = new QListWidget(DoctorSelectionDialog);
        departmentsListWidget->setObjectName(QString::fromUtf8("departmentsListWidget"));
        departmentsListWidget->setMaximumSize(QSize(16777213, 16777215));

        horizontalLayout->addWidget(departmentsListWidget);

        doctorsTableWidget = new QTableWidget(DoctorSelectionDialog);
        doctorsTableWidget->setObjectName(QString::fromUtf8("doctorsTableWidget"));

        horizontalLayout->addWidget(doctorsTableWidget);


        verticalLayout->addLayout(horizontalLayout);

        nextButton = new QPushButton(DoctorSelectionDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);


        retranslateUi(DoctorSelectionDialog);

        QMetaObject::connectSlotsByName(DoctorSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorSelectionDialog)
    {
        DoctorSelectionDialog->setWindowTitle(QApplication::translate("DoctorSelectionDialog", "Dialog", nullptr));
        nextButton->setText(QApplication::translate("DoctorSelectionDialog", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorSelectionDialog: public Ui_DoctorSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORSELECTIONDIALOG_H
