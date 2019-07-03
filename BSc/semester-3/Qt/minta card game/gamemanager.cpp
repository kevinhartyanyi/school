#include "gamemanager.h"

#include <QDir>
#include <QFileInfo>
#include <QApplication>
#include <QDateTime>

GameManager::GameManager()
{
    loadPacks(QApplication::applicationDirPath() + QDir::separator() + "packs");
    // az alkalmazás könyvtárából kiindulva kezdünk betölteni

    _currentPlayerIndex = 0;

    _timer = new QTimer(this);
    _timer->setInterval(1000); // idõzítő a kártyák visszaforgatásához
    connect(_timer, SIGNAL(timeout()), this, SLOT(hideCards()));
}

GameManager::~GameManager()
{
    foreach(CardPack* pack, _cardPacks)
        delete pack;
    foreach(Player* player, _players)
        delete player;
}

void GameManager::newGame(int numRows, int numCols)
{
    _timer->stop();

    _cardIds.clear(); // régi értékek törlése
    _cardFound.clear();

    qsrand(QDateTime::currentDateTime().time().msec());
    if (numRows * numCols > 0 && _players.size() == 2)
    {
        // új értékek felvétele
        int cardId;
        for (int i = 0; i < numRows * numCols / 2; i++)
        {
            do{
                cardId = qrand() % _cardPacks[_currentCardPackIndex]->cardCount(); // a kártyákat véletlenszerűen választjuk
            } while (_cardIds.contains(cardId)); // úgy, hogy ne ismétlődjenek

            _cardIds.append(cardId);
            _cardIds.append(cardId);
            _cardFound.append(false);
            _cardFound.append(false);
        }
        _firstCardIndex = _secondCardIndex = -1;
        _foundCards = 0;

        _players[0]->newGame();
        _players[1]->newGame();

        shuffleCards();

        statusChanged(trUtf8("Új játék elindítva, ") + _players[_currentPlayerIndex]->getName() + trUtf8(" következik."));
    }
}
void GameManager::selectCard(int index)
{
    if (!_timer->isActive() && index < _cardFound.size() && index >= 0 && !_cardFound[index])
        // ha megfelelő az index, nem már megtalált kártyát választottunk ki, és nem fut az idõzítő
    {
        if (_firstCardIndex == -1) // ha az első kártyát jelöltük ki
        {
            _firstCardIndex = index;
            cardChanged(index, _cardPacks[_currentCardPackIndex]->getFace(_cardIds[_firstCardIndex]));
            // megjelenítjük a képét
        }
        else // ha a második kártyát jelöltük ki
        {
            if (_firstCardIndex != index) // ha nem az elõzõ kártyát választottuk ki
            {
                _secondCardIndex = index;

                cardChanged(index, _cardPacks[_currentCardPackIndex]->getFace(_cardIds[_secondCardIndex]));

                if (_cardIds[_secondCardIndex] == _cardIds[_firstCardIndex]) // ha megtaláltuk a párt
                {
                    _cardFound[_firstCardIndex] = _cardFound[_secondCardIndex] = true; // elmentjük, hogy megtaláltuk a kártyát
                    _foundCards++; // újabb kártyát találtunk meg

                    _players[_currentPlayerIndex]->addHit(); // felvesszük a találatot
                    _firstCardIndex = _secondCardIndex = -1;

                    if (_foundCards == _cardIds.size() / 2) // ha megtaláltuk az összes kártyát
                    {
                        statusChanged(trUtf8("Pár megtalálva! Játék vége."));
                        if (_players[0]->getHits() > _players[1]->getHits()) // megnézzük, melyik játékos nyerte a kört
                        {
                            _players[0]->addVictory();
                            gameOver(trUtf8("A játékot %1 nyerte.").arg(_players[0]->getName()));
                        }
                        else if (_players[0]->getHits() < _players[1]->getHits())
                        {
                            _players[1]->addVictory();
                            gameOver(trUtf8("A játékot %1 nyerte.").arg(_players[1]->getName()));
                        }
                        else
                        {
                            gameOver(trUtf8("A játék döntetlen lett."));
                        }
                    }
                    else
                    {
                        statusChanged(trUtf8("Pár megtalálva! Ismét ") + _players[_currentPlayerIndex]->getName() + trUtf8(" következik."));
                    }
                }
                else
                {
                    _players[_currentPlayerIndex]->addMiss(); // felvesszük a tévedést
                    _currentPlayerIndex = (_currentPlayerIndex + 1) % 2;
                    statusChanged(trUtf8("Nem párok! ") + _players[_currentPlayerIndex]->getName() + trUtf8(" következik."));
                    _timer->start();
                }
            }
        }
    }
}

void GameManager::setPlayers(QString firstPlayer, QString secondPlayer)
{    
    foreach(Player* player, _players) // töröljük a régi játékosokat
        delete player;

    _players.clear();
    _players.append(new Player(firstPlayer)); // felvesszük a két játékost
    _players.append(new Player(secondPlayer));
    newGame(0,0); // egy üres játékot indítunk
    statusChanged(trUtf8("Új játékosok beállítva."));
}

void GameManager::hideCards()
{
    if (_firstCardIndex > -1 && _secondCardIndex > -1) // ha vannak felfordítva kártyák
    {
        cardChanged(_firstCardIndex, _cardPacks[_currentCardPackIndex]->getBack()); // visszafordítjuk őket
        cardChanged(_secondCardIndex, _cardPacks[_currentCardPackIndex]->getBack());
        _firstCardIndex = _secondCardIndex = -1;
    }
    _timer->stop(); // idõzítõ leállítása
}

void GameManager::loadPacks(const QString dirName)
{
    foreach(CardPack* pack, _cardPacks) // régi kártyák törlése, amennyiben voltak
        delete pack;
    _cardPacks.clear();

    _cardPacks.append(new CardPack(":/packs/default")); // betöltjük az erőforrásban eltárolt kártyákat is

    QDir dir(dirName); // betöltjük a könyvárban lévõ alkönyvtárakat
    dir.setFilter(QDir::Dirs);
    foreach(QString entry, dir.entryList())
    {
        _cardPacks.append(new CardPack(dirName + QDir::separator() + entry)); // minden alkönyvtár egy kártyacsomagot tartalmaz
    }
}

void GameManager::shuffleCards()
{
    qsrand(QDateTime::currentDateTime().time().msec());
    for (int i = 0; i < _cardIds.size() * 10; i++)
    {
        int ind1 = qrand() % _cardIds.size(); // vélletlenszerűen kiválasztunk két kártyát
        int ind2 = qrand() % _cardIds.size();
        int tmp = _cardIds[ind1]; // és megcseréljük őket
        _cardIds[ind1] = _cardIds[ind2];
        _cardIds[ind2] = tmp;
    }
}
