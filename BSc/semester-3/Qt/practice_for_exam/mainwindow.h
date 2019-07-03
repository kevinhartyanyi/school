#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <time.h>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QtDebug>
#include "ask.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void AskSize();
    void Table();
    int Number();
    ~MainWindow();

public slots:
    void Pause();
    void set(int);
    void changeTime();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    QVBoxLayout* verti;
    QGridLayout* table;
    QWidget* center;
    QPushButton pausebutton;
    QLabel timee;
    int size;
    int timenumb;
    QString white = "background-color:white;";
    QString black = "background-color:black;";
    QString red = "background-color:red;";
    QString blue = "background-color:blue;";

};

#endif // MAINWINDOW_H
