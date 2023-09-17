#include "colors.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Colors w;
    w.setMaximumSize(488,390);
    w.setMinimumSize(488,390);
    w.show();
    return a.exec();
}
