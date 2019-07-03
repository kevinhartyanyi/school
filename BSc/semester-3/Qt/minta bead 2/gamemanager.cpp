#include "gamemanager.h"

#include <QTime>

GameManager::GameManager(int length) : _gameLength(length)
{
    _timer = new QTimer();
    _timer->setInterval(1000);

    qsrand(QTime::currentTime().msec());

    connect(_timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

GameManager::~GameManager()
{
    _timer->stop();
    delete _timer;
}

void GameManager::newGame(int size)
{
    if (_timer->isActive())
        _timer->stop(); // időzítő leáll

    _number = _previewTime = size;
    _gameTime = _goodGuessCount = _badGuessCount = 0;
    _hasShownImage = false;
    _currentImageIndex = 0;
    _images.clear();

    QVector<int> numbers(_number);

    for (int i = 0; i < _number; i++) // a számokat sorban legeneráljuk
    {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < 100; i++) // majd permutáljuk õket véletlenszerûen
    {
        int a = qrand() % numbers.size();
        int b = qrand() % numbers.size();

        int temp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = temp;
    } // így minden képből egy lesz

    for (int i = 0; i < _number; i++)
    {
        _images.append(QPixmap(":/images/" + QString::number(numbers[i]) + ".png")); // beállítjuk az elérési útvonalukat
    }

    _timer->start(); // időzítő indul
}

void GameManager::pauseGame()
{
    if (_previewTime > 0 || _gameTime >= _gameLength)
        return;

    if (_timer->isActive()) // ha megy az időzítő
    {
        messageChanged(trUtf8("Pihi van."));
        _timer->stop(); // leállítjuk
    }
    else
        _timer->start(); // különben elindít
}

void GameManager::stepGame(int nr)
{
   if (_timer->isActive() && !_hasShownImage && nr >= 0 && nr < _images.size())
   {
       _hasShownImage = true;
       if (nr == _currentImageIndex) // ha jó képre kattintott
           _goodGuessCount++;
       else
           _badGuessCount++;
   }
}

const QPixmap& GameManager::getImage(int nr) const
{
    if ((_previewTime > 0 || !_hasShownImage) && nr >= 0 && nr < _images.size()) // előnézet van
    {
        return _images[nr];
    }
    else
    {
        return _images[0];
    }
}

void GameManager::timerTimeOut()
{
    if (_gameTime == _gameLength) // játék vége
    {
        _timer->stop();
        messageChanged(trUtf8("Játék vége! Kezdhetsz újat."));
        emit gameOver(_goodGuessCount, _badGuessCount);
    }
    else
    {
        if (_previewTime > 0)
        {
            _previewTime--; // előnézetnél csak csökkentjük az időt
            messageChanged(trUtf8("Előnézet még ") + QString::number(_previewTime) + trUtf8(" másodpercig."));
        }
        else
        {
            messageChanged(trUtf8("Még ") + QString::number(_gameLength - _gameTime) + trUtf8(" másodperc a játékból."));
            if (_gameTime % 2 == 0) // két másodpercenként váltjuk a képet
            {
                _hasShownImage = false;
                _currentImageIndex = qrand() % _number;

                emit imageChanged(_images[_currentImageIndex]);
            }
            _gameTime++; // növeljük a játékidőt
        }
    }
}
