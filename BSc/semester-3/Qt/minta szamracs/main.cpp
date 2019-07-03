#include <QApplication>
#include "numbergridwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumberGridWidget w;
    w.show();
    
    return a.exec();
}
