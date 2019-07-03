/********************************************************************************
** Form generated from reading UI file 'savedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDIALOG_H
#define UI_SAVEDIALOG_H

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

class Ui_savedialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *savedialog)
    {
        if (savedialog->objectName().isEmpty())
            savedialog->setObjectName(QStringLiteral("savedialog"));
        savedialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(savedialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(savedialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(savedialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(savedialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(savedialog);

        QMetaObject::connectSlotsByName(savedialog);
    } // setupUi

    void retranslateUi(QDialog *savedialog)
    {
        savedialog->setWindowTitle(QApplication::translate("savedialog", "Dialog", 0));
        label->setText(QApplication::translate("savedialog", "<html><head/><body><p><span style=\" font-size:16pt;\">Save Name</span></p></body></html>", 0));
        lineEdit->setText(QApplication::translate("savedialog", "Game100", 0));
        pushButton->setText(QApplication::translate("savedialog", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class savedialog: public Ui_savedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDIALOG_H
