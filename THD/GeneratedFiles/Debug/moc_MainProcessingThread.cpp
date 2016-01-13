/****************************************************************************
** Meta object code from reading C++ file 'MainProcessingThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainProcessingThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainProcessingThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainProcessingThread_t {
    QByteArrayData data[7];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainProcessingThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainProcessingThread_t qt_meta_stringdata_MainProcessingThread = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 17),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 5),
QT_MOC_LITERAL(4, 46, 22),
QT_MOC_LITERAL(5, 69, 3),
QT_MOC_LITERAL(6, 73, 7)
    },
    "MainProcessingThread\0sendLiveFeedFrame\0"
    "\0frame\0sendDetectionFeedFrame\0Mat\0"
    "process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainProcessingThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MainProcessingThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainProcessingThread *_t = static_cast<MainProcessingThread *>(_o);
        switch (_id) {
        case 0: _t->sendLiveFeedFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendDetectionFeedFrame((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 2: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainProcessingThread::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainProcessingThread::sendLiveFeedFrame)) {
                *result = 0;
            }
        }
        {
            typedef void (MainProcessingThread::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainProcessingThread::sendDetectionFeedFrame)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainProcessingThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainProcessingThread.data,
      qt_meta_data_MainProcessingThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainProcessingThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainProcessingThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainProcessingThread.stringdata))
        return static_cast<void*>(const_cast< MainProcessingThread*>(this));
    return QObject::qt_metacast(_clname);
}

int MainProcessingThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MainProcessingThread::sendLiveFeedFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainProcessingThread::sendDetectionFeedFrame(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
