#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgridlayout.h"
#include <QGraphicsScene>
#include "coloritem.h"
#include <QTranslator>
#include <QListView>
//#include <QDesktopWidget>
#include "adjustWindowSize.h"
#include <QSignalMapper>
#include <QDebug>
#include <QSettings>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
#include <windows.h>
#include <dbt.h>
#include <shlwapi.h>

#include <QMenu>
#include <QMessageBox>
#include "talkToDevice.h"
#include <QTextCodec>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);






    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground(":/resources/background.jpg");


    float scaleX = resizeWindow::getScale();

   
    QImage fitimgpic = ImgAllbackground.scaled(this->width() * scaleX, this->height() * scaleX, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);




    ui->logoPicture->setPixmap(QPixmap(":/resources/LOGO.png"));
    ui->logoPicture->setScaledContents(true);



    ui->minimumButton->setStyleSheet(tr("border-image:url(:/resources/minimize.jpg);"));
    ui->closeButton->setStyleSheet(tr("border-image:url(:/resources/close.png);"));




    ui->statusPicture->setPixmap(QPixmap(":/resources/enDisconnect.jpg"));
    ui->statusPicture->setScaledContents(true);









    setupLanguageMenu();



    pEqulizer = new equlizerPage(this);
    pMicrophoneSpeaker = new microphoneSpeakerPage(this);
    pEffectPage = new effectPage(this);
    pSoundSurroundPage = new soundSurround(this);

    ui->stackedWidget->addWidget(pEqulizer);
    //ui->stackedWidget->addWidget(pView);
    ui->stackedWidget->addWidget(pSoundSurroundPage);
    ui->stackedWidget->addWidget(pMicrophoneSpeaker);
    ui->stackedWidget->addWidget(pEffectPage);

    ui->stackedWidget->setCurrentWidget(pEqulizer);


    //connect(ui->LanguageComboBox, SIGNAL(currentIndexChanged(const QString)), this, SLOT(changeLanguage(const QString)));

    loadDefaultSetting();

    //on_enLanguageButton_clicked();

    setUIlanguage();

    resizeAllUI();



    setFixedSize(this->width(), this->height());



    registerNotification();





    setFocus();


}

void MainWindow::setupLanguageMenu()
{



    ui->languageButton->setIcon(QIcon(":/resources/languageRed.jpg"));
    ui->languageButton->setStyleSheet(QString("QPushButton::menu-indicator{image:none;}"
                                           "QPushButton{border-style: none;}"
                                           "QPushButton:hover{background-color:red; color: white;}"
                                           "QPushButton:pressed{background-color:red; ""border-style: inset;}"));
    ui->languageButton->setCursor(QCursor(Qt::PointingHandCursor));



      QMenu *setUpMenu = new QMenu(this);
      QAction *selectChinese = new QAction(setUpMenu);
      QAction *selectEnglish = new QAction(setUpMenu);
      QAction *selectKorean = new QAction(setUpMenu);


      selectEnglish->setText(tr("EN"));
      selectChinese->setText(tr("CN"));
      selectKorean->setText(tr("KR"));

  


      setUpMenu->addAction(selectEnglish);
      setUpMenu->addAction(selectChinese);
      setUpMenu->addAction(selectKorean);



      setUpMenu->setWindowFlags(setUpMenu->windowFlags() | Qt::FramelessWindowHint);
      setUpMenu->setAttribute(Qt::WA_TranslucentBackground);
      setUpMenu->setStyleSheet(" QMenu {border-radius:2px;font-family:'Arial';font-size:16px;}"
                        " QMenu::item {height:20px; width:40px;padding-left:25px;border: 1px solid none;}"
                        "QMenu::item:selected {background-color:red; \
                         padding-left:25px;border: 0px solid rgb(65,173,255); color: white; }");

      qDebug() << "setUpMenu " << setUpMenu->width() << setUpMenu->height() << resizeWindow::getScale();



      // less than 1920
       if(resizeWindow::getScale() < 1)
       {

            setUpMenu->setStyleSheet(" QMenu::item {padding-left:5px;}"
            "QMenu::item:selected {background-color:red;}");

            setUpMenu->setFixedWidth(65 * resizeWindow::getScale());

            qDebug() << "setUpMenu->menuAction() " << setUpMenu->menuAction()->menu()->width();


       }





       ui->languageButton->setMenu(setUpMenu);
       ui->languageButton->show();

       connect(selectEnglish, &QAction::triggered, this, &MainWindow::on_enLanguageButton_clicked);
       connect(selectChinese, &QAction::triggered, this, &MainWindow::on_cnLanguageButton_clicked);
       connect(selectKorean, &QAction::triggered, this, &MainWindow::selectKoreanLanguage);

}

