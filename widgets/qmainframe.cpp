#include "qmainframe.h"
#include "qapplicationviewer.h"
#include <QDebug>

QMainFrame::QMainFrame(QWidget *parent) : QMainWindow(parent)
{
    m_frame.useTimer();
    m_frame.useEventlog();
    m_frame.putContent(&m_mdiArea);
    m_mdiArea.setMinimumSize(QSize(200, 200));
    m_mdiArea.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    setCentralWidget(&m_frame);
}

void QMainFrame::openApplication(QWidget *app)
{
    // Handle ownership of the frame!!!
    QApplicationViewer *window = new QApplicationViewer(this);
    window->putContent(app);
    m_mdiArea.addSubWindow(window);
    app->show();
}
