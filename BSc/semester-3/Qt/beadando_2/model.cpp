#include "model.h"
#include <QTime>
#include <QKeyEvent>
#include "stdlib.h"
#include <QFile>
#include <QApplication>


model::model(QString name, QObject *parent) : QObject(parent)
{
    table = new QStringList;
    loadname = name;
    paused = false;
}

void model::setLoad(QString name)
{
    loadname = name;
}

void model::loadMap()
{
    qDebug() << "Read from File";

    QFile file(":/Load/Load/"+loadname);

    if(!file.open(QFile::QIODevice::ReadOnly|QFile::QIODevice::Text))
    {
        qDebug() << "Cannot open file";
        return;
    }

    QTextStream read(&file);
    size = read.readLine().toInt();
    int i = 0;
    qDebug() << size;
    sendSize(size);
    while(!read.atEnd())
    {
        if(i < size*size)
            table->append(read.readLine());
        else
        {
            QString line = read.readLine();
            QStringList list = line.split(' ');
            specia_timer* t = new specia_timer(list[0].toInt(), list[1].toInt(), list[2], this);
            enemy_timers.insert(list[0].toInt(),t);
            connect(t, SIGNAL(time_out()),this,SLOT(enemy_timeout()));
        }
        ++i;
    }

    file.close();

}

void model::saveMap()
{
    qDebug() << "Write to File";

    QFile file("Game1.txt");

    if(!file.open(QFile::QIODevice::WriteOnly|QFile::QIODevice::Text))
    {
        qDebug() << "Cannot open file";
        return;
    }

    QTextStream write(&file);
    write << size << "\n";
    for(QString type : *table)
    {
        write << type << "\n";
    }

    for(specia_timer* t : enemy_timers)
    {
        write << t->getCord() << " " << t->getRandomTime() << " " << t->getDirection() << "\n";
    }

    file.close();
}

void model::newGame(int size)
{
    player = 0;
    point = 0;
    this->size = size;
    if(loadname == "")
        generateTable();
    else
        loadMap();

    emit tableSet(table);
}

void model::pause(bool newstate)
{
    paused = newstate;
}

void model::generateTable()
{

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    for(int i = 0; i < size*size; ++i)
    {
        QString type = randomBlock(i);


        if(type == "Enemy")
        {
            table->append("Neutral");

            QString direction;
            if(i / size == 0)
                direction = "Down";
            else if(i / size == size - 1)
                direction = "Up";
            else if(i % size == 0)
                direction = "Right";
            else
                direction = "Left";

            specia_timer* t = new specia_timer(i, randomTime(), direction, this);
            enemy_timers.insert(i,t);
            connect(t, SIGNAL(time_out()),this,SLOT(enemy_timeout()));

        }
        else
        {
            table->append(type);
        }

    }

    //saveMap();

}

int model::randomTime()
{
    return (qrand() % 5000 + 500);
}

void model::sendTable()
{
    emit tableSet(table);
}

QString model::randomBlock(int position)
{
    int random_number = qrand() % 100 + 1;
    qDebug() << random_number;

    if(!playerDead(position, 0) && (position / size == 0 || position % size == 0 || position / size == size - 1 || position % size == size - 1))
    {
        if(random_number < 40)
            return "Resource";
        else if(random_number < 60)
            return "Enemy";
        else
            return "Neutral";
    }
    else
    {
        if(random_number < 50)
            return "Neutral";
        else if(position / size > 1 && position/ size < size-2 && position % size > 1 && position % size < size-2 && random_number < 70)
            return "Obstacle";
        else
            return "Resource";


    }


}

void model::playerMove(int cord)
{
    this->player = cord;


    if(checkGameOver())
    {

    }
    else if(table->value(player) == "Resource")
    {
        table->replace(player,"Neutral");
        ++point;
        emit itemPickup(point);
    }
}

bool model::playerDead(int enemy_cord, int player_cord)
{
    return ((abs((enemy_cord / size) - (player_cord / size)) <= 1) && (abs((enemy_cord % size) - (player_cord % size)) <= 1));
}

QString model::getType(int cord)
{
    return table->value(cord);
}

int model::getPlayer()
{
    return player;
}

model::~model()
{
    delete table;
    for(specia_timer* t : enemy_timers)
    {
        delete t;
    }
}


void model::enemy_timeout()
{
    if(paused)
        return;

    specia_timer* timer = (specia_timer*)sender();
    int current_position = timer->getCord();
    int position = current_position;
    if(timer->getDirection() == "Left")
    {
        qDebug() << "Left ";
        if((position % size) == 0 || table->value(position-1) == "Obstacle")
        {
            position = position + 1;
            timer->setDirection("Right");

        }
        else
        {
            position = position - 1;
        }

        timer->changeCord(position);
    }
    else if(timer->getDirection() == "Right")
    {
        qDebug() << "Right";
        if((position % size) == size-1 || table->value(position+1) == "Obstacle")
        {
            position = position - 1;
            timer->setDirection("Left");

        }
        else
        {
            position = position + 1;
        }

        timer->changeCord(position);
    }
    else if(timer->getDirection() == "Down")
    {
        qDebug() << "Down";
        if((position / size) == size - 1 || table->value(position+size) == "Obstacle")
        {
            position = position - size;
            timer->setDirection("Up");

        }
        else
        {
            position = position + size;
        }

        timer->changeCord(position);
    }
    else if(timer->getDirection() == "Up")
    {
        qDebug() << "Up";
        //qDebug() << "Positin " << position-size;
        if((position / size) == 0 || (position-size >= 0 && table->value(position-size) == "Obstacle"))
        {
            position = position + size;
            timer->setDirection("Down");

        }
        else
        {
            position = position - size;
        }

        timer->changeCord(position);
    }

    emit enemyMove(current_position, position);

    checkGameOver();
}

QList<int> model::getEnemies()
{
    QList<int> re;
    for(specia_timer* t : enemy_timers)
    {
        re.append(t->getCord());
    }
    return re;
}

bool model::checkGameOver()
{
    bool l = false;
    for(specia_timer* t : enemy_timers)
    {
        if(playerDead(t->getCord(),player))
            l =  true;
    }
    if(l)
    {
        emit gameOver("Lose");
        return true;
    }
    else
    {
        int c = 0;
        for(QString s : *table)
        {
            if(s == "Resource")
                ++c;
        }
        qDebug() << "Resources: " << c;
        if(c == 0)
        {
            emit gameOver("Win");
            return true;
        }
    }
    return false;
}



