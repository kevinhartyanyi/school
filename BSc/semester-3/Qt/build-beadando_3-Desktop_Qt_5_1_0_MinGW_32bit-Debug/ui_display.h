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

class Ui_Display
{
public:
    QAction *actionNew_Game;
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QStringLiteral("Display"));
        Display->resize(400, 300);
        actionNew_Game = new QAction(Display);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionExit = new QAction(Display);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(Display);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Display->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Display);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        Display->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Display);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Display->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Display);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Display->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addAction(actionExit);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QApplication::translate("Display", "Display", 0));
        actionNew_Game->setText(QApplication::translate("Display", "New Game", 0));
        actionExit->setText(QApplication::translate("Display", "Exit", 0));
        menuGame->setTitle(QApplication::translate("Display", "Game", 0));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
