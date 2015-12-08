/****************************************************************************
** Meta object code from reading C++ file 'assignments.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assignments.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assignments.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_assignments_t {
    QByteArrayData data[20];
    char stringdata0[562];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_assignments_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_assignments_t qt_meta_stringdata_assignments = {
    {
QT_MOC_LITERAL(0, 0, 11), // "assignments"
QT_MOC_LITERAL(1, 12, 35), // "on_pushButton_addAssignment_c..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 38), // "on_comboBox_courses_currentTe..."
QT_MOC_LITERAL(4, 88, 4), // "arg1"
QT_MOC_LITERAL(5, 93, 36), // "on_pushButton_editAssignment_..."
QT_MOC_LITERAL(6, 130, 32), // "on_checkBox_pointsEarned_clicked"
QT_MOC_LITERAL(7, 163, 30), // "on_checkBox_percentage_clicked"
QT_MOC_LITERAL(8, 194, 34), // "on_checkBox_pointsEarned_2_cl..."
QT_MOC_LITERAL(9, 229, 32), // "on_checkBox_percentage_2_clicked"
QT_MOC_LITERAL(10, 262, 36), // "on_pushButton_saveAssignment_..."
QT_MOC_LITERAL(11, 299, 40), // "on_comboBox_courses_2_current..."
QT_MOC_LITERAL(12, 340, 32), // "on_tableView_assignments_clicked"
QT_MOC_LITERAL(13, 373, 5), // "index"
QT_MOC_LITERAL(14, 379, 38), // "on_pushButton_saveAssignment_..."
QT_MOC_LITERAL(15, 418, 38), // "on_pushButton_deleteAssignmen..."
QT_MOC_LITERAL(16, 457, 30), // "on_pushButton_cancel_2_clicked"
QT_MOC_LITERAL(17, 488, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(18, 517, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(19, 539, 22) // "refreshAssignmentTable"

    },
    "assignments\0on_pushButton_addAssignment_clicked\0"
    "\0on_comboBox_courses_currentTextChanged\0"
    "arg1\0on_pushButton_editAssignment_clicked\0"
    "on_checkBox_pointsEarned_clicked\0"
    "on_checkBox_percentage_clicked\0"
    "on_checkBox_pointsEarned_2_clicked\0"
    "on_checkBox_percentage_2_clicked\0"
    "on_pushButton_saveAssignment_clicked\0"
    "on_comboBox_courses_2_currentTextChanged\0"
    "on_tableView_assignments_clicked\0index\0"
    "on_pushButton_saveAssignment_2_clicked\0"
    "on_pushButton_deleteAssignment_clicked\0"
    "on_pushButton_cancel_2_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_clicked\0refreshAssignmentTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_assignments[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QModelIndex,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void assignments::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        assignments *_t = static_cast<assignments *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_addAssignment_clicked(); break;
        case 1: _t->on_comboBox_courses_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_editAssignment_clicked(); break;
        case 3: _t->on_checkBox_pointsEarned_clicked(); break;
        case 4: _t->on_checkBox_percentage_clicked(); break;
        case 5: _t->on_checkBox_pointsEarned_2_clicked(); break;
        case 6: _t->on_checkBox_percentage_2_clicked(); break;
        case 7: _t->on_pushButton_saveAssignment_clicked(); break;
        case 8: _t->on_comboBox_courses_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_tableView_assignments_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_saveAssignment_2_clicked(); break;
        case 11: _t->on_pushButton_deleteAssignment_clicked(); break;
        case 12: _t->on_pushButton_cancel_2_clicked(); break;
        case 13: _t->on_pushButton_cancel_clicked(); break;
        case 14: _t->on_pushButton_clicked(); break;
        case 15: _t->refreshAssignmentTable(); break;
        default: ;
        }
    }
}

const QMetaObject assignments::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_assignments.data,
      qt_meta_data_assignments,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *assignments::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *assignments::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_assignments.stringdata0))
        return static_cast<void*>(const_cast< assignments*>(this));
    return QDialog::qt_metacast(_clname);
}

int assignments::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
