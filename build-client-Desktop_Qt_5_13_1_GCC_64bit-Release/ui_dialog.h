/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *hostInfo;
    QLabel *label_2;
    QLineEdit *hostName;
    QLabel *label_3;
    QLineEdit *ipAddr;
    QTextEdit *textEdit;
    QLabel *label_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(389, 455);
        QFont font;
        font.setFamily(QString::fromUtf8("padmaa-Bold.1.1"));
        Dialog->setFont(font);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 364, 96));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setTextFormat(Qt::RichText);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        hostInfo = new QPushButton(layoutWidget);
        hostInfo->setObjectName(QString::fromUtf8("hostInfo"));

        gridLayout->addWidget(hostInfo, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(67, 17));
        label_2->setMaximumSize(QSize(67, 177215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        hostName = new QLineEdit(layoutWidget);
        hostName->setObjectName(QString::fromUtf8("hostName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hostName->sizePolicy().hasHeightForWidth());
        hostName->setSizePolicy(sizePolicy);
        hostName->setMinimumSize(QSize(281, 25));
        hostName->setMaximumSize(QSize(281, 25));

        gridLayout->addWidget(hostName, 1, 1, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(67, 17));
        label_3->setMaximumSize(QSize(67, 17));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        ipAddr = new QLineEdit(layoutWidget);
        ipAddr->setObjectName(QString::fromUtf8("ipAddr"));
        ipAddr->setMinimumSize(QSize(281, 25));
        ipAddr->setMaximumSize(QSize(281, 25));

        gridLayout->addWidget(ipAddr, 2, 1, 1, 2);

        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 180, 361, 231));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 81, 17));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 420, 89, 25));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 150, 251, 25));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 150, 89, 25));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\346\234\254\346\234\272\344\277\241\346\201\257\357\274\232", nullptr));
        hostInfo->setText(QCoreApplication::translate("Dialog", "\347\202\271\345\207\273\350\216\267\345\217\226\350\257\246\346\203\205", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "UDP\345\256\242\346\210\267\347\253\257", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\345\205\263\351\227\255", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
