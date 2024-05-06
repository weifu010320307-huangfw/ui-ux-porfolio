

#include "workerThread.h"


#include <QDebug>
//#include <unistd.h>


workerThread::workerThread(QObject *parent) : QObject(parent)
{

}

void workerThread::doWork()
{
    while (true)
    {
        qDebug()<<"workerThread running...";
        //sleep(2);
    }
}
