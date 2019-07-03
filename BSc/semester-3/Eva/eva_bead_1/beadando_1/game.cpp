#include "game.h"
#include "ui_game.h"
#include "tablesize.h"
#include "gameover.h"

Game::Game(struct size createsize, QWidget *parent) : QMainWindow(parent), ui(new Ui::Game)
{
    ui->setupUi(this);
    setMinimumSize(500,500);
    setBaseSize(500,500);
    setWindowTitle("Battle");

    view = new QLabel;
    view->setMaximumHeight(20);
    view->setAlignment(Qt::AlignCenter);
    view->setTextFormat(Qt::RichText);

    mainLayout = new QVBoxLayout();
    boardLayout = new QGridLayout();

    mainLayout->addWidget(view);
    mainLayout->addLayout(boardLayout);

    centerWidget = new QWidget;
    centerWidget->setLayout(mainLayout);
    setCentralWidget(centerWidget);

    this->size = createsize;

    NewGame();

}

Game::~Game()
{
    for(QVector<Warrior*> row : Table)
    {
        for(Warrior* w : row)
        {
            delete w;
        }
    }

    delete view;
    delete boardLayout;
    delete mainLayout;

    delete ui;
}

void Game::NewGame()
{

    turn = 1;

    //TableSize TSize;
    //TSize.setModal(true);
    //TSize.exec();
    //this->size = TSize.GetTable();

    view->setText("<font-family: Arial><h2>Turn: "+QString::number(turn) +"</h2></font-family>");
    GenerateTable();
    qDebug() << "Live";
    UpdateWarriors();

}

void Game::GenerateTable()
{

    //for(QVector<Warrior*> wari : Table)
    //{
    //    for(Warrior* w : wari)
    //    {
    //        delete w;
    //    }
    //}

    for(int i = 0; i < this->size.x; ++i)
    {
        QVector<Warrior*> row;
        for(int j = 0; j < this->size.y; ++j)
        {
            Warrior* w;
            if(i == 0 || i == 1)
            {
                w = new Warrior(1, {i,j});
                row.append(w); ////////////////////////////////////////////////////////////////////
                boardLayout->addWidget(w,i,j);
            }
            else if(i == this->size.x-1 || i == this->size.x-2)
            {
                w = new Warrior(2, {i,j});
                row.append(w); ////////////////////////////////////////////////////////////////////
                boardLayout->addWidget(w,i,j);
            }
            else
            {
                w = new Warrior(0, {i,j});
                row.append(w); ////////////////////////////////////////////////////////////////////
                boardLayout->addWidget(w,i,j);
            }
            connect(w,SIGNAL(clicked()),this,SLOT(ButtonClicked()));

        }
        Table.append(row);
    }
}


void Game::ButtonClicked()
{
    QObject* senderObject = sender();
    Warrior* w = qobject_cast<Warrior*>(senderObject);

    if(w->attacked)
    {
        for(Warrior* wa : offenseWarrior)
        {
            if(wa->Player() == 1)
                wa->ChangeColour(colour_player_1);
            else if(wa->Player() == 2)
                wa->ChangeColour(colour_player_2);
            else
                wa->ChangeColour(colour_neutral);

            wa->Active(false);
            wa->attacked = false;
        }
        offenseWarrior.clear();

        if((turn%2)+1 == 2)
        {
            w->SetPlayer(2);
            w->ChangeColour(colour_player_2);
            current->ChangeColour(colour_player_2);
        }
        else
        {
            w->SetPlayer(1);
            w->ChangeColour(colour_player_1);
            current->ChangeColour(colour_player_1);
        }
        w->Active(false);

        if(true)
        {
            current->ChangeColour(colour_neutral);
            current->SetPlayer(0);
        }
        else
        {

        }

        NextTurn();
    }
    else
    {
        struct size cord = w->Cord();
        current = Table[cord.x][cord.y];

        current->ChangeColour("background-color: Plum;");
        //qDebug() << w->Player();



        CollectWarriors(offenseWarrior,cord,w->Player());

        for(QVector<Warrior*> wvector : Table)
        {
            for(Warrior* war : wvector)
            {
                war->Active(false);
            }
        }

        for(Warrior* act : offenseWarrior)
        {
            if(act->Player() != 0)
                act->ChangeColour(colour_enemy);
            else
                act->ChangeColour(colour_active);

            act->Active(true);
            act->attacked = true;
        }
    }

}

