/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../beadando_2/display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_display_t {
    QByteArrayData data[15];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_display_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_display_t qt_meta_stringdata_display = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 8),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 12),
QT_MOC_LITERAL(4, 31, 6),
QT_MOC_LITERAL(5, 38, 10),
QT_MOC_LITERAL(6, 49, 10),
QT_MOC_LITERAL(7, 60, 3),
QT_MOC_LITERAL(8, 64, 10),
QT_MOC_LITERAL(9, 75, 8),
QT_MOC_LITERAL(10, 84, 7),
QT_MOC_LITERAL(11, 92, 5),
QT_MOC_LITERAL(12, 98, 8),
QT_MOC_LITERAL(13, 107, 27),
QT_MOC_LITERAL(14, 135, 23)
    },
    "display\0setTable\0\0QStringList*\0fields\0"
    "changeTime\0itemPickup\0pos\0enemyMoved\0"
    "GameOver\0setSize\0pause\0loadGame\0"
    "on_actionNew_Game_triggered\0"
    "on_actionExit_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_display[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a,
       5,    0,   67,    2, 0x0a,
       6,    1,   68,    2, 0x08,
       8,    2,   71,    2, 0x08,
       9,    1,   76,    2, 0x08,
      10,    1,   79,    2, 0x08,
      11,    0,   82,    2, 0x08,
      12,    1,   83,    2, 0x08,
      13,    0,   86,    2, 0x08,
      14,    0,   87,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        display *_t = static_cast<display *>(_o);
        switch (_id) {
        case 0: _t->setTable((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 1: _t->changeTime(); break;
        case 2: _t->itemPickup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->enemyMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->GameOver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->pause(); break;
        case 7: _t->loadGame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_actionNew_Game_triggered(); break;
        case 9: _t->on_actionExit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject display::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_display.data,
      qt_meta_data_display,  qt_static_metacall, 0, 0}
};


const QMetaObject *display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_display.stringdata))
        return static_cast<void*>(const_cast< display*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
