/****************************************************************************
** Meta object code from reading C++ file 'MenuEditeur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProjetQt/MenuEditeur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuEditeur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuEditeur_t {
    QByteArrayData data[8];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MenuEditeur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MenuEditeur_t qt_meta_stringdata_MenuEditeur = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 13),
QT_MOC_LITERAL(4, 42, 18),
QT_MOC_LITERAL(5, 61, 18),
QT_MOC_LITERAL(6, 80, 11),
QT_MOC_LITERAL(7, 92, 15)
    },
    "MenuEditeur\0ajouterDossier\0\0EditionCursus\0"
    "ajouterEquivalence\0ajouterInscription\0"
    "consulterUV\0consulterCursus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuEditeur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    0,   47,    2, 0x0a,
       6,    0,   48,    2, 0x0a,
       7,    0,   49,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuEditeur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuEditeur *_t = static_cast<MenuEditeur *>(_o);
        switch (_id) {
        case 0: _t->ajouterDossier(); break;
        case 1: _t->EditionCursus(); break;
        case 2: _t->ajouterEquivalence(); break;
        case 3: _t->ajouterInscription(); break;
        case 4: _t->consulterUV(); break;
        case 5: _t->consulterCursus(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MenuEditeur::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MenuEditeur.data,
      qt_meta_data_MenuEditeur,  qt_static_metacall, 0, 0}
};


const QMetaObject *MenuEditeur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuEditeur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuEditeur.stringdata))
        return static_cast<void*>(const_cast< MenuEditeur*>(this));
    return QWidget::qt_metacast(_clname);
}

int MenuEditeur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
