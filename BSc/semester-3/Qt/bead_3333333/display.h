#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include "cord.h"
#include "imagebutton.h"
#include "size.h"
#include "model.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVector>
#include <QMetaEnum>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "gameover.h"
#include <QMessageBox>
#include <QLCDNumber>
#include "savedialog.h"



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
    void loadGame(QString);
    void End();
    void Error();
    void saveGame();
    void saveName(QString);
    void LoadTheGame(Cord,Cord,int,int,QString,QString,int);
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
    bool error;
    void delay();




    QVBoxLayout* mainlayout;
    QGridLayout* tablelayout;
    QHBoxLayout* lcdlayout;
    QWidget* central;
    QPushButton turn;
    QPushButton pause;
    QPushButton save;
    QVector<QVector<imageButton*>> map;

    model* mymodel;

    int size;
    bool endGame;
    bool load;

    QLCDNumber life1;
    QLCDNumber life2;

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
