#ifndef PORTDETECTTHREAD_H
#define PORTDETECTTHREAD_H
#include <QtCore>
#include <QThread>
#include <QDebug>

class PortDetectThread : public QThread
{
    Q_OBJECT
public:
    PortDetectThread(QObject *parent = 0);
    ~PortDetectThread();
private:
    void run();

signals:
    void detect(void);

public slots:

};

#endif // PORTDETECTTHREAD_H
