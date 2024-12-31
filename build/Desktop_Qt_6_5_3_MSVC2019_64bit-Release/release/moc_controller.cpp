/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../controller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControllerENDCLASS = QtMocHelpers::stringData(
    "Controller",
    "showMsg",
    "",
    "msg",
    "signalInitWorker",
    "signalInitTcp",
    "ip",
    "port",
    "signalInitUdp",
    "signalFlushAutoCheckCmd",
    "cmdCheck1",
    "cmdCheck2",
    "cmdCheck3",
    "signalSendControlCmd",
    "cmdList",
    "signalSendCheckCmd",
    "signalLightPowerOn",
    "on",
    "signalWrite2Kafka",
    "topic",
    "strJson",
    "strKey",
    "slotLightIsOff",
    "lightId",
    "slotWrite2Kafka"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {
    uint offsetsAndSizes[50];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[17];
    char stringdata5[14];
    char stringdata6[3];
    char stringdata7[5];
    char stringdata8[14];
    char stringdata9[24];
    char stringdata10[10];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[21];
    char stringdata14[8];
    char stringdata15[19];
    char stringdata16[19];
    char stringdata17[3];
    char stringdata18[18];
    char stringdata19[6];
    char stringdata20[8];
    char stringdata21[7];
    char stringdata22[15];
    char stringdata23[8];
    char stringdata24[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControllerENDCLASS_t qt_meta_stringdata_CLASSControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Controller"
        QT_MOC_LITERAL(11, 7),  // "showMsg"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 3),  // "msg"
        QT_MOC_LITERAL(24, 16),  // "signalInitWorker"
        QT_MOC_LITERAL(41, 13),  // "signalInitTcp"
        QT_MOC_LITERAL(55, 2),  // "ip"
        QT_MOC_LITERAL(58, 4),  // "port"
        QT_MOC_LITERAL(63, 13),  // "signalInitUdp"
        QT_MOC_LITERAL(77, 23),  // "signalFlushAutoCheckCmd"
        QT_MOC_LITERAL(101, 9),  // "cmdCheck1"
        QT_MOC_LITERAL(111, 9),  // "cmdCheck2"
        QT_MOC_LITERAL(121, 9),  // "cmdCheck3"
        QT_MOC_LITERAL(131, 20),  // "signalSendControlCmd"
        QT_MOC_LITERAL(152, 7),  // "cmdList"
        QT_MOC_LITERAL(160, 18),  // "signalSendCheckCmd"
        QT_MOC_LITERAL(179, 18),  // "signalLightPowerOn"
        QT_MOC_LITERAL(198, 2),  // "on"
        QT_MOC_LITERAL(201, 17),  // "signalWrite2Kafka"
        QT_MOC_LITERAL(219, 5),  // "topic"
        QT_MOC_LITERAL(225, 7),  // "strJson"
        QT_MOC_LITERAL(233, 6),  // "strKey"
        QT_MOC_LITERAL(240, 14),  // "slotLightIsOff"
        QT_MOC_LITERAL(255, 7),  // "lightId"
        QT_MOC_LITERAL(263, 15)   // "slotWrite2Kafka"
    },
    "Controller",
    "showMsg",
    "",
    "msg",
    "signalInitWorker",
    "signalInitTcp",
    "ip",
    "port",
    "signalInitUdp",
    "signalFlushAutoCheckCmd",
    "cmdCheck1",
    "cmdCheck2",
    "cmdCheck3",
    "signalSendControlCmd",
    "cmdList",
    "signalSendCheckCmd",
    "signalLightPowerOn",
    "on",
    "signalWrite2Kafka",
    "topic",
    "strJson",
    "strKey",
    "slotLightIsOff",
    "lightId",
    "slotWrite2Kafka"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    0,   83,    2, 0x06,    3 /* Public */,
       5,    2,   84,    2, 0x06,    4 /* Public */,
       8,    0,   89,    2, 0x06,    7 /* Public */,
       9,    3,   90,    2, 0x06,    8 /* Public */,
      13,    1,   97,    2, 0x06,   12 /* Public */,
      15,    1,  100,    2, 0x06,   14 /* Public */,
      16,    1,  103,    2, 0x06,   16 /* Public */,
      18,    3,  106,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      22,    1,  113,    2, 0x0a,   22 /* Public */,
      24,    0,  116,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   10,   11,   12,
    QMetaType::Void, QMetaType::QStringList,   14,
    QMetaType::Void, QMetaType::QStringList,   14,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   20,   21,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Controller, std::true_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalInitWorker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalInitTcp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalInitUdp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalFlushAutoCheckCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'signalSendControlCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'signalSendCheckCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'signalLightPowerOn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalWrite2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotLightIsOff'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotWrite2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->signalInitWorker(); break;
        case 2: _t->signalInitTcp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->signalInitUdp(); break;
        case 4: _t->signalFlushAutoCheckCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 5: _t->signalSendControlCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 6: _t->signalSendCheckCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 7: _t->signalLightPowerOn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->signalWrite2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 9: _t->slotLightIsOff((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->slotWrite2Kafka(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(QString );
            if (_t _q_method = &Controller::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::signalInitWorker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QString , int );
            if (_t _q_method = &Controller::signalInitTcp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::signalInitUdp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QStringList , QStringList , QStringList );
            if (_t _q_method = &Controller::signalFlushAutoCheckCmd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QStringList );
            if (_t _q_method = &Controller::signalSendControlCmd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QStringList );
            if (_t _q_method = &Controller::signalSendCheckCmd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Controller::*)(bool );
            if (_t _q_method = &Controller::signalLightPowerOn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QString , QString , QString );
            if (_t _q_method = &Controller::signalWrite2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Controller::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::signalInitWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controller::signalInitTcp(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::signalInitUdp()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Controller::signalFlushAutoCheckCmd(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::signalSendControlCmd(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Controller::signalSendCheckCmd(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::signalLightPowerOn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::signalWrite2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
