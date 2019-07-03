#include "cardpack.h"

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QImageReader>

CardPack::CardPack(const QString& path)
{
    QFile nameFile(path + QDir::separator() + "name.txt"); // név betöltése
    if(!nameFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&nameFile);
    while (!in.atEnd()) {
        _name += in.readLine();
    }

    QStringList imageFilters; // szûrés a támogatott képformátumokra
    foreach (QByteArray format, QImageReader::supportedImageFormats())
        imageFilters += "*." + format;

    QStringList allFiles; // képfájlok betöltése
    foreach(QString file, QDir(path).entryList(imageFilters, QDir::Files))
        allFiles += QFileInfo(QDir(path),file).baseName();

    if(!allFiles.contains("back")) // ha nincs hátlap
    {
        return;
    }

    QString backFile = QDir(path).entryList(QStringList("back.*"), QDir::Files).at(0); // hátlap betöltése
    _back = QPixmap(path + QDir::separator() + backFile);

    foreach(QString file, QDir(path).entryList(imageFilters, QDir::Files)){
        if (!(file.startsWith("back.")))
        {
            _faces.append(QPixmap(path + QDir::separator() + file)); // előlapok betöltése
        }
    }
}

const QPixmap& CardPack::getFace(int index) const
{
    if (index >= 0 && index < _faces.size())
        return _faces[index];
    else
        return _back;
}

