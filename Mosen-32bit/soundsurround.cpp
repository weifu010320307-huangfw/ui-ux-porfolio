#include "soundsurround.h"
#include "ui_soundsurround.h"
#include <QGraphicsScene>
#include "coloritem.h"
#include "adjustWindowSize.h"
#include "talkToDevice.h"

#include "qdebug.h"
#include <QtMath>
#include <QMap>
#include <QPropertyAnimation>
#include <QSettings>


soundSurround::soundSurround(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::soundSurround), m_isAnimationRunning(false), m_isUserChangeVolume(false)
{
    ui->setupUi(this);

    ui->speakerPicture->setPixmap(QPixmap(":/resources/speaker.png"));
    ui->speakerPicture->setScaledContents(true);

    ui->increaseButton->setStyleSheet(tr("border-image:url(:/resources/plus.png);"));
    ui->minusButton->setStyleSheet(tr("border-image:url(:/resources/minus.png);"));







    float scaleRatio = resizeWindow::getScale();

    qreal posX = scaleRatio * -200;
    qreal posY = scaleRatio * -200;
    qreal width = scaleRatio * 400;
    qreal height = scaleRatio * 400;

    //scene = new QGraphicsScene(-200, -200, 400, 400, this);
    scene = new QGraphicsScene(posX, posY, width, height, this);
    animateCtrl = new animateColorItem(this);
    scene->addItem(animateCtrl);




    pView = new QGraphicsView(scene, this);
    pView->setRenderHint(QPainter::Antialiasing);
    pView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->stackedWidget->addWidget(pView);
    ui->stackedWidget->setCurrentWidget(pView);

    pView->show();

    initializeChannelCurrentValue();




}

void soundSurround::initializeChannelCurrentValue()
{
    int currentValue = ui->horizontalSliderCenter->value();
    ui->label_C->setText(QString::number(currentValue) + "db");



    currentValue = ui->horizontalSliderLB->value();
    ui->label_LB->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderLS->value();
    ui->label_LS->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderRB->value();
    ui->label_RB->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderRS->value();
    ui->label_RS->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderW->value();
    ui->label_W->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderLeft->value();
    ui->label_L->setText(QString::number(currentValue) + "db");

    currentValue = ui->horizontalSliderRight->value();
    ui->label_R->setText(QString::number(currentValue) + "db");



}

//soundSurround::soundSurround(QGraphicsView* pView, QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::soundSurround)
//{
//    Q_UNUSED(parent)

//    ui->setupUi(this);

////    scene = new QGraphicsScene(-200, -200, 400, 400, this);
////    animateColorItem* animateCtrl = new animateColorItem(*scene);

////    scene->addItem(animateCtrl);




////    pView = new QGraphicsView(scene, this);
////    pView->setRenderHint(QPainter::Antialiasing);
////    pView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

////    pView->show();

//}

soundSurround::~soundSurround()
{
    delete ui;
}

void soundSurround::translateUI()
{

    ui->retranslateUi(this);
}

void soundSurround::on_switchSoundSurroundButton_clicked()
{
    uint8_t senddata[6] = {0x00};
    static bool on_off = false;
    TalkToDevice devCommunication;

    if(false == devCommunication.findDevice())
    {
        return;
    }

    senddata[0] = 0x02;  // 0x00£ºread  0x01:write 0x02:write&save
    senddata[1] = 0x01;  // rev
    senddata[2] = 0x01;  // surround 0x01:on 0x02:off
    senddata[3] = 0x02;  // 3d 0x01:on 0x02:off
    senddata[4] = 0x02;  // micENC 0x01:on 0x02:off

    if (on_off)
    {
        on_off = false;
        senddata[5] = 0x01;  // Stereo 0x01:on 0x02:off

        m_isSoundSurroundOn = true;


    }
    else
    {
        on_off = true;
        senddata[5] = 0x02;


        m_isSoundSurroundOn = false;

    }

    m_isAnimationRunning = on_off;

    devCommunication.bbhwrite_cmddata(0x31, senddata, 0x06);

    m_isAnimationRunning ? animateCtrl->getAnimationObject()->start() : animateCtrl->getAnimationObject()->pause();

    ui->switchSoundSurroundButton->setChecked(m_isAnimationRunning);

    qDebug() << "m_isAnimationRunning = " << m_isAnimationRunning;

}

