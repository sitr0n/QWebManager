#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QMdiSubWindow>
#include "qapplicationviewer.h"

class TestApplication;
class TestSettings;

// QBrowser
class Test : public QApplicationViewer
{
    Q_OBJECT
public:
    explicit Test(QWidget *parent = nullptr);

signals:

public slots:


private:
    TestApplication *app;
    TestSettings *settings;

};

class TestApplication : public QWidget
{
    Q_OBJECT
public:
    explicit TestApplication(QWidget *parent = 0);

private:
    QLineEdit *test_edit;
    QPushButton *test_button;
};

class TestSettings : public QWidget
{
    Q_OBJECT
public:
    explicit TestSettings(QWidget *parent = 0);

private:
    QLineEdit *test_edit;
    QSpinBox *test_spin;
};

#endif // TEST_H
