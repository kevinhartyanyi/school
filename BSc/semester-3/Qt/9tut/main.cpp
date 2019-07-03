#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir Dir("C:/Users/Kevin/Desktop/semester 3/Qt/9tut");

    for(QFileInfo inf : Dir.entryInfoList())
    {
        qDebug() << inf.absoluteFilePath();
        if(inf.isDir()) qDebug() << "Dir: " << inf.absoluteFilePath();
        if(inf.isFile()) qDebug() << "File: " << inf.absoluteFilePath();
    }


    return a.exec();
}