void MainWindow::changeLanguage(QString strLanguage)
{

    if(strLanguage.indexOf("中文") != -1 || strLanguage.indexOf("CN") != -1)
    {
        on_cnLanguageButton_clicked();
    }
    else if(strLanguage.indexOf("英文") != -1 || strLanguage.indexOf("EN") != -1)
    {
        on_enLanguageButton_clicked();
    }
    else if(strLanguage.indexOf("KR") != -1)
    {
        selectKoreanLanguage();
    }

}



void MainWindow::resizeAllUI()
{

    QSignalMapper *mapper = new QSignalMapper(this);

     QObjectList list = children();
     foreach (QObject *obj, list) {


         if (obj->metaObject()->className() == QStringLiteral("QWidget"))
         {
             auto widget = qobject_cast<QWidget*>(obj);

             resizeWindow::resizeUI(widget);

             QObjectList list2 = obj->children();
             foreach (QObject *obj1, list2){

                 qDebug() << obj1->metaObject()->className() << "\n";

                 if (obj1->inherits("QPushButton")){
                     QPushButton *b = qobject_cast<QPushButton*>(obj1);
                     mapper->setMapping(b, b->text());
                     connect(b, SIGNAL(clicked(bool)), mapper, SLOT(map()));
                 }
             }
         }
     }
     connect(mapper, SIGNAL(mapped(QString)), this, SLOT(slotButton(QString)));

     resizeWindow::resizeUI(pEqulizer);
     resizeWindow::resizeUI(pMicrophoneSpeaker);
     resizeWindow::resizeUI(pEffectPage);
     resizeWindow::resizeUI(pSoundSurroundPage);


     resizeWindow::resizeUI(this);
}

void MainWindow::slotButton(QString s)
{
    qDebug() << s;
}


MainWindow::~MainWindow()
{
    delete ui;
    //delete pDragFrame;

}





void MainWindow::on_closeButton_clicked()
{
    close();
}




void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - pos);
       event->accept();
    }
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        pos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
     }
}


void MainWindow::on_equlizerPageButton_clicked()
{
    // change other selected button selection
    ui->effectPageButton->setChecked(false);
    ui->microphonePageButton->setChecked(false);
    ui->surroundSoundButton->setChecked(false);
    ui->saveConfigButton->setChecked(false);
    ui->selectConfigButton->setChecked(false);



    ui->stackedWidget->setCurrentWidget(pEqulizer);
}





void MainWindow::selectKoreanLanguage()
{
    QTranslator translator;



    translator.load("kr.qm");

    qApp->installTranslator(&translator);

    ui->retranslateUi(this);



    // sub page translation
    pMicrophoneSpeaker->translateUI();
    pEqulizer->translateUI();
    pEffectPage->translateUI();
    pSoundSurroundPage->translateUI();

    ui->languageText->setText("KR");






}




void MainWindow::on_cnLanguageButton_clicked()
{



    QTranslator translator;



    translator.load("cn.qm");

    qApp->installTranslator(&translator);

    ui->retranslateUi(this);



    // sub page translation
    pMicrophoneSpeaker->translateUI();
    pEqulizer->translateUI();
    pEffectPage->translateUI();
    pSoundSurroundPage->translateUI();

    ui->languageText->setText("CN");





//    ui->LanguageComboBox->clear();
//    ui->LanguageComboBox->addItem("中文");
//    ui->LanguageComboBox->addItem("英文");
}




