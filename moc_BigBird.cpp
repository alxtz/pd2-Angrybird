/****************************************************************************
** Meta object code from reading C++ file 'BigBird.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameScene/Birds/BigBird.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BigBird.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BigBird_t {
    QByteArrayData data[7];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BigBird_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BigBird_t qt_meta_stringdata_BigBird = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BigBird"
QT_MOC_LITERAL(1, 8, 10), // "setPullPos"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "x"
QT_MOC_LITERAL(4, 22, 1), // "y"
QT_MOC_LITERAL(5, 24, 9), // "updatePos"
QT_MOC_LITERAL(6, 34, 14) // "specialAbility"

    },
    "BigBird\0setPullPos\0\0x\0y\0updatePos\0"
    "specialAbility"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BigBird[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       5,    0,   34,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BigBird::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BigBird *_t = static_cast<BigBird *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPullPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->updatePos(); break;
        case 2: _t->specialAbility(); break;
        default: ;
        }
    }
}

const QMetaObject BigBird::staticMetaObject = {
    { &AbsBird::staticMetaObject, qt_meta_stringdata_BigBird.data,
      qt_meta_data_BigBird,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BigBird::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BigBird::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BigBird.stringdata0))
        return static_cast<void*>(const_cast< BigBird*>(this));
    return AbsBird::qt_metacast(_clname);
}

int BigBird::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbsBird::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
