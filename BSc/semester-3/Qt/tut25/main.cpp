#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList List;

    List.append("Hello");

    QString Line = "a,b,c,d,e,f,g";

    List = Line.split(",");
    List.replaceInStrings("b","batman");

    QString After = List.join(",");
    qDebug() << After;

    for(QString item : List)
    {
        qDebug() << item;
    }
    return a.exec();
}