void MainWindow::setUIlanguage()
{
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForTr(codec);
//    QTextCodec::setCodecForCStrings(codec);

    QTranslator translator;
    QLocale locale;



    if( locale.language() == QLocale::Chinese )
    {
        qDebug() << "中文系统";
        on_cnLanguageButton_clicked();

    }
    else if( locale.language() == QLocale::Korean )
    {
        qDebug() << "Korean system";

        selectKoreanLanguage();
    }
    else
    {
        qDebug() << "English system" ;

        on_enLanguageButton_clicked();
    }
}


void MainWindow::on_enLanguageButton_clicked()
{



    QTranslator translator;



    translator.load("en.qm");


    qApp->installTranslator(&translator);

    ui->retranslateUi(this);

    pMicrophoneSpeaker->translateUI();
    pEqulizer->translateUI();
    pEffectPage->translateUI();
    pSoundSurroundPage->translateUI();

    ui->languageText->setText("EN");






//    ui->LanguageComboBox->clear();
//    ui->LanguageComboBox->addItem("Chinese");
//    ui->LanguageComboBox->addItem("English");
}





void MainWindow::on_effectPageButton_clicked()
{
    // change other selected button selection
    ui->equlizerPageButton->setChecked(false);
    ui->microphonePageButton->setChecked(false);
    ui->surroundSoundButton->setChecked(false);
    ui->saveConfigButton->setChecked(false);
    ui->selectConfigButton->setChecked(false);

    ui->stackedWidget->setCurrentWidget(pEffectPage);
}


void MainWindow::on_microphonePageButton_clicked()
{
    // change other selected button selection
    ui->effectPageButton->setChecked(false);
    ui->equlizerPageButton->setChecked(false);
    ui->surroundSoundButton->setChecked(false);
    ui->saveConfigButton->setChecked(false);
    ui->selectConfigButton->setChecked(false);

    ui->stackedWidget->setCurrentWidget(pMicrophoneSpeaker);
}


void MainWindow::on_surroundSoundButton_clicked()
{
    //ui->stackedWidget->setCurrentWidget(pView);
    //pView->show();

    // change other selected button selection
    ui->effectPageButton->setChecked(false);
    ui->microphonePageButton->setChecked(false);
    ui->equlizerPageButton->setChecked(false);
    ui->saveConfigButton->setChecked(false);
    ui->selectConfigButton->setChecked(false);
    ui->aboutButton->setChecked(false);

    ui->stackedWidget->setCurrentWidget(pSoundSurroundPage);

}


void MainWindow::on_saveConfigButton_clicked()
{


    ui->selectConfigButton->setChecked(false);
    ui->aboutButton->setChecked(false);

    QString path = QCoreApplication::applicationDirPath();


    QString strConfigFile = QFileDialog::getSaveFileName(this,tr("select or create a file to save configuration"), path, tr("ini Files(*.ini)"));

    qDebug() << "file selected is " << strConfigFile;

    if(strConfigFile.isEmpty())
    {
        return;
    }

    saveSetting(strConfigFile);
}


void MainWindow::on_selectConfigButton_clicked()
{
    ui->saveConfigButton->setChecked(false);
    ui->aboutButton->setChecked(false);

    QString path = QCoreApplication::applicationDirPath();


    QString strConfigFile = QFileDialog::getOpenFileName(this,tr("select configuration file"), path, tr("ini Files(*.ini)"));

    if(strConfigFile.isEmpty())
    {
        return;
    }



    qDebug() << strConfigFile;

    QSettings *settings = new QSettings(strConfigFile, QSettings::IniFormat, this);

    pEqulizer->loadEqualizerSetting(settings);
    pEffectPage->loadEffectSetting(settings);
    pSoundSurroundPage->loadSoundSurroundSetting(settings);

}


