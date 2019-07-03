#include "mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setMinimumSize(500,500);
    setWindowTitle(trUtf8("Kártyajáték"));

    _newGameAction = new QAction(trUtf8("Ú&j játék"), this);
    _newGameAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    _newGameAction->setStatusTip(trUtf8("Új játék indítása"));

    _configureAction = new QAction(trUtf8("&Beállítások"), this);
    _configureAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    _configureAction->setStatusTip(trUtf8("Játék beállításainak módosítása"));

    _exitAction = new QAction(trUtf8("&Kilépés"), this);
    _exitAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    _exitAction->setStatusTip(trUtf8("Kilépés a játékból"));

    _gameMenu = menuBar()->addMenu(trUtf8("&Játék"));
    _gameMenu->addAction(_newGameAction);
    _gameMenu->addAction(_configureAction);
    _gameMenu->addSeparator();
    _gameMenu->addAction(_exitAction);

    _gameWidget = new GameWidget(this);
    setCentralWidget(_gameWidget);

    statusBar()->showMessage(trUtf8("A játék indítása a menüből érhető el."));

    connect(_newGameAction, SIGNAL(triggered()), _gameWidget, SLOT(newGame()));
    connect(_configureAction, SIGNAL(triggered()), _gameWidget, SLOT(configureGame()));
    connect(_exitAction, SIGNAL(triggered()), this, SLOT(close()));

    connect(_gameWidget, SIGNAL(statusChanged(QString)), this->statusBar(), SLOT(showMessage(QString)));
    // állapotváltás a játékban
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton returnButton;

    // bezáráskor megkérdezzük, biztos kilép-e a játékos
    returnButton = QMessageBox::warning(this, trUtf8("Kártyajáték - Kilépés"), trUtf8("Biztos ki akarsz lépni a játékból?"), QMessageBox::Yes | QMessageBox::No);
    if (returnButton == QMessageBox::No)
        event->ignore();
    else
        event->accept();
}

