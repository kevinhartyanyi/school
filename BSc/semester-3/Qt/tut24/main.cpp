#include <QCoreApplication>
#include <QMap>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, QString> Employees;

    Employees.insert(1, "Bob");
    Employees.insert(2, "Chad");
    Employees.insert(3, "Mary");

    qDebug() << "3 = " << Employees.value(3);

    for(int i : Employees.keys())
    {
        qDebug() << Employees[i];
    }

    QHashIterator<int, QString> Iter(Employees);

    while (Iter.hasNext())
    {
        Iter.next();
        qDebug() << Iter.key() << " " << Iter.value();
    }

    return a.exec();
}
