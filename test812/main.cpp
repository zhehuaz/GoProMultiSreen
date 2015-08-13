#include "framainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fraMainWindow w;
    w.show();

    return a.exec();
}
