#include "parseQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    parseQt w;
    w.show();
    return a.exec();
}
