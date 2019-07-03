#include <QApplication>
#include "configurationdialog.h"

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("ELTE"); // alkalmazás tulajdosnágainak beállítása
    a.setApplicationName("CardGame");

    MainWindow m;
    m.show();
    
    return a.exec();
}
