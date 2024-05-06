/********************************************************************************
** Form generated from reading UI file 'equalizer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUALIZER_H
#define UI_EQUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(754, 583);
        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(180, 90, 21, 331));
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksBothSides);
        verticalSlider->setTickInterval(25);
        verticalSlider_2 = new QSlider(Dialog);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(230, 90, 21, 331));
        verticalSlider_2->setValue(50);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_2->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_2->setTickInterval(25);
        verticalSlider_3 = new QSlider(Dialog);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(280, 90, 21, 331));
        verticalSlider_3->setValue(50);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_3->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_3->setTickInterval(25);
        verticalSlider_4 = new QSlider(Dialog);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setGeometry(QRect(330, 90, 21, 331));
        verticalSlider_4->setValue(50);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_4->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_4->setTickInterval(25);
        verticalSlider_5 = new QSlider(Dialog);
        verticalSlider_5->setObjectName(QString::fromUtf8("verticalSlider_5"));
        verticalSlider_5->setGeometry(QRect(380, 90, 21, 331));
        verticalSlider_5->setValue(50);
        verticalSlider_5->setOrientation(Qt::Vertical);
        verticalSlider_5->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_5->setTickInterval(25);
        verticalSlider_6 = new QSlider(Dialog);
        verticalSlider_6->setObjectName(QString::fromUtf8("verticalSlider_6"));
        verticalSlider_6->setGeometry(QRect(430, 90, 21, 331));
        verticalSlider_6->setValue(50);
        verticalSlider_6->setOrientation(Qt::Vertical);
        verticalSlider_6->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_6->setTickInterval(25);
        verticalSlider_7 = new QSlider(Dialog);
        verticalSlider_7->setObjectName(QString::fromUtf8("verticalSlider_7"));
        verticalSlider_7->setGeometry(QRect(480, 90, 21, 331));
        verticalSlider_7->setValue(50);
        verticalSlider_7->setOrientation(Qt::Vertical);
        verticalSlider_7->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_7->setTickInterval(25);
        verticalSlider_8 = new QSlider(Dialog);
        verticalSlider_8->setObjectName(QString::fromUtf8("verticalSlider_8"));
        verticalSlider_8->setGeometry(QRect(530, 90, 21, 331));
        verticalSlider_8->setValue(50);
        verticalSlider_8->setOrientation(Qt::Vertical);
        verticalSlider_8->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_8->setTickInterval(25);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUALIZER_H
