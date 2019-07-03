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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QComboBox *comboBox;
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_6 = new QPushButton(Size);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setStyleSheet(QStringLiteral("background-color: DarkViolet ;"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_3 = new QPushButton(Size);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setStyleSheet(QStringLiteral("background-color: LightSalmon;"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Size);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setStyleSheet(QStringLiteral("background-color: LightSeaGreen;"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(Size);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setStyleSheet(QStringLiteral("background-color: Lavender;"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(Size);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: LightGreen;"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(Size);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Size);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(Size);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_2 = new QLabel(Size);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_6 = new QLabel(Size);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(Size);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        comboBox = new QComboBox(Size);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


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
        pushButton_6->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_2->setText(QString());
        label_3->setText(QApplication::translate("Size", "Player", 0));
        label_4->setText(QApplication::translate("Size", "Enemy", 0));
        label_5->setText(QApplication::translate("Size", "Resource", 0));
        label_2->setText(QApplication::translate("Size", "Obstacle", 0));
        label_6->setText(QApplication::translate("Size", "Neutral", 0));
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
