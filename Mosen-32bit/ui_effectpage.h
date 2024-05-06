/********************************************************************************
** Form generated from reading UI file 'effectpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFECTPAGE_H
#define UI_EFFECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_effectPage
{
public:
    QPushButton *theaterEffectButton;
    QPushButton *bathRoomEffectButton;
    QPushButton *outdoorEffectButton;
    QPushButton *livingRoomEffectButton;
    QPushButton *noEffectButton;
    QLabel *effectPicture;

    void setupUi(QDialog *effectPage)
    {
        if (effectPage->objectName().isEmpty())
            effectPage->setObjectName(QString::fromUtf8("effectPage"));
        effectPage->resize(1111, 522);
        effectPage->setWindowOpacity(1.000000000000000);
        effectPage->setStyleSheet(QString::fromUtf8(""));
        theaterEffectButton = new QPushButton(effectPage);
        theaterEffectButton->setObjectName(QString::fromUtf8("theaterEffectButton"));
        theaterEffectButton->setGeometry(QRect(0, 20, 191, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font.setPointSize(12);
        theaterEffectButton->setFont(font);
        theaterEffectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        theaterEffectButton->setIconSize(QSize(32, 32));
        theaterEffectButton->setCheckable(true);
        theaterEffectButton->setChecked(false);
        theaterEffectButton->setAutoRepeat(false);
        theaterEffectButton->setAutoExclusive(true);
        theaterEffectButton->setFlat(true);
        bathRoomEffectButton = new QPushButton(effectPage);
        bathRoomEffectButton->setObjectName(QString::fromUtf8("bathRoomEffectButton"));
        bathRoomEffectButton->setGeometry(QRect(0, 80, 191, 61));
        bathRoomEffectButton->setFont(font);
        bathRoomEffectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        bathRoomEffectButton->setIconSize(QSize(32, 32));
        bathRoomEffectButton->setCheckable(true);
        bathRoomEffectButton->setChecked(false);
        bathRoomEffectButton->setAutoRepeat(false);
        bathRoomEffectButton->setAutoExclusive(true);
        bathRoomEffectButton->setFlat(true);
        outdoorEffectButton = new QPushButton(effectPage);
        outdoorEffectButton->setObjectName(QString::fromUtf8("outdoorEffectButton"));
        outdoorEffectButton->setGeometry(QRect(0, 140, 191, 61));
        outdoorEffectButton->setFont(font);
        outdoorEffectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        outdoorEffectButton->setIconSize(QSize(32, 32));
        outdoorEffectButton->setCheckable(true);
        outdoorEffectButton->setChecked(false);
        outdoorEffectButton->setAutoRepeat(false);
        outdoorEffectButton->setAutoExclusive(true);
        outdoorEffectButton->setFlat(true);
        livingRoomEffectButton = new QPushButton(effectPage);
        livingRoomEffectButton->setObjectName(QString::fromUtf8("livingRoomEffectButton"));
        livingRoomEffectButton->setGeometry(QRect(0, 200, 191, 61));
        livingRoomEffectButton->setFont(font);
        livingRoomEffectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        livingRoomEffectButton->setIconSize(QSize(32, 32));
        livingRoomEffectButton->setCheckable(true);
        livingRoomEffectButton->setChecked(false);
        livingRoomEffectButton->setAutoRepeat(false);
        livingRoomEffectButton->setAutoExclusive(true);
        livingRoomEffectButton->setFlat(true);
        noEffectButton = new QPushButton(effectPage);
        noEffectButton->setObjectName(QString::fromUtf8("noEffectButton"));
        noEffectButton->setGeometry(QRect(0, 260, 191, 61));
        noEffectButton->setFont(font);
        noEffectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{background-color:red;}\n"
"QPushButton:checked{background-color:red;}"));
        noEffectButton->setIconSize(QSize(32, 32));
        noEffectButton->setCheckable(true);
        noEffectButton->setChecked(true);
        noEffectButton->setAutoRepeat(false);
        noEffectButton->setAutoExclusive(true);
        noEffectButton->setFlat(true);
        effectPicture = new QLabel(effectPage);
        effectPicture->setObjectName(QString::fromUtf8("effectPicture"));
        effectPicture->setGeometry(QRect(220, 0, 891, 511));

        retranslateUi(effectPage);

        QMetaObject::connectSlotsByName(effectPage);
    } // setupUi

    void retranslateUi(QDialog *effectPage)
    {
        effectPage->setWindowTitle(QCoreApplication::translate("effectPage", "Dialog", nullptr));
        theaterEffectButton->setText(QCoreApplication::translate("effectPage", "\346\210\217\351\231\242", nullptr));
        bathRoomEffectButton->setText(QCoreApplication::translate("effectPage", "\346\265\264\345\256\244", nullptr));
        outdoorEffectButton->setText(QCoreApplication::translate("effectPage", "\346\210\267\345\244\226", nullptr));
        livingRoomEffectButton->setText(QCoreApplication::translate("effectPage", "\345\256\242\345\216\205", nullptr));
        noEffectButton->setText(QCoreApplication::translate("effectPage", "\346\227\240\351\237\263\346\225\210", nullptr));
        effectPicture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class effectPage: public Ui_effectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFECTPAGE_H
