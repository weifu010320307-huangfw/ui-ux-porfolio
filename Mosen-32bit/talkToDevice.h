#ifndef TALKTODEVICE_H
#define TALKTODEVICE_H

#include "hidapi.h"
#include "qvector.h"


class TalkToDevice
{

public:

    static unsigned long long sumData(unsigned char data[], int datalength);

    bool findDevice(bool showMessage = true, unsigned short targetDeviceVID = 0x3206, unsigned short targetDevicePID = 0x4000);
    void readWriteDevice(QVector<unsigned char>& dataSendBuffer, QVector<unsigned char>& dataReadBackBuffe);
    void bbhwrite_cmddata(uint8_t cmd,uint8_t* data,int length);

    TalkToDevice()
    {
        hid_init();
    }

    ~TalkToDevice()
    {
        hid_exit();
    }


    //QVector<unsigned char> m_dataReadBackBuffer;

private:

    hid_device* m_bbhPhoneDevice;
};





#endif // TALKTODEVICE_H
