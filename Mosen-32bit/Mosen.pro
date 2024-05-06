QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TRANSLATIONS+=cn.ts en.ts kr.ts

RC_ICONS = mosen.ico

VERSION = 2.0.0.4


QMAKE_TARGET_COMPANY = " Mosen"

QMAKE_TARGET_PRODUCT = "Mosen Ear Phone"

QMAKE_TARGET_DESCRIPTION = "For game player"

QMAKE_TARGET_COPYRIGHT = "Copyright 2021 The Mosen company. All rights reserved."

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TalkToDevice.cpp \
    adjustWindowSize.cpp \
    coloritem.cpp \
    dragObjFrame.cpp \
    effectpage.cpp \
    equlizerpage.cpp \
    main.cpp \
    mainwindow.cpp \
    microphonespeakerpage.cpp \
    soundsurround.cpp \
    workerThread.cpp

HEADERS += \
    adjustWindowSize.h \
    coloritem.h \
    dragObjFrame.h \
    effectpage.h \
    equlizerpage.h \
    mainwindow.h \
    microphonespeakerpage.h \
    soundsurround.h \
    talkToDevice.h \
    workerThread.h

FORMS += \
    effectpage.ui \
    equlizerpage.ui \
    mainwindow.ui \
    microphonespeakerpage.ui \
    soundsurround.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    bbh.qrc

win32: LIBS += -L$$PWD/./ -lhidapi 

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
