#include "display.h"
#include "ui_display.h"
#include "dialog.h"

Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    error = false;

    setMinimumSize(500,500);
    setWindowTitle("Play");

    load = false;


    //pause.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    tablelayout = new QGridLayout(this);
    mainlayout = new QVBoxLayout(this);
    lcdlayout = new QHBoxLayout(this);
    central = new QWidget(this);

    endGame = false;

    mainlayout->addWidget(&turn);
    turn.setText("Next Turn");
    connect(&turn,SIGNAL(clicked()),this,SLOT(step()));
    mainlayout->addWidget(&pause);
    pause.setText("Pause");
    connect(&pause, SIGNAL(clicked()),this, SLOT(Pause()));
    mainlayout->addWidget(&save);
    save.setText("Save");
    connect(&save, SIGNAL(clicked()), this, SLOT(saveGame()));

    lcdlayout->addWidget(&life2);
    lcdlayout->addWidget(&life1);

    mainlayout->addLayout(lcdlayout);

    createSize();

    //if(!load)
    //{




        if(!load)
        {
            qDebug() << "No Load";
            map.resize(size);
            if(!error)
            {
                qDebug() << "No Error";

                generateTable();
                createModel();
            }
            life1.display(3);
            life2.display(3);
        }







        mainlayout->addLayout(tablelayout);

        central->setLayout(mainlayout);

        this->setCentralWidget(central);
    //}
    //else
    //{
        qDebug() << "Here";
    //}



}

void Display::Error()
{
    qDebug() << "Close Real";
    close();
}

void Display::LoadTheGame(Cord c1,Cord c2,int life1,int life2,QString d1,QString d2,int size)
{
    if(mymodel->getError())
    {
        qDebug() << "Error";
        close();
    }
    this->size = size;
    qDebug() << "Almost";
    this->life1.display(life1);
    this->life2.display(life2);
    qDebug() << "Almost2";


    map.resize(size);
    qDebug() << "Almost3 Size " << this->size;
    generateTable();

    map[c1.x][c1.y]->changePlayers(Red,d1);
    map[c2.x][c2.y]->changePlayers(Blue,d2);

    player1 = c1;
    player2 = c2;



}

void Display::saveGame()
{
    qDebug() << "Let's save";
    savedialog save;
    connect(&save, SIGNAL(saveName(QString)),this,SLOT(saveName(QString)));
    save.exec();
}

void Display::saveName(QString name)
{
    mymodel->saveGame(name);
}

void Display::createModel()
{
    this->mymodel = new class model(this);
    connect(this->mymodel, SIGNAL(GameOver(Players)), this, SLOT(GameOver(Players)));
    connect(this->mymodel, SIGNAL(Error()), this, SLOT(Error()));
    connect(this->mymodel, SIGNAL(Moved(Players,Cord)), this, SLOT(Moved(Players,Cord)));
    connect(this->mymodel, SIGNAL(ChangeDirection(Players, QString)), this, SLOT(ChangeDirection(Players, QString)));
    connect(this->mymodel, SIGNAL(LaserAttack(Players,bool)), this, SLOT(Laser(Players,bool)));
    connect(this->mymodel, SIGNAL(PunchAttack(Players,bool)),this,SLOT(Punch(Players,bool)));
    connect(this->mymodel, SIGNAL(SendLoad(Cord,Cord,int,int,QString,QString,int)),this,SLOT(LoadTheGame(Cord,Cord,int,int,QString,QString,int)));

    Cord startpoint1;
    Cord startpoint2;
    if(size % 2 ==0)
    {
        startpoint1.x = (size/2);
        startpoint1.y = (size/2) - 2;

        startpoint2.x = (size/2);
        startpoint2.y = (size/2);
    }
    else
    {
        startpoint1.x = (size/2);
        startpoint1.y = (size/2) + 1;

        startpoint2.x = (size/2);
        startpoint2.y = (size/2) - 1;
    }
    map[startpoint1.x][startpoint1.y]->changePlayers(Red,"Up");
    map[startpoint2.x][startpoint2.y]->changePlayers(Blue,"Up");

    Cord1 = {startpoint1.x,startpoint1.y};
    Cord2 = {startpoint2.x,startpoint2.y};

    player1 = Cord1;
    player2 = Cord2;

    this->mymodel->newGame(startpoint1,startpoint2, size, "");
}
void Display::Pause()
{
    turn.setEnabled(false);
    QMessageBox message;
    message.setWindowTitle("Resume");
    message.setText("Resume");
    message.setStandardButtons(QMessageBox::Ok);
    message.exec();
    turn.setEnabled(true);
}
void Display::createSize()
{
    load = false;
    Size sizedialog(this);
    sizedialog.setModal(true);
    connect(&sizedialog,SIGNAL(sendSize(int)),this,SLOT(setSize(int)));
    connect(&sizedialog, SIGNAL(sendLoad(QString)), this, SLOT(loadGame(QString)));
    sizedialog.exec();
}

