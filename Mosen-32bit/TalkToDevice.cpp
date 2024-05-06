

#include "talkToDevice.h"
#include "qstring.h"
#include "qdebug.h"
#include "qvector.h"
#include "qmessagebox.h"


unsigned long long TalkToDevice::sumData(unsigned char data[], int datalength)
{

    unsigned long long sum = 0;
    for(int i = 0; i < datalength; i++)
    {

        sum += data[i];
    }

    return sum;
}


bool TalkToDevice::findDevice(bool showMessage, unsigned short targetDeviceVID, unsigned short targetDevicePID)
{

    // find target device
    hid_device_info* targetDevInfo = hid_enumerate(targetDeviceVID, targetDevicePID);


    bool bConnectDevice = false;
    if(targetDevInfo)
    {
        QString strDevName(targetDevInfo->path);


        qDebug() << "device path = " << strDevName;
    }
    else
    {
        QString strMsg = "device is not connected..";
        qDebug() << strMsg;

        if(showMessage)
        {
            QMessageBox::information(nullptr, "Info", strMsg);
        }

        return bConnectDevice;
    }




    // open the target device
    hid_device* bbhPhoneDevice = hid_open(targetDeviceVID, targetDevicePID, nullptr);


    if(bbhPhoneDevice)
    {

        m_bbhPhoneDevice = bbhPhoneDevice;

        bConnectDevice = true;

    }
    else
    {

        QString strMsg = "open device fail..";
        qDebug() << strMsg;

        QMessageBox::information(nullptr, "Info", strMsg);



    }

    return bConnectDevice;
}

void TalkToDevice::readWriteDevice(QVector<unsigned char>& dataSendBuffer, QVector<unsigned char>& dataReadBackBuffer)
{

    if(m_bbhPhoneDevice == nullptr)
    {
        qDebug() << "device is not available..";
        return;
    }


    // create one byte more to save the data sum
    unsigned char* dataToSend = new unsigned char[dataSendBuffer.size() + 1];

    for(int i = 0; i < dataSendBuffer.size(); i++)
    {
        dataToSend[i] = dataSendBuffer[i];
    }


    unsigned char vectorDataSum = TalkToDevice::sumData((unsigned char*)dataToSend, dataSendBuffer.size());

    // save the data sum as the last byte
    dataToSend[dataSendBuffer.size()] = vectorDataSum;

    //int dataSize = sizeof(dataToSend) / sizeof(dataToSend[0]);
    int dataSize = dataSendBuffer.size() + 1;
    int bytesWritten = hid_write(m_bbhPhoneDevice, dataToSend, dataSize);

    if(bytesWritten != -1)
    {
        qDebug() << "success written " << bytesWritten << " bytes";




        // read the feedback data
        unsigned char dataReadBack[64] = { 0 };
        int dataLength = 64;
        int timeOut = 300; // ms

        int readBytes = hid_read_timeout(m_bbhPhoneDevice, dataReadBack, dataLength,  timeOut);

        if(readBytes > 0)
        {
            qDebug() << "success reading " << readBytes << " bytes back";




           for(int i = 0; i < dataLength; i++)
           {

               //print the data reading back
               //qDebug("%x", dataReadBack);

               dataReadBackBuffer.push_back(dataReadBack[i]);

           }

            qDebug("%s", dataReadBack);



        }

        if(readBytes == 0)
        {
            qDebug() << "reading time out..";
        }

        if(readBytes == -1)
        {
            qDebug() << "error occur when reading..";
        }



    }
    else
    {
        qDebug() << "hid_write communication error...";
    }

    delete [] dataToSend;
}

void TalkToDevice::bbhwrite_cmddata(uint8_t cmd,uint8_t* data,int length)
{
    // create one byte more to save the data sum
    unsigned char* dataToSend = new unsigned char[length + 7];
    int i = 0;

    if(m_bbhPhoneDevice == nullptr)
    {
        qDebug() << "device is not available..";
        return;
    }
    i = 0;
    dataToSend[i++] = 0x4f;
    dataToSend[i++] = 0x30;
    dataToSend[i++] = 0x80;
    dataToSend[i++] = 0x18;
    dataToSend[i++] = cmd;
    dataToSend[i++] = length;
    for (int j= 0; j < length; j++)
    {
        dataToSend[i++] = data[j];
    }

    unsigned char vectorDataSum = TalkToDevice::sumData((unsigned char*)dataToSend, length + 6);

    // save the data sum as the last byte
    dataToSend[i++] = vectorDataSum;

    qDebug("data size: %d vectorDataSum: %x , size: %d",sizeof(dataToSend), vectorDataSum, length + 7);

    int bytesWritten = hid_write(m_bbhPhoneDevice, dataToSend, length + 7);

    qDebug("send data:");
    for (int i = 0; i < (length + 7); i++)
    {
        qDebug("data[%d] = %x", i ,dataToSend[i]);
    }

    if(bytesWritten != -1)
    {
        qDebug() << "success written " << bytesWritten << " bytes";

        // read the feedback data
        unsigned char dataReadBack[64] = { 0 };
        int dataLength = 64;
        int timeOut = 300; // ms

        int readBytes = hid_read_timeout(m_bbhPhoneDevice, dataReadBack, dataLength,  timeOut);

        if(readBytes > 0)
        {
            qDebug() << "success reading " << readBytes << " bytes back";

           for(int i = 0; i < dataLength; i++)
           {
               //print the data reading back
               //qDebug("%x", dataReadBack);
           }

            qDebug("%s", dataReadBack);
        }

        if(readBytes == 0)
        {
            qDebug() << "reading time out..";
        }

        if(readBytes == -1)
        {
            qDebug() << "error occur when reading..";
        }
    }
    else
    {
        qDebug() << "hid_write communication error...";
    }

    delete [] dataToSend;
}

