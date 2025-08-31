/********************************************************************************
** Form generated from reading UI file 'emrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMRDIALOG_H
#define UI_EMRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EmrDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *visitsListWidget;
    QFormLayout *formLayout;
    QLineEdit *dateLineEdit;
    QLabel *label_2;
    QLineEdit *doctorLineEdit;
    QLabel *label_3;
    QLineEdit *departmentLineEdit;
    QLabel *label_4;
    QLineEdit *complaintTextEdit;
    QLabel *label_5;
    QLineEdit *diagnosisTextEdit;
    QLabel *label_6;
    QLineEdit *planTextEdit;
    QLabel *label_7;
    QLineEdit *notesTextEdit;
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QDialog *EmrDialog)
    {
        if (EmrDialog->objectName().isEmpty())
            EmrDialog->setObjectName(QString::fromUtf8("EmrDialog"));
        EmrDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EmrDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        visitsListWidget = new QListWidget(EmrDialog);
        visitsListWidget->setObjectName(QString::fromUtf8("visitsListWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(visitsListWidget->sizePolicy().hasHeightForWidth());
        visitsListWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(visitsListWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        dateLineEdit = new QLineEdit(EmrDialog);
        dateLineEdit->setObjectName(QString::fromUtf8("dateLineEdit"));
        dateLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLineEdit);

        label_2 = new QLabel(EmrDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        doctorLineEdit = new QLineEdit(EmrDialog);
        doctorLineEdit->setObjectName(QString::fromUtf8("doctorLineEdit"));
        doctorLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, doctorLineEdit);

        label_3 = new QLabel(EmrDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        departmentLineEdit = new QLineEdit(EmrDialog);
        departmentLineEdit->setObjectName(QString::fromUtf8("departmentLineEdit"));
        departmentLineEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, departmentLineEdit);

        label_4 = new QLabel(EmrDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        complaintTextEdit = new QLineEdit(EmrDialog);
        complaintTextEdit->setObjectName(QString::fromUtf8("complaintTextEdit"));
        complaintTextEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, complaintTextEdit);

        label_5 = new QLabel(EmrDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        diagnosisTextEdit = new QLineEdit(EmrDialog);
        diagnosisTextEdit->setObjectName(QString::fromUtf8("diagnosisTextEdit"));
        diagnosisTextEdit->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, diagnosisTextEdit);

        label_6 = new QLabel(EmrDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        planTextEdit = new QLineEdit(EmrDialog);
        planTextEdit->setObjectName(QString::fromUtf8("planTextEdit"));
        planTextEdit->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, planTextEdit);

        label_7 = new QLabel(EmrDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        notesTextEdit = new QLineEdit(EmrDialog);
        notesTextEdit->setObjectName(QString::fromUtf8("notesTextEdit"));
        notesTextEdit->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, notesTextEdit);

        label = new QLabel(EmrDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        closeButton = new QPushButton(EmrDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EmrDialog);

        QMetaObject::connectSlotsByName(EmrDialog);
    } // setupUi

    void retranslateUi(QDialog *EmrDialog)
    {
        EmrDialog->setWindowTitle(QApplication::translate("EmrDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("EmrDialog", "\345\260\261\350\257\212\345\214\273\347\224\237", nullptr));
        label_3->setText(QApplication::translate("EmrDialog", "\346\211\200\345\261\236\347\247\221\345\256\244", nullptr));
        label_4->setText(QApplication::translate("EmrDialog", "\346\202\243\350\200\205\344\270\273\350\257\211", nullptr));
        label_5->setText(QApplication::translate("EmrDialog", "\350\257\212\346\226\255\347\273\223\346\236\234", nullptr));
        label_6->setText(QApplication::translate("EmrDialog", "\346\262\273\347\226\227\346\226\271\346\241\210", nullptr));
        label_7->setText(QApplication::translate("EmrDialog", "\345\214\273\347\224\237\345\230\261\345\222\220", nullptr));
        label->setText(QApplication::translate("EmrDialog", "\345\260\261\350\257\212\346\227\245\346\234\237", nullptr));
        closeButton->setText(QApplication::translate("EmrDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmrDialog: public Ui_EmrDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMRDIALOG_H
