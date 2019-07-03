#ifndef PLAYERSTATUSWIDGET_H
#define PLAYERSTATUSWIDGET_H

#include <QWidget>

#include "player.h"

namespace Ui {
    class PlayerStatusWidget;
}

// játékos adatait megjelenítő vezérlő
class PlayerStatusWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PlayerStatusWidget(QWidget *parent = 0);
    ~PlayerStatusWidget();

public slots:
    void setPlayer(Player* p) // játékos beállítása
    {
        _player = p;
        refreshPlayer();
    }
    void refreshPlayer(); // játékos adatainak frissítése

private:
    Ui::PlayerStatusWidget *_ui;
    Player* _player; // játékos
};

#endif // PLAYERSTATUSWIDGET_H
