#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H




#include <QObject>

class workerThread : public QObject
{
    Q_OBJECT
public:
    explicit workerThread(QObject *parent = nullptr);

public slots:
    void doWork();
};


#endif // WORKERTHREAD_H