void Display::loadGame(QString name)
{
    if(!load && !error)
    {
        load = true;
        this->mymodel = new class model(this);
        connect(this->mymodel, SIGNAL(GameOver(Players)), this, SLOT(GameOver(Players)));
        connect(this->mymodel, SIGNAL(Moved(Players,Cord)), this, SLOT(Moved(Players,Cord)));
        connect(this->mymodel, SIGNAL(ChangeDirection(Players, QString)), this, SLOT(ChangeDirection(Players, QString)));
        connect(this->mymodel, SIGNAL(LaserAttack(Players,bool)), this, SLOT(Laser(Players,bool)));
        connect(this->mymodel, SIGNAL(PunchAttack(Players,bool)),this,SLOT(Punch(Players,bool)));
        connect(this->mymodel, SIGNAL(SendLoad(Cord,Cord,int,int,QString,QString,int)),this,SLOT(LoadTheGame(Cord,Cord,int,int,QString,QString,int)));
        qDebug() << "Load Button";
        mymodel->loadGame(name);
        if(mymodel->getError())
        {
            qDebug() << "Close";
            error = true;
            load = false;
            //this->close();
        }
    }
}

void Display::setSize(int size)
{
    this->size = size;
}

Display::~Display()
{
    delete ui;
}

void Display::generateTable()
{


    for(int i = 0; i < size; ++i)
    {
        map[i].resize(size);
        for(int j = 0; j < size; ++j)
        {
            imageButton* im = new imageButton(Neutral, this);
            tablelayout->addWidget(im, i, j);
            map[i][j] = im;
        }
    }

}

void Display::step()
{
    Cord c1 = mymodel->currentPos(1);
    Cord c2 = mymodel->currentPos(2);
    qDebug() << c1.x << " " << c1.y << "     " << c2.x << " " << c2.y;
    Dialog dial(size,1, this->mymodel->currentPos(1));
    connect(&dial, SIGNAL(sendText(QString,int,QString,QString,int)), this, SLOT(SetCommand(QString, int,QString,QString,int)));
    dial.setText("Player 1 Command:");
    dial.exec();

    Dialog dial2(size,2, this->mymodel->currentPos(2));
    connect(&dial2, SIGNAL(sendText(QString,int,QString,QString,int)), this, SLOT(SetCommand(QString, int,QString,QString,int)));
    dial2.setText("Player 2 Command:");
    dial2.exec();

    this->mymodel->step(Cord1,dir1,attack1,Cord2,dir2,attack2);



}

void Display::SetCommand(QString movedirection, int move,QString changedirection,QString attack, int player)
{
    qDebug() << "Command";
   if(player == 1)
   {
       Cord current = this->mymodel->currentPos(1);

       if(movedirection == "Up")
           Cord1 = {current.x-move,current.y};
       else if(movedirection == "Down")
           Cord1 = {current.x+move,current.y};
       else if(movedirection == "Right")
           Cord1 = {current.x,current.y+move};
       else
           Cord1 = {current.x,current.y-move};

       dir1 = changedirection;
       attack1 = attack;
       qDebug() << "Red " << Cord1.x << " " << Cord1.y << " " << dir1 << " " <<attack1 << " " << current.x << " " << current.y;
    }
   else
   {
       Cord current = this->mymodel->currentPos(2);
       if(movedirection == "Up")
           Cord2 = {current.x-move,current.y};
       else if(movedirection == "Down")
           Cord2 = {current.x+move,current.y};
       else if(movedirection == "Right")
           Cord2 = {current.x,current.y+move};
       else
           Cord2 = {current.x,current.y-move};

       dir2 = changedirection;
       attack2 = attack;
   }
}



