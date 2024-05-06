#include "equlizerpage.h"
#include "ui_equlizerpage.h"
#include "talkToDevice.h"
#include <QSettings>
#include "qdebug.h"

equlizerPage::equlizerPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equlizerPage)
{
    ui->setupUi(this);

   // ui->line1->setStyleSheet("background-color:white; ");


}

equlizerPage::~equlizerPage()
{
    delete ui;
}


void equlizerPage::translateUI()
{

    ui->retranslateUi(this);
}

void equlizerPage::on_resetButton_clicked()
{
    ui->verticalSlider1->setValue(0);
    ui->verticalSlider2->setValue(0);
    ui->verticalSlider3->setValue(0);
    ui->verticalSlider4->setValue(0);
    ui->verticalSlider5->setValue(0);
    ui->verticalSlider6->setValue(0);
    ui->verticalSlider7->setValue(0);
    ui->verticalSlider8->setValue(0);
    ui->verticalSlider9->setValue(0);
    ui->verticalSlider10->setValue(0);
}


void equlizerPage::on_enableEQButton_clicked()
{

}


void equlizerPage::on_enable3DButton_clicked()
{

}




void equlizerPage::on_verticalSlider1_valueChanged(int value)
{
    qDebug("value : %d ,%d,%d",value,ui->verticalSlider1->value(),ui->verticalSlider3->value());

    ui->lb_32->setText(QString::number(value) + "db");


    bbh_slider_freq_value();
#if 0
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
    senddata[i++] = 0x00; // end
    senddata[i++] = 0x00; // rev
    senddata[i++] = 0x00; // freq_H
    senddata[i++] = 0x20; // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)value; // band_L
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 19);

    senddata[0] = 0x02;  // 0x00：read  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off
    senddata[5] = 0x01;
    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);
#endif
}


