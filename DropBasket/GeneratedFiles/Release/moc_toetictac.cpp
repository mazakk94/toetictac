/****************************************************************************
** Meta object code from reading C++ file 'toetictac.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../toetictac.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toetictac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Toetictac_t {
    QByteArrayData data[9];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Toetictac_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Toetictac_t qt_meta_stringdata_Toetictac = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Toetictac"
QT_MOC_LITERAL(1, 10, 11), // "startClient"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "newClientConnected"
QT_MOC_LITERAL(4, 42, 12), // "readFromServ"
QT_MOC_LITERAL(5, 55, 14), // "readFromClient"
QT_MOC_LITERAL(6, 70, 11), // "startServer"
QT_MOC_LITERAL(7, 82, 10), // "clientSend"
QT_MOC_LITERAL(8, 93, 10) // "serverSend"

    },
    "Toetictac\0startClient\0\0newClientConnected\0"
    "readFromServ\0readFromClient\0startServer\0"
    "clientSend\0serverSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Toetictac[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Toetictac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Toetictac *_t = static_cast<Toetictac *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startClient(); break;
        case 1: _t->newClientConnected(); break;
        case 2: _t->readFromServ(); break;
        case 3: _t->readFromClient(); break;
        case 4: _t->startServer(); break;
        case 5: _t->clientSend(); break;
        case 6: _t->serverSend(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Toetictac::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Toetictac.data,
      qt_meta_data_Toetictac,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Toetictac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Toetictac::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Toetictac.stringdata0))
        return static_cast<void*>(const_cast< Toetictac*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Toetictac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
