#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QMessageBox>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::GameWidget)
{
    _ui->setupUi(this);

    _manager = new GameManager(); // létrehozzuk a játékkezelő

    _configurationDialog = 0;
    _isConfigured = false; // kezdetben nincs konfigurálva a játék

    connect(_manager, SIGNAL(statusChanged(QString)), this, SIGNAL(statusChanged(QString)));
    // a logikai réteg eseménye egy újabb eseményt vált ki

    connect(_manager, SIGNAL(statusChanged(QString)), _ui->firstPlayerStatus, SLOT(refreshPlayer()));
    connect(_manager, SIGNAL(statusChanged(QString)), _ui->secondPlayerStatus, SLOT(refreshPlayer()));
    // a felhasználó adatainak frissítése

    connect(_manager, SIGNAL(cardChanged(int,QPixmap)), this, SLOT(gameManager_CardChanged(int, QPixmap)));
    // kártya felületének váltása

    connect(_manager, SIGNAL(gameOver(QString)), this, SLOT(gameManager_GameOver(QString)));
    // játék vége
}

GameWidget::~GameWidget()
{
    foreach(ImageButton* button, _buttons)
        delete button;

    delete _ui;
    delete _configurationDialog;
    delete _manager;
}

void GameWidget::newGame()
{
    if (!_isConfigured) // ha nincsenek beállítás, megjelenítjük a beállító ablakot
        configureGame();

    if (_isConfigured) // ha már vannak beállítások
    {
        int rows = _configurationDialog->numberOfRows();
        int cols = _configurationDialog->numberOfColumns();

        _manager->newGame(rows, cols); // létrehozzuk az új játékot

        foreach(ImageButton* button, _buttons) // régi felület törlése
        {
            _ui->gridLayout->removeWidget(button);
            delete button;
        }
        _buttons.clear();
        _ui->gridLayout->removeItem(_ui->verticalSpacer);

        for (int i = 0; i < rows; i++) // új felület létrehozása
            for (int j = 0; j < cols; j++)
        {
            ImageButton* button = new ImageButton();
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setPixmap(_manager->currentPack()->getBack()); // kezdetben mindenhol a hátlapot jelenítjük meg
            connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

            _buttons.append(button);
            _ui->gridLayout->addWidget(button, i, j);
        }
    }
    else
        // figyelmeztetjük, hogy nincsenek beállítások
        QMessageBox::critical(this,
                              trUtf8("Kártyajáték - Figyelmeztetés"),
                              trUtf8("A beállítások nincsenek elmentve,\nígy nem lehet új játékot kezdeni!"));
}

void GameWidget::configureGame()
{
    if (_configurationDialog == 0)
        _configurationDialog = new ConfigurationDialog(_manager->allCardPacks(), this);

    // megjelenítjük a beállító dialógust
    if (_configurationDialog->exec() == QDialog::Accepted) // amennyiben elfogadjuk
    {
        _manager->setPlayers(_configurationDialog->firstPlayerName(), _configurationDialog->secondPlayerName());
        _manager->setCurrentPack(_configurationDialog->selectedCardPack());
        // beállítjuk a játékosokat és a kiválasztott csomagot

        _ui->firstPlayerStatus->setPlayer(_manager->firstPlayer()); // visszaírjuk a játékosok adatait
        _ui->secondPlayerStatus->setPlayer(_manager->secondPlayer());

        _isConfigured = true;
    }
}

void GameWidget::buttonClicked()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    _manager->selectCard(_ui->gridLayout->indexOf(senderButton)); // a kártya kiválasztása a modellben
}

void GameWidget::gameManager_CardChanged(int index, const QPixmap& pixmap)
{
    if (index >= 0 && index < _buttons.size())
        _buttons[index]->setPixmap(pixmap); // kép beállítása a gombra
}

void GameWidget::gameManager_GameOver(QString message)
{
    QMessageBox::information(this, trUtf8("Kártyajáték - Kör vége"),
                             trUtf8("Vége a körnek!\n%1\nIndul a következő kör!").arg(message));
    newGame();
}

