#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewidget.h"

// főablak
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);
    
private:
    QAction* _newGameAction; // új játék akció
    QAction* _exitAction; // kilépés akció
    QAction* _configureAction; // beállítások akciója

    QMenu* _gameMenu; // játékmenü

    GameWidget* _gameWidget; // játékmezõ vezérlője
};

#endif // MAINWINDOW_H
