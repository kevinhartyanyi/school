#ifndef CARDPACK_H
#define CARDPACK_H

#include <QString>
#include <QVector>
#include <QPixmap>

// kártyacsomag típusa
class CardPack
{

public:
    explicit CardPack(const QString &path);

    QString getName() const { return _name; } // kártyacsomag neve
    int cardCount() const { return _faces.size(); } // kártyák száma
    QVector<QPixmap> getFaces() const { return _faces; } // előlapok lekérdezése
    const QPixmap& getBack() const { return _back; } // hátlap lekérdezése
    const QPixmap& getFace(int index) const; // adott előlap lekérdezése

private:
    QString _name; // csomag neve
    QVector<QPixmap> _faces; // előlapok
    QPixmap _back; // hátlap
};

#endif // CARDPACK_H
