#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QHash>
#include <QDebug>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include "model.h"
#include "field.h"
#include "size.h"
#include "gameover.h"

namespace Ui {
class display;
}

class display : public QMainWindow
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();

public slots:
    void setTable(QStringList* fields);
    void changeTime();

private slots:
    void itemPickup(int pos);
    void enemyMoved(int,int);
    void GameOver(QString);
    void setSize(int);
    void pause();
    void loadGame(QString);

    void on_actionNew_Game_triggered();

    void on_actionExit_triggered();

private:
    void keyPressEvent(QKeyEvent*) override;


    Ui::display *ui;

    void generateTable();
    void setColour(Field* field, QString type);
    void timeSetup();
    void changeEnemies();
    void createModel();
    void createSize();

    QGridLayout* tablelayout;
    QVBoxLayout* mainlayout;
    QLabel* time_label;
    QLabel* point_label;
    QTimer* timer;
    QPushButton pausebutton;

    QList<int> enemies;


    int size;
    int sec;
    QString loadname;


    model* mymodel;
    QList<Field*> table;
    QWidget* center;



    QString colour_enemy = "background-color: LightSalmon;";
    QString colour_neutral = "background-color: LightGreen;";
    QString colour_resource = "background-color: LightSeaGreen;";
    QString colour_obstacle = "background-color: Lavender;";
    QString colour_player = "background-color: DarkViolet ;";



};

#endif // DISPLAY_H
