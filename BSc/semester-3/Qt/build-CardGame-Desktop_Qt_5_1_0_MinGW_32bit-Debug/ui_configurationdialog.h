/********************************************************************************
** Form generated from reading UI file 'configurationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONDIALOG_H
#define UI_CONFIGURATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationDialog
{
public:
    QFrame *frame;
    QLineEdit *lineSecondPlayerName;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineFirstPlayerName;
    QFrame *frame_2;
    QSpinBox *spinCols;
    QLabel *label_4;
    QSpinBox *spinRows;
    QLabel *label_3;
    QFrame *cardFrame;
    QLabel *label_6;
    QComboBox *comboCardPack;
    QLabel *label_5;
    QLabel *labelCardCount;
    QWidget *gridLayoutWidget;
    QGridLayout *cardLayout;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QWidget *ConfigurationDialog)
    {
        if (ConfigurationDialog->objectName().isEmpty())
            ConfigurationDialog->setObjectName(QStringLiteral("ConfigurationDialog"));
        ConfigurationDialog->resize(400, 536);
        ConfigurationDialog->setStyleSheet(QStringLiteral("QFrame { background-color : white }"));
        frame = new QFrame(ConfigurationDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 241, 81));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        lineSecondPlayerName = new QLineEdit(frame);
        lineSecondPlayerName->setObjectName(QStringLiteral("lineSecondPlayerName"));
        lineSecondPlayerName->setGeometry(QRect(90, 39, 141, 31));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 81, 21));
        lineFirstPlayerName = new QLineEdit(frame);
        lineFirstPlayerName->setObjectName(QStringLiteral("lineFirstPlayerName"));
        lineFirstPlayerName->setGeometry(QRect(90, 9, 141, 31));
        frame_2 = new QFrame(ConfigurationDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(260, 10, 131, 81));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        spinCols = new QSpinBox(frame_2);
        spinCols->setObjectName(QStringLiteral("spinCols"));
        spinCols->setGeometry(QRect(70, 40, 51, 31));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 51, 21));
        spinRows = new QSpinBox(frame_2);
        spinRows->setObjectName(QStringLiteral("spinRows"));
        spinRows->setGeometry(QRect(70, 11, 51, 31));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 46, 21));
        cardFrame = new QFrame(ConfigurationDialog);
        cardFrame->setObjectName(QStringLiteral("cardFrame"));
        cardFrame->setGeometry(QRect(10, 100, 381, 391));
        cardFrame->setStyleSheet(QStringLiteral(""));
        cardFrame->setFrameShape(QFrame::Box);
        cardFrame->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(cardFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 101, 21));
        comboCardPack = new QComboBox(cardFrame);
        comboCardPack->setObjectName(QStringLiteral("comboCardPack"));
        comboCardPack->setGeometry(QRect(120, 10, 251, 31));
        label_5 = new QLabel(cardFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 50, 111, 21));
        labelCardCount = new QLabel(cardFrame);
        labelCardCount->setObjectName(QStringLiteral("labelCardCount"));
        labelCardCount->setGeometry(QRect(120, 50, 81, 21));
        gridLayoutWidget = new QWidget(cardFrame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 80, 361, 301));
        cardLayout = new QGridLayout(gridLayoutWidget);
        cardLayout->setObjectName(QStringLiteral("cardLayout"));
        cardLayout->setContentsMargins(0, 0, 0, 0);
        buttonOk = new QPushButton(ConfigurationDialog);
        buttonOk->setObjectName(QStringLiteral("buttonOk"));
        buttonOk->setGeometry(QRect(310, 490, 81, 31));
        buttonCancel = new QPushButton(ConfigurationDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(230, 490, 81, 31));
        QWidget::setTabOrder(lineFirstPlayerName, lineSecondPlayerName);
        QWidget::setTabOrder(lineSecondPlayerName, spinRows);
        QWidget::setTabOrder(spinRows, spinCols);
        QWidget::setTabOrder(spinCols, comboCardPack);
        QWidget::setTabOrder(comboCardPack, buttonCancel);
        QWidget::setTabOrder(buttonCancel, buttonOk);

        retranslateUi(ConfigurationDialog);

        QMetaObject::connectSlotsByName(ConfigurationDialog);
    } // setupUi

    void retranslateUi(QWidget *ConfigurationDialog)
    {
        ConfigurationDialog->setWindowTitle(QApplication::translate("ConfigurationDialog", "Form", 0));
        label->setText(QApplication::translate("ConfigurationDialog", "1. j\303\241t\303\251kos:", 0));
        label_2->setText(QApplication::translate("ConfigurationDialog", "2. j\303\241t\303\251kos:", 0));
        label_4->setText(QApplication::translate("ConfigurationDialog", "Oszlop:", 0));
        label_3->setText(QApplication::translate("ConfigurationDialog", "Sor:", 0));
        label_6->setText(QApplication::translate("ConfigurationDialog", "K\303\241rtyacsomag:", 0));
        label_5->setText(QApplication::translate("ConfigurationDialog", "K\303\241rty\303\241k sz\303\241ma:", 0));
        labelCardCount->setText(QApplication::translate("ConfigurationDialog", "0", 0));
        buttonOk->setText(QApplication::translate("ConfigurationDialog", "&OK", 0));
        buttonCancel->setText(QApplication::translate("ConfigurationDialog", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationDialog: public Ui_ConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONDIALOG_H
