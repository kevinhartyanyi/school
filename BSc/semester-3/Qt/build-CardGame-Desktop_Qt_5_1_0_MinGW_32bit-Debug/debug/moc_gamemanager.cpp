/****************************************************************************
** Meta object code from reading C++ file 'gamemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../minta card game/gamemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameManager_t {
    QByteArrayData data[21];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameManager_t qt_meta_stringdata_GameManager = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 5),
QT_MOC_LITERAL(4, 31, 9),
QT_MOC_LITERAL(5, 41, 13),
QT_MOC_LITERAL(6, 55, 6),
QT_MOC_LITERAL(7, 62, 8),
QT_MOC_LITERAL(8, 71, 7),
QT_MOC_LITERAL(9, 79, 10),
QT_MOC_LITERAL(10, 90, 11),
QT_MOC_LITERAL(11, 102, 12),
QT_MOC_LITERAL(12, 115, 14),
QT_MOC_LITERAL(13, 130, 9),
QT_MOC_LITERAL(14, 140, 4),
QT_MOC_LITERAL(15, 145, 7),
QT_MOC_LITERAL(16, 153, 7),
QT_MOC_LITERAL(17, 161, 7),
QT_MOC_LITERAL(18, 169, 10),
QT_MOC_LITERAL(19, 180, 6),
QT_MOC_LITERAL(20, 187, 9)
    },
    "GameManager\0cardChanged\0\0index\0cardImage\0"
    "statusChanged\0status\0gameOver\0message\0"
    "setPlayers\0firstPlayer\0secondPlayer\0"
    "setCurrentPack\0CardPack*\0pack\0newGame\0"
    "numRows\0numCols\0selectCard\0cardId\0"
    "hideCards\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x05,
       5,    1,   59,    2, 0x05,
       7,    1,   62,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    2,   65,    2, 0x0a,
      12,    1,   70,    2, 0x0a,
      15,    2,   73,    2, 0x0a,
      18,    1,   78,    2, 0x0a,
      20,    0,   81,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,

       0        // eod
};

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameManager *_t = static_cast<GameManager *>(_o);
        switch (_id) {
        case 0: _t->cardChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->statusChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->gameOver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setPlayers((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->setCurrentPack((*reinterpret_cast< CardPack*(*)>(_a[1]))); break;
        case 5: _t->newGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->selectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->hideCards(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameManager::*_t)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameManager::cardChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GameManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameManager::statusChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GameManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameManager::gameOver)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GameManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameManager.data,
      qt_meta_data_GameManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameManager.stringdata))
        return static_cast<void*>(const_cast< GameManager*>(this));
    return QObject::qt_metacast(_clname);
}

int GameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void GameManager::cardChanged(int _t1, const QPixmap & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameManager::statusChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameManager::gameOver(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
