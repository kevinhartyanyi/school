#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>
#include <QHash>
#include <QStringList>
#include <QDebug>
#include <QTimer>
#include "specia_timer.h"

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QString name, QObject *parent = nullptr);
    void sendTable();
    void playerMove(int cord);
    int getPlayer();
    void newGame(int size);
    QString getType(int cord);
    QList<int> getEnemies();
    void pause(bool);
    void setLoad(QString name);
    ~model();

signals:
    void tableSet(QStringList*);
    void enemyMove(int,int);
    void itemPickup(int);    
    void gameOver(QString);
    void sendSize(int);


private slots:
    void enemy_timeout();

private:

    void generateTable();
    bool playerDead(int enemy_cord, int player_cord);
    bool checkGameOver();
    void saveMap();
    void loadMap();

    QString randomBlock(int);
    int randomTime();

    QHash<int,specia_timer*> enemy_timers;
    int size;
    QStringList* table;
    int player;
    int point;
    bool paused;
    QString loadname;
};

#endif // MODEL_H