void soundSurround::changeRotateDirection(bool isClockwise)
{
   


    animateCtrl->getAnimationObject()->pause();

    // clear old data, set new for it
    animateCtrl->clearOldAnimation();

    

    bool isSaveInitialPosition = false;
    if(m_initialPositions.isEmpty())
    {
        isSaveInitialPosition = true;

        qDebug() << "m_initialPositions is empty..";
    }



    // rotate 45 degree each time
    double angleInArc = 45 * M_PI / 180;


    QVector<float> directionIndex;

    if(isClockwise)
    {
        directionIndex = { 1.0, 7/8.0, 6/8.0, 5/8.0, 4/8.0, 3/8.0, 2/8.0, 1/8.0, 0 };
    }
    else
    {
        directionIndex = { 0, 1/8.0, 2/8.0, 3/8.0, 4/8.0, 5/8.0, 6/8.0, 7/8.0, 1.0 };
    }


    QStringList iconNames = { "C", "L", "LS", "LB", "W", "RB", "RS", "R" };

    for (int i = 0; i < iconNames.count(); i++)
    {


        //QPropertyAnimation *itemAnimation = qobject_cast<QPropertyAnimation *>(animateCtrl->getAnimationObject()->animationAt(i));







        QPropertyAnimation *itemAnimation = new QPropertyAnimation(m_channelItems[iconNames[i]], "pos", animateCtrl);



        double xPos = m_channelItems[iconNames[i]]->pos().x();
        double yPos = m_channelItems[iconNames[i]]->pos().y();


        if(isSaveInitialPosition || m_isUserChangeVolume)
        {
            m_initialPositions.insert(iconNames[i], QPointF(xPos, yPos));
        }

        // if the user does change the volume, we can keep use the initialize position
        // if there is change, use the new position, and update the initialize data
        if(false == m_isUserChangeVolume)
        {
            xPos = m_initialPositions[iconNames[i]].x();
            yPos = m_initialPositions[iconNames[i]].y();


        }









//        double value45 = atan2(1, 1);
//        qDebug() << "value45 =" << value45;
//         qDebug() << "value45 in angle =" << value45 *180 / M_PI;

        double valueCos = cos(angleInArc);
        double valueSin = sin(angleInArc);

        // x1 = x * cos + y * sin
        // y1 = -x * sin + y * cos



//        itemAnimation->setKeyValueAt(directionIndex[0], m_channelItems[iconNames[i]]->pos());
        itemAnimation->setKeyValueAt(directionIndex[0], QPointF(xPos, yPos));
        itemAnimation->setKeyValueAt(directionIndex[1], QPointF( xPos * valueCos + yPos * valueSin, -xPos * valueSin + yPos * valueCos));
        itemAnimation->setKeyValueAt(directionIndex[2], QPointF(xPos * cos(2 * angleInArc) + yPos * sin(2 * angleInArc),
                                                 -xPos * sin(2 * angleInArc) + yPos * cos(2 * angleInArc)));

        itemAnimation->setKeyValueAt(directionIndex[3], QPointF(xPos * cos(3 * angleInArc) + yPos * sin(3 * angleInArc),
                                                 -xPos * sin(3 * angleInArc) + yPos * cos(3 * angleInArc)));

        itemAnimation->setKeyValueAt(directionIndex[4], QPointF(xPos * cos(4 * angleInArc) + yPos * sin(4 * angleInArc),
                                                 -xPos * sin(4 * angleInArc) + yPos * cos(4 * angleInArc)));

        itemAnimation->setKeyValueAt(directionIndex[5], QPointF(xPos * cos(5 * angleInArc) + yPos * sin(5 * angleInArc),
                                                 -xPos * sin(5 * angleInArc) + yPos * cos(5 * angleInArc)));

        itemAnimation->setKeyValueAt(directionIndex[6], QPointF(xPos * cos(6 * angleInArc) + yPos * sin(6 * angleInArc),
                                                 -xPos * sin(6 * angleInArc) + yPos * cos(6 * angleInArc)));

        itemAnimation->setKeyValueAt(directionIndex[7], QPointF(xPos * cos(7 * angleInArc) + yPos * sin(7 * angleInArc),
                                                 -xPos * sin(7 * angleInArc) + yPos * cos(7 * angleInArc)));


        //itemAnimation->setKeyValueAt(directionIndex[8], m_channelItems[iconNames[i]]->pos());

        itemAnimation->setKeyValueAt(directionIndex[8], QPointF(xPos, yPos));

        itemAnimation->setDuration(30000);
        animateCtrl->getAnimationObject()->addAnimation(itemAnimation);


        qDebug() << "itemAnimation->keyValues() count = " << itemAnimation->keyValues().count();

    }



    animateCtrl->getAnimationObject()->start();

    m_isAnimationRunning = true;

    // after set new channel position
    // reset the flag
    m_isUserChangeVolume = false;
}

