/****************************************************************************
** Meta object code from reading C++ file 'taskmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PROECT/taskmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskManager_t {
    const uint offsetsAndSize[20];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TaskManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TaskManager_t qt_meta_stringdata_TaskManager = {
    {
QT_MOC_LITERAL(0, 11), // "TaskManager"
QT_MOC_LITERAL(12, 6), // "mySlot"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 4), // "text"
QT_MOC_LITERAL(25, 21), // "on_calendar_activated"
QT_MOC_LITERAL(47, 4), // "date"
QT_MOC_LITERAL(52, 21), // "on_add_button_clicked"
QT_MOC_LITERAL(74, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(99, 24), // "on_quit_action_triggered"
QT_MOC_LITERAL(124, 25) // "on_about_action_triggered"

    },
    "TaskManager\0mySlot\0\0text\0on_calendar_activated\0"
    "date\0on_add_button_clicked\0"
    "on_delete_button_clicked\0"
    "on_quit_action_triggered\0"
    "on_about_action_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    0 /* Public */,
       4,    1,   53,    2, 0x08,    2 /* Private */,
       6,    0,   56,    2, 0x08,    4 /* Private */,
       7,    0,   57,    2, 0x08,    5 /* Private */,
       8,    0,   58,    2, 0x08,    6 /* Private */,
       9,    0,   59,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TaskManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mySlot((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        case 1: _t->on_calendar_activated((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->on_add_button_clicked(); break;
        case 3: _t->on_delete_button_clicked(); break;
        case 4: _t->on_quit_action_triggered(); break;
        case 5: _t->on_about_action_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject TaskManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TaskManager.offsetsAndSize,
    qt_meta_data_TaskManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TaskManager_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<QString> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TaskManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskManager.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TaskManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
