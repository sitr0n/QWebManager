#include "qwebmanager.h"
#include <QPushButton>
QWebManager::QWebManager(QWidget *parent) : QMainFrame(parent)
{
    setWindowTitle("Web Manager");

    openApplication(new QPushButton("yo", this));
}

void QWebManager::setHost(bool enable)
{

}
