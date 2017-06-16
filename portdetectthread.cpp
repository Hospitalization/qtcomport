#include "portdetectthread.h"

PortDetectThread::PortDetectThread(QObject *parent) :
    QThread(parent)
{
    qDebug()<<"new";
}
PortDetectThread::~PortDetectThread(){
    qDebug()<<"end";
}

void PortDetectThread::run()
{
    while(1){
        msleep(500);
        emit detect();
    }
}
