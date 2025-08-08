/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../gui/desktop/view/include/gamewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__GameWidget_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_s21__GameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_s21__GameWidget_t qt_meta_stringdata_s21__GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "s21::GameWidget"
QT_MOC_LITERAL(1, 16, 16), // "DeviceInputFixed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "UserAction_t"
QT_MOC_LITERAL(4, 47, 6), // "action"
QT_MOC_LITERAL(5, 54, 4), // "hold"
QT_MOC_LITERAL(6, 59, 15), // "TransmiteSignal"
QT_MOC_LITERAL(7, 75, 4), // "Exit"
QT_MOC_LITERAL(8, 80, 10), // "BackUpdate"
QT_MOC_LITERAL(9, 91, 10) // "UpdateInfo"

    },
    "s21::GameWidget\0DeviceInputFixed\0\0"
    "UserAction_t\0action\0hold\0TransmiteSignal\0"
    "Exit\0BackUpdate\0UpdateInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__GameWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   44,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void s21::GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->DeviceInputFixed((*reinterpret_cast< UserAction_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->TransmiteSignal((*reinterpret_cast< UserAction_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->Exit(); break;
        case 3: _t->BackUpdate(); break;
        case 4: _t->UpdateInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWidget::*)(UserAction_t , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWidget::DeviceInputFixed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject s21::GameWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__GameWidget.data,
    qt_meta_data_s21__GameWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *s21::GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__GameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void s21::GameWidget::DeviceInputFixed(UserAction_t _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
