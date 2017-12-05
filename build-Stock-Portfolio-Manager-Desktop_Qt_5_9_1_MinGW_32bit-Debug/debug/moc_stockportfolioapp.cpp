/****************************************************************************
** Meta object code from reading C++ file 'stockportfolioapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Stock-Portfolio-Manager/stockportfolioapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockportfolioapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_stockportfolioapp_t {
    QByteArrayData data[6];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_stockportfolioapp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_stockportfolioapp_t qt_meta_stringdata_stockportfolioapp = {
    {
QT_MOC_LITERAL(0, 0, 17), // "stockportfolioapp"
QT_MOC_LITERAL(1, 18, 24), // "on_newListButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "on_setTimer"
QT_MOC_LITERAL(4, 56, 27), // "on_actionNew_List_triggered"
QT_MOC_LITERAL(5, 84, 27) // "on_actionLog_In_2_triggered"

    },
    "stockportfolioapp\0on_newListButton_clicked\0"
    "\0on_setTimer\0on_actionNew_List_triggered\0"
    "on_actionLog_In_2_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stockportfolioapp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void stockportfolioapp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        stockportfolioapp *_t = static_cast<stockportfolioapp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_newListButton_clicked(); break;
        case 1: _t->on_setTimer(); break;
        case 2: _t->on_actionNew_List_triggered(); break;
        case 3: _t->on_actionLog_In_2_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject stockportfolioapp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_stockportfolioapp.data,
      qt_meta_data_stockportfolioapp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *stockportfolioapp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stockportfolioapp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_stockportfolioapp.stringdata0))
        return static_cast<void*>(const_cast< stockportfolioapp*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int stockportfolioapp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