void equlizerPage::on_verticalSlider2_valueChanged(int value)
{
    ui->lb_64->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider3_valueChanged(int value)
{
    ui->lb_125->setText(QString::number(value) + "db");

    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider4_valueChanged(int value)
{
    ui->lb_250->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider5_valueChanged(int value)
{
    ui->lb_500->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider6_valueChanged(int value)
{
    ui->lb_1000->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider7_valueChanged(int value)
{
    ui->lb_2000->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider8_valueChanged(int value)
{
    ui->lb_4000->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider9_valueChanged(int value)
{
    ui->lb_8000->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}


void equlizerPage::on_verticalSlider10_valueChanged(int value)
{
    ui->lb_16000->setText(QString::number(value) + "db");
    bbh_slider_freq_value();
}

void equlizerPage::bbh_slider_freq_value(void)
{
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
    senddata[i++] = ((32 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (32 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider1->value(); // band_L
    senddata[i++] = ((64 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (64 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider2->value(); // band_L
    senddata[i++] = ((125 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (125 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider3->value(); // band_L
    senddata[i++] = ((250 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (250 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider4->value(); // band_L
    senddata[i++] = ((500 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (500 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider5->value(); // band_L
    memset(&senddata[i], 0x00, 9);
    devCommunication.bbhwrite_cmddata(0x21, senddata, 0x26);

    i = 0;
    senddata[i++] = 0x02; // 写入并保存
    senddata[i++] = 0x05; // start
    senddata[i++] = 0x09; // end
    senddata[i++] = 0x00; // rev

    senddata[i++] = ((1000 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (1000 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider6->value(); // band_L
    senddata[i++] = ((2000 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (2000 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider7->value(); // band_L
    senddata[i++] = ((4000 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (4000 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider8->value(); // band_L
    senddata[i++] = ((8000 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (8000 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider9->value(); // band_L
    senddata[i++] = ((16000 >> 8) & 0x00ff); // freq_H
    senddata[i++] = (16000 & 0x00ff); // freq_L
    senddata[i++] = 0x07; // band_H
    senddata[i++] = 0xd0; // band_L
    senddata[i++] = (uint8_t)ui->verticalSlider10->value(); // band_L
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


void equlizerPage::saveEqualizerSetting(QSettings* pSettings)
{
    assert(pSettings);

    if((false == ui->setting1Button->isChecked()) && (false == ui->setting2Button->isChecked()))
    {
        pSettings->beginGroup("Equalizer");
        pSettings->setValue("slider32Hz", ui->verticalSlider1->value());
        pSettings->setValue("slider64Hz", ui->verticalSlider2->value());
        pSettings->setValue("slider125Hz", ui->verticalSlider3->value());
        pSettings->setValue("slider250Hz", ui->verticalSlider4->value());
        pSettings->setValue("slider500Hz", ui->verticalSlider5->value());
        pSettings->setValue("slider1000Hz", ui->verticalSlider6->value());
        pSettings->setValue("slider2000Hz", ui->verticalSlider7->value());
        pSettings->setValue("slider4000Hz", ui->verticalSlider8->value());
        pSettings->setValue("slider8000Hz", ui->verticalSlider9->value());
        pSettings->setValue("slider16000Hz", ui->verticalSlider10->value());
        pSettings->endGroup();
    }



    if(ui->setting1Button->isChecked())
    {
        pSettings->beginGroup("EqualizerSetting1");
        pSettings->setValue("slider32Hz", ui->verticalSlider1->value());
        pSettings->setValue("slider64Hz", ui->verticalSlider2->value());
        pSettings->setValue("slider125Hz", ui->verticalSlider3->value());
        pSettings->setValue("slider250Hz", ui->verticalSlider4->value());
        pSettings->setValue("slider500Hz", ui->verticalSlider5->value());
        pSettings->setValue("slider1000Hz", ui->verticalSlider6->value());
        pSettings->setValue("slider2000Hz", ui->verticalSlider7->value());
        pSettings->setValue("slider4000Hz", ui->verticalSlider8->value());
        pSettings->setValue("slider8000Hz", ui->verticalSlider9->value());
        pSettings->setValue("slider16000Hz", ui->verticalSlider10->value());
        pSettings->endGroup();
    }



    if(ui->setting2Button->isChecked())
    {
        pSettings->beginGroup("EqualizerSetting2");
        pSettings->setValue("slider32Hz", ui->verticalSlider1->value());
        pSettings->setValue("slider64Hz", ui->verticalSlider2->value());
        pSettings->setValue("slider125Hz", ui->verticalSlider3->value());
        pSettings->setValue("slider250Hz", ui->verticalSlider4->value());
        pSettings->setValue("slider500Hz", ui->verticalSlider5->value());
        pSettings->setValue("slider1000Hz", ui->verticalSlider6->value());
        pSettings->setValue("slider2000Hz", ui->verticalSlider7->value());
        pSettings->setValue("slider4000Hz", ui->verticalSlider8->value());
        pSettings->setValue("slider8000Hz", ui->verticalSlider9->value());
        pSettings->setValue("slider16000Hz", ui->verticalSlider10->value());
        pSettings->endGroup();
    }




}

void equlizerPage::loadEqualizerSetting(QSettings* pSettings)
{
    if((false == ui->setting1Button->isChecked()) && (false == ui->setting2Button->isChecked()))
    {
        pSettings->beginGroup("Equalizer");
        int sliderValue = pSettings->value("slider32Hz", 0).toInt();
        ui->verticalSlider1->setValue(sliderValue);

        sliderValue = pSettings->value("slider64Hz", 0).toInt();
        ui->verticalSlider2->setValue(sliderValue);

        sliderValue = pSettings->value("slider125Hz", 0).toInt();
        ui->verticalSlider3->setValue(sliderValue);

        sliderValue = pSettings->value("slider250Hz", 0).toInt();
        ui->verticalSlider4->setValue(sliderValue);

        sliderValue = pSettings->value("slider500Hz", 0).toInt();
        ui->verticalSlider5->setValue(sliderValue);

        sliderValue = pSettings->value("slider1000Hz", 0).toInt();
        ui->verticalSlider6->setValue(sliderValue);

        sliderValue = pSettings->value("slider2000Hz", 0).toInt();
        ui->verticalSlider7->setValue(sliderValue);

        sliderValue = pSettings->value("slider4000Hz", 0).toInt();
        ui->verticalSlider8->setValue(sliderValue);

        sliderValue = pSettings->value("slider8000Hz", 0).toInt();
        ui->verticalSlider9->setValue(sliderValue);

        sliderValue = pSettings->value("slider16000Hz", 0).toInt();
        ui->verticalSlider10->setValue(sliderValue);


        pSettings->endGroup();
    }


    if(ui->setting1Button->isChecked())
    {
        pSettings->beginGroup("EqualizerSetting1");
        int sliderValue = pSettings->value("slider32Hz", 0).toInt();
        ui->verticalSlider1->setValue(sliderValue);

        sliderValue = pSettings->value("slider64Hz", 0).toInt();
        ui->verticalSlider2->setValue(sliderValue);

        sliderValue = pSettings->value("slider125Hz", 0).toInt();
        ui->verticalSlider3->setValue(sliderValue);

        sliderValue = pSettings->value("slider250Hz", 0).toInt();
        ui->verticalSlider4->setValue(sliderValue);

        sliderValue = pSettings->value("slider500Hz", 0).toInt();
        ui->verticalSlider5->setValue(sliderValue);

        sliderValue = pSettings->value("slider1000Hz", 0).toInt();
        ui->verticalSlider6->setValue(sliderValue);

        sliderValue = pSettings->value("slider2000Hz", 0).toInt();
        ui->verticalSlider7->setValue(sliderValue);

        sliderValue = pSettings->value("slider4000Hz", 0).toInt();
        ui->verticalSlider8->setValue(sliderValue);

        sliderValue = pSettings->value("slider8000Hz", 0).toInt();
        ui->verticalSlider9->setValue(sliderValue);

        sliderValue = pSettings->value("slider16000Hz", 0).toInt();
        ui->verticalSlider10->setValue(sliderValue);


        pSettings->endGroup();
    }


    if(ui->setting2Button->isChecked())
    {
        pSettings->beginGroup("EqualizerSetting2");
        int sliderValue = pSettings->value("slider32Hz", 0).toInt();
        ui->verticalSlider1->setValue(sliderValue);

        sliderValue = pSettings->value("slider64Hz", 0).toInt();
        ui->verticalSlider2->setValue(sliderValue);

        sliderValue = pSettings->value("slider125Hz", 0).toInt();
        ui->verticalSlider3->setValue(sliderValue);

        sliderValue = pSettings->value("slider250Hz", 0).toInt();
        ui->verticalSlider4->setValue(sliderValue);

        sliderValue = pSettings->value("slider500Hz", 0).toInt();
        ui->verticalSlider5->setValue(sliderValue);

        sliderValue = pSettings->value("slider1000Hz", 0).toInt();
        ui->verticalSlider6->setValue(sliderValue);

        sliderValue = pSettings->value("slider2000Hz", 0).toInt();
        ui->verticalSlider7->setValue(sliderValue);

        sliderValue = pSettings->value("slider4000Hz", 0).toInt();
        ui->verticalSlider8->setValue(sliderValue);

        sliderValue = pSettings->value("slider8000Hz", 0).toInt();
        ui->verticalSlider9->setValue(sliderValue);

        sliderValue = pSettings->value("slider16000Hz", 0).toInt();
        ui->verticalSlider10->setValue(sliderValue);


        pSettings->endGroup();
    }

}

void equlizerPage::on_setting1Button_clicked()
{


    readConfiguration();
}




void equlizerPage::on_setting2Button_clicked()
{

    readConfiguration();
}

void equlizerPage::readConfiguration()
{

    TalkToDevice devCommunication;
    if(false == devCommunication.findDevice())
    {
        return;
    }

    QString strConfigFile = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings *settings = new QSettings(strConfigFile, QSettings::IniFormat, this);


    loadEqualizerSetting(settings);
}

