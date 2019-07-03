#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString m = "hello world";

    qDebug () << m;
    return a.exec();
}
