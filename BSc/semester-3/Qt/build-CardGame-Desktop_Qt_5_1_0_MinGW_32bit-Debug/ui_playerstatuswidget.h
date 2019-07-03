/********************************************************************************
** Form generated from reading UI file 'playerstatuswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSTATUSWIDGET_H
#define UI_PLAYERSTATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerStatusWidget
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelPlayerName;
    QLabel *labelPlayerHitsMisses;
    QLabel *labelPlayerGames;

    void setupUi(QWidget *PlayerStatusWidget)
    {
        if (PlayerStatusWidget->objectName().isEmpty())
            PlayerStatusWidget->setObjectName(QStringLiteral("PlayerStatusWidget"));
        PlayerStatusWidget->resize(200, 70);
        PlayerStatusWidget->setStyleSheet(QStringLiteral("QFrame { background-color : white }"));
        frame = new QFrame(PlayerStatusWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 201, 71));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 71, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 71, 16));
        labelPlayerName = new QLabel(frame);
        labelPlayerName->setObjectName(QStringLiteral("labelPlayerName"));
        labelPlayerName->setGeometry(QRect(70, 9, 121, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelPlayerName->setFont(font);
        labelPlayerHitsMisses = new QLabel(frame);
        labelPlayerHitsMisses->setObjectName(QStringLiteral("labelPlayerHitsMisses"));
        labelPlayerHitsMisses->setGeometry(QRect(90, 30, 81, 20));
        labelPlayerHitsMisses->setFont(font);
        labelPlayerGames = new QLabel(frame);
        labelPlayerGames->setObjectName(QStringLiteral("labelPlayerGames"));
        labelPlayerGames->setGeometry(QRect(90, 50, 91, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelPlayerGames->setFont(font1);

        retranslateUi(PlayerStatusWidget);

        QMetaObject::connectSlotsByName(PlayerStatusWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayerStatusWidget)
    {
        PlayerStatusWidget->setWindowTitle(QApplication::translate("PlayerStatusWidget", "Form", 0));
        label->setText(QApplication::translate("PlayerStatusWidget", "J\303\241t\303\251kos:", 0));
        label_2->setText(QApplication::translate("PlayerStatusWidget", "Tal\303\241latok:", 0));
        label_3->setText(QApplication::translate("PlayerStatusWidget", "J\303\241tszm\303\241k:", 0));
        labelPlayerName->setText(QApplication::translate("PlayerStatusWidget", "_", 0));
        labelPlayerHitsMisses->setText(QApplication::translate("PlayerStatusWidget", "_ / _", 0));
        labelPlayerGames->setText(QApplication::translate("PlayerStatusWidget", "_", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayerStatusWidget: public Ui_PlayerStatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSTATUSWIDGET_H
