/********************************************************************************
** Form generated from reading UI file 'create.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Create
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *Yspin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *Xspin;
    QPushButton *BattleButton;

    void setupUi(QWidget *Create)
    {
        if (Create->objectName().isEmpty())
            Create->setObjectName(QStringLiteral("Create"));
        Create->resize(400, 300);
        verticalLayout = new QVBoxLayout(Create);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(Create);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Create);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        Yspin = new QSpinBox(Create);
        Yspin->setObjectName(QStringLiteral("Yspin"));

        horizontalLayout->addWidget(Yspin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Create);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Xspin = new QSpinBox(Create);
        Xspin->setObjectName(QStringLiteral("Xspin"));

        horizontalLayout_2->addWidget(Xspin);


        verticalLayout->addLayout(horizontalLayout_2);

        BattleButton = new QPushButton(Create);
        BattleButton->setObjectName(QStringLiteral("BattleButton"));

        verticalLayout->addWidget(BattleButton);


        retranslateUi(Create);

        QMetaObject::connectSlotsByName(Create);
    } // setupUi

    void retranslateUi(QWidget *Create)
    {
        Create->setWindowTitle(QApplication::translate("Create", "Dialog", 0));
        label_3->setText(QApplication::translate("Create", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#ff5500;\">Choose The Board Size</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("Create", "Y", 0));
        label->setText(QApplication::translate("Create", "X", 0));
        BattleButton->setText(QApplication::translate("Create", "Battle", 0));
    } // retranslateUi

};

namespace Ui {
    class Create: public Ui_Create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H
