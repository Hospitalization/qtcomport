#include "portdetectthread.h"

PortDetectThread::PortDetectThread(QObject *parent) :
    QThread(parent)
{
    printf("Thread new\n");
}
PortDetectThread::~PortDetectThread(){
    printf("Thread end\n");
}

void PortDetectThread::run()
{
    while(1){
        msleep(500);
        emit detect();
    }
}
