#include "playerstatuswidget.h"
#include "ui_playerstatuswidget.h"

PlayerStatusWidget::PlayerStatusWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::PlayerStatusWidget)
{
    _ui->setupUi(this);
    _player = 0;
}

PlayerStatusWidget::~PlayerStatusWidget()
{
    delete _ui;
}

void PlayerStatusWidget::refreshPlayer()
{
    if (_player != 0) // ha van játékos, megjelenítjük az adatait
    {
        _ui->labelPlayerName->setText(_player->getName());
        _ui->labelPlayerHitsMisses->setText(QString::number(_player->getHits()) + "/" + QString::number(_player->getMisses()));
        _ui->labelPlayerGames->setText(QString::number(_player->getVictories()));
    }
}
