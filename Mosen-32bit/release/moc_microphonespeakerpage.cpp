/****************************************************************************
** Meta object code from reading C++ file 'microphonespeakerpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../microphonespeakerpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'microphonespeakerpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_microphoneSpeakerPage_t {
    QByteArrayData data[17];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_microphoneSpeakerPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_microphoneSpeakerPage_t qt_meta_stringdata_microphoneSpeakerPage = {
    {
QT_MOC_LITERAL(0, 0, 21), // "microphoneSpeakerPage"
QT_MOC_LITERAL(1, 22, 23), // "workerThreadStartSignal"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 31), // "on_microphoneAdjust_sliderMoved"
QT_MOC_LITERAL(4, 79, 8), // "position"
QT_MOC_LITERAL(5, 88, 28), // "on_speakerAdjust_sliderMoved"
QT_MOC_LITERAL(6, 117, 12), // "adjustVolume"
QT_MOC_LITERAL(7, 130, 10), // "deviceType"
QT_MOC_LITERAL(8, 141, 34), // "on_microphoneDisableButton_cl..."
QT_MOC_LITERAL(9, 176, 31), // "on_speakerDisableButton_clicked"
QT_MOC_LITERAL(10, 208, 15), // "intializeVolume"
QT_MOC_LITERAL(11, 224, 9), // "getVolume"
QT_MOC_LITERAL(12, 234, 6), // "float&"
QT_MOC_LITERAL(13, 241, 6), // "volume"
QT_MOC_LITERAL(14, 248, 32), // "on_microphoneAdjust_valueChanged"
QT_MOC_LITERAL(15, 281, 5), // "value"
QT_MOC_LITERAL(16, 287, 29) // "on_speakerAdjust_valueChanged"

    },
    "microphoneSpeakerPage\0workerThreadStartSignal\0"
    "\0on_microphoneAdjust_sliderMoved\0"
    "position\0on_speakerAdjust_sliderMoved\0"
    "adjustVolume\0deviceType\0"
    "on_microphoneDisableButton_clicked\0"
    "on_speakerDisableButton_clicked\0"
    "intializeVolume\0getVolume\0float&\0"
    "volume\0on_microphoneAdjust_valueChanged\0"
    "value\0on_speakerAdjust_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_microphoneSpeakerPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    2,   71,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    2,   79,    2, 0x08 /* Private */,
      14,    1,   84,    2, 0x08 /* Private */,
      16,    1,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,    7,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void microphoneSpeakerPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<microphoneSpeakerPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workerThreadStartSignal(); break;
        case 1: _t->on_microphoneAdjust_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_speakerAdjust_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->adjustVolume((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_microphoneDisableButton_clicked(); break;
        case 5: _t->on_speakerDisableButton_clicked(); break;
        case 6: _t->intializeVolume(); break;
        case 7: _t->getVolume((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->on_microphoneAdjust_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_speakerAdjust_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (microphoneSpeakerPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&microphoneSpeakerPage::workerThreadStartSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject microphoneSpeakerPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_microphoneSpeakerPage.data,
    qt_meta_data_microphoneSpeakerPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *microphoneSpeakerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *microphoneSpeakerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_microphoneSpeakerPage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int microphoneSpeakerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void microphoneSpeakerPage::workerThreadStartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
