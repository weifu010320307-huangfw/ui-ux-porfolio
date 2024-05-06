/********************************************************************************
** Form generated from reading UI file 'soundsurround.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDSURROUND_H
#define UI_SOUNDSURROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_soundSurround
{
public:
    QPushButton *switchSoundSurroundButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QSlider *horizontalSliderLeft;
    QLabel *label;
    QSlider *horizontalSliderRight;
    QLabel *label_2;
    QSlider *horizontalSliderLS;
    QLabel *label_3;
    QSlider *horizontalSliderRS;
    QLabel *label_4;
    QSlider *horizontalSliderRB;
    QLabel *label_5;
    QSlider *horizontalSliderLB;
    QLabel *label_6;
    QSlider *horizontalSliderW;
    QLabel *label_7;
    QSlider *horizontalSliderCenter;
    QLabel *label_8;
    QLabel *label_L;
    QLabel *label_R;
    QLabel *label_LS;
    QLabel *label_RS;
    QLabel *label_LB;
    QLabel *label_RB;
    QLabel *label_C;
    QLabel *label_W;
    QPushButton *counterClockwiseSurroundButton;
    QPushButton *clockwiseSurroundButton;
    QPushButton *resetSurroundButton;
    QPushButton *minusButton;
    QPushButton *increaseButton;
    QLabel *speakerPicture;
    QPushButton *dragAdjustVolumeButton;

    void setupUi(QDialog *soundSurround)
    {
        if (soundSurround->objectName().isEmpty())
            soundSurround->setObjectName(QString::fromUtf8("soundSurround"));
        soundSurround->resize(1111, 521);
        switchSoundSurroundButton = new QPushButton(soundSurround);
        switchSoundSurroundButton->setObjectName(QString::fromUtf8("switchSoundSurroundButton"));
        switchSoundSurroundButton->setGeometry(QRect(0, 20, 191, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font.setPointSize(12);
        switchSoundSurroundButton->setFont(font);
        switchSoundSurroundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        switchSoundSurroundButton->setIconSize(QSize(32, 32));
        switchSoundSurroundButton->setCheckable(true);
        switchSoundSurroundButton->setChecked(false);
        switchSoundSurroundButton->setAutoRepeat(false);
        switchSoundSurroundButton->setAutoExclusive(true);
        switchSoundSurroundButton->setFlat(true);
        stackedWidget = new QStackedWidget(soundSurround);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 30, 591, 471));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        horizontalSliderLeft = new QSlider(soundSurround);
        horizontalSliderLeft->setObjectName(QString::fromUtf8("horizontalSliderLeft"));
        horizontalSliderLeft->setGeometry(QRect(833, 130, 201, 22));
        horizontalSliderLeft->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderLeft->setMinimum(-13);
        horizontalSliderLeft->setMaximum(4);
        horizontalSliderLeft->setPageStep(2);
        horizontalSliderLeft->setValue(-4);
        horizontalSliderLeft->setOrientation(Qt::Horizontal);
        horizontalSliderLeft->setTickPosition(QSlider::TicksAbove);
        label = new QLabel(soundSurround);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 130, 21, 20));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderRight = new QSlider(soundSurround);
        horizontalSliderRight->setObjectName(QString::fromUtf8("horizontalSliderRight"));
        horizontalSliderRight->setGeometry(QRect(833, 160, 201, 22));
        horizontalSliderRight->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderRight->setMinimum(-13);
        horizontalSliderRight->setMaximum(4);
        horizontalSliderRight->setPageStep(2);
        horizontalSliderRight->setValue(-4);
        horizontalSliderRight->setOrientation(Qt::Horizontal);
        horizontalSliderRight->setTickPosition(QSlider::TicksAbove);
        label_2 = new QLabel(soundSurround);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(810, 160, 21, 20));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderLS = new QSlider(soundSurround);
        horizontalSliderLS->setObjectName(QString::fromUtf8("horizontalSliderLS"));
        horizontalSliderLS->setGeometry(QRect(833, 210, 201, 22));
        horizontalSliderLS->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderLS->setMinimum(-13);
        horizontalSliderLS->setMaximum(4);
        horizontalSliderLS->setPageStep(2);
        horizontalSliderLS->setValue(-4);
        horizontalSliderLS->setOrientation(Qt::Horizontal);
        horizontalSliderLS->setTickPosition(QSlider::TicksAbove);
        label_3 = new QLabel(soundSurround);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(810, 210, 21, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderRS = new QSlider(soundSurround);
        horizontalSliderRS->setObjectName(QString::fromUtf8("horizontalSliderRS"));
        horizontalSliderRS->setGeometry(QRect(833, 240, 201, 22));
        horizontalSliderRS->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderRS->setMinimum(-13);
        horizontalSliderRS->setMaximum(4);
        horizontalSliderRS->setPageStep(2);
        horizontalSliderRS->setValue(-4);
        horizontalSliderRS->setOrientation(Qt::Horizontal);
        horizontalSliderRS->setTickPosition(QSlider::TicksAbove);
        label_4 = new QLabel(soundSurround);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 240, 21, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderRB = new QSlider(soundSurround);
        horizontalSliderRB->setObjectName(QString::fromUtf8("horizontalSliderRB"));
        horizontalSliderRB->setGeometry(QRect(833, 320, 201, 22));
        horizontalSliderRB->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderRB->setMinimum(-13);
        horizontalSliderRB->setMaximum(4);
        horizontalSliderRB->setPageStep(2);
        horizontalSliderRB->setValue(-4);
        horizontalSliderRB->setOrientation(Qt::Horizontal);
        horizontalSliderRB->setTickPosition(QSlider::TicksAbove);
        label_5 = new QLabel(soundSurround);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(810, 290, 21, 20));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderLB = new QSlider(soundSurround);
        horizontalSliderLB->setObjectName(QString::fromUtf8("horizontalSliderLB"));
        horizontalSliderLB->setGeometry(QRect(833, 290, 201, 22));
        horizontalSliderLB->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderLB->setMinimum(-13);
        horizontalSliderLB->setMaximum(4);
        horizontalSliderLB->setPageStep(2);
        horizontalSliderLB->setValue(-4);
        horizontalSliderLB->setOrientation(Qt::Horizontal);
        horizontalSliderLB->setTickPosition(QSlider::TicksAbove);
        label_6 = new QLabel(soundSurround);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(810, 320, 21, 20));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderW = new QSlider(soundSurround);
        horizontalSliderW->setObjectName(QString::fromUtf8("horizontalSliderW"));
        horizontalSliderW->setGeometry(QRect(833, 400, 201, 22));
        horizontalSliderW->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderW->setMinimum(-13);
        horizontalSliderW->setMaximum(4);
        horizontalSliderW->setPageStep(2);
        horizontalSliderW->setValue(-4);
        horizontalSliderW->setOrientation(Qt::Horizontal);
        horizontalSliderW->setTickPosition(QSlider::TicksAbove);
        label_7 = new QLabel(soundSurround);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(810, 370, 21, 20));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSliderCenter = new QSlider(soundSurround);
        horizontalSliderCenter->setObjectName(QString::fromUtf8("horizontalSliderCenter"));
        horizontalSliderCenter->setGeometry(QRect(833, 370, 201, 22));
        horizontalSliderCenter->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         top: 8px; bottom: 8px;    border-radius: 9px; }     QSlider::handle:horizontal {         width:15px;        border:1px;  background: #008792;         margin: -4px 0; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:horizontal {         background: darkgray;     }     QSlider::sub-page:horizontal {         background:lightblue ;     }"));
        horizontalSliderCenter->setMinimum(-13);
        horizontalSliderCenter->setMaximum(4);
        horizontalSliderCenter->setPageStep(2);
        horizontalSliderCenter->setValue(-4);
        horizontalSliderCenter->setOrientation(Qt::Horizontal);
        horizontalSliderCenter->setTickPosition(QSlider::TicksAbove);
        label_8 = new QLabel(soundSurround);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(810, 400, 21, 20));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_L = new QLabel(soundSurround);
        label_L->setObjectName(QString::fromUtf8("label_L"));
        label_L->setGeometry(QRect(1050, 130, 41, 16));
        label_L->setFont(font1);
        label_L->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_R = new QLabel(soundSurround);
        label_R->setObjectName(QString::fromUtf8("label_R"));
        label_R->setGeometry(QRect(1050, 160, 41, 16));
        label_R->setFont(font1);
        label_R->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_LS = new QLabel(soundSurround);
        label_LS->setObjectName(QString::fromUtf8("label_LS"));
        label_LS->setGeometry(QRect(1050, 210, 41, 16));
        label_LS->setFont(font1);
        label_LS->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_RS = new QLabel(soundSurround);
        label_RS->setObjectName(QString::fromUtf8("label_RS"));
        label_RS->setGeometry(QRect(1050, 240, 41, 16));
        label_RS->setFont(font1);
        label_RS->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_LB = new QLabel(soundSurround);
        label_LB->setObjectName(QString::fromUtf8("label_LB"));
        label_LB->setGeometry(QRect(1050, 290, 41, 16));
        label_LB->setFont(font1);
        label_LB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_RB = new QLabel(soundSurround);
        label_RB->setObjectName(QString::fromUtf8("label_RB"));
        label_RB->setGeometry(QRect(1050, 320, 41, 16));
        label_RB->setFont(font1);
        label_RB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_C = new QLabel(soundSurround);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        label_C->setGeometry(QRect(1050, 370, 41, 16));
        label_C->setFont(font1);
        label_C->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_W = new QLabel(soundSurround);
        label_W->setObjectName(QString::fromUtf8("label_W"));
        label_W->setGeometry(QRect(1050, 400, 41, 16));
        label_W->setFont(font1);
        label_W->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        counterClockwiseSurroundButton = new QPushButton(soundSurround);
        counterClockwiseSurroundButton->setObjectName(QString::fromUtf8("counterClockwiseSurroundButton"));
        counterClockwiseSurroundButton->setEnabled(true);
        counterClockwiseSurroundButton->setGeometry(QRect(0, 140, 191, 61));
        counterClockwiseSurroundButton->setFont(font);
        counterClockwiseSurroundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        counterClockwiseSurroundButton->setIconSize(QSize(32, 32));
        counterClockwiseSurroundButton->setCheckable(true);
        counterClockwiseSurroundButton->setChecked(false);
        counterClockwiseSurroundButton->setAutoRepeat(false);
        counterClockwiseSurroundButton->setAutoExclusive(true);
        counterClockwiseSurroundButton->setFlat(true);
        clockwiseSurroundButton = new QPushButton(soundSurround);
        clockwiseSurroundButton->setObjectName(QString::fromUtf8("clockwiseSurroundButton"));
        clockwiseSurroundButton->setEnabled(true);
        clockwiseSurroundButton->setGeometry(QRect(0, 200, 191, 61));
        clockwiseSurroundButton->setFont(font);
        clockwiseSurroundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        clockwiseSurroundButton->setIconSize(QSize(32, 32));
        clockwiseSurroundButton->setCheckable(true);
        clockwiseSurroundButton->setChecked(false);
        clockwiseSurroundButton->setAutoRepeat(false);
        clockwiseSurroundButton->setAutoExclusive(true);
        clockwiseSurroundButton->setFlat(true);
        resetSurroundButton = new QPushButton(soundSurround);
        resetSurroundButton->setObjectName(QString::fromUtf8("resetSurroundButton"));
        resetSurroundButton->setEnabled(true);
        resetSurroundButton->setGeometry(QRect(0, 260, 191, 61));
        resetSurroundButton->setFont(font);
        resetSurroundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        resetSurroundButton->setIconSize(QSize(32, 32));
        resetSurroundButton->setCheckable(true);
        resetSurroundButton->setChecked(false);
        resetSurroundButton->setAutoRepeat(false);
        resetSurroundButton->setAutoExclusive(true);
        resetSurroundButton->setFlat(true);
        minusButton = new QPushButton(soundSurround);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(810, 90, 30, 28));
        minusButton->setAutoRepeat(true);
        increaseButton = new QPushButton(soundSurround);
        increaseButton->setObjectName(QString::fromUtf8("increaseButton"));
        increaseButton->setGeometry(QRect(1050, 90, 30, 28));
        increaseButton->setAutoRepeat(true);
        speakerPicture = new QLabel(soundSurround);
        speakerPicture->setObjectName(QString::fromUtf8("speakerPicture"));
        speakerPicture->setGeometry(QRect(922, 90, 31, 26));
        dragAdjustVolumeButton = new QPushButton(soundSurround);
        dragAdjustVolumeButton->setObjectName(QString::fromUtf8("dragAdjustVolumeButton"));
        dragAdjustVolumeButton->setEnabled(true);
        dragAdjustVolumeButton->setGeometry(QRect(0, 80, 191, 61));
        dragAdjustVolumeButton->setFont(font);
        dragAdjustVolumeButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        dragAdjustVolumeButton->setIconSize(QSize(32, 32));
        dragAdjustVolumeButton->setCheckable(true);
        dragAdjustVolumeButton->setChecked(false);
        dragAdjustVolumeButton->setAutoRepeat(false);
        dragAdjustVolumeButton->setAutoExclusive(true);
        dragAdjustVolumeButton->setFlat(true);

        retranslateUi(soundSurround);

        QMetaObject::connectSlotsByName(soundSurround);
    } // setupUi

    void retranslateUi(QDialog *soundSurround)
    {
        soundSurround->setWindowTitle(QCoreApplication::translate("soundSurround", "Dialog", nullptr));
        switchSoundSurroundButton->setText(QCoreApplication::translate("soundSurround", "\345\274\200\345\220\257/\345\205\263\351\227\2557.1\347\216\257\347\273\225", nullptr));
        label->setText(QCoreApplication::translate("soundSurround", "L", nullptr));
        label_2->setText(QCoreApplication::translate("soundSurround", "R", nullptr));
        label_3->setText(QCoreApplication::translate("soundSurround", "LS", nullptr));
        label_4->setText(QCoreApplication::translate("soundSurround", "RS", nullptr));
        label_5->setText(QCoreApplication::translate("soundSurround", "LB", nullptr));
        label_6->setText(QCoreApplication::translate("soundSurround", "RB", nullptr));
        label_7->setText(QCoreApplication::translate("soundSurround", "C", nullptr));
        label_8->setText(QCoreApplication::translate("soundSurround", "W", nullptr));
//        label_L->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_R->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_LS->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_RS->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_LB->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_RB->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_C->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
//        label_W->setText(QCoreApplication::translate("soundSurround", "0 db", nullptr));
        counterClockwiseSurroundButton->setText(QCoreApplication::translate("soundSurround", "\351\200\206\346\227\266\351\222\210\347\216\257\347\273\225", nullptr));
        clockwiseSurroundButton->setText(QCoreApplication::translate("soundSurround", "\351\241\272\346\227\266\351\222\210\347\216\257\347\273\225", nullptr));
        resetSurroundButton->setText(QCoreApplication::translate("soundSurround", "\351\207\215\347\275\256", nullptr));
        minusButton->setText(QString());
        increaseButton->setText(QString());
        speakerPicture->setText(QString());
        dragAdjustVolumeButton->setText(QCoreApplication::translate("soundSurround", "\346\213\226\346\213\275\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class soundSurround: public Ui_soundSurround {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDSURROUND_H
