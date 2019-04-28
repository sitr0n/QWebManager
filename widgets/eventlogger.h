#ifndef EVENTLOGGER_H
#define EVENTLOGGER_H

#include <QPlainTextEdit>
#include <QTimer>
#include <QTextStream>

class EventLogger : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit EventLogger(QTextStream &events, QWidget *parent = 0);
    void setSampleInterval(int interval);

private slots:
    void poll_stream();

private:
    QTimer ticker;
    QTextStream &stream;

    void print(QString line);
};

#endif // EVENTLOGGER_H
