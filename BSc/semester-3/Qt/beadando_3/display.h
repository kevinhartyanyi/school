#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include "cord.h"
#include "imagebutton.h"
#include "size.h"
#include "model.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QVector>
#include <QMetaEnum>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "gameover.h"
#include <QMessageBox>



namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(Directions)
    Q_ENUMS(Attacks)
    Q_ENUMS(Players)

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private slots:
    void setSize(int);
    void Moved(Players,Cord);
    void ChangeDirection(Players, QString);
    void Laser(Players,bool);
    void Punch(Players,bool);
    void GameOver(Players);
    void SetCommand(QString,int,QString,QString,int);    
    void Pause();
    //void Timer();
    void step();

    void on_actionNew_Game_triggered();

    void on_actionExit_triggered();

private:
    Ui::Display *ui;
    void newGame();
    void createSize();
    void createModel();
    void generateTable();
    void delay();




    QVBoxLayout* mainlayout;
    QGridLayout* tablelayout;
    QWidget* central;
    QPushButton turn;
    QPushButton pause;
    QVector<QVector<imageButton*>> map;

    model* mymodel;

    int size;

    Cord Cord1;
    Cord Cord2;

    Cord player1;
    Cord player2;

    QString dir1;
    QString dir2;

    QString attack1;
    QString attack2;

    QTimer* timer;

};

#endif // DISPLAY_H