void soundSurround::on_clockwiseSurroundButton_clicked()
{

    changeRotateDirection(true);





}


void soundSurround::on_counterClockwiseSurroundButton_clicked()
{

    changeRotateDirection(false);



}



void soundSurround::on_horizontalSliderW_valueChanged(int value)
{

    //adjustVolume("channelW", value);
    adjustVolume("W", value);
    ui->label_W->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderCenter_valueChanged(int value)
{
    //adjustVolume("channelC", value);
    adjustVolume("C", value);
    ui->label_C->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderRB_valueChanged(int value)
{
    //adjustVolume("channelRb", value);
    adjustVolume("RB", value);
    ui->label_RB->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderLB_valueChanged(int value)
{
    //adjustVolume("channeLb", value);
    adjustVolume("LB", value);
    ui->label_LB->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderRS_valueChanged(int value)
{
    //adjustVolume("channelRs", value);
    adjustVolume("RS", value);
    ui->label_RS->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderLS_valueChanged(int value)
{
    //adjustVolume("channelLs", value);
    adjustVolume("LS", value);
    ui->label_LS->setText(QString::number(value) + "db");
}


void soundSurround::on_horizontalSliderRight_valueChanged(int value)
{
   // adjustVolume("channelR", value);
    adjustVolume("R", value);
    ui->label_R->setText(QString::number(value) + "db");
}

void soundSurround::on_horizontalSliderLeft_valueChanged(int value)
{
    //adjustVolume("channelL", value);
    adjustVolume("L", value);
    ui->label_L->setText(QString::number(value) + "db");
}

void soundSurround::adjustVolumeAll(bool bIncrease)
{
//    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderRight,
//                                  ui->horizontalSliderLS, ui->horizontalSliderRS, ui->horizontalSliderLB,
//                                  ui->horizontalSliderRB, ui->horizontalSliderW };

    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderLS,
                                  ui->horizontalSliderLB, ui->horizontalSliderW, ui->horizontalSliderRB,
                                  ui->horizontalSliderRS, ui->horizontalSliderRight,
                                 };

    for(auto pSlider : sliders)
    {

        int value = pSlider->value();

        int minValue = pSlider->minimum();
        int maxValue = pSlider->maximum();

        if(value >= minValue && value <= maxValue)
        {
            if(bIncrease)
            {
                pSlider->setValue(++value);
            }
            else
            {
                pSlider->setValue(--value);
            }

        }


        qDebug() << "currentValue " << value;

    }
}


void soundSurround::adjustVolume(QString strChannelName, int position)
{
    // slider range from -13 to 4
    int sliderValue[] = { -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };

    QMap<int, int> positionToIndex;

    int size = sizeof(sliderValue) / sizeof(sliderValue[0]);

    for(int i = 0; i < size; i++)
    {

        // save index start from 1
        positionToIndex.insert(sliderValue[i], i + 1);
    }



    double currentX = m_channelItems[strChannelName]->pos().x();
    double currentY = m_channelItems[strChannelName]->pos().y();


    // anytime if animation is stop and volume is changed
    // then the channel initialize position is changed
    if(false == m_isAnimationRunning)
    {
        m_isUserChangeVolume = true;
        //m_initialPositions[strChannelName] = QPointF(currentX, currentY);

    }


    qreal ratio = resizeWindow::getScale();

    // map slider range to the radius of circle
    // minus 74, map (74 - 200) to (-13 - 4)
    // range is 126 = 18 x 7
    int circleRadiusRange = (200 - 74) * ratio;
    double distanceToCircleCenter = circleRadiusRange / size;

    distanceToCircleCenter *= positionToIndex[position];

    // 74 map to slider -13
    distanceToCircleCenter += 74 * ratio;

    // the center is an image of 35 x 35 size, only move to the edge of it
    // skip those postion less than 40
//    if(distanceToCircleCenter < 50)
//    {
//        return;
//    }


    // atan() calculate angle not very correct
    double angle = atan2(currentY, currentX);
    //angle = angle * 180 / M_PI;
    qDebug() << "angle = " << angle * 180 / M_PI;


//    QStringList iconNameList = { "channelC", "channelL", "channelR", "channelLb", "channelRb",
//                             "channelLs", "channelRs", "channelW" };
//    for(auto str : iconNameList)
//    {
//        qDebug() << str << channelItems[str]->pos();
//    }



    qDebug() << "position = " << position;
    qDebug() << "distanceToCircleCenter = " << distanceToCircleCenter;



    //qDebug() << "Current position currentX = " << currentX << "currentY = " << currentY;



//    int newXPosition = distanceToCircleCenter * positionToIndex[position] * cos(angle);
//    int newYPosition = distanceToCircleCenter * positionToIndex[position] * sin(angle);

    double newXPosition = distanceToCircleCenter * cos(angle);
    double newYPosition = distanceToCircleCenter * sin(angle);






    m_channelItems[strChannelName]->setPos(newXPosition, newYPosition);



    //qDebug() << "New position currentX = " << newXPosition  << "currentY = " << newYPosition;
}

void soundSurround::on_minusButton_clicked()
{
    animateCtrl->getAnimationObject()->stop();
    adjustVolumeAll(false);
    m_isAnimationRunning = false;
}


void soundSurround::on_increaseButton_clicked()
{
    animateCtrl->getAnimationObject()->stop();
    adjustVolumeAll(true);
    m_isAnimationRunning = false;
}

void soundSurround::linkChannelItemToSlider(ColorItem* pItem, int itemIndex)
{
    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderLS,
                                  ui->horizontalSliderLB, ui->horizontalSliderW, ui->horizontalSliderRB,
                                  ui->horizontalSliderRS, ui->horizontalSliderRight,
                                 };


    m_channelSlidersMap.insert(pItem, sliders[itemIndex]);
}

void soundSurround::adjustAllVolumeByMoveItem(QGraphicsItem* pItem, double itemPosition)
//void soundSurround::adjustAllVolumeByMoveItem(ColorItem* pItem, double itemPosition)
{

    //qDebug() << "adjustAllVolumeByMoveItem pointer = " << pItem << " distance to circle center = " << itemPosition;

    qDebug() << " distance to circle center = " << itemPosition;



    // slider range from -13 to 4
    int sliderValue[] = { -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };

//    QMap<int, int> positionToIndex;

    int size = sizeof(sliderValue) / sizeof(sliderValue[0]);

//    for(int i = 0; i < size; i++)
//    {

//        // save index start from 1
//        positionToIndex.insert(i + 1, sliderValue[i]);
//    }

    qreal ratio = resizeWindow::getScale();

    // minus 74, map (74 - 200) to (-13 - 4)
    // range is 126 = 18 x 7
    int circleRadiusRange = (200 - 74) * ratio;
    double distancePerStep = circleRadiusRange / size;

    int targetValueIndex = (itemPosition - 74 * ratio) / distancePerStep;

    //qDebug() << "targetValueIndex = " << targetValueIndex;

    if(targetValueIndex >= 0 && targetValueIndex < size && pItem)
    {
        //m_channelSlidersMap[(QGraphicsPixmapItem*)pItem]->setValue(sliderValue[targetValueIndex]);

        m_channelSlidersMap[(ColorItem*)pItem]->setValue(sliderValue[targetValueIndex]);

    }




}


void soundSurround::on_dragAdjustVolumeButton_clicked()
{


    animateCtrl->getAnimationObject()->pause();

    m_isAnimationRunning = false;




//    //if(ui->dragAdjustVolumeButton->isChecked())
//    if(m_isAnimationPause)
//    {
//        animateCtrl->getAnimationObject()->start();
//        m_isAnimationPause = false;
//    }
//    else
//    {
//        animateCtrl->getAnimationObject()->pause();
//        m_isAnimationPause = true;
//    }



}


void soundSurround::on_resetSurroundButton_clicked()
{

    delete animateCtrl;
    animateCtrl = new animateColorItem(this);
    scene->addItem(animateCtrl);

    m_isAnimationRunning = true;


    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderLS,
                                  ui->horizontalSliderLB, ui->horizontalSliderW, ui->horizontalSliderRB,
                                  ui->horizontalSliderRS, ui->horizontalSliderRight,
                                 };

    QVector<QLabel*> channelLabels = { ui->label_C, ui->label_L, ui->label_LS, ui->label_LB, ui->label_W, ui->label_RB,
                                       ui->label_RS, ui->label_R };

    int defaultValue = -4;
    for(auto pSlider : sliders)
    {
        pSlider->setValue(defaultValue);

    }


    for(auto pLabel : channelLabels)
    {
        pLabel->setText(QString::number(defaultValue) + "db");
    }


    m_initialPositions.clear();


}

void soundSurround::saveSoundSurroundSetting(QSettings* pSettings)
{
    assert(pSettings);

    pSettings->beginGroup("7.1SoundSurround");

    if(m_isSoundSurroundOn)
    {
        pSettings->setValue("SoundSurroundSwitch", 1);
    }
    else
    {
        pSettings->setValue("SoundSurroundSwitch", 0);
    }



    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderLS,
                                  ui->horizontalSliderLB, ui->horizontalSliderW, ui->horizontalSliderRB,
                                  ui->horizontalSliderRS, ui->horizontalSliderRight,
                                 };

    QStringList iconNames = { "C", "L", "LS", "LB", "W", "RB", "RS", "R" };

    for (int i = 0; i < iconNames.count(); i++)
    {

        double xPos = m_channelItems[iconNames[i]]->pos().x();
        double yPos = m_channelItems[iconNames[i]]->pos().y();

        //QString strPos = QString("%1, %2").arg(xPos).arg(yPos);

      QString strPos = QString::number(xPos) + ", " + QString::number(yPos);


        qDebug() << iconNames[i] << " = " << strPos;

        pSettings->setValue(iconNames[i], strPos);



        // save volume for all channle
        QString channelVolume = "channle" + iconNames[i];

        pSettings->setValue(channelVolume, sliders[i]->value());


    }



    pSettings->endGroup();

}

void soundSurround::loadSoundSurroundSetting(QSettings* pSettings)
{

    pSettings->beginGroup("7.1Soundsurround");





    QVector<QSlider*> sliders = { ui->horizontalSliderCenter, ui->horizontalSliderLeft, ui->horizontalSliderLS,
                                  ui->horizontalSliderLB, ui->horizontalSliderW, ui->horizontalSliderRB,
                                  ui->horizontalSliderRS, ui->horizontalSliderRight,
                                 };

    QStringList iconNames = { "C", "L", "LS", "LB", "W", "RB", "RS", "R" };

    for (int i = 0; i < iconNames.count(); i++)
    {



        QString strChannelPosition = pSettings->value(iconNames[i], "0, 0").toString();

        qDebug() << iconNames[i] << " = " << strChannelPosition;

        QStringList strPositionList= strChannelPosition.split(",");

        double xPos = strPositionList[0].toFloat();
        double yPos = strPositionList[1].toFloat();

        m_channelItems[iconNames[i]]->setPos(xPos, yPos);

        //m_initialPositions.insert(iconNames[i], QPointF(xPos, yPos));

        //m_isUserChangeVolume = true;

        //m_initialPositions[iconNames[i]] = QPointF(xPos, yPos);
        m_initialPositions.clear();





        // set volume for all channle
        QString channelVolume = "channle" + iconNames[i];
        int sliderValue = pSettings->value(channelVolume, 0).toInt();
        sliders[i]->setValue(sliderValue);


    }

    //qDebug() << "load default ok..";

    changeRotateDirection(false);

    m_isSoundSurroundOn = pSettings->value("SoundSurroundSwitch", 0).toBool();

    if(m_isSoundSurroundOn)
    {
        ui->switchSoundSurroundButton->setChecked(true);
        //animateCtrl->getAnimationObject()->start();

        //on_switchSoundSurroundButton_clicked();


    }




    pSettings->endGroup();
}

