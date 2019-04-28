#ifndef QMAINFRAME_H
#define QMAINFRAME_H

#include <QMainWindow>
#include "toolframe.h"
#include <QMdiArea>

class QMainFrame : public QMainWindow
{
    Q_OBJECT
public:
    explicit QMainFrame(QWidget *parent = nullptr);

    void openApplication(QWidget *app);

signals:

public slots:

private:
    ToolFrame m_frame;
    QMdiArea m_mdiArea;
};

#endif // QMAINFRAME_H
