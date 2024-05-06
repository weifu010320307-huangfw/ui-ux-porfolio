#include "effectpage.h"
#include "ui_effectpage.h"
#include "talkToDevice.h"
#include <QSettings>
#include <qdebug.h>

effectPage::effectPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::effectPage)
{
    ui->setupUi(this);




    QString strPictureName = ":/resources/noEffect.jpg";
    drawPageBackground(strPictureName);

}

effectPage::~effectPage()
{
    delete ui;
}

void effectPage::translateUI()
{

    ui->retranslateUi(this);
}

const uint8_t noEffect[] = {
    0x00,0x20,0x07,0xd0,0x00,
    0x00,0x40,0x07,0xd0,0x00,
    0x00,0x7d,0x07,0xd0,0x00,
    0x00,0xfa,0x07,0xd0,0x00,
    0x00,0xfa,0x07,0xd0,0x00,
    0x03,0xe8,0x07,0xd0,0x00,
    0x07,0xd0,0x07,0xd0,0x00,
    0x0f,0xa0,0x07,0xd0,0x00,
    0x1f,0x40,0x07,0xd0,0x00,
    0x3e,0x80,0x07,0xd0,0x00,
};

const uint8_t outdoor[] = {
    0x00,0x20,0x07,0xd0,0x0c,
    0x00,0x40,0x07,0xd0,0x0c,
    0x00,0x7d,0x07,0xd0,0x0c,
    0x00,0xfa,0x07,0xd0,0x0c,
    0x00,0xfa,0x07,0xd0,0x0c,
    0x03,0xe8,0x07,0xd0,0x0c,
    0x07,0xd0,0x07,0xd0,0x0c,
    0x0f,0xa0,0x07,0xd0,0x0c,
    0x1f,0x40,0x07,0xd0,0x0c,
    0x3e,0x80,0x07,0xd0,0x0c,
};

const uint8_t theater[] = {
    0x00,0x20,0x07,0xd0,0x0c,
    0x00,0x40,0x07,0xd0,0x0c,
    0x00,0x7d,0x07,0xd0,0x0c,
    0x00,0xfa,0x07,0xd0,0x0c,
    0x00,0xfa,0x07,0xd0,0x0c,
    0x03,0xe8,0x07,0xd0,0x0c,
    0x07,0xd0,0x07,0xd0,0x0c,
    0x0f,0xa0,0x07,0xd0,0x0c,
    0x1f,0x40,0x07,0xd0,0x0c,
    0x3e,0x80,0x07,0xd0,0x0c,
};


const uint8_t bathroom[] = {
    0x00,0x20,0x07,0xd0,0xf4,
    0x00,0x40,0x07,0xd0,0xf4,
    0x00,0x7d,0x07,0xd0,0xf4,
    0x00,0xfa,0x07,0xd0,0xf4,
    0x00,0xfa,0x07,0xd0,0xf4,
    0x03,0xe8,0x07,0xd0,0xf4,
    0x07,0xd0,0x07,0xd0,0xf4,
    0x0f,0xa0,0x07,0xd0,0xf4,
    0x1f,0x40,0x07,0xd0,0xf4,
    0x3e,0x80,0x07,0xd0,0xf4,
};

const uint8_t livingroom[] = {
    0x00,0x20,0x07,0xd0,0x07,
    0x00,0x40,0x07,0xd0,0x07,
    0x00,0x7d,0x07,0xd0,0x07,
    0x00,0xfa,0x07,0xd0,0x07,
    0x00,0xfa,0x07,0xd0,0x07,
    0x03,0xe8,0x07,0xd0,0x07,
    0x07,0xd0,0x07,0xd0,0x07,
    0x0f,0xa0,0x07,0xd0,0x07,
    0x1f,0x40,0x07,0xd0,0x07,
    0x3e,0x80,0x07,0xd0,0x07,
};

void effectPage::drawPageBackground(QString& strPictureName)
{

    ui->effectPicture->setPixmap(QPixmap(strPictureName));
    ui->effectPicture->setScaledContents(true);
}

