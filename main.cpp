#include "widgets/test.h"
#include "widgets/qwebmanager.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebManager w;
    w.showMaximized();
    //w.showFullScreen();
    //w.show();

    return a.exec();
}
