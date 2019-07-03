#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QTimer>
#include <QIcon>
#include <QPixmap>

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager(int length);
    ~GameManager();
    bool canPlay() const { return _timer->isActive() && !_hasShownImage; } // lehet-e lépni a játékban
    const QPixmap& getImage(int nr) const; // kép lekérdezése

public slots:
    void newGame(int size); // új játék
    void pauseGame(); // játék szüneteltetése
    void stepGame(int nr); // lépés a játékban

private slots:
    void timerTimeOut(); // időzítő eseménykezelője

signals:
    void messageChanged(QString message); // üzenetváltás eseménye
    void imageChanged(const QPixmap& image); // képváltás eseménye
    void gameOver(int goodGuess, int badGuess); // játék vége eseménye

private:
    int _number; // képek száma
    int _gameTime; // játékidő
    int _previewTime; // kezdeti idő (az előnézethez)
    bool _hasShownImage; // kattintottunk-e már egy képre
    int _goodGuessCount; // jó találatok száma
    int _badGuessCount; // rossz találatok száma
    const int _gameLength; // játék hossza

    QTimer* _timer; // idõzítő
    QVector<QPixmap> _images; // képek elérési útvonalai
    int _currentImageIndex; // aktuális kép elérési útvonala
};

#endif // GAMEMANAGER_H
