#include "mainwidget.h"
#include "startsoftwarewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //StartSoftwareWidget s;
    //s.show();
    MainWidget w;
    w.show();
    return a.exec();
}
