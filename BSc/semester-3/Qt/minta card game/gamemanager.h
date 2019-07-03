#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QTimer>
#include "cardpack.h"
#include "player.h"

// játékkezelő típusa
class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager();
    ~GameManager();

    CardPack* currentPack() const { return _cardPacks[_currentCardPackIndex]; } // aktuális kártyacsomag lekérdezése
    Player* currentPlayer() const { return _players[_currentPlayerIndex]; } // aktuális játékos lekérdezése
    QVector<CardPack*> allCardPacks() const { return _cardPacks; } // összes kártyacsomag lekérdezése
    Player* firstPlayer() const { return _players[0]; } // első játékos lekérdezése
    Player* secondPlayer() const { return _players[1]; } // második játékos lekérdezése

public slots:
    void setPlayers(QString firstPlayer, QString secondPlayer); // játékosok beállítása
    void setCurrentPack(CardPack *pack) { _currentCardPackIndex = _cardPacks.indexOf(pack); newGame(0,0); } // kártyacsomag beállítása
    void newGame(int numRows, int numCols); // új játék indítása
    void selectCard(int cardId); // kártya kiválasztása

signals: // események
    void cardChanged(int index, const QPixmap& cardImage); // kártyacsere eseménye
    void statusChanged(QString status); // állapotváltás eseménye
    void gameOver(QString message); // játék végének eseménye

private slots:
    void hideCards(); // kártyák elrejtése

private:
    void loadPacks(const QString dirName); // kártyacsomagok betöltése adott könyvtárból
    void shuffleCards(); // kártyák átrendezése

    QVector<CardPack*> _cardPacks; // kártyacsomagok
    QVector<Player*> _players; // játékosok
    int _currentNumCols; // oszlopok száma
    int _currentNumRows; // sorok száma
    int _currentCardPackIndex; // kiválasztott kártyacsomag indexe
    int _currentPlayerIndex; // kiválasztott játékos indexe
    QTimer* _timer; // idõzítő a kártya visszaváltásához

    QVector<bool> _cardFound; // megtaláltuk-e a kártyákat
    int _foundCards; // megtalált kártyák  száma
    QVector<int> _cardIds; // kártyák azonosítói
    int _firstCardIndex; // első kiválasztott kártya indexe
    int _secondCardIndex; // második kiválasztott kártya indexe
};

#endif // GAMEMANAGER_H
