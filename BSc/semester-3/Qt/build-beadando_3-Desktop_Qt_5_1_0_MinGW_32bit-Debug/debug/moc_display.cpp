/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../beaaaaaaad/display.h"
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
struct qt_meta_stringdata_Display_t {
    QByteArrayData data[21];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Display_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Display_t qt_meta_stringdata_Display = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 7),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 5),
QT_MOC_LITERAL(4, 23, 7),
QT_MOC_LITERAL(5, 31, 4),
QT_MOC_LITERAL(6, 36, 15),
QT_MOC_LITERAL(7, 52, 5),
QT_MOC_LITERAL(8, 58, 5),
QT_MOC_LITERAL(9, 64, 8),
QT_MOC_LITERAL(10, 73, 10),
QT_MOC_LITERAL(11, 84, 5),
QT_MOC_LITERAL(12, 90, 8),
QT_MOC_LITERAL(13, 99, 3),
QT_MOC_LITERAL(14, 103, 5),
QT_MOC_LITERAL(15, 109, 8),
QT_MOC_LITERAL(16, 118, 8),
QT_MOC_LITERAL(17, 127, 11),
QT_MOC_LITERAL(18, 139, 4),
QT_MOC_LITERAL(19, 144, 27),
QT_MOC_LITERAL(20, 172, 23)
    },
    "Display\0setSize\0\0Moved\0Players\0Cord\0"
    "ChangeDirection\0Laser\0Punch\0GameOver\0"
    "SetCommand\0Pause\0loadGame\0End\0Error\0"
    "saveGame\0saveName\0LoadTheGame\0step\0"
    "on_actionNew_Game_triggered\0"
    "on_actionExit_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Display[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08,
       3,    2,  102,    2, 0x08,
       6,    2,  107,    2, 0x08,
       7,    2,  112,    2, 0x08,
       8,    2,  117,    2, 0x08,
       9,    1,  122,    2, 0x08,
      10,    5,  125,    2, 0x08,
      11,    0,  136,    2, 0x08,
      12,    1,  137,    2, 0x08,
      13,    0,  140,    2, 0x08,
      14,    0,  141,    2, 0x08,
      15,    0,  142,    2, 0x08,
      16,    1,  143,    2, 0x08,
      17,    7,  146,    2, 0x08,
      18,    0,  161,    2, 0x08,
      19,    0,  162,    2, 0x08,
      20,    0,  163,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, flags, count, data

 // enum data: key, value

       0        // eod
};

void Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Display *_t = static_cast<Display *>(_o);
        switch (_id) {
        case 0: _t->setSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Moved((*reinterpret_cast< Players(*)>(_a[1])),(*reinterpret_cast< Cord(*)>(_a[2]))); break;
        case 2: _t->ChangeDirection((*reinterpret_cast< Players(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->Laser((*reinterpret_cast< Players(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->Punch((*reinterpret_cast< Players(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->GameOver((*reinterpret_cast< Players(*)>(_a[1]))); break;
        case 6: _t->SetCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 7: _t->Pause(); break;
        case 8: _t->loadGame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->End(); break;
        case 10: _t->Error(); break;
        case 11: _t->saveGame(); break;
        case 12: _t->saveName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->LoadTheGame((*reinterpret_cast< Cord(*)>(_a[1])),(*reinterpret_cast< Cord(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 14: _t->step(); break;
        case 15: _t->on_actionNew_Game_triggered(); break;
        case 16: _t->on_actionExit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject Display::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Display.data,
      qt_meta_data_Display,  qt_static_metacall, 0, 0}
};


const QMetaObject *Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Display.stringdata))
        return static_cast<void*>(const_cast< Display*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
