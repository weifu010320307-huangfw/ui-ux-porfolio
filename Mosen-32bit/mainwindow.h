#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qslider.h"
#include <QMouseEvent>
#include "dragObjFrame.h"
#include <QGraphicsView>
#include "equlizerpage.h"
#include "microphonespeakerpage.h"
#include "effectpage.h"
#include "soundsurround.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void saveSetting(QString strConfigFile = "");


    void updateDeviceStatus(bool deviceConnect);

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);


    bool nativeEvent(const QByteArray& eventType, void * message, long* result);
    void registerNotification();

private slots:


    void loadDefaultSetting();
    void on_closeButton_clicked();



    void changeLanguage(QString strLanguage);

    void on_cnLanguageButton_clicked();
    void selectKoreanLanguage();


    void setUIlanguage();

    void on_enLanguageButton_clicked();

    void on_equlizerPageButton_clicked();

    void on_effectPageButton_clicked();

    void on_microphonePageButton_clicked();

    void on_surroundSoundButton_clicked();

    void on_saveConfigButton_clicked();

    void on_selectConfigButton_clicked();

    void slotButton(QString s);
    void resizeAllUI();

    void on_minimumButton_clicked();

    void setupLanguageMenu();


    void on_aboutButton_clicked();
    void getHardwareVersion(QString& strVersion);

private:
    Ui::MainWindow *ui;


    QPoint pos;


    equlizerPage* pEqulizer;
    microphoneSpeakerPage* pMicrophoneSpeaker;
    effectPage* pEffectPage;
    soundSurround* pSoundSurroundPage;


};
#endif // MAINWINDOW_H