void MainWindow::loadDefaultSetting()
{

//    // this is needed
//    TalkToDevice devCommunication;
//    bool bDeviceConnect = devCommunication.findDevice(false);
//    if(false == bDeviceConnect)
//    {
//        return;
//    }


    QString strConfigFile = qApp->applicationDirPath() + "/config.ini";

    qDebug() << strConfigFile;

    QSettings *settings = new QSettings(strConfigFile, QSettings::IniFormat, this);

    pEqulizer->loadEqualizerSetting(settings);
    pEffectPage->loadEffectSetting(settings);
    pSoundSurroundPage->loadSoundSurroundSetting(settings);
}




void MainWindow::on_minimumButton_clicked()
{
    showMinimized();
}


void MainWindow::saveSetting(QString strConfigFile)
{



//    if(strConfigFile.isEmpty())
//    {
//        strConfigFile = QCoreApplication::applicationDirPath() + "/config.ini";
//    }

//    else
//    {
//        strConfigFile = QCoreApplication::applicationDirPath() + "/" + strConfigFile;
//    }


    qDebug() << strConfigFile;



    QSettings *settings = new QSettings(strConfigFile, QSettings::IniFormat, this);


    pEqulizer->saveEqualizerSetting(settings);
    pEffectPage->saveEffectSetting(settings);
    pSoundSurroundPage->saveSoundSurroundSetting(settings);


}

bool MainWindow::nativeEvent(const QByteArray & eventType, void * message, long* result)
{

    if (eventType == "windows_generic_MSG")
    {
        MSG* pMsg = static_cast<MSG*>(message);

        if(pMsg && pMsg->message == WM_DEVICECHANGE)
        {
           // int position = (int)pMsg->lParam;

            PDEV_BROADCAST_DEVICEINTERFACE devInterface = (PDEV_BROADCAST_DEVICEINTERFACE)pMsg->lParam;
            //QString strDeviceID = QString::fromWCharArray(devInterface->dbcc_name);


            UINT  nEventType = pMsg->wParam;

            qDebug() << "nEventType = " << nEventType;


            QString strDeviceID;
            switch (pMsg->wParam)
            {

                case DBT_DEVICEARRIVAL:
                {

                    qDebug() << "DBT_DEVICEARRIVAL";

                    if(devInterface)
                    {
                        strDeviceID = QString::fromWCharArray(devInterface->dbcc_name);
                    }


                    if (-1 != strDeviceID.contains("USB\VID_3206&PID_4000", Qt::CaseInsensitive))
                    {
                        qDebug() << strDeviceID << " arrival..";

                        updateDeviceStatus(true);
                    }


                }

                break;

                case DBT_DEVICEREMOVECOMPLETE:
                {

                    qDebug() << "DBT_DEVICEREMOVECOMPLETE";

                    if(devInterface)
                    {
                        strDeviceID = QString::fromWCharArray(devInterface->dbcc_name);
                    }

                    if (-1 != strDeviceID.contains("USB\VID_3206&PID_4000", Qt::CaseInsensitive))
                    {
                        qDebug() << strDeviceID << " remove..";

                        updateDeviceStatus(false);
                    }
                 }
                 break;

            }





            *result = 0;
            return true;


        }
    }

    return QWidget::nativeEvent(eventType, message, result);


}

void MainWindow::registerNotification()
{
    HDEVNOTIFY hDevNotify;


    // GUID_DEVINTERFACE_USB_DEVICE
    const GUID deviceGUID = { 0xA5DCBF10, 0x6530, 0x11D2, { 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } };



    DEV_BROADCAST_DEVICEINTERFACE	deviceMsgInfo;
    ZeroMemory( &deviceMsgInfo, sizeof(deviceMsgInfo) );

    deviceMsgInfo.dbcc_size				= sizeof(deviceMsgInfo);
    deviceMsgInfo.dbcc_devicetype	= DBT_DEVTYP_DEVICEINTERFACE;
    deviceMsgInfo.dbcc_reserved		= 0;


    deviceMsgInfo.dbcc_classguid = deviceGUID;

    HWND windowHandle = (HWND)this->winId();


    hDevNotify = RegisterDeviceNotification(windowHandle,
                                            &deviceMsgInfo,
                                            DEVICE_NOTIFY_WINDOW_HANDLE );

    if( !hDevNotify )
    {
        qDebug() << "RegisterDeviceNotification unsuccess " ;
        return ;
    }



}