void Display::Moved(Players player,Cord cord)
{
    if(player == Red)
    {
        qDebug() << "Red new Cord " << cord.x << " " << cord.y;
        map[player1.x][player1.y]->changePlayers(Neutral,"");
        map[cord.x][cord.y]->changePlayers(Red,dir1);//////////////////////////////////////////////////////////////
        player1 = cord;

    }
    else
    {
         qDebug() << "Blue new Cord " << cord.x << " " << cord.y << "  Old " << player2.x << " " << player2.y;
         map[player2.x][player2.y]->changePlayers(Neutral,"");
         map[cord.x][cord.y]->changePlayers(Blue,dir2);////////////////////////////////////////////////////////////
         player2 = cord;
    }
}
void Display::ChangeDirection(Players player, QString dir)
{
    if(player == Red)
    {
        qDebug() << "Red new Direction " << dir;
        map[player1.x][player1.y]->changeDirection(dir);
    }
    else
    {
         qDebug() << "Blue new Direction " << dir;         
         map[player2.x][player2.y]->changeDirection(dir);
    }
}
void Display::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Display::Laser(Players player, bool hit)
{
    turn.setEnabled(false);
    if(player == Red)
    {
        qDebug() << "Red new Laser ";
        if(hit)
        {
            qDebug() << "Red hit ";
            map[player2.x][player2.y]->changePlayers(Damaged,"");
            delay();
            map[player2.x][player2.y]->changePlayers(Blue,dir2);
            life2.display(life2.value()-1);
        }
    }
    else
    {
         qDebug() << "Blue new Laser ";
         if(hit)
         {
             qDebug() << "Blue hit ";
             map[player1.x][player1.y]->changePlayers(Damaged,"");
             delay();
             map[player1.x][player1.y]->changePlayers(Red,dir1);
             life1.display(life1.value()-1);
         }
    }
    turn.setEnabled(true);
}
void Display::Punch(Players player, bool hit)
{
    turn.setEnabled(false);
    if(player == Red)
    {
        qDebug() << "Red new Punch " ;
        if(hit)
        {
            qDebug() << "Hit";
            map[player2.x][player2.y]->changePlayers(Damaged,"");
            delay();
            map[player2.x][player2.y]->changePlayers(Blue,dir2);
            life2.display(life2.value()-1);
        }
    }
    else
    {        
        qDebug() << "Blue new Punch ";
        if(hit)
        {
            qDebug() << "Hit";
            map[player1.x][player1.y]->changePlayers(Damaged,"");
            delay();
            map[player1.x][player1.y]->changePlayers(Red,dir1);
            life1.display(life1.value()-1);
        }


    }
    turn.setEnabled(true);
}
void Display::GameOver(Players player)
{
    if(player == Red)
    {
        endGame = true;
        qDebug() << "Red Win ";
        gameover over("Red",this);
        connect(&over, SIGNAL(exitGame()), this, SLOT(End()));
        connect(&over, SIGNAL(newGame()), this, SLOT(on_actionNew_Game_triggered()));
        over.exec();

    }
    else
    {
         endGame = true;
         qDebug() << "Blue Win ";
         gameover over("Blue",this);
         connect(&over, SIGNAL(exitGame()), this, SLOT(End()));
         connect(&over, SIGNAL(newGame()), this, SLOT(on_actionNew_Game_triggered()));
         over.exec();
    }
}


void Display::on_actionNew_Game_triggered()
{
    qDebug() << "New Game";
    endGame = false;

    life1.display(3);
    life2.display(3);
    if(!error)
    {
    for(auto a : map)
    {
        qDebug() << "Del";
        for(auto b : a)
        {
            delete b;
        }
    }
    }
    delete mymodel;


    error = false;

    if(load)
    {

    }

    load = false;

    createSize();
    map.resize(size);
    if(!load)
    {
        generateTable();
        createModel();
    }
    qDebug() << "Itt";
}

void Display::on_actionExit_triggered()
{
    qDebug() << "Close Exit";
    close();
}

void Display::End()
{
    qDebug() << "End";
    if(endGame)
        close();
}
