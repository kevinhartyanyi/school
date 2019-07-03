#include "display.h"
#include "ui_display.h"
#include <QMessageBox>
#include <QThread>



display::display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

    setMinimumSize(500,500);
    setBaseSize(500,500);
    setWindowTitle("Play");


    loadname = "";

    createSize();



    timer = new QTimer(this);
    sec = 0;

    tablelayout = new QGridLayout(this);
    mainlayout = new QVBoxLayout(this);
    time_label = new QLabel("Time: ",this);
    point_label = new QLabel("Point: 0",this);

    time_label->setMaximumHeight(20);
    point_label->setMaximumHeight(20);

    pausebutton.setText("Pause");
    connect(&pausebutton,SIGNAL(clicked()),this,SLOT(pause()));

    mainlayout->addWidget(&pausebutton);
    mainlayout->addWidget(time_label);
    mainlayout->addWidget(point_label);

    mainlayout->addLayout(tablelayout);

    this->center = new QWidget(this);
    this->center->setLayout(mainlayout);

    setCentralWidget(center);

    connect(timer, SIGNAL(timeout()), this, SLOT(changeTime()));
    timer->start(1000);

    createModel();

}

void display::pause()
{    
    QMessageBox Pause;
    Pause.setWindowTitle("Pause");
    Pause.setText("Resume");
    timer->blockSignals(true);
    this->mymodel->pause(true);
    Pause.exec();
    timer->blockSignals(false);
    this->mymodel->pause(false);
}

void display::setSize(int size)
{
    this->size = size;
}

void display::createSize()
{
    Size sizedialog(this);
    sizedialog.setModal(true);
    connect(&sizedialog,SIGNAL(sendSize(int)),this,SLOT(setSize(int)));
    connect(&sizedialog, SIGNAL(sendLoad(QString)), this, SLOT(loadGame(QString)));
    sizedialog.exec();
}

void display::loadGame(QString load)
{
    qDebug() << "Load: " << load;
    loadname = load;
}

void display::createModel()
{
    this->mymodel = new class model(loadname, this);
    connect(this->mymodel, SIGNAL(tableSet(QStringList*)), this, SLOT(setTable(QStringList*)));
    connect(this->mymodel, SIGNAL(itemPickup(int)), this, SLOT(itemPickup(int)));
    connect(this->mymodel, SIGNAL(enemyMove(int,int)), this, SLOT(enemyMoved(int,int)));
    connect(this->mymodel, SIGNAL(gameOver(QString)), this, SLOT(GameOver(QString)));
    connect(this->mymodel, SIGNAL(sendSize(int)),this,SLOT(setSize(int)));
    this->mymodel->newGame(size);
}

display::~display()
{

    qDebug() << "destroy";
    for(Field* f : table)
    {
        delete f;
    }
    table.clear();

    delete time_label;
    delete point_label;
    delete tablelayout;
    delete mainlayout;

    delete timer;

    delete this->mymodel;

    delete ui;
}

void display::setTable(QStringList* fields)
{
    for(Field* f : table)
    {
        delete f;
    }
    table.clear();


    Field* type;
    int i = 0;

    for(QString field : *fields)
    {
        type = new Field();

        setColour(type, field);

        tablelayout->addWidget(type, i / size, i % size);
        table.append(type);
        ++i;
    }

    table.value(mymodel->getPlayer())->changeColour(colour_player);

    changeEnemies();

}

void display::changeEnemies()
{
    enemies = mymodel->getEnemies();
    for(int e : enemies)
        table.value(e)->changeColour(colour_enemy);
}

void display::keyPressEvent(QKeyEvent* event)
{
    int player = mymodel->getPlayer();
    int prev = player;
    int current_cord;
    switch (event->key())
    {
    case Qt::Key_W:
        current_cord = player / size;
        if(current_cord != 0 && mymodel->getType(player - size) != "Obstacle")
            player = player - size;
        break;

    case Qt::Key_A:
        current_cord = player % size;
        if(current_cord != 0 && mymodel->getType(player - 1) != "Obstacle")
            player = player - 1;
        break;

    case Qt::Key_S:
        current_cord = player / size;
        if(current_cord != size-1 && mymodel->getType(player + size) != "Obstacle")
            player = player + size;
        break;

    case Qt::Key_D:
        current_cord = player % size;
        if(current_cord != size-1 && mymodel->getType(player + 1) != "Obstacle")
            player = player + 1;
        break;

    default:
        break;

    }

    setColour(table.value(prev), mymodel->getType(prev));
    table.value(player)->changeColour(colour_player);
    mymodel->playerMove(player);



}

void display::setColour(Field* field, QString type)
{
    if(type == "Neutral")
        field->changeColour(colour_neutral);
    else if(type == "Resource")
        field->changeColour(colour_resource);
    else if(type == "Enemy")
        field->changeColour(colour_enemy);
    else
        field->changeColour(colour_obstacle);
}

void display::itemPickup(int point)
{
    this->point_label->setText("Point: " + QString::number(point));
}

void display::on_actionNew_Game_triggered()
{
    delete this->mymodel;

    point_label->setText("Point: 0");
    loadname = "";

    createSize();
    time_label->setText("Time: 0");
    sec = 0;
    createModel();
}

void display::on_actionExit_triggered()
{
    qDebug() << "Exit";
    this->close();
}

void display::changeTime()
{
    time_label->setText("Time: " + QString::number(++sec));
}

void display::enemyMoved(int pre,int cur)
{
    enemies.replace(enemies.indexOf(pre), cur);
    setColour(table.value(pre), mymodel->getType(pre));
    table.value(cur)->changeColour(colour_enemy);
}

void display::GameOver(QString over)
{    
    qDebug() << "Game Over";
    timer->stop();
    delete this->mymodel;
    this->mymodel = NULL;
    class gameOver end(this);
    end.setStat(over);
    end.setModal(true);
    connect(&end,SIGNAL(rejected()),this,SLOT(on_actionExit_triggered()));
    connect(&end,SIGNAL(accepted()),this,SLOT(on_actionNew_Game_triggered()));
    end.exec();
}
