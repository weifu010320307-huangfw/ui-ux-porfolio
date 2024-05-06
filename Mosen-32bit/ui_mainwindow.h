/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *logoPicture;
    QPushButton *equlizerPageButton;
    QFrame *line;
    QPushButton *effectPageButton;
    QPushButton *microphonePageButton;
    QPushButton *surroundSoundButton;
    QFrame *line_5;
    QFrame *line_4;
    QFrame *line_3;
    QPushButton *saveConfigButton;
    QPushButton *selectConfigButton;
    QFrame *line_2;
    QFrame *line_6;
    QLabel *statusPicture;
    QLabel *languageText;
    QPushButton *minimumButton;
    QPushButton *closeButton;
    QPushButton *languageButton;
    QPushButton *aboutButton;
    QFrame *line_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 807);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1200, 807));
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 230, 1131, 521));
        stackedWidget->setStyleSheet(QString::fromUtf8("background:transparent;"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        logoPicture = new QLabel(centralwidget);
        logoPicture->setObjectName(QString::fromUtf8("logoPicture"));
        logoPicture->setGeometry(QRect(70, 60, 291, 41));
        logoPicture->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        equlizerPageButton = new QPushButton(centralwidget);
        equlizerPageButton->setObjectName(QString::fromUtf8("equlizerPageButton"));
        equlizerPageButton->setGeometry(QRect(30, 130, 151, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font.setPointSize(16);
        equlizerPageButton->setFont(font);
        equlizerPageButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        equlizerPageButton->setIconSize(QSize(32, 32));
        equlizerPageButton->setCheckable(true);
        equlizerPageButton->setChecked(false);
        equlizerPageButton->setAutoRepeat(false);
        equlizerPageButton->setAutoExclusive(false);
        equlizerPageButton->setFlat(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, 160, 20, 21));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        effectPageButton = new QPushButton(centralwidget);
        effectPageButton->setObjectName(QString::fromUtf8("effectPageButton"));
        effectPageButton->setGeometry(QRect(190, 130, 151, 81));
        effectPageButton->setFont(font);
        effectPageButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        effectPageButton->setIconSize(QSize(32, 32));
        effectPageButton->setCheckable(true);
        effectPageButton->setChecked(false);
        effectPageButton->setAutoRepeat(false);
        effectPageButton->setAutoExclusive(false);
        effectPageButton->setFlat(true);
        microphonePageButton = new QPushButton(centralwidget);
        microphonePageButton->setObjectName(QString::fromUtf8("microphonePageButton"));
        microphonePageButton->setGeometry(QRect(350, 130, 151, 81));
        microphonePageButton->setFont(font);
        microphonePageButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        microphonePageButton->setIconSize(QSize(32, 32));
        microphonePageButton->setCheckable(true);
        microphonePageButton->setChecked(false);
        microphonePageButton->setAutoRepeat(false);
        microphonePageButton->setAutoExclusive(false);
        microphonePageButton->setFlat(true);
        surroundSoundButton = new QPushButton(centralwidget);
        surroundSoundButton->setObjectName(QString::fromUtf8("surroundSoundButton"));
        surroundSoundButton->setGeometry(QRect(500, 130, 151, 81));
        surroundSoundButton->setFont(font);
        surroundSoundButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        surroundSoundButton->setIconSize(QSize(32, 32));
        surroundSoundButton->setCheckable(true);
        surroundSoundButton->setChecked(false);
        surroundSoundButton->setAutoRepeat(false);
        surroundSoundButton->setAutoExclusive(false);
        surroundSoundButton->setFlat(true);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(650, 160, 20, 21));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(490, 160, 20, 21));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(330, 160, 20, 21));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        saveConfigButton = new QPushButton(centralwidget);
        saveConfigButton->setObjectName(QString::fromUtf8("saveConfigButton"));
        saveConfigButton->setGeometry(QRect(710, 50, 111, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font1.setPointSize(12);
        saveConfigButton->setFont(font1);
        saveConfigButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        saveConfigButton->setIconSize(QSize(32, 32));
        saveConfigButton->setCheckable(true);
        saveConfigButton->setChecked(false);
        saveConfigButton->setAutoRepeat(false);
        saveConfigButton->setAutoExclusive(false);
        saveConfigButton->setFlat(true);
        selectConfigButton = new QPushButton(centralwidget);
        selectConfigButton->setObjectName(QString::fromUtf8("selectConfigButton"));
        selectConfigButton->setGeometry(QRect(830, 50, 111, 51));
        selectConfigButton->setFont(font1);
        selectConfigButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        selectConfigButton->setIconSize(QSize(32, 32));
        selectConfigButton->setCheckable(true);
        selectConfigButton->setChecked(false);
        selectConfigButton->setAutoRepeat(false);
        selectConfigButton->setAutoExclusive(false);
        selectConfigButton->setFlat(true);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(730, 90, 71, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(850, 90, 71, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        statusPicture = new QLabel(centralwidget);
        statusPicture->setObjectName(QString::fromUtf8("statusPicture"));
        statusPicture->setGeometry(QRect(1070, 70, 32, 32));
        languageText = new QLabel(centralwidget);
        languageText->setObjectName(QString::fromUtf8("languageText"));
        languageText->setGeometry(QRect(1107, 4, 21, 21));
        languageText->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        minimumButton = new QPushButton(centralwidget);
        minimumButton->setObjectName(QString::fromUtf8("minimumButton"));
        minimumButton->setGeometry(QRect(1150, 6, 22, 20));
        minimumButton->setFocusPolicy(Qt::NoFocus);
        minimumButton->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        minimumButton->setIconSize(QSize(22, 20));
        minimumButton->setFlat(false);
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(1180, 6, 18, 16));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        closeButton->setIconSize(QSize(22, 20));
        closeButton->setFlat(false);
        languageButton = new QPushButton(centralwidget);
        languageButton->setObjectName(QString::fromUtf8("languageButton"));
        languageButton->setGeometry(QRect(1130, 10, 12, 10));
        languageButton->setFocusPolicy(Qt::NoFocus);
        languageButton->setLayoutDirection(Qt::LeftToRight);
        languageButton->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        languageButton->setIconSize(QSize(22, 20));
        languageButton->setFlat(false);
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(947, 51, 111, 51));
        aboutButton->setFont(font1);
        aboutButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{border:0px; color:white;background:transparent;}\n"
"QPushButton:hover{color:red;}\n"
"QPushButton:checked{color:red;}"));
        aboutButton->setIconSize(QSize(32, 32));
        aboutButton->setCheckable(true);
        aboutButton->setChecked(false);
        aboutButton->setAutoRepeat(false);
        aboutButton->setAutoExclusive(false);
        aboutButton->setFlat(true);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(968, 89, 71, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFont font2;
        font2.setPointSize(12);
        statusbar->setFont(font2);
        statusbar->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoPicture->setText(QString());
        equlizerPageButton->setText(QCoreApplication::translate("MainWindow", "\345\235\207\350\241\241\345\231\250", nullptr));
        effectPageButton->setText(QCoreApplication::translate("MainWindow", "\351\237\263\346\225\210", nullptr));
        microphonePageButton->setText(QCoreApplication::translate("MainWindow", "\351\272\246\345\205\213\351\243\216", nullptr));
        surroundSoundButton->setText(QCoreApplication::translate("MainWindow", "7.1\347\216\257\347\273\225\345\243\260", nullptr));
        saveConfigButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        selectConfigButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\351\205\215\347\275\256", nullptr));
        statusPicture->setText(QString());
        languageText->setText(QCoreApplication::translate("MainWindow", "CN", nullptr));
        minimumButton->setText(QString());
        closeButton->setText(QString());
        languageButton->setText(QString());
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
