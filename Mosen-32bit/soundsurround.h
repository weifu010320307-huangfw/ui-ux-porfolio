#ifndef SOUNDSURROUND_H
#define SOUNDSURROUND_H

#include <QDialog>
#include <QGraphicsView>
#include <QMap>

class animateColorItem;
class soundSurrondScene;
class QGraphicsItem;
class QGraphicsPixmapItem;
class QSlider;
class ColorItem;
class QSettings;


namespace Ui {
class soundSurround;
}

class soundSurround : public QDialog
{
    Q_OBJECT

public:
    explicit soundSurround(QWidget *parent = nullptr);


    ~soundSurround();

    void translateUI();
    void adjustAllVolumeByMoveItem(QGraphicsItem* pItem, double itemPosition);
    bool isInAnimation() { return m_isAnimationRunning; }


    void saveSoundSurroundSetting(QSettings* pSettings);
    void loadSoundSurroundSetting(QSettings* pSettings);

private:
    void adjustVolume(QString strChannelName, int position);
    void adjustVolumeAll(bool bIncrease);
    void initializeChannelCurrentValue();


private slots:
    void on_switchSoundSurroundButton_clicked();

    void on_clockwiseSurroundButton_clicked();

    void on_counterClockwiseSurroundButton_clicked();

    void on_horizontalSliderLeft_valueChanged(int value);

    void on_horizontalSliderRight_valueChanged(int value);

    void on_horizontalSliderLS_valueChanged(int value);

    void on_horizontalSliderRS_valueChanged(int value);

    void on_horizontalSliderLB_valueChanged(int value);

    void on_horizontalSliderRB_valueChanged(int value);

    void on_horizontalSliderCenter_valueChanged(int value);

    void on_horizontalSliderW_valueChanged(int value);



    void on_minusButton_clicked();

    void on_increaseButton_clicked();

    void linkChannelItemToSlider(ColorItem* pItem, int itemIndex);

    //void adjustAllVolumeByMoveItem(ColorItem* pItem, double itemPosition);


    void on_dragAdjustVolumeButton_clicked();

    void on_resetSurroundButton_clicked();
    void changeRotateDirection(bool isClockwise);

private:
    Ui::soundSurround *ui;

    QGraphicsView* pView;
    QGraphicsScene* scene;

    soundSurrondScene* m_soundSurrondScene;

    animateColorItem* animateCtrl;

    QMap<QString, ColorItem*> m_channelItems;


    QMap<ColorItem*, QSlider*> m_channelSlidersMap;

    bool m_isAnimationRunning;
    bool m_isSoundSurroundOn;

    bool m_isUserChangeVolume;
    QMap<QString, QPointF> m_initialPositions;



    friend class animateColorItem;

};

#endif // SOUNDSURROUND_H
