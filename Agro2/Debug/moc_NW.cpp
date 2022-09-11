/****************************************************************************
** Meta object code from reading C++ file 'NW.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NW.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NW.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NW_t {
    QByteArrayData data[14];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NW_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NW_t qt_meta_stringdata_NW = {
    {
QT_MOC_LITERAL(0, 0, 2), // "NW"
QT_MOC_LITERAL(1, 3, 18), // "No_Internet_signal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "NasosOn"
QT_MOC_LITERAL(4, 31, 8), // "NasosOff"
QT_MOC_LITERAL(5, 40, 7), // "NW_INIT"
QT_MOC_LITERAL(6, 48, 10), // "Get_Status"
QT_MOC_LITERAL(7, 59, 16), // "Send_sensor_data"
QT_MOC_LITERAL(8, 76, 2), // "ID"
QT_MOC_LITERAL(9, 79, 12), // "RequestError"
QT_MOC_LITERAL(10, 92, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(11, 120, 17), // "Check_sensor_data"
QT_MOC_LITERAL(12, 138, 18), // "Update_sensor_date"
QT_MOC_LITERAL(13, 157, 6) // "dataId"

    },
    "NW\0No_Internet_signal\0\0NasosOn\0NasosOff\0"
    "NW_INIT\0Get_Status\0Send_sensor_data\0"
    "ID\0RequestError\0QNetworkReply::NetworkError\0"
    "Check_sensor_data\0Update_sensor_date\0"
    "dataId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NW[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    2,   64,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void NW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NW *_t = static_cast<NW *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->No_Internet_signal(); break;
        case 1: _t->NasosOn(); break;
        case 2: _t->NasosOff(); break;
        case 3: _t->NW_INIT(); break;
        case 4: { int _r = _t->Get_Status();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->Send_sensor_data((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->RequestError((*reinterpret_cast< const QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 7: _t->Check_sensor_data(); break;
        case 8: _t->Update_sensor_date((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NW::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NW::No_Internet_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NW::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NW::NasosOn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NW::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NW::NasosOff)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject NW::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NW.data,
      qt_meta_data_NW,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NW::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NW.stringdata0))
        return static_cast<void*>(const_cast< NW*>(this));
    return QObject::qt_metacast(_clname);
}

int NW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void NW::No_Internet_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void NW::NasosOn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void NW::NasosOff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
