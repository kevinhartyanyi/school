/****************************************************************************
** Meta object code from reading C++ file 'gamemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../minta bead 2/gamemanager.h"
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
    QByteArrayData data[15];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameManager_t qt_meta_stringdata_GameManager = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 7),
QT_MOC_LITERAL(4, 36, 12),
QT_MOC_LITERAL(5, 49, 5),
QT_MOC_LITERAL(6, 55, 8),
QT_MOC_LITERAL(7, 64, 9),
QT_MOC_LITERAL(8, 74, 8),
QT_MOC_LITERAL(9, 83, 7),
QT_MOC_LITERAL(10, 91, 4),
QT_MOC_LITERAL(11, 96, 9),
QT_MOC_LITERAL(12, 106, 8),
QT_MOC_LITERAL(13, 115, 2),
QT_MOC_LITERAL(14, 118, 12)
    },
    "GameManager\0messageChanged\0\0message\0"
    "imageChanged\0image\0gameOver\0goodGuess\0"
    "badGuess\0newGame\0size\0pauseGame\0"
    "stepGame\0nr\0timerTimeOut\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       4,    1,   52,    2, 0x05,
       6,    2,   55,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    1,   60,    2, 0x0a,
      11,    0,   63,    2, 0x0a,
      12,    1,   64,    2, 0x0a,
      14,    0,   67,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QPixmap,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameManager *_t = static_cast<GameManager *>(_o);
        switch (_id) {
        case 0: _t->messageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->imageChanged((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 2: _t->gameOver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->newGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pauseGame(); break;
        case 5: _t->stepGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->timerTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameManager::messageChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GameManager::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameManager::imageChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GameManager::*_t)(int , int );
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GameManager::messageChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameManager::imageChanged(const QPixmap & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameManager::gameOver(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
