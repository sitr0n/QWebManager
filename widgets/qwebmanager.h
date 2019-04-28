#ifndef QWEBMANAGER_H
#define QWEBMANAGER_H

#include <QWidget>
#include "qmainframe.h"

class WebManagerSettings;
class QWebManager : public QMainFrame
{
    Q_OBJECT
public:
    explicit QWebManager(QWidget *parent = nullptr);

    void setHost(bool enable);

signals:

public slots:
};

class WebManagerSettings : public QWidget
{
    Q_OBJECT
public:
    explicit WebManagerSettings(QWidget *parent = nullptr);
};

#endif // QWEBMANAGER_H
