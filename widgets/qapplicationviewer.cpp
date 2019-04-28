#include "qapplicationviewer.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QDebug>

QApplicationViewer::QApplicationViewer(QWidget *parent) :
    QMdiSubWindow(parent)
{
    setWindowIcon(QIcon("noicon"));
    frame.useTimer();
    frame.useEventlog();
    setWidget(&frame);

    connect(&frame, SIGNAL(resize()), this, SLOT(resize()));
}

void QApplicationViewer::putContent(QWidget *w)
{
    frame.putContent(w);
}

void QApplicationViewer::putSettings(QWidget *w)
{
    frame.putSettings(w, context());
}

void QApplicationViewer::resize()
{
    if (!(QWidget::isMaximized() || QWidget::isFullScreen())) {
        QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
        QWidget::resize(sizeHint());
    }
}

QString QApplicationViewer::context()
{
    QRegExp space("\\s");
    return QString(windowTitle().simplified().remove(space));
}
