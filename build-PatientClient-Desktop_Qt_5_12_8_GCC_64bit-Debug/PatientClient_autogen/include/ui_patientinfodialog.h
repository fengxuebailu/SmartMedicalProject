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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientInfoDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *photoLabel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *ageLineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *phoneLineEdit;
    QLabel *label_6;
    QLineEdit *emailLineEdit;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *dobLineEdit;
    QLineEdit *idCardLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *editSaveButton;
    QPushButton *closeButton;

    void setupUi(QDialog *PatientInfoDialog)
    {
        if (PatientInfoDialog->objectName().isEmpty())
            PatientInfoDialog->setObjectName(QString::fromUtf8("PatientInfoDialog"));
        PatientInfoDialog->resize(546, 457);
        PatientInfoDialog->setStyleSheet(QString::fromUtf8("/* ---- \345\257\271\350\257\235\346\241\206\346\225\264\344\275\223\346\240\267\345\274\217 ---- */\n"
"QDialog {\n"
"    background-color: #f5f7fa; /* \344\270\216\344\270\273\347\252\227\345\217\243\344\270\200\350\207\264\347\232\204\346\237\224\345\222\214\350\203\214\346\231\257\350\211\262 */\n"
"}\n"
"\n"
"/* ---- \351\241\266\351\203\250\345\244\264\345\203\217\345\214\272\345\237\237 ---- */\n"
"QLabel#photoLabel {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 40px; /* \345\234\206\345\275\242\345\244\264\345\203\217 */\n"
"    min-width: 80px;\n"
"    min-height: 80px;\n"
"    max-width: 80px;\n"
"    max-height: 80px;\n"
"}\n"
"/* \351\241\266\351\203\250\347\232\204\345\247\223\345\220\215\345\222\214\345\271\264\351\276\204\350\276\223\345\205\245\346\241\206\357\274\214\346\210\221\344\273\254\350\256\251\345\256\203\347\234\213\350\265\267\346\235\245\344\270\215\345\203\217\350\276\223\345\205\245\346\241\206 */\n"
"QLineEdit#nameLineEdit, QLineEdit#ageLineEdit {\n"
"    font-size: 18"
                        "px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    border: none; /* \345\216\273\346\216\211\350\276\271\346\241\206 */\n"
"    background-color: transparent; /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"}\n"
"QLineEdit#ageLineEdit {\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"    color: #555;\n"
"}\n"
"\n"
"\n"
"/* ---- \345\215\241\347\211\207\346\240\267\345\274\217 (QGroupBox) ---- */\n"
"QGroupBox {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 10px;\n"
"    margin-top: 15px; /* \350\256\251\346\240\207\351\242\230\345\222\214\344\270\212\344\270\200\344\270\252\345\205\203\347\264\240\346\234\211\350\267\235\347\246\273 */\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* \345\215\241\347\211\207\346\240\207\351\242\230\347\232\204\346\240\267\345\274\217 */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    left: 15px;\n"
"    padding: 0 5px 5px 5px;\n"
"    color: #3498db; /"
                        "* \346\240\207\351\242\230\347\224\250\344\270\273\351\242\230\350\223\235\350\211\262 */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* ---- \345\215\241\347\211\207\345\206\205\351\203\250\347\232\204\350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 ---- */\n"
"QLineEdit {\n"
"    background-color: #f5f7fa; /* \346\265\205\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 13px;\n"
"}\n"
"/* \345\275\223\350\276\223\345\205\245\346\241\206\345\217\230\344\270\272\345\217\252\350\257\273\346\227\266\357\274\214\350\256\251\345\256\203\347\234\213\350\265\267\346\235\245\346\233\264\345\203\217\346\231\256\351\200\232\346\226\207\346\234\254 */\n"
"QLineEdit:read-only {\n"
"    background-color: white;\n"
"    border: none;\n"
"}\n"
"\n"
"\n"
"/* ---- \345\272\225\351\203\250\346\214\211\351\222\256\346\240\267\345\274\217 ---- */\n"
"QPushButton {\n"
"    min-width: 80px;\n"
"    min-height: 25px;\n"
""
                        "    border-radius: 8px;\n"
"    font-size: 13px;\n"
"}\n"
"/* \344\277\235\345\255\230\346\214\211\351\222\256\347\224\250\344\270\273\351\242\230\350\211\262 */\n"
"QPushButton#editSaveButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton#editSaveButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"/* \345\205\263\351\227\255\346\214\211\351\222\256\347\224\250\346\231\256\351\200\232\346\240\267\345\274\217 */\n"
"QPushButton#closeButton {\n"
"    background-color: #bdc3c7;\n"
"    color: white;\n"
"}\n"
"QPushButton#closeButton:hover {\n"
"    background-color: #95a5a6;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(PatientInfoDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        photoLabel = new QLabel(PatientInfoDialog);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(84, 84));
        photoLabel->setMaximumSize(QSize(84, 84));
        photoLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));
        photoLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(photoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        nameLabel = new QLabel(PatientInfoDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_3->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(PatientInfoDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(PatientInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        ageLineEdit = new QLineEdit(PatientInfoDialog);
        ageLineEdit->setObjectName(QString::fromUtf8("ageLineEdit"));
        ageLineEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(ageLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(PatientInfoDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 501, 80));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        phoneLineEdit = new QLineEdit(formLayoutWidget_2);
        phoneLineEdit->setObjectName(QString::fromUtf8("phoneLineEdit"));
        phoneLineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, phoneLineEdit);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        emailLineEdit = new QLineEdit(formLayoutWidget_2);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, emailLineEdit);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(PatientInfoDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 40, 501, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        dobLineEdit = new QLineEdit(formLayoutWidget);
        dobLineEdit->setObjectName(QString::fromUtf8("dobLineEdit"));
        dobLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, dobLineEdit);

        idCardLineEdit = new QLineEdit(formLayoutWidget);
        idCardLineEdit->setObjectName(QString::fromUtf8("idCardLineEdit"));
        idCardLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, idCardLineEdit);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        editSaveButton = new QPushButton(PatientInfoDialog);
        editSaveButton->setObjectName(QString::fromUtf8("editSaveButton"));

        horizontalLayout_2->addWidget(editSaveButton);

        closeButton = new QPushButton(PatientInfoDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 6);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 3);
        verticalLayout_2->setStretch(3, 1);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PatientInfoDialog);

        QMetaObject::connectSlotsByName(PatientInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientInfoDialog)
    {
        PatientInfoDialog->setWindowTitle(QApplication::translate("PatientInfoDialog", "Dialog", nullptr));
        photoLabel->setText(QApplication::translate("PatientInfoDialog", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        nameLabel->setText(QApplication::translate("PatientInfoDialog", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QApplication::translate("PatientInfoDialog", "\345\271\264\351\276\204", nullptr));
        groupBox_2->setTitle(QApplication::translate("PatientInfoDialog", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("PatientInfoDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_6->setText(QApplication::translate("PatientInfoDialog", "\351\202\256\347\256\261", nullptr));
        groupBox->setTitle(QApplication::translate("PatientInfoDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("PatientInfoDialog", "\345\207\272\347\224\237\345\271\264\346\234\210", nullptr));
        label_4->setText(QApplication::translate("PatientInfoDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        editSaveButton->setText(QApplication::translate("PatientInfoDialog", "\344\277\256\346\224\271\350\265\204\346\226\231", nullptr));
        closeButton->setText(QApplication::translate("PatientInfoDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientInfoDialog: public Ui_PatientInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTINFODIALOG_H
