#include "filecontroller.h"
#include <QDebug>

FileController::FileController(QObject* parent) : QObject (parent)
{

}

void FileController::save(QString savename, int life1, QString player1,
                          QString direct1, Cord cord1, int max1,
                          int life2, QString player2,
                          QString direct2, Cord cord2, int max2)
{
    QFile file(savename+".txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;
        qDebug() << "Save For Real";
         QTextStream out(&file);
         out << life1 << " " << player1 << " " << direct1 << " " << cord1.x << " " << cord1.y << " " << max1 << "\n";
         out << life2 << " " << player2 << " " << direct2 << " " << cord2.x << " " << cord2.y << " " << max2 << "\n";

}

FileController::~FileController()
{

}

void FileController::load(QString loadname)
{
    error = false;
    QFile file(loadname+".txt");
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         {
             qDebug() << "No File";
             error = true;
             return;
         }
        qDebug() << "Load For Real";
        QTextStream in(&file);

         player1 = new QString(in.readLine());
         player2 = new QString(in.readLine());


         qDebug() << *player1;
}
