#include "framainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fraMainWindow w;

    w.show();

    //a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    int result = a.exec();


    return result;
}
