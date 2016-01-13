/****************************************************************************
** Meta object code from reading C++ file 'thd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../thd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_THD_t {
    QByteArrayData data[25];
    char stringdata[377];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_THD_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_THD_t qt_meta_stringdata_THD = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 14),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 5),
QT_MOC_LITERAL(4, 26, 19),
QT_MOC_LITERAL(5, 46, 3),
QT_MOC_LITERAL(6, 50, 20),
QT_MOC_LITERAL(7, 71, 6),
QT_MOC_LITERAL(8, 78, 3),
QT_MOC_LITERAL(9, 82, 19),
QT_MOC_LITERAL(10, 102, 20),
QT_MOC_LITERAL(11, 123, 20),
QT_MOC_LITERAL(12, 144, 15),
QT_MOC_LITERAL(13, 160, 16),
QT_MOC_LITERAL(14, 177, 8),
QT_MOC_LITERAL(15, 186, 16),
QT_MOC_LITERAL(16, 203, 14),
QT_MOC_LITERAL(17, 218, 16),
QT_MOC_LITERAL(18, 235, 22),
QT_MOC_LITERAL(19, 258, 21),
QT_MOC_LITERAL(20, 280, 20),
QT_MOC_LITERAL(21, 301, 19),
QT_MOC_LITERAL(22, 321, 18),
QT_MOC_LITERAL(23, 340, 18),
QT_MOC_LITERAL(24, 359, 17)
    },
    "THD\0updateLiveFeed\0\0frame\0updateDetectionFeed\0"
    "Mat\0updateConsoleMessage\0String\0msg\0"
    "updateAnalysisImage\0updateAnalysisImage2\0"
    "updateAnalysisImage3\0updateVideoInfo\0"
    "getVideoDuration\0filename\0updateCannyImage\0"
    "updateCarImage\0updateSpeedImage\0"
    "onRelease_btnPlayPause\0onRelease_btnSlowDown\0"
    "onRelease_btnSpeedUp\0onRelease_btnBrowse\0"
    "onRelease_btnClear\0onRelease_btnStart\0"
    "onRelease_btnStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_THD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x0a /* Public */,
       4,    1,  112,    2, 0x0a /* Public */,
       6,    0,  115,    2, 0x0a /* Public */,
       6,    1,  116,    2, 0x0a /* Public */,
       9,    1,  119,    2, 0x0a /* Public */,
      10,    1,  122,    2, 0x0a /* Public */,
      11,    1,  125,    2, 0x0a /* Public */,
      12,    0,  128,    2, 0x0a /* Public */,
      13,    1,  129,    2, 0x0a /* Public */,
      15,    1,  132,    2, 0x0a /* Public */,
      16,    1,  135,    2, 0x0a /* Public */,
      17,    1,  138,    2, 0x0a /* Public */,
      18,    0,  141,    2, 0x0a /* Public */,
      19,    0,  142,    2, 0x0a /* Public */,
      20,    0,  143,    2, 0x0a /* Public */,
      21,    0,  144,    2, 0x0a /* Public */,
      22,    0,  145,    2, 0x0a /* Public */,
      23,    0,  146,    2, 0x0a /* Public */,
      24,    0,  147,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 7,   14,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void THD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        THD *_t = static_cast<THD *>(_o);
        switch (_id) {
        case 0: _t->updateLiveFeed((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->updateDetectionFeed((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 2: _t->updateConsoleMessage(); break;
        case 3: _t->updateConsoleMessage((*reinterpret_cast< String(*)>(_a[1]))); break;
        case 4: _t->updateAnalysisImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 5: _t->updateAnalysisImage2((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 6: _t->updateAnalysisImage3((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 7: _t->updateVideoInfo(); break;
        case 8: { int _r = _t->getVideoDuration((*reinterpret_cast< String(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->updateCannyImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 10: _t->updateCarImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 11: _t->updateSpeedImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 12: _t->onRelease_btnPlayPause(); break;
        case 13: _t->onRelease_btnSlowDown(); break;
        case 14: _t->onRelease_btnSpeedUp(); break;
        case 15: _t->onRelease_btnBrowse(); break;
        case 16: _t->onRelease_btnClear(); break;
        case 17: _t->onRelease_btnStart(); break;
        case 18: _t->onRelease_btnStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mat >(); break;
            }
            break;
        }
    }
}

const QMetaObject THD::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_THD.data,
      qt_meta_data_THD,  qt_static_metacall, 0, 0}
};


const QMetaObject *THD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *THD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_THD.stringdata))
        return static_cast<void*>(const_cast< THD*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int THD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
