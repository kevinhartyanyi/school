/****************************************************************************
** Meta object code from reading C++ file 'configurationdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../minta card game/configurationdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configurationdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigurationDialog_t {
    QByteArrayData data[13];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConfigurationDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConfigurationDialog_t qt_meta_stringdata_ConfigurationDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 18),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 4),
QT_MOC_LITERAL(4, 45, 19),
QT_MOC_LITERAL(5, 65, 15),
QT_MOC_LITERAL(6, 81, 2),
QT_MOC_LITERAL(7, 84, 18),
QT_MOC_LITERAL(8, 103, 11),
QT_MOC_LITERAL(9, 115, 14),
QT_MOC_LITERAL(10, 130, 5),
QT_MOC_LITERAL(11, 136, 10),
QT_MOC_LITERAL(12, 147, 10)
    },
    "ConfigurationDialog\0setFirstPlayerName\0"
    "\0name\0setSecondPlayerName\0setNumberOfRows\0"
    "nr\0setNumberOfColumns\0checkValues\0"
    "changeCardPack\0index\0setMaxRows\0"
    "setMaxCols\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigurationDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a,
       4,    1,   57,    2, 0x0a,
       5,    1,   60,    2, 0x0a,
       7,    1,   63,    2, 0x0a,
       8,    0,   66,    2, 0x08,
       9,    1,   67,    2, 0x08,
      11,    0,   70,    2, 0x08,
      12,    0,   71,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigurationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigurationDialog *_t = static_cast<ConfigurationDialog *>(_o);
        switch (_id) {
        case 0: _t->setFirstPlayerName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setSecondPlayerName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setNumberOfRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setNumberOfColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->checkValues(); break;
        case 5: _t->changeCardPack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setMaxRows(); break;
        case 7: _t->setMaxCols(); break;
        default: ;
        }
    }
}

const QMetaObject ConfigurationDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigurationDialog.data,
      qt_meta_data_ConfigurationDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConfigurationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigurationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigurationDialog.stringdata))
        return static_cast<void*>(const_cast< ConfigurationDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigurationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
