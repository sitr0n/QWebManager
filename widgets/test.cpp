#include "test.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QDebug>

Test::Test(QWidget *parent) :
    QApplicationViewer(parent),
    app(new TestApplication()),
    settings(new TestSettings())
{
    setWindowTitle("Test");
    putContent(app);
    putSettings(settings);
}


TestSettings::TestSettings(QWidget *parent) :
    QWidget(parent),
    test_edit(new QLineEdit(this)),
    test_spin(new QSpinBox(this))
{
    auto layout = new QFormLayout(this);
    layout->addRow(tr("&Edit"), test_edit);
    layout->addRow(tr("&Spin"), test_spin);
}

TestApplication::TestApplication(QWidget *parent) :
    QWidget(parent),
    test_edit(new QLineEdit(this)),
    test_button(new QPushButton(this))
{
    setLayout(new QVBoxLayout(this));
    layout()->addWidget(test_edit);
    layout()->addWidget(test_button);
}
