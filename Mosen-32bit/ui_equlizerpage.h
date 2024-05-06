/********************************************************************************
** Form generated from reading UI file 'equlizerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQULIZERPAGE_H
#define UI_EQULIZERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_equlizerPage
{
public:
    QSlider *verticalSlider1;
    QSlider *verticalSlider2;
    QSlider *verticalSlider4;
    QSlider *verticalSlider3;
    QSlider *verticalSlider6;
    QSlider *verticalSlider5;
    QPushButton *setting2Button;
    QPushButton *enable3DButton;
    QPushButton *enableEQButton;
    QPushButton *resetButton;
    QPushButton *setting1Button;
    QSlider *verticalSlider7;
    QSlider *verticalSlider8;
    QSlider *verticalSlider9;
    QSlider *verticalSlider10;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line1;
    QFrame *line2;
    QFrame *line3;
    QFrame *line4;
    QFrame *line5;
    QLabel *lb_32;
    QLabel *lb_64;
    QLabel *lb_125;
    QLabel *lb_250;
    QLabel *lb_500;
    QLabel *lb_1000;
    QLabel *lb_2000;
    QLabel *lb_4000;
    QLabel *lb_8000;
    QLabel *lb_16000;

    void setupUi(QDialog *equlizerPage)
    {
        if (equlizerPage->objectName().isEmpty())
            equlizerPage->setObjectName(QString::fromUtf8("equlizerPage"));
        equlizerPage->resize(1111, 522);
        verticalSlider1 = new QSlider(equlizerPage);
        verticalSlider1->setObjectName(QString::fromUtf8("verticalSlider1"));
        verticalSlider1->setGeometry(QRect(310, 60, 21, 381));
        verticalSlider1->setAutoFillBackground(false);
        verticalSlider1->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;    border-radius: 9px; }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 15px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider1->setMinimum(-12);
        verticalSlider1->setMaximum(12);
        verticalSlider1->setPageStep(2);
        verticalSlider1->setValue(0);
        verticalSlider1->setOrientation(Qt::Vertical);
        verticalSlider1->setInvertedAppearance(false);
        verticalSlider1->setInvertedControls(false);
        verticalSlider1->setTickPosition(QSlider::TicksBothSides);
        verticalSlider1->setTickInterval(25);
        verticalSlider2 = new QSlider(equlizerPage);
        verticalSlider2->setObjectName(QString::fromUtf8("verticalSlider2"));
        verticalSlider2->setGeometry(QRect(380, 60, 21, 381));
        verticalSlider2->setAutoFillBackground(false);
        verticalSlider2->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider2->setMinimum(-12);
        verticalSlider2->setMaximum(12);
        verticalSlider2->setPageStep(2);
        verticalSlider2->setValue(0);
        verticalSlider2->setOrientation(Qt::Vertical);
        verticalSlider2->setInvertedAppearance(false);
        verticalSlider2->setInvertedControls(false);
        verticalSlider2->setTickPosition(QSlider::TicksBothSides);
        verticalSlider2->setTickInterval(25);
        verticalSlider4 = new QSlider(equlizerPage);
        verticalSlider4->setObjectName(QString::fromUtf8("verticalSlider4"));
        verticalSlider4->setGeometry(QRect(520, 60, 21, 381));
        verticalSlider4->setAutoFillBackground(false);
        verticalSlider4->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider4->setMinimum(-12);
        verticalSlider4->setMaximum(12);
        verticalSlider4->setPageStep(2);
        verticalSlider4->setValue(0);
        verticalSlider4->setOrientation(Qt::Vertical);
        verticalSlider4->setInvertedAppearance(false);
        verticalSlider4->setInvertedControls(false);
        verticalSlider4->setTickPosition(QSlider::TicksBothSides);
        verticalSlider4->setTickInterval(25);
        verticalSlider3 = new QSlider(equlizerPage);
        verticalSlider3->setObjectName(QString::fromUtf8("verticalSlider3"));
        verticalSlider3->setGeometry(QRect(450, 60, 21, 381));
        verticalSlider3->setAutoFillBackground(false);
        verticalSlider3->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider3->setMinimum(-12);
        verticalSlider3->setMaximum(12);
        verticalSlider3->setPageStep(2);
        verticalSlider3->setValue(0);
        verticalSlider3->setOrientation(Qt::Vertical);
        verticalSlider3->setInvertedAppearance(false);
        verticalSlider3->setInvertedControls(false);
        verticalSlider3->setTickPosition(QSlider::TicksBothSides);
        verticalSlider3->setTickInterval(25);
        verticalSlider6 = new QSlider(equlizerPage);
        verticalSlider6->setObjectName(QString::fromUtf8("verticalSlider6"));
        verticalSlider6->setGeometry(QRect(660, 60, 21, 381));
        verticalSlider6->setAutoFillBackground(false);
        verticalSlider6->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider6->setMinimum(-12);
        verticalSlider6->setMaximum(12);
        verticalSlider6->setPageStep(2);
        verticalSlider6->setValue(0);
        verticalSlider6->setOrientation(Qt::Vertical);
        verticalSlider6->setInvertedAppearance(false);
        verticalSlider6->setInvertedControls(false);
        verticalSlider6->setTickPosition(QSlider::TicksBothSides);
        verticalSlider6->setTickInterval(25);
        verticalSlider5 = new QSlider(equlizerPage);
        verticalSlider5->setObjectName(QString::fromUtf8("verticalSlider5"));
        verticalSlider5->setGeometry(QRect(590, 60, 21, 381));
        verticalSlider5->setAutoFillBackground(false);
        verticalSlider5->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider5->setMinimum(-12);
        verticalSlider5->setMaximum(12);
        verticalSlider5->setPageStep(2);
        verticalSlider5->setValue(0);
        verticalSlider5->setOrientation(Qt::Vertical);
        verticalSlider5->setInvertedAppearance(false);
        verticalSlider5->setInvertedControls(false);
        verticalSlider5->setTickPosition(QSlider::TicksBothSides);
        verticalSlider5->setTickInterval(25);
        setting2Button = new QPushButton(equlizerPage);
        setting2Button->setObjectName(QString::fromUtf8("setting2Button"));
        setting2Button->setGeometry(QRect(0, 260, 191, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font.setPointSize(12);
        setting2Button->setFont(font);
        setting2Button->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        setting2Button->setCheckable(true);
        setting2Button->setAutoExclusive(true);
        setting2Button->setFlat(true);
        enable3DButton = new QPushButton(equlizerPage);
        enable3DButton->setObjectName(QString::fromUtf8("enable3DButton"));
        enable3DButton->setGeometry(QRect(0, 80, 191, 61));
        enable3DButton->setFont(font);
        enable3DButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        enable3DButton->setCheckable(true);
        enable3DButton->setAutoExclusive(true);
        enable3DButton->setFlat(true);
        enableEQButton = new QPushButton(equlizerPage);
        enableEQButton->setObjectName(QString::fromUtf8("enableEQButton"));
        enableEQButton->setGeometry(QRect(0, 20, 191, 61));
        enableEQButton->setFont(font);
        enableEQButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        enableEQButton->setIconSize(QSize(32, 32));
        enableEQButton->setCheckable(true);
        enableEQButton->setChecked(false);
        enableEQButton->setAutoRepeat(false);
        enableEQButton->setAutoExclusive(true);
        enableEQButton->setFlat(true);
        resetButton = new QPushButton(equlizerPage);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(0, 140, 191, 61));
        resetButton->setFont(font);
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        resetButton->setCheckable(true);
        resetButton->setAutoExclusive(true);
        resetButton->setFlat(true);
        setting1Button = new QPushButton(equlizerPage);
        setting1Button->setObjectName(QString::fromUtf8("setting1Button"));
        setting1Button->setGeometry(QRect(0, 200, 191, 61));
        setting1Button->setFont(font);
        setting1Button->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        setting1Button->setCheckable(true);
        setting1Button->setAutoExclusive(true);
        setting1Button->setFlat(true);
        verticalSlider7 = new QSlider(equlizerPage);
        verticalSlider7->setObjectName(QString::fromUtf8("verticalSlider7"));
        verticalSlider7->setGeometry(QRect(730, 60, 21, 381));
        verticalSlider7->setAutoFillBackground(false);
        verticalSlider7->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider7->setMinimum(-12);
        verticalSlider7->setMaximum(12);
        verticalSlider7->setPageStep(2);
        verticalSlider7->setValue(0);
        verticalSlider7->setOrientation(Qt::Vertical);
        verticalSlider7->setInvertedAppearance(false);
        verticalSlider7->setInvertedControls(false);
        verticalSlider7->setTickPosition(QSlider::TicksBothSides);
        verticalSlider7->setTickInterval(25);
        verticalSlider8 = new QSlider(equlizerPage);
        verticalSlider8->setObjectName(QString::fromUtf8("verticalSlider8"));
        verticalSlider8->setGeometry(QRect(800, 60, 21, 381));
        verticalSlider8->setAutoFillBackground(false);
        verticalSlider8->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider8->setMinimum(-12);
        verticalSlider8->setMaximum(12);
        verticalSlider8->setPageStep(2);
        verticalSlider8->setValue(0);
        verticalSlider8->setOrientation(Qt::Vertical);
        verticalSlider8->setInvertedAppearance(false);
        verticalSlider8->setInvertedControls(false);
        verticalSlider8->setTickPosition(QSlider::TicksBothSides);
        verticalSlider8->setTickInterval(25);
        verticalSlider9 = new QSlider(equlizerPage);
        verticalSlider9->setObjectName(QString::fromUtf8("verticalSlider9"));
        verticalSlider9->setGeometry(QRect(870, 60, 21, 381));
        verticalSlider9->setAutoFillBackground(false);
        verticalSlider9->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider9->setMinimum(-12);
        verticalSlider9->setMaximum(12);
        verticalSlider9->setPageStep(2);
        verticalSlider9->setValue(0);
        verticalSlider9->setOrientation(Qt::Vertical);
        verticalSlider9->setInvertedAppearance(false);
        verticalSlider9->setInvertedControls(false);
        verticalSlider9->setTickPosition(QSlider::TicksBothSides);
        verticalSlider9->setTickInterval(25);
        verticalSlider10 = new QSlider(equlizerPage);
        verticalSlider10->setObjectName(QString::fromUtf8("verticalSlider10"));
        verticalSlider10->setGeometry(QRect(940, 60, 21, 381));
        verticalSlider10->setAutoFillBackground(false);
        verticalSlider10->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {         background: red;         position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */         left: 4px; right: 4px;     }     QSlider::handle:vertical {         height: 15px;        border:1px;  background: #008792;         margin: 0 -4px; /* expand outside the groove */    border-radius: 1px; }     QSlider::add-page:vertical {         background: lightblue;     }     QSlider::sub-page:vertical {         background: darkgray;     }\n"
""));
        verticalSlider10->setMinimum(-12);
        verticalSlider10->setMaximum(12);
        verticalSlider10->setPageStep(2);
        verticalSlider10->setValue(0);
        verticalSlider10->setOrientation(Qt::Vertical);
        verticalSlider10->setInvertedAppearance(false);
        verticalSlider10->setInvertedControls(false);
        verticalSlider10->setTickPosition(QSlider::TicksBothSides);
        verticalSlider10->setTickInterval(25);
        label = new QLabel(equlizerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 450, 41, 16));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(equlizerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 450, 41, 16));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(equlizerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 450, 41, 16));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(equlizerPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 450, 41, 16));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(equlizerPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 450, 41, 16));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(equlizerPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(660, 450, 41, 16));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(equlizerPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(730, 450, 41, 16));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(equlizerPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(800, 450, 41, 16));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(equlizerPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(870, 450, 41, 16));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(equlizerPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(940, 450, 91, 16));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line1 = new QFrame(equlizerPage);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setGeometry(QRect(350, 60, 21, 16));
        line1->setAutoFillBackground(true);
        line1->setStyleSheet(QString::fromUtf8(""));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);
        line2 = new QFrame(equlizerPage);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setGeometry(QRect(350, 140, 21, 16));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);
        line3 = new QFrame(equlizerPage);
        line3->setObjectName(QString::fromUtf8("line3"));
        line3->setGeometry(QRect(350, 330, 21, 16));
        line3->setFrameShape(QFrame::HLine);
        line3->setFrameShadow(QFrame::Sunken);
        line4 = new QFrame(equlizerPage);
        line4->setObjectName(QString::fromUtf8("line4"));
        line4->setGeometry(QRect(350, 420, 21, 16));
        line4->setFrameShape(QFrame::HLine);
        line4->setFrameShadow(QFrame::Sunken);
        line5 = new QFrame(equlizerPage);
        line5->setObjectName(QString::fromUtf8("line5"));
        line5->setGeometry(QRect(350, 240, 21, 16));
        line5->setFrameShape(QFrame::HLine);
        line5->setFrameShadow(QFrame::Sunken);
        lb_32 = new QLabel(equlizerPage);
        lb_32->setObjectName(QString::fromUtf8("lb_32"));
        lb_32->setGeometry(QRect(310, 30, 41, 16));
        QFont font2;
        font2.setPointSize(12);
        lb_32->setFont(font2);
        lb_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_64 = new QLabel(equlizerPage);
        lb_64->setObjectName(QString::fromUtf8("lb_64"));
        lb_64->setGeometry(QRect(380, 30, 41, 16));
        lb_64->setFont(font2);
        lb_64->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_125 = new QLabel(equlizerPage);
        lb_125->setObjectName(QString::fromUtf8("lb_125"));
        lb_125->setGeometry(QRect(450, 30, 41, 16));
        lb_125->setFont(font2);
        lb_125->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_250 = new QLabel(equlizerPage);
        lb_250->setObjectName(QString::fromUtf8("lb_250"));
        lb_250->setGeometry(QRect(520, 30, 41, 16));
        lb_250->setFont(font2);
        lb_250->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_500 = new QLabel(equlizerPage);
        lb_500->setObjectName(QString::fromUtf8("lb_500"));
        lb_500->setGeometry(QRect(590, 30, 41, 16));
        lb_500->setFont(font2);
        lb_500->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_1000 = new QLabel(equlizerPage);
        lb_1000->setObjectName(QString::fromUtf8("lb_1000"));
        lb_1000->setGeometry(QRect(660, 30, 41, 16));
        lb_1000->setFont(font2);
        lb_1000->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_2000 = new QLabel(equlizerPage);
        lb_2000->setObjectName(QString::fromUtf8("lb_2000"));
        lb_2000->setGeometry(QRect(730, 30, 41, 16));
        lb_2000->setFont(font2);
        lb_2000->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_4000 = new QLabel(equlizerPage);
        lb_4000->setObjectName(QString::fromUtf8("lb_4000"));
        lb_4000->setGeometry(QRect(800, 30, 41, 16));
        lb_4000->setFont(font2);
        lb_4000->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_8000 = new QLabel(equlizerPage);
        lb_8000->setObjectName(QString::fromUtf8("lb_8000"));
        lb_8000->setGeometry(QRect(870, 30, 41, 16));
        lb_8000->setFont(font2);
        lb_8000->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_16000 = new QLabel(equlizerPage);
        lb_16000->setObjectName(QString::fromUtf8("lb_16000"));
        lb_16000->setGeometry(QRect(940, 30, 41, 16));
        lb_16000->setFont(font2);
        lb_16000->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(equlizerPage);

        QMetaObject::connectSlotsByName(equlizerPage);
    } // setupUi

    void retranslateUi(QDialog *equlizerPage)
    {
        equlizerPage->setWindowTitle(QCoreApplication::translate("equlizerPage", "Dialog", nullptr));
        setting2Button->setText(QCoreApplication::translate("equlizerPage", "\350\256\276\345\256\2322", nullptr));
        enable3DButton->setText(QCoreApplication::translate("equlizerPage", "\345\220\257\347\224\2503D", nullptr));
        enableEQButton->setText(QCoreApplication::translate("equlizerPage", "\345\220\257\345\212\250EQ", nullptr));
        resetButton->setText(QCoreApplication::translate("equlizerPage", "\351\207\215\347\275\256", nullptr));
        setting1Button->setText(QCoreApplication::translate("equlizerPage", "\350\256\276\345\256\2321", nullptr));
        label->setText(QCoreApplication::translate("equlizerPage", "32", nullptr));
        label_2->setText(QCoreApplication::translate("equlizerPage", "64", nullptr));
        label_3->setText(QCoreApplication::translate("equlizerPage", "125", nullptr));
        label_4->setText(QCoreApplication::translate("equlizerPage", "250", nullptr));
        label_5->setText(QCoreApplication::translate("equlizerPage", "500", nullptr));
        label_6->setText(QCoreApplication::translate("equlizerPage", "1000", nullptr));
        label_7->setText(QCoreApplication::translate("equlizerPage", "2000", nullptr));
        label_8->setText(QCoreApplication::translate("equlizerPage", "4000", nullptr));
        label_9->setText(QCoreApplication::translate("equlizerPage", "8000", nullptr));
        label_10->setText(QCoreApplication::translate("equlizerPage", "16000(HZ)", nullptr));
        lb_32->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_64->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_125->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_250->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_500->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_1000->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_2000->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_4000->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_8000->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
        lb_16000->setText(QCoreApplication::translate("equlizerPage", "0 db", nullptr));
    } // retranslateUi

};

namespace Ui {
    class equlizerPage: public Ui_equlizerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQULIZERPAGE_H