void effectPage::on_theaterEffectButton_clicked()
{
    QString strPictureName = ":/resources/theater.jpg";
    drawPageBackground(strPictureName);
    uint8_t senddata[38] = {0x00};
    int i = 0;

    TalkToDevice devCommunication;

    if(false == devCommunication.findDevice())
    {
        return;
    }

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x00; // start
    senddata[i++] = 0x04; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = theater[j];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = theater[j + 25];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);

}


void effectPage::on_bathRoomEffectButton_clicked()
{
    QString strPictureName = ":/resources/bathroom.jpg";
    drawPageBackground(strPictureName);
    uint8_t senddata[38] = {0x00};
    int i = 0;

    TalkToDevice devCommunication;
    if(false == devCommunication.findDevice())
    {
        return;
    }

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x00; // start
    senddata[i++] = 0x04; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = bathroom[j];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = bathroom[j + 25];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);
}


void effectPage::on_outdoorEffectButton_clicked()
{
    QString strPictureName = ":/resources/outdoor.jpg";
    drawPageBackground(strPictureName);
    uint8_t senddata[38] = {0x00};
    int i = 0;

    TalkToDevice devCommunication;
    if(false == devCommunication.findDevice())
    {
        return;
    }

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x00; // start
    senddata[i++] = 0x04; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = outdoor[j];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = outdoor[j + 25];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);
}


void effectPage::on_livingRoomEffectButton_clicked()
{
    QString strPictureName = ":/resources/livingroom.jpg";
    drawPageBackground(strPictureName);
    uint8_t senddata[38] = {0x00};
    int i = 0;

    TalkToDevice devCommunication;
    if(false == devCommunication.findDevice())
    {
        return;
    }

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x00; // start
    senddata[i++] = 0x04; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = livingroom[j];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = livingroom[j + 25];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);
}


void effectPage::on_noEffectButton_clicked()
{
    QString strPictureName = ":/resources/noEffect.jpg";
    drawPageBackground(strPictureName);

    uint8_t senddata[38] = {0x00};
    int i = 0;

    TalkToDevice devCommunication;
    if(false == devCommunication.findDevice())
    {
        return;
    }

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x00; // start
    senddata[i++] = 0x04; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = noEffect[j];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev
    for (int j = 0; j < 25; j++)
    {
        senddata[i++] = noEffect[j + 25];
    }
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);
}


void effectPage::saveEffectSetting(QSettings* pSettings)
{
    assert(pSettings);

    pSettings->beginGroup("Effect");

    if(ui->bathRoomEffectButton->isChecked())
    {
        pSettings->setValue("currentEffect", "bathRoom");
    }

    else if(ui->livingRoomEffectButton->isChecked())
    {
        pSettings->setValue("currentEffect", "livingRoom");
    }

    else if(ui->noEffectButton->isChecked())
    {
        pSettings->setValue("currentEffect", "noEffect");
    }

    else if(ui->outdoorEffectButton->isChecked())
    {
        pSettings->setValue("currentEffect", "outdoorEffect");
    }

    else if(ui->theaterEffectButton->isChecked())
    {
        pSettings->setValue("currentEffect", "theaterEffect");
    }


    pSettings->endGroup();



}


void effectPage::loadEffectSetting(QSettings* pSettings)
{

    pSettings->beginGroup("Effect");
    QString strCurrentEffect = pSettings->value("currentEffect","").toString();

    qDebug() << strCurrentEffect;


    if(strCurrentEffect == "theaterEffect")
    {
        ui->theaterEffectButton->setChecked(true);
    }

    else if(strCurrentEffect == "outdoorEffect")
    {
        ui->outdoorEffectButton->setChecked(true);
    }

    else if(strCurrentEffect == "noEffect")
    {
        ui->noEffectButton->setChecked(true);
    }

    else if(strCurrentEffect == "livingRoom")
    {
        ui->livingRoomEffectButton->setChecked(true);
    }

    else if(strCurrentEffect == "bathRoom")
    {
        ui->bathRoomEffectButton->setChecked(true);
    }


    pSettings->endGroup();


}
