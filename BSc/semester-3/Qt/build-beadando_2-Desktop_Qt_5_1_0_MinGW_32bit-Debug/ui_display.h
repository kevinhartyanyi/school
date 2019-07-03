/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_display
{
public:
    QAction *actionNew_Game;
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *display)
    {
        if (display->objectName().isEmpty())
            display->setObjectName(QStringLiteral("display"));
        display->resize(400, 300);
        actionNew_Game = new QAction(display);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionExit = new QAction(display);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(display);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        display->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(display);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        display->setMenuBar(menuBar);
        mainToolBar = new QToolBar(display);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        display->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(display);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        display->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addAction(actionExit);
        mainToolBar->addAction(actionNew_Game);
        mainToolBar->addAction(actionExit);

        retranslateUi(display);

        QMetaObject::connectSlotsByName(display);
    } // setupUi

    void retranslateUi(QMainWindow *display)
    {
        display->setWindowTitle(QApplication::translate("display", "display", 0));
        actionNew_Game->setText(QApplication::translate("display", "New Game", 0));
        actionExit->setText(QApplication::translate("display", "Exit", 0));
        menuGame->setTitle(QApplication::translate("display", "Game", 0));
    } // retranslateUi

};

namespace Ui {
    class display: public Ui_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
