/********************************************************************************
** Form generated from reading UI file 'size.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZE_H
#define UI_SIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Size
{
public:
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox;
    QLabel *label_7;
    QPushButton *pushButton;

    void setupUi(QDialog *Size)
    {
        if (Size->objectName().isEmpty())
            Size->setObjectName(QStringLiteral("Size"));
        Size->resize(400, 300);
        verticalLayout_5 = new QVBoxLayout(Size);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(Size);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(Size);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        checkBox = new QCheckBox(Size);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        spinBox = new QSpinBox(Size);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_3->addWidget(spinBox);

        label_7 = new QLabel(Size);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);


        verticalLayout_4->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(Size);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Size);

        QMetaObject::connectSlotsByName(Size);
    } // setupUi

    void retranslateUi(QDialog *Size)
    {
        Size->setWindowTitle(QApplication::translate("Size", "Dialog", 0));
        label->setText(QApplication::translate("Size", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#3fa3be;\">Choose The Map Size</span></p></body></html>", 0));
        checkBox->setText(QApplication::translate("Size", "Load Game", 0));
        label_7->setText(QApplication::translate("Size", "New Game Size", 0));
        pushButton->setText(QApplication::translate("Size", "Go", 0));
    } // retranslateUi

};

namespace Ui {
    class Size: public Ui_Size {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZE_H
