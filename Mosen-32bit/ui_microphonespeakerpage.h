/********************************************************************************
** Form generated from reading UI file 'microphonespeakerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICROPHONESPEAKERPAGE_H
#define UI_MICROPHONESPEAKERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_microphoneSpeakerPage
{
public:
    QDial *speakerAdjust;
    QLCDNumber *microphoneLcdNumber;
    QLCDNumber *speakerLcdNumber;
    QLabel *label_2;
    QLabel *label;
    QDial *microphoneAdjust;
    QPushButton *microphoneDisableButton;
    QPushButton *speakerDisableButton;

    void setupUi(QDialog *microphoneSpeakerPage)
    {
        if (microphoneSpeakerPage->objectName().isEmpty())
            microphoneSpeakerPage->setObjectName(QString::fromUtf8("microphoneSpeakerPage"));
        microphoneSpeakerPage->resize(1111, 522);
        speakerAdjust = new QDial(microphoneSpeakerPage);
        speakerAdjust->setObjectName(QString::fromUtf8("speakerAdjust"));
        speakerAdjust->setGeometry(QRect(630, 200, 181, 161));
        speakerAdjust->setMaximum(100);
        microphoneLcdNumber = new QLCDNumber(microphoneSpeakerPage);
        microphoneLcdNumber->setObjectName(QString::fromUtf8("microphoneLcdNumber"));
        microphoneLcdNumber->setGeometry(QRect(350, 110, 111, 51));
        microphoneLcdNumber->setSegmentStyle(QLCDNumber::Filled);
        microphoneLcdNumber->setProperty("value", QVariant(50.000000000000000));
        speakerLcdNumber = new QLCDNumber(microphoneSpeakerPage);
        speakerLcdNumber->setObjectName(QString::fromUtf8("speakerLcdNumber"));
        speakerLcdNumber->setGeometry(QRect(630, 110, 111, 51));
        speakerLcdNumber->setSegmentStyle(QLCDNumber::Filled);
        speakerLcdNumber->setProperty("value", QVariant(60.000000000000000));
        label_2 = new QLabel(microphoneSpeakerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(690, 390, 111, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_2->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font.setPointSize(14);
        label_2->setFont(font);
        label = new QLabel(microphoneSpeakerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 390, 111, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label->setPalette(palette1);
        label->setFont(font);
        microphoneAdjust = new QDial(microphoneSpeakerPage);
        microphoneAdjust->setObjectName(QString::fromUtf8("microphoneAdjust"));
        microphoneAdjust->setGeometry(QRect(350, 200, 181, 161));
        microphoneAdjust->setMaximum(100);
        microphoneDisableButton = new QPushButton(microphoneSpeakerPage);
        microphoneDisableButton->setObjectName(QString::fromUtf8("microphoneDisableButton"));
        microphoneDisableButton->setGeometry(QRect(0, 20, 191, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font1.setPointSize(12);
        microphoneDisableButton->setFont(font1);
        microphoneDisableButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        microphoneDisableButton->setIconSize(QSize(32, 32));
        microphoneDisableButton->setCheckable(true);
        microphoneDisableButton->setChecked(false);
        microphoneDisableButton->setAutoRepeat(false);
        microphoneDisableButton->setAutoExclusive(false);
        microphoneDisableButton->setFlat(true);
        speakerDisableButton = new QPushButton(microphoneSpeakerPage);
        speakerDisableButton->setObjectName(QString::fromUtf8("speakerDisableButton"));
        speakerDisableButton->setGeometry(QRect(0, 80, 191, 61));
        speakerDisableButton->setFont(font1);
        speakerDisableButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        speakerDisableButton->setIconSize(QSize(32, 32));
        speakerDisableButton->setCheckable(true);
        speakerDisableButton->setChecked(false);
        speakerDisableButton->setAutoRepeat(false);
        speakerDisableButton->setAutoExclusive(false);
        speakerDisableButton->setFlat(true);

        retranslateUi(microphoneSpeakerPage);

        QMetaObject::connectSlotsByName(microphoneSpeakerPage);
    } // setupUi

    void retranslateUi(QDialog *microphoneSpeakerPage)
    {
        microphoneSpeakerPage->setWindowTitle(QCoreApplication::translate("microphoneSpeakerPage", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("microphoneSpeakerPage", "\346\211\254\345\243\260\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("microphoneSpeakerPage", "\351\272\246\345\205\213\351\243\216", nullptr));
        microphoneDisableButton->setText(QCoreApplication::translate("microphoneSpeakerPage", "\351\272\246\345\205\213\351\243\216\351\235\231\351\237\263/\345\274\200\345\220\257", nullptr));
        speakerDisableButton->setText(QCoreApplication::translate("microphoneSpeakerPage", "\346\211\254\345\243\260\345\231\250\351\235\231\351\237\263/\345\274\200\345\220\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class microphoneSpeakerPage: public Ui_microphoneSpeakerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICROPHONESPEAKERPAGE_H
