#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Write(QString Filename)
{
    QFile myFile(Filename);

    if(!myFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Cant open file for writing";
        return;
    }

    QTextStream out(&myFile);
    out << "Hello world";
    myFile.flush();
    myFile.close();
}
void Read(QString Filename)
{
    QFile myFile(Filename);

    if(!myFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Cant open file for reading";
        return;
    }

    QTextStream in(&myFile);
    QString myText = in.readAll();

    qDebug() << myText;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QString myFile = "C:/Users/Kevin/Desktop/semester 3/Qt/10tut/cute.txt";

    //Write(myFile);
    //Read(myFile);

    Read(":/MyFiles/10tut.pro");



    return a.exec();
}
