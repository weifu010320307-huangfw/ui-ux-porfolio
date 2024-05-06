#ifndef MICROPHONESPEAKERPAGE_H
#define MICROPHONESPEAKERPAGE_H

#include <QDialog>

namespace Ui {
class microphoneSpeakerPage;
}

class microphoneSpeakerPage : public QDialog
{
    Q_OBJECT

public:
    explicit microphoneSpeakerPage(QWidget *parent = nullptr);
    ~microphoneSpeakerPage();

    void translateUI();


    void sendStartSignalToWorkerThread(void);

signals:
    void workerThreadStartSignal();


private slots:
    void on_microphoneAdjust_sliderMoved(int position);

    void on_speakerAdjust_sliderMoved(int position);

    void adjustVolume(int deviceType, int position);

    void on_microphoneDisableButton_clicked();

    void on_speakerDisableButton_clicked();

    void intializeVolume();
    void getVolume( int deviceType, float& volume);

    void on_microphoneAdjust_valueChanged(int value);





    void on_speakerAdjust_valueChanged(int value);

private:
    Ui::microphoneSpeakerPage *ui;

    bool m_isMicrophoneMuteCheck;
    bool m_isSpeakerMuteCheck;

};

#endif // MICROPHONESPEAKERPAGE_H