void Game::CollectWarriors(QVector<Warrior*>& vector, struct size cord, int player)
{
    if(player == 1)
    {
        if(cord.x+1 < size.x)
        {
            if(Table[cord.x+1][cord.y]->Player() != player && Table[cord.x+1][cord.y]->Player() != 2)
            {
                vector.append(Table[cord.x+1][cord.y]);
                //activeCordinates.append({cord.x+1, cord.y});
            }
        }

        if(cord.x+1 < size.x && cord.y+1 < size.y)
        {
            //qDebug() << size.y << " " << cord.y;
            if(Table[cord.x+1][cord.y+1]->Player() != player)
            {
                vector.append(Table[cord.x+1][cord.y+1]);
                //activeCordinates.append({cord.x+1, cord.y+1});
            }
        }

        if(cord.x+1 < size.x && cord.y-1 >= 0)
        {
            if(Table[cord.x+1][cord.y-1]->Player() != player)
            {
                vector.append(Table[cord.x+1][cord.y-1]);
                //activeCordinates.append({cord.x+1, cord.y-1});
            }
        }
    }
    else
    {
        //qDebug() << size.y << " " << cord.y;
        if(cord.x-1 >= 0)
        {
            if(Table[cord.x-1][cord.y]->Player() != player && Table[cord.x-1][cord.y]->Player() != 1)
            {
                vector.append(Table[cord.x-1][cord.y]);
                //activeCordinates.append({cord.x-1, cord.y});
            }
        }

        if(cord.x-1 >= 0 && cord.y+1 < size.y)
        {
            if(Table[cord.x-1][cord.y+1]->Player() != player)
            {
                vector.append(Table[cord.x-1][cord.y+1]);
                //activeCordinates.append({cord.x-1, cord.y+1});
            }
        }

        if(cord.x-1 >= 0 && cord.y-1 >= 0)
        {
            if(Table[cord.x-1][cord.y-1]->Player() != player)
            {
                vector.append(Table[cord.x-1][cord.y-1]);
                //activeCordinates.append({cord.x-1, cord.y-1});
            }
        }
    }
}

bool Game::CollectWarriors(struct size cord, int player)
{
    if(player == 1)
    {
        if(cord.x+1 < size.x)
        {
            if(Table[cord.x+1][cord.y]->Player() != player && Table[cord.x+1][cord.y]->Player() != 2)
            {
                return true;
            }
        }

        if(cord.x+1 < size.x && cord.y+1 < size.y)
        {
            //qDebug() << size.y << " " << cord.y;
            if(Table[cord.x+1][cord.y+1]->Player() != player)
            {
                return true;
            }
        }

        if(cord.x+1 < size.x && cord.y-1 >= 0)
        {
            if(Table[cord.x+1][cord.y-1]->Player() != player)
            {
                return true;
            }
        }
    }
    else
    {
        //qDebug() << size.y << " " << cord.y;
        if(cord.x-1 >= 0)
        {
            if(Table[cord.x-1][cord.y]->Player() != player && Table[cord.x-1][cord.y]->Player() != 1)
            {
                return true;
            }
        }

        if(cord.x-1 >= 0 && cord.y+1 < size.y)
        {
            if(Table[cord.x-1][cord.y+1]->Player() != player)
            {
                return true;
            }
        }

        if(cord.x-1 >= 0 && cord.y-1 >= 0)
        {
            if(Table[cord.x-1][cord.y-1]->Player() != player)
            {
                return true;
            }
        }
    }

    return false;
}

void Game::UpdateWarriors()
{
    activeWarrior.clear();
    for(QVector<Warrior*> wvector : Table)
    {
        for(Warrior* w : wvector)
        {
            w->Active(false);
            if(w->Player() != 0 && (turn % 2)+1 == w->Player() && CollectWarriors(w->Cord(), w->Player()))
                activeWarrior.append(w);
        }
        qDebug() << activeWarrior.size();
    }

    for(Warrior* w : activeWarrior)
    {
        w->Active(true);
    }

}

bool Game::GameOver()
{
    for(Warrior* w : Table[0])
    {
        if(w->Player() == 2)
            return true;
    }
    for(Warrior* w : Table[size.x-1])
    {
        if(w->Player() == 1)
            return true;
    }
    int playerone = 0;
    int playertwo = 0;
    for(QVector<Warrior*> vector : Table)
    {
        for(Warrior* w : vector)
        {
            if(w->Player() == 0)
                ++playerone;
            else if(w->Player() == 2)
                ++playertwo;
        }
    }
    if(playerone == 0 || playertwo == 0)
        return true;

    return false;
}

void Game::NextTurn()
{
    if(GameOver())
    {
        class GameOver gameover;
        gameover.setModal(true);
        gameover.SetTurns(turn);
        //Ezt lehetne? connect(gameover.ui->NewGameButton, SIGNAL(clicked()), this, SLOT(on_actionNew_Game_triggered()))
        connect(&gameover, SIGNAL(NewGame()), this, SLOT(on_actionNew_Game_triggered()));
        connect(&gameover, SIGNAL(EndGame()), this, SLOT(on_actionExit_triggered()));
        gameover.exec();
        //delete  gameover;

    }
    else
    {
        ++turn;
        view->setText("<font-family: Arial><h2>Turn: "+QString::number(turn) +"</h2></font-family>");
        qDebug() << "Turn " << turn;
        UpdateWarriors();
    }
}


void Game::on_actionExit_triggered()
{
    emit EndGame();
}


void Game::on_actionNew_Game_triggered()
{
    //(QVector<Warrior*> row : Table) //Ez miért nem működik?
    //{
    //    for(Warrior* w : row)
    //    {
    //        delete w;
    //    }
    //}
    //delete view;
    //delete boardLayout;
    //delete mainLayout;
    //delete ui;

    emit StartNewGame(); //Hogyan írhatom meg, hogy mit csináljon az egyedi signalom?

}
