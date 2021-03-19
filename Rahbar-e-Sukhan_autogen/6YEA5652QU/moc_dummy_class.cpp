/****************************************************************************
** Meta object code from reading C++ file 'dummy_class.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/dummy_class.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dummy_class.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dummy_class_t {
    QByteArrayData data[16];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dummy_class_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dummy_class_t qt_meta_stringdata_dummy_class = {
    {
QT_MOC_LITERAL(0, 0, 11), // "dummy_class"
QT_MOC_LITERAL(1, 12, 14), // "retrieve_input"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "input"
QT_MOC_LITERAL(4, 34, 11), // "no_of_lines"
QT_MOC_LITERAL(5, 46, 11), // "no_of_words"
QT_MOC_LITERAL(6, 58, 5), // "index"
QT_MOC_LITERAL(7, 64, 12), // "ravani_score"
QT_MOC_LITERAL(8, 77, 10), // "send_meter"
QT_MOC_LITERAL(9, 88, 1), // "i"
QT_MOC_LITERAL(10, 90, 14), // "send_word_list"
QT_MOC_LITERAL(11, 105, 1), // "j"
QT_MOC_LITERAL(12, 107, 4), // "init"
QT_MOC_LITERAL(13, 112, 8), // "con_init"
QT_MOC_LITERAL(14, 121, 9), // "edit_line"
QT_MOC_LITERAL(15, 131, 13) // "updated_input"

    },
    "dummy_class\0retrieve_input\0\0input\0"
    "no_of_lines\0no_of_words\0index\0"
    "ravani_score\0send_meter\0i\0send_word_list\0"
    "j\0init\0con_init\0edit_line\0updated_input"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dummy_class[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,
      10,    2,   72,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      14,    2,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int,    6,
    QMetaType::Int, QMetaType::Int,    6,
    QMetaType::QStringList, QMetaType::Int,    9,
    QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    9,   11,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,    6,

       0        // eod
};

void dummy_class::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dummy_class *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->retrieve_input((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->no_of_lines();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->no_of_words((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->ravani_score((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QStringList _r = _t->send_meter((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QStringList _r = _t->send_word_list((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->init((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->con_init((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->edit_line((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dummy_class::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_dummy_class.data,
    qt_meta_data_dummy_class,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dummy_class::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dummy_class::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dummy_class.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dummy_class::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
