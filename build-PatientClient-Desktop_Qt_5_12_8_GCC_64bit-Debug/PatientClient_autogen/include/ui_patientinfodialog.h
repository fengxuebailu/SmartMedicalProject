/********************************************************************************
** Form generated from reading UI file 'patientinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTINFODIALOG_H
#define UI_PATIENTINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *photoLabel;
    QGridLayout *gridLayout;
    QLineEdit *ageLineEdit;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *dobLineEdit;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *idCardLineEdit;
    QLabel *label_5;
    QLineEdit *phoneLineEdit;
    QLabel *label_6;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *editSaveButton;
    QPushButton *closeButton;

    void setupUi(QDialog *PatientInfoDialog)
    {
        if (PatientInfoDialog->objectName().isEmpty())
            PatientInfoDialog->setObjectName(QString::fromUtf8("PatientInfoDialog"));
        PatientInfoDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PatientInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        photoLabel = new QLabel(PatientInfoDialog);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(120, 150));
        photoLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));
        photoLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, photoLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ageLineEdit = new QLineEdit(PatientInfoDialog);
        ageLineEdit->setObjectName(QString::fromUtf8("ageLineEdit"));
        ageLineEdit->setReadOnly(true);

        gridLayout->addWidget(ageLineEdit, 2, 1, 1, 1);

        nameLineEdit = new QLineEdit(PatientInfoDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setReadOnly(true);

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(PatientInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(PatientInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        dobLineEdit = new QLineEdit(PatientInfoDialog);
        dobLineEdit->setObjectName(QString::fromUtf8("dobLineEdit"));
        dobLineEdit->setReadOnly(true);

        gridLayout->addWidget(dobLineEdit, 3, 1, 1, 1);

        label = new QLabel(PatientInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout);

        label_4 = new QLabel(PatientInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        idCardLineEdit = new QLineEdit(PatientInfoDialog);
        idCardLineEdit->setObjectName(QString::fromUtf8("idCardLineEdit"));
        idCardLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, idCardLineEdit);

        label_5 = new QLabel(PatientInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        phoneLineEdit = new QLineEdit(PatientInfoDialog);
        phoneLineEdit->setObjectName(QString::fromUtf8("phoneLineEdit"));
        phoneLineEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneLineEdit);

        label_6 = new QLabel(PatientInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        emailLineEdit = new QLineEdit(PatientInfoDialog);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, emailLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editSaveButton = new QPushButton(PatientInfoDialog);
        editSaveButton->setObjectName(QString::fromUtf8("editSaveButton"));

        horizontalLayout->addWidget(editSaveButton);

        closeButton = new QPushButton(PatientInfoDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PatientInfoDialog);

        QMetaObject::connectSlotsByName(PatientInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientInfoDialog)
    {
        PatientInfoDialog->setWindowTitle(QApplication::translate("PatientInfoDialog", "Dialog", nullptr));
        photoLabel->setText(QApplication::translate("PatientInfoDialog", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        label_2->setText(QApplication::translate("PatientInfoDialog", "\345\271\264\351\276\204", nullptr));
        label_3->setText(QApplication::translate("PatientInfoDialog", "\345\207\272\347\224\237\345\271\264\346\234\210", nullptr));
        label->setText(QApplication::translate("PatientInfoDialog", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QApplication::translate("PatientInfoDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_5->setText(QApplication::translate("PatientInfoDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_6->setText(QApplication::translate("PatientInfoDialog", "\351\202\256\347\256\261", nullptr));
        editSaveButton->setText(QApplication::translate("PatientInfoDialog", "\344\277\256\346\224\271\350\265\204\346\226\231", nullptr));
        closeButton->setText(QApplication::translate("PatientInfoDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientInfoDialog: public Ui_PatientInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTINFODIALOG_H
