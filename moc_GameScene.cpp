/****************************************************************************
** Meta object code from reading C++ file 'GameScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameScene/GameScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameScene_t {
    QByteArrayData data[12];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameScene_t qt_meta_stringdata_GameScene = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameScene"
QT_MOC_LITERAL(1, 10, 11), // "setEndScene"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "updateWorld"
QT_MOC_LITERAL(4, 35, 11), // "releaseBird"
QT_MOC_LITERAL(5, 47, 10), // "setNewBird"
QT_MOC_LITERAL(6, 58, 17), // "useSpecialAbility"
QT_MOC_LITERAL(7, 76, 14), // "spawnBlueChild"
QT_MOC_LITERAL(8, 91, 1), // "x"
QT_MOC_LITERAL(9, 93, 1), // "y"
QT_MOC_LITERAL(10, 95, 9), // "deletePig"
QT_MOC_LITERAL(11, 105, 11) // "testEndGame"

    },
    "GameScene\0setEndScene\0\0updateWorld\0"
    "releaseBird\0setNewBird\0useSpecialAbility\0"
    "spawnBlueChild\0x\0y\0deletePig\0testEndGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   59,    2, 0x0a /* Public */,
       4,    0,   60,    2, 0x0a /* Public */,
       5,    0,   61,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    2,   63,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameScene *_t = static_cast<GameScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setEndScene((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->updateWorld(); break;
        case 2: _t->releaseBird(); break;
        case 3: _t->setNewBird(); break;
        case 4: _t->useSpecialAbility(); break;
        case 5: _t->spawnBlueChild((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->deletePig(); break;
        case 7: _t->testEndGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameScene::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameScene::setEndScene)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GameScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GameScene.data,
      qt_meta_data_GameScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameScene.stringdata0))
        return static_cast<void*>(const_cast< GameScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int GameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameScene::setEndScene(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
