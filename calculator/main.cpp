#include "mainwindow.h"
#include <QApplication>
#include <homewindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homewindow w;
    w.show();
    return a.exec();
}
