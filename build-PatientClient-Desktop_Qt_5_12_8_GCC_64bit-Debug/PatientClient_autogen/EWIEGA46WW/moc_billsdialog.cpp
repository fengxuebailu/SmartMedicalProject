/****************************************************************************
** Meta object code from reading C++ file 'billsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PatientClient/billsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'billsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BillsDialog_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BillsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BillsDialog_t qt_meta_stringdata_BillsDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BillsDialog"
QT_MOC_LITERAL(1, 12, 31), // "on_billsTableWidget_itemChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(4, 63, 4), // "item"
QT_MOC_LITERAL(5, 68, 20), // "on_payButton_clicked"
QT_MOC_LITERAL(6, 89, 22) // "on_closeButton_clicked"

    },
    "BillsDialog\0on_billsTableWidget_itemChanged\0"
    "\0QTableWidgetItem*\0item\0on_payButton_clicked\0"
    "on_closeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BillsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BillsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BillsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_billsTableWidget_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->on_payButton_clicked(); break;
        case 2: _t->on_closeButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BillsDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_BillsDialog.data,
    qt_meta_data_BillsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BillsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BillsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BillsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BillsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
