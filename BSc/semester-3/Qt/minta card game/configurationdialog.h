#ifndef CONFIGURATIONWIDGET_H
#define CONFIGURATIONWIDGET_H

#include <QDialog>
#include <QLabel>
#include "cardpack.h"

namespace Ui {
    class ConfigurationDialog;
}

// játékbeállító dialógusablak típusa
class ConfigurationDialog : public QDialog
{    
    Q_OBJECT
public:
    explicit ConfigurationDialog(QVector<CardPack*> cps, QWidget *parent = 0);
    ~ConfigurationDialog();

    QString firstPlayerName(); // első játékos neve
    QString secondPlayerName(); // második játékos neve
    int numberOfRows(); // sorok száma
    int numberOfColumns(); // oszlopok száma
    CardPack* selectedCardPack(); // kiválasztott kártyacsomag

public slots:
    void setFirstPlayerName(QString name);
    void setSecondPlayerName(QString name);
    void setNumberOfRows(int nr);
    void setNumberOfColumns(int nr);

private slots:
    void checkValues(); // értékek ellenőrzése bezárás előtt
    void changeCardPack(int index); // kártyacsomag váltása
    void setMaxRows(); // maximális sorszám beállítás
    void setMaxCols(); // maximális oszlopszám beállítása

private:
    void loadSettings(); // beállítások betöltése
    void saveSettings(); // beállítások mentése

    Ui::ConfigurationDialog *_ui; // tervező felület
    QVector<CardPack*> _cardPacks; // kártyacsomagok
    QVector<QLabel*> _cardLabels; // kártyákat megjelenítő címkék
};

#endif // CONFIGURATIONWIDGET_H
