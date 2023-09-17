/****************************************************************************
** Meta object code from reading C++ file 'colors.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../laba1/colors.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Colors_t {
    const uint offsetsAndSize[38];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Colors_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Colors_t qt_meta_stringdata_Colors = {
    {
QT_MOC_LITERAL(0, 6), // "Colors"
QT_MOC_LITERAL(7, 17), // "changed_SpinFirst"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(57, 4), // "text"
QT_MOC_LITERAL(62, 37), // "on_comboBox_center_currentTex..."
QT_MOC_LITERAL(100, 8), // "setColor"
QT_MOC_LITERAL(109, 32), // "on_comboBox_3_currentTextChanged"
QT_MOC_LITERAL(142, 18), // "changed_SpinSecond"
QT_MOC_LITERAL(161, 17), // "changed_SpinThird"
QT_MOC_LITERAL(179, 18), // "changed_SpinFourth"
QT_MOC_LITERAL(198, 24), // "changed_SpinFirst_center"
QT_MOC_LITERAL(223, 25), // "changed_SpinSecond_ctnter"
QT_MOC_LITERAL(249, 24), // "changed_SpinThird_center"
QT_MOC_LITERAL(274, 25), // "changed_SpinFourth_center"
QT_MOC_LITERAL(300, 23), // "changed_SpinFirst_right"
QT_MOC_LITERAL(324, 24), // "changed_SpinSecond_right"
QT_MOC_LITERAL(349, 23), // "changed_SpinThird_right"
QT_MOC_LITERAL(373, 24) // "changed_SpinFourth_right"

    },
    "Colors\0changed_SpinFirst\0\0"
    "on_comboBox_currentTextChanged\0text\0"
    "on_comboBox_center_currentTextChanged\0"
    "setColor\0on_comboBox_3_currentTextChanged\0"
    "changed_SpinSecond\0changed_SpinThird\0"
    "changed_SpinFourth\0changed_SpinFirst_center\0"
    "changed_SpinSecond_ctnter\0"
    "changed_SpinThird_center\0"
    "changed_SpinFourth_center\0"
    "changed_SpinFirst_right\0"
    "changed_SpinSecond_right\0"
    "changed_SpinThird_right\0"
    "changed_SpinFourth_right"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Colors[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    1,  111,    2, 0x08,    2 /* Private */,
       5,    1,  114,    2, 0x08,    4 /* Private */,
       6,    0,  117,    2, 0x08,    6 /* Private */,
       7,    1,  118,    2, 0x08,    7 /* Private */,
       8,    0,  121,    2, 0x08,    9 /* Private */,
       9,    0,  122,    2, 0x08,   10 /* Private */,
      10,    0,  123,    2, 0x08,   11 /* Private */,
      11,    0,  124,    2, 0x08,   12 /* Private */,
      12,    0,  125,    2, 0x08,   13 /* Private */,
      13,    0,  126,    2, 0x08,   14 /* Private */,
      14,    0,  127,    2, 0x08,   15 /* Private */,
      15,    0,  128,    2, 0x08,   16 /* Private */,
      16,    0,  129,    2, 0x08,   17 /* Private */,
      17,    0,  130,    2, 0x08,   18 /* Private */,
      18,    0,  131,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Colors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Colors *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changed_SpinFirst(); break;
        case 1: _t->on_comboBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_comboBox_center_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setColor(); break;
        case 4: _t->on_comboBox_3_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->changed_SpinSecond(); break;
        case 6: _t->changed_SpinThird(); break;
        case 7: _t->changed_SpinFourth(); break;
        case 8: _t->changed_SpinFirst_center(); break;
        case 9: _t->changed_SpinSecond_ctnter(); break;
        case 10: _t->changed_SpinThird_center(); break;
        case 11: _t->changed_SpinFourth_center(); break;
        case 12: _t->changed_SpinFirst_right(); break;
        case 13: _t->changed_SpinSecond_right(); break;
        case 14: _t->changed_SpinThird_right(); break;
        case 15: _t->changed_SpinFourth_right(); break;
        default: ;
        }
    }
}

const QMetaObject Colors::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Colors.offsetsAndSize,
    qt_meta_data_Colors,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Colors_t
, QtPrivate::TypeAndForceComplete<Colors, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Colors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Colors::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Colors.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Colors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
