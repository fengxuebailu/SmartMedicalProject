/********************************************************************************
** Form generated from reading UI file 'doctordetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORDETAILSDIALOG_H
#define UI_DOCTORDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoctorDetailsDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *photoLabel;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLabel *titleLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *departmentLabel;
    QLabel *genderLabel;
    QTextBrowser *bioTextBrowser;
    QPushButton *closeButton;

    void setupUi(QDialog *DoctorDetailsDialog)
    {
        if (DoctorDetailsDialog->objectName().isEmpty())
            DoctorDetailsDialog->setObjectName(QString::fromUtf8("DoctorDetailsDialog"));
        DoctorDetailsDialog->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(DoctorDetailsDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        photoLabel = new QLabel(DoctorDetailsDialog);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(150, 120));
        photoLabel->setStyleSheet(QString::fromUtf8("background-color: #eee;"));
        photoLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(photoLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nameLabel = new QLabel(DoctorDetailsDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        nameLabel->setFont(font);

        horizontalLayout->addWidget(nameLabel);

        titleLabel = new QLabel(DoctorDetailsDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        horizontalLayout->addWidget(titleLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        departmentLabel = new QLabel(DoctorDetailsDialog);
        departmentLabel->setObjectName(QString::fromUtf8("departmentLabel"));

        horizontalLayout_2->addWidget(departmentLabel);

        genderLabel = new QLabel(DoctorDetailsDialog);
        genderLabel->setObjectName(QString::fromUtf8("genderLabel"));

        horizontalLayout_2->addWidget(genderLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        bioTextBrowser = new QTextBrowser(DoctorDetailsDialog);
        bioTextBrowser->setObjectName(QString::fromUtf8("bioTextBrowser"));

        verticalLayout_2->addWidget(bioTextBrowser);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        closeButton = new QPushButton(DoctorDetailsDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout_3->addWidget(closeButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(DoctorDetailsDialog);

        QMetaObject::connectSlotsByName(DoctorDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorDetailsDialog)
    {
        DoctorDetailsDialog->setWindowTitle(QApplication::translate("DoctorDetailsDialog", "Dialog", nullptr));
        photoLabel->setText(QApplication::translate("DoctorDetailsDialog", "TextLabel", nullptr));
        nameLabel->setText(QApplication::translate("DoctorDetailsDialog", "\345\214\273\347\224\237\345\247\223\345\220\215", nullptr));
        titleLabel->setText(QApplication::translate("DoctorDetailsDialog", "\350\201\214\347\247\260", nullptr));
        departmentLabel->setText(QApplication::translate("DoctorDetailsDialog", "\346\211\200\345\261\236\347\247\221\345\256\244", nullptr));
        genderLabel->setText(QApplication::translate("DoctorDetailsDialog", "\346\200\247\345\210\253", nullptr));
        closeButton->setText(QApplication::translate("DoctorDetailsDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorDetailsDialog: public Ui_DoctorDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORDETAILSDIALOG_H
