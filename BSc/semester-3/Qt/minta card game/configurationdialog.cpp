#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <qmath.h>
#include <QMessageBox>
#include <QSettings>

ConfigurationDialog::ConfigurationDialog(QVector<CardPack*> cps, QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::ConfigurationDialog), _cardPacks(cps)
{
    _ui->setupUi(this);
    setFixedSize(400,530);
    setWindowTitle(trUtf8("Kártyajáték - Beállítások"));

    foreach(CardPack* pack, _cardPacks)
    {
        _ui->comboCardPack->addItem(pack->getName());
    }

    connect(_ui->comboCardPack, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCardPack(int)));
    connect(_ui->spinRows, SIGNAL(valueChanged(int)), this, SLOT(setMaxCols()));
    connect(_ui->spinCols, SIGNAL(valueChanged(int)), this, SLOT(setMaxRows()));

    connect(_ui->buttonOk, SIGNAL(clicked()), this, SLOT(checkValues()));
    connect(_ui->buttonCancel, SIGNAL(clicked()), this, SLOT(reject()));

    if (_cardPacks.size() > 0)
    {
        _ui->comboCardPack->setCurrentIndex(0);
        changeCardPack(0);
    }

    loadSettings();
}

ConfigurationDialog::~ConfigurationDialog()
{
    saveSettings();

    delete _ui;
}

QString ConfigurationDialog::firstPlayerName() { return _ui->lineFirstPlayerName->text(); }
QString ConfigurationDialog::secondPlayerName() { return _ui->lineSecondPlayerName->text(); }
int ConfigurationDialog::numberOfRows() { return _ui->spinRows->value(); }
int ConfigurationDialog::numberOfColumns() { return _ui->spinCols->value(); }

void ConfigurationDialog::setFirstPlayerName(QString name) { _ui->lineFirstPlayerName->setText(name); }
void ConfigurationDialog::setSecondPlayerName(QString name) { _ui->lineSecondPlayerName->setText(name); }
void ConfigurationDialog::setNumberOfRows(int nr) { _ui->spinRows->setValue(nr); }
void ConfigurationDialog::setNumberOfColumns(int nr) { _ui->spinCols->setValue(nr); }

CardPack* ConfigurationDialog::selectedCardPack() { return _cardPacks[_ui->comboCardPack->currentIndex()]; }

void ConfigurationDialog::checkValues()
{
    if (_ui->lineFirstPlayerName->text().isEmpty() ||
        _ui->lineSecondPlayerName->text().isEmpty())
    {
        QMessageBox::critical(this, trUtf8("Kártyajáték - Beállítások"), trUtf8("A játékosok nevei nincsenek kitöltve!"));
    }
    else if (_ui->spinCols->value() * _ui->spinRows->value() % 2 != 0)
    {
        QMessageBox::critical(this, trUtf8("Kártyajáték - Beállítások"), trUtf8("A kártyák összszámának párosnak kell lennie!"));
    }
    else if (_ui->spinCols->value() * _ui->spinRows->value() < 4)
    {
        QMessageBox::critical(this, trUtf8("Kártyajáték - Beállítások"), trUtf8("Legalább 4 kártyának kell lennie!"));
    }
    else
        accept();
}

void ConfigurationDialog::changeCardPack(int index)
{
    _ui->labelCardCount->setText(QString::number(_cardPacks[index]->cardCount()));

    for (int i = 0; i < _cardLabels.size(); i++) // régi kártyák törlése
    {
        _ui->cardLayout->removeWidget(_cardLabels[i]);
        delete _cardLabels[i];
    }
    _cardLabels.clear();

    int cols = sqrt(_cardPacks[index]->cardCount());

    for (int j = 0; j < _cardPacks[index]->cardCount(); j++) // új kártyák beállítása
    {
        QLabel* label = new QLabel();
        label->setPixmap(_cardPacks[index]->getFace(j).scaled(340 / cols, 340 / cols));
        _ui->cardLayout->addWidget(label, j / cols, j % cols);

        _cardLabels.append(label);
    }

    _ui->spinCols->setMinimum(1);
    _ui->spinRows->setMinimum(1);
    _ui->spinCols->setMaximum(_cardPacks[index]->cardCount());
    _ui->spinRows->setMaximum(_cardPacks[index]->cardCount());
}

void ConfigurationDialog::setMaxRows()
{
    _ui->spinRows->setMaximum(_cardPacks[_ui->comboCardPack->currentIndex()]->cardCount() / _ui->spinCols->value() * 2);
}

void ConfigurationDialog::setMaxCols()
{
    _ui->spinCols->setMaximum(_cardPacks[_ui->comboCardPack->currentIndex()]->cardCount() / _ui->spinRows->value() * 2);
}


void ConfigurationDialog::loadSettings()
{
    QSettings settings("ELTE", "CardGame");
    // létrehozzuk a beállításokat (a paraméterek megadása felesleges, mert az alkalmazásba ezeket már beállítátottuk)
    if (settings.contains("selectedCardPackIndex"))
    {
        // ha korábban elmentettük a beállításokat, akkor betöltjük őket
        _ui->comboCardPack->setCurrentIndex(settings.value("selectedCardPackIndex").toInt());
        setFirstPlayerName(settings.value("firstPlayerName").toString());
        setSecondPlayerName(settings.value("secondPlayerName").toString());
        setNumberOfRows(settings.value("numberOfRows").toInt());
        setNumberOfColumns(settings.value("numberOfColumns").toInt());
        // az érték QVariant típusú, ezért konvertáljuk
    }
}

void ConfigurationDialog::saveSettings()
{
    QSettings settings("ELTE", "CardGame");

    settings.setValue("selectedCardPackIndex", _ui->comboCardPack->currentIndex());
    settings.setValue("firstPlayerName", firstPlayerName());
    settings.setValue("secondPlayerName", secondPlayerName());
    settings.setValue("numberOfRows", numberOfRows());
    settings.setValue("numberOfColumns", numberOfColumns());
    // elmentjük az értékeket
}


