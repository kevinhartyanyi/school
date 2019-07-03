#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <QFile>
#include "cord.h"
#include <QTextStream>


class FileController : public QObject
{
    Q_OBJECT

public:
    FileController(QObject* parent = nullptr);
    void save(QString savename, int life1, QString player1,
              QString direct1, Cord cord1, int max1,
              int life2, QString player2,
              QString direct2, Cord cord2, int max2);
    void load(QString);
    QString getPlayer1() {return *player1;}
    QString getPlayer2() {return *player2;}
    bool getError() {return error;}
    ~FileController();

private:
    QString* player1;
    QString* player2;
    QString n1;
    bool error;
};

#endif // FILECONTROLLER_H
