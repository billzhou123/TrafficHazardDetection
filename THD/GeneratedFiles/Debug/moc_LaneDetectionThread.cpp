/****************************************************************************
** Meta object code from reading C++ file 'LaneDetectionThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LaneDetectionThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LaneDetectionThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LaneDetectionThread_t {
    QByteArrayData data[9];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LaneDetectionThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LaneDetectionThread_t qt_meta_stringdata_LaneDetectionThread = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 23),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 13),
QT_MOC_LITERAL(4, 59, 17),
QT_MOC_LITERAL(5, 77, 14),
QT_MOC_LITERAL(6, 92, 3),
QT_MOC_LITERAL(7, 96, 5),
QT_MOC_LITERAL(8, 102, 7)
    },
    "LaneDetectionThread\0sendApproxLanePositions\0"
    "\0vector<Vec4i>\0sendLanePositions\0"
    "sendCannyImage\0Mat\0frame\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LaneDetectionThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void LaneDetectionThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LaneDetectionThread *_t = static_cast<LaneDetectionThread *>(_o);
        switch (_id) {
        case 0: _t->sendApproxLanePositions((*reinterpret_cast< vector<Vec4i>(*)>(_a[1]))); break;
        case 1: _t->sendLanePositions((*reinterpret_cast< vector<Vec4i>(*)>(_a[1]))); break;
        case 2: _t->sendCannyImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 3: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LaneDetectionThread::*_t)(vector<Vec4i> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LaneDetectionThread::sendApproxLanePositions)) {
                *result = 0;
            }
        }
        {
            typedef void (LaneDetectionThread::*_t)(vector<Vec4i> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LaneDetectionThread::sendLanePositions)) {
                *result = 1;
            }
        }
        {
            typedef void (LaneDetectionThread::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LaneDetectionThread::sendCannyImage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject LaneDetectionThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LaneDetectionThread.data,
      qt_meta_data_LaneDetectionThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *LaneDetectionThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LaneDetectionThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LaneDetectionThread.stringdata))
        return static_cast<void*>(const_cast< LaneDetectionThread*>(this));
    return QObject::qt_metacast(_clname);
}

int LaneDetectionThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LaneDetectionThread::sendApproxLanePositions(vector<Vec4i> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LaneDetectionThread::sendLanePositions(vector<Vec4i> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LaneDetectionThread::sendCannyImage(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
