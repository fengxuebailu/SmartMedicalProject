/****************************************************************************
** Meta object code from reading C++ file 'doctorselectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../PatientClient/doctorselectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctorselectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorSelectionDialog_t {
    QByteArrayData data[12];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoctorSelectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoctorSelectionDialog_t qt_meta_stringdata_DoctorSelectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DoctorSelectionDialog"
QT_MOC_LITERAL(1, 22, 14), // "doctorSelected"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "doctorId"
QT_MOC_LITERAL(4, 47, 10), // "doctorName"
QT_MOC_LITERAL(5, 58, 36), // "on_departmentsListWidget_item..."
QT_MOC_LITERAL(6, 95, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 112, 4), // "item"
QT_MOC_LITERAL(8, 117, 33), // "on_doctorsTableWidget_cellCli..."
QT_MOC_LITERAL(9, 151, 3), // "row"
QT_MOC_LITERAL(10, 155, 6), // "column"
QT_MOC_LITERAL(11, 162, 21) // "on_nextButton_clicked"

    },
    "DoctorSelectionDialog\0doctorSelected\0"
    "\0doctorId\0doctorName\0"
    "on_departmentsListWidget_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_doctorsTableWidget_cellClicked\0row\0"
    "column\0on_nextButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorSelectionDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x08 /* Private */,
       8,    2,   42,    2, 0x08 /* Private */,
      11,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,

       0        // eod
};

void DoctorSelectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoctorSelectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doctorSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->on_departmentsListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_doctorsTableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_nextButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoctorSelectionDialog::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorSelectionDialog::doctorSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DoctorSelectionDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DoctorSelectionDialog.data,
    qt_meta_data_DoctorSelectionDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DoctorSelectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorSelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorSelectionDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DoctorSelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DoctorSelectionDialog::doctorSelected(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
