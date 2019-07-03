/********************************************************************************
** Form generated from reading UI file 'tablesize.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLESIZE_H
#define UI_TABLESIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TableSize
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

    void setupUi(QDialog *TableSize)
    {
        if (TableSize->objectName().isEmpty())
            TableSize->setObjectName(QStringLiteral("TableSize"));
        TableSize->resize(400, 300);
        verticalLayout = new QVBoxLayout(TableSize);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(TableSize);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(TableSize);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        Yspin = new QSpinBox(TableSize);
        Yspin->setObjectName(QStringLiteral("Yspin"));

        horizontalLayout->addWidget(Yspin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(TableSize);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Xspin = new QSpinBox(TableSize);
        Xspin->setObjectName(QStringLiteral("Xspin"));

        horizontalLayout_2->addWidget(Xspin);


        verticalLayout->addLayout(horizontalLayout_2);

        BattleButton = new QPushButton(TableSize);
        BattleButton->setObjectName(QStringLiteral("BattleButton"));

        verticalLayout->addWidget(BattleButton);


        retranslateUi(TableSize);

        QMetaObject::connectSlotsByName(TableSize);
    } // setupUi

    void retranslateUi(QDialog *TableSize)
    {
        TableSize->setWindowTitle(QApplication::translate("TableSize", "Dialog", 0));
        label_3->setText(QApplication::translate("TableSize", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#ff5500;\">Choose The Board Size</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("TableSize", "Y", 0));
        label->setText(QApplication::translate("TableSize", "X", 0));
        BattleButton->setText(QApplication::translate("TableSize", "Battle", 0));
    } // retranslateUi

};

namespace Ui {
    class TableSize: public Ui_TableSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLESIZE_H
