/****************************************************************************
** Meta object code from reading C++ file 'dossier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProjetQt/dossier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dossier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DossierEditeur_t {
    QByteArrayData data[10];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DossierEditeur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DossierEditeur_t qt_meta_stringdata_DossierEditeur = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 13),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 16),
QT_MOC_LITERAL(5, 64, 11),
QT_MOC_LITERAL(6, 76, 12),
QT_MOC_LITERAL(7, 89, 19),
QT_MOC_LITERAL(8, 109, 1),
QT_MOC_LITERAL(9, 111, 19)
    },
    "DossierEditeur\0sauverDossier\0\0"
    "ajoutInscription\0ajoutEquivalence\0"
    "ajoutCursus\0supprimerCur\0modifierInscription\0"
    "j\0modifierEquivalence\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DossierEditeur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a,
       3,    0,   60,    2, 0x0a,
       4,    0,   61,    2, 0x0a,
       5,    0,   62,    2, 0x0a,
       6,    0,   63,    2, 0x0a,
       7,    1,   64,    2, 0x0a,
       7,    0,   67,    2, 0x2a,
       9,    1,   68,    2, 0x0a,
       9,    0,   71,    2, 0x2a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void DossierEditeur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DossierEditeur *_t = static_cast<DossierEditeur *>(_o);
        switch (_id) {
        case 0: _t->sauverDossier(); break;
        case 1: _t->ajoutInscription(); break;
        case 2: _t->ajoutEquivalence(); break;
        case 3: _t->ajoutCursus(); break;
        case 4: _t->supprimerCur(); break;
        case 5: _t->modifierInscription((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->modifierInscription(); break;
        case 7: _t->modifierEquivalence((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->modifierEquivalence(); break;
        default: ;
        }
    }
}

const QMetaObject DossierEditeur::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DossierEditeur.data,
      qt_meta_data_DossierEditeur,  qt_static_metacall, 0, 0}
};


const QMetaObject *DossierEditeur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DossierEditeur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DossierEditeur.stringdata))
        return static_cast<void*>(const_cast< DossierEditeur*>(this));
    return QWidget::qt_metacast(_clname);
}

int DossierEditeur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
