#include "mainwindow.h"

#include <QApplication>
#include "talkToDevice.h"


#include "qdebug.h"



int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(bbh);






    QApplication a(argc, argv);
    a.setStyle("fusion");



    MainWindow w;






    //w.setWindowFlags(Qt::Dialog);
    w.setWindowFlags(Qt::FramelessWindowHint);

    w.show();

//    TalkToDevice bbhDev;
//    bbhDev.findDevice();
    //device path =  "\\\\?\\hid#vid_3206&pid_4000&mi_03&col01#7&ce31051&0&0000#{4d1e55b2-f16f-11cf-88cb-001111000030}"

    TalkToDevice devCommunication;


    bool bDeviceConnect = devCommunication.findDevice(false);
    w.updateDeviceStatus(bDeviceConnect);





    return a.exec();
}