void MainWindow::updateDeviceStatus(bool deviceConnect)
{


    QString strLanguage = ui->languageText->text();

    qDebug() << strLanguage;

    if(deviceConnect)
    {

        ui->statusPicture->setPixmap(QPixmap(":/resources/enConnect.jpg"));

//        if("EN" == strLanguage)
//        {

//            ui->deviceStatusPicture->setPixmap(QPixmap(":/resources/enConnect.jpg"));

//        }

//        if("CN" == strLanguage)
//        {

//            ui->deviceStatusPicture->setPixmap(QPixmap(":/resources/active.png"));


//        }
    }
    else
    {

        ui->statusPicture->setPixmap(QPixmap(":/resources/enDisconnect.jpg"));

//        if("EN" == strLanguage)
//        {

//            ui->deviceStatusPicture->setPixmap(QPixmap(":/resources/enDisconnect.jpg"));


//        }

//        if("CN" == strLanguage)
//        {

//            ui->deviceStatusPicture->setPixmap(QPixmap(":/resources/inactive.png"));


//        }
    }


    ui->statusPicture->setScaledContents(true);

}




void MainWindow::on_aboutButton_clicked()
{
    ui->selectConfigButton->setChecked(false);
    ui->saveConfigButton->setChecked(false);


    QString strHardwareVersion;
    getHardwareVersion(strHardwareVersion);


    QString strVersion = "Designed by BBH Company, software version: 2.0.0.7, release date: 2021.10.25, hardware version: " + strHardwareVersion;
    QMessageBox::information(nullptr, "Info", strVersion);


}

void MainWindow::getHardwareVersion(QString& strVersion)
{

    QVector<unsigned char> dataSendBuffer;
    QVector<unsigned char> dataBackuffer;


    dataSendBuffer.push_back(0x4e);
    dataSendBuffer.push_back(0x30);
    dataSendBuffer.push_back(0x80);
    dataSendBuffer.push_back(0x18);
    dataSendBuffer.push_back(0x01);
    dataSendBuffer.push_back(0x00);


//    // create one byte more to save the data sum
//    unsigned char* data = new unsigned char[dataSendBuffer.size() + 1];

//    for(int i = 0; i < dataSendBuffer.size(); i++)
//    {
//        data[i] = dataSendBuffer[i];
//    }


//    unsigned char vectorDataSum = TalkToDevice::sumData((unsigned char*)data, dataSendBuffer.size());

//    // save the data sum as the last byte
//    data[dataSendBuffer.size()] = vectorDataSum;




    TalkToDevice devCommunication;

    if(false == devCommunication.findDevice())
    {
        return;
    }

    devCommunication.readWriteDevice(dataSendBuffer, dataBackuffer);

    if(dataBackuffer.size() > 0)
    {
        unsigned char* dataReadback = new unsigned char[dataBackuffer.size()];



        for(int i = 0; i < dataBackuffer.size(); i++)
        {
            dataReadback[i] = dataBackuffer[i];

        }



        strVersion = ((char*)dataReadback);

        delete [] dataReadback;
    }




    //QStringList strList = strVersion.split(L' ');

//    int pos = strVersion.indexOf(' ');

//    qDebug() << pos;

   // strVersion = strList.back();

    // there is useless information at the beginning
    // get the right 17 char
    strVersion = strVersion.right(17);

    qDebug() << "hardware verison = " << strVersion;
}

