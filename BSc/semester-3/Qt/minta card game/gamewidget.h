#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "imagebutton.h"
#include "gamemanager.h"
#include "configurationdialog.h"

namespace Ui {
    class GameWidget;
}

// játékfelületet megjelenítő vezérlő típusa
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

signals:
    void statusChanged(QString status); // játékvállapot változásának eseménye
public slots:
    void newGame(); // új játék indítása
    void configureGame(); // játék konfigurálása

private slots:
    void buttonClicked(); // gombra kattintás
    void gameManager_CardChanged(int index, const QPixmap& pixmap); // kártya képcseréje
    void gameManager_GameOver(QString message); // játék vége

private:
    Ui::GameWidget *_ui;

    GameManager* _manager; // játékmenedzser
    QVector<ImageButton*> _buttons; // kártyákat megjelenítő gombok
    bool _isConfigured; // volt-e már konfigurálás
    ConfigurationDialog* _configurationDialog; // konfigurációs dialógusablak
};

#endif // GAMEWIDGET_H
