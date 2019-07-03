/********************************************************************************
** Form generated from reading UI file 'ask.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASK_H
#define UI_ASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ask
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Ask)
    {
        if (Ask->objectName().isEmpty())
            Ask->setObjectName(QStringLiteral("Ask"));
        Ask->resize(400, 300);
        verticalLayout = new QVBoxLayout(Ask);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Ask);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(Ask);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Ask);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Ask);

        QMetaObject::connectSlotsByName(Ask);
    } // setupUi

    void retranslateUi(QDialog *Ask)
    {
        Ask->setWindowTitle(QApplication::translate("Ask", "Dialog", 0));
        label->setText(QApplication::translate("Ask", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">Table Size</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Ask", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Ask: public Ui_Ask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASK_H
