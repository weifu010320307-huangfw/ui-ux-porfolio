#include "microphonespeakerpage.h"
#include "ui_microphonespeakerpage.h"
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>
#include <QAxBase>
//#include "workerThread.h"
#include <QThread>
#include "qdebug.h"

microphoneSpeakerPage::microphoneSpeakerPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::microphoneSpeakerPage), m_isMicrophoneMuteCheck(false), m_isSpeakerMuteCheck(false)
{
    ui->setupUi(this);

    intializeVolume();


//    QThread* m_objThread = new QThread();
//    workerThread* m_Thread = new workerThread;

//    m_Thread->moveToThread(m_objThread);
//    connect(m_objThread, &QThread::finished, m_objThread, &QObject::deleteLater);
//    connect(this, &microphoneSpeakerPage::workerThreadStartSignal, m_Thread, &workerThread::doWork);
//    m_objThread->start();

    //sendStartSignalToWorkerThread();
}

microphoneSpeakerPage::~microphoneSpeakerPage()
{
    delete ui;
}


void microphoneSpeakerPage::translateUI()
{

    ui->retranslateUi(this);
}

void microphoneSpeakerPage::on_microphoneAdjust_sliderMoved(int position)
{


    adjustVolume(eCapture, position);
    ui->microphoneLcdNumber->display(position);

}


void microphoneSpeakerPage::on_speakerAdjust_sliderMoved(int position)
{

    adjustVolume(eRender, position);
    ui->speakerLcdNumber->display(position);
}

void microphoneSpeakerPage::adjustVolume(int deviceType, int position)
{
    HRESULT hr;
    IMMDeviceEnumerator* pDeviceEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pAudioEndpointVolume = nullptr;
    IAudioClient* pAudioClient = nullptr;

    try
    {
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pDeviceEnumerator);
        if (FAILED(hr)) throw "CoCreateInstance";

        hr = pDeviceEnumerator->GetDefaultAudioEndpoint(deviceType == 0 ? eRender : eCapture, eMultimedia, &pDevice);
        if (FAILED(hr)) throw "GetDefaultAudioEndpoint";

        hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
        if (FAILED(hr)) throw "pDevice->Active";

        hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
        if (FAILED(hr)) throw "pDevice->Active";

        if (position == -2)
        {


            hr = pAudioEndpointVolume->SetMute(FALSE, NULL);
            if (FAILED(hr)) throw "SetUnMute";
        }

        else if (position == -1)
        {

            hr = pAudioEndpointVolume->SetMute(TRUE, NULL);

            if (FAILED(hr)) throw "SetMute";
        }
        else {
            if (position < 0 || position > 100) {
                hr = E_INVALIDARG;
                throw "Invalid Arg";
            }

            float fVolume;
            fVolume = position / 100.0f;
            hr = pAudioEndpointVolume->SetMasterVolumeLevelScalar(fVolume, &GUID_NULL);
            if (FAILED(hr)) throw "SetMasterVolumeLevelScalar";

            pAudioClient->Release();
            pAudioEndpointVolume->Release();
            pDevice->Release();
            pDeviceEnumerator->Release();
            return;
        }
    }
    catch (...)
    {
        if (pAudioClient) pAudioClient->Release();
        if (pAudioEndpointVolume) pAudioEndpointVolume->Release();
        if (pDevice) pDevice->Release();
        if (pDeviceEnumerator) pDeviceEnumerator->Release();
        throw;
    }

    return;
}


void microphoneSpeakerPage::sendStartSignalToWorkerThread()
{

    emit workerThreadStartSignal();

}


void microphoneSpeakerPage::on_microphoneDisableButton_clicked()
{
    if(ui->microphoneDisableButton->isChecked())
    {
        // to mute
        adjustVolume(eCapture, -1);
    }
    else
    {
        // unmute
        adjustVolume(eCapture, -2);
    }



}


void microphoneSpeakerPage::on_speakerDisableButton_clicked()
{
    if(ui->speakerDisableButton->isChecked())
    {
        adjustVolume(eRender, -1);
    }
    else
    {
        adjustVolume(eRender, -2);
    }


}


void microphoneSpeakerPage::intializeVolume()
{

    float microphoneVolume = 0;
    getVolume(eCapture, microphoneVolume);


    // return number is dot number less than 1
    ui->microphoneLcdNumber->display(microphoneVolume * 100);
    ui->microphoneAdjust->setSliderPosition(microphoneVolume * 100);


    float speakerVolume = 0;
    getVolume(eRender, speakerVolume);

    ui->speakerLcdNumber->display(speakerVolume * 100);
    ui->speakerAdjust->setSliderPosition(speakerVolume * 100);


}

void microphoneSpeakerPage::getVolume(int deviceType, float& volume)
{
    HRESULT hr;
    IMMDeviceEnumerator* pDeviceEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pAudioEndpointVolume = nullptr;
    IAudioClient* pAudioClient = nullptr;

    try
    {
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pDeviceEnumerator);
        if (FAILED(hr)) throw "CoCreateInstance";

        hr = pDeviceEnumerator->GetDefaultAudioEndpoint(deviceType == 0 ? eRender : eCapture, eMultimedia, &pDevice);
        if (FAILED(hr)) throw "GetDefaultAudioEndpoint";

        hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
        if (FAILED(hr)) throw "pDevice->Active";

        hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
        if (FAILED(hr)) throw "pDevice->Active";



        hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&volume);
        if (FAILED(hr)) throw "GetMasterVolumeLevelScalar";

        pAudioClient->Release();
        pAudioEndpointVolume->Release();
        pDevice->Release();
        pDeviceEnumerator->Release();
        return;
    }
    catch (...)
    {
        if (pAudioClient) pAudioClient->Release();
        if (pAudioEndpointVolume) pAudioEndpointVolume->Release();
        if (pDevice) pDevice->Release();
        if (pDeviceEnumerator) pDeviceEnumerator->Release();
        throw;
    }

    return;
}

void microphoneSpeakerPage::on_microphoneAdjust_valueChanged(int value)
{
    qDebug() << value;

    adjustVolume(eCapture, value);
    ui->microphoneLcdNumber->display(value);
}







void microphoneSpeakerPage::on_speakerAdjust_valueChanged(int value)
{
    adjustVolume(eRender, value);
    ui->speakerLcdNumber->display(value);
}

