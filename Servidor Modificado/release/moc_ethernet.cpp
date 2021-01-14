/****************************************************************************
** Meta object code from reading C++ file 'ethernet.h'
**
** Created: Thu 29. Sep 11:40:00 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ethernet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ethernet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ethernet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      35,    9,    9,    9, 0x08,
      57,    9,    9,    9, 0x08,
      79,    9,    9,    9, 0x08,
     104,    9,    9,    9, 0x08,
     130,    9,    9,    9, 0x08,
     159,    9,    9,    9, 0x08,
     185,    9,    9,    9, 0x08,
     211,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ethernet[] = {
    "Ethernet\0\0on_startServer_clicked()\0"
    "acceptTheConnection()\0respondToConnection()\0"
    "connectionAboutToClose()\0"
    "on_btn_conectar_clicked()\0"
    "on_btn_desconectar_clicked()\0"
    "on_btn_grfc_Sen_clicked()\0"
    "on_btn_grfc_Luz_clicked()\0DatosRecibidos()\0"
};

void Ethernet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ethernet *_t = static_cast<Ethernet *>(_o);
        switch (_id) {
        case 0: _t->on_startServer_clicked(); break;
        case 1: _t->acceptTheConnection(); break;
        case 2: _t->respondToConnection(); break;
        case 3: _t->connectionAboutToClose(); break;
        case 4: _t->on_btn_conectar_clicked(); break;
        case 5: _t->on_btn_desconectar_clicked(); break;
        case 6: _t->on_btn_grfc_Sen_clicked(); break;
        case 7: _t->on_btn_grfc_Luz_clicked(); break;
        case 8: _t->DatosRecibidos(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Ethernet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ethernet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Ethernet,
      qt_meta_data_Ethernet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ethernet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ethernet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ethernet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ethernet))
        return static_cast<void*>(const_cast< Ethernet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Ethernet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
