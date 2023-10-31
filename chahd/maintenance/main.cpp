#include "maintenaceform.h"
#include "connection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maintenaceform w;
    connection c;
    c.createconnect();
    w.show();
    return a.exec();
}
