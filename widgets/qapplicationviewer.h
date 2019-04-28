#ifndef QAPPLICATIONVIEWER_H
#define QAPPLICATIONVIEWER_H

#include "toolframe.h"
#include <QMdiSubWindow>

class QApplicationViewer : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit QApplicationViewer(QWidget *parent = nullptr);
    void putContent(QWidget *w); // Protected in the future?
protected:
    //void putContent(QWidget *w);
    void putSettings(QWidget *w);

signals:

public slots:

private slots:
    void resize();

private:
    ToolFrame frame; // Make pointer, if program crashes.. for some reason....
    QString context();
};


#endif // QAPPLICATIONVIEWER_H
