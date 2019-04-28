#include "eventlogger.h"
#include <QScrollBar>
#include <QTime>
#define MIN_WIDTH 300
#define MIN_HEIGHT 50
EventLogger::EventLogger(QTextStream &events, QWidget *parent) :
    QPlainTextEdit(parent),
    stream(events)
{
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    setMinimumSize(QSize(MIN_WIDTH, MIN_HEIGHT));
    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
    setReadOnly(true);
    insertPlainText(QString("[%1] Application opened").arg(QTime::currentTime().toString(QString("hh:mm:ss"))));

    connect(&ticker, SIGNAL(timeout()), this, SLOT(poll_stream()));
    setSampleInterval(1000);
    ticker.start();
}

void EventLogger::setSampleInterval(int interval)
{
    ticker.setInterval(interval);
}

void EventLogger::print(QString line)
{
    QTextCursor cursor = textCursor();
    cursor.setPosition(this->document()->characterCount() - 1);
    setTextCursor(cursor);
    insertPlainText(QString("\n[%1] %2").arg(QTime::currentTime().toString(QString("hh:mm:ss"))).arg(line));

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void EventLogger::poll_stream()
{
    QString line = stream.readLine();
    if (!line.isNull()) {
        print(line);
    }
}
