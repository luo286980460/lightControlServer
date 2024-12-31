/****************************************************************************
** Meta object code from reading C++ file 'controllerworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../controllerworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllerworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSControllerWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControllerWorkerENDCLASS = QtMocHelpers::stringData(
    "ControllerWorker",
    "showMsg",
    "",
    "msg",
    "signalLightIsOff",
    "lightId",
    "signalWrite2Kafka",
    "slotInitWorker",
    "slotInitTcp",
    "ip",
    "port",
    "slotInitUdp",
    "slotReadyReadTcp",
    "slotReadyReadUdp",
    "slotCmd2Controller",
    "cmdList",
    "slotFlushAutoCheckCmd",
    "cmdCheckState",
    "cmdCheckPowerState",
    "cmdCheckPathTrackingDelay",
    "slotSendControlCmd",
    "slotSendCheckCmd"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerWorkerENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[17];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[17];
    char stringdata5[8];
    char stringdata6[18];
    char stringdata7[15];
    char stringdata8[12];
    char stringdata9[3];
    char stringdata10[5];
    char stringdata11[12];
    char stringdata12[17];
    char stringdata13[17];
    char stringdata14[19];
    char stringdata15[8];
    char stringdata16[22];
    char stringdata17[14];
    char stringdata18[19];
    char stringdata19[26];
    char stringdata20[19];
    char stringdata21[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControllerWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControllerWorkerENDCLASS_t qt_meta_stringdata_CLASSControllerWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "ControllerWorker"
        QT_MOC_LITERAL(17, 7),  // "showMsg"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 3),  // "msg"
        QT_MOC_LITERAL(30, 16),  // "signalLightIsOff"
        QT_MOC_LITERAL(47, 7),  // "lightId"
        QT_MOC_LITERAL(55, 17),  // "signalWrite2Kafka"
        QT_MOC_LITERAL(73, 14),  // "slotInitWorker"
        QT_MOC_LITERAL(88, 11),  // "slotInitTcp"
        QT_MOC_LITERAL(100, 2),  // "ip"
        QT_MOC_LITERAL(103, 4),  // "port"
        QT_MOC_LITERAL(108, 11),  // "slotInitUdp"
        QT_MOC_LITERAL(120, 16),  // "slotReadyReadTcp"
        QT_MOC_LITERAL(137, 16),  // "slotReadyReadUdp"
        QT_MOC_LITERAL(154, 18),  // "slotCmd2Controller"
        QT_MOC_LITERAL(173, 7),  // "cmdList"
        QT_MOC_LITERAL(181, 21),  // "slotFlushAutoCheckCmd"
        QT_MOC_LITERAL(203, 13),  // "cmdCheckState"
        QT_MOC_LITERAL(217, 18),  // "cmdCheckPowerState"
        QT_MOC_LITERAL(236, 25),  // "cmdCheckPathTrackingDelay"
        QT_MOC_LITERAL(262, 18),  // "slotSendControlCmd"
        QT_MOC_LITERAL(281, 16)   // "slotSendCheckCmd"
    },
    "ControllerWorker",
    "showMsg",
    "",
    "msg",
    "signalLightIsOff",
    "lightId",
    "signalWrite2Kafka",
    "slotInitWorker",
    "slotInitTcp",
    "ip",
    "port",
    "slotInitUdp",
    "slotReadyReadTcp",
    "slotReadyReadUdp",
    "slotCmd2Controller",
    "cmdList",
    "slotFlushAutoCheckCmd",
    "cmdCheckState",
    "cmdCheckPowerState",
    "cmdCheckPathTrackingDelay",
    "slotSendControlCmd",
    "slotSendCheckCmd"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       4,    1,   89,    2, 0x06,    3 /* Public */,
       6,    0,   92,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   93,    2, 0x0a,    6 /* Public */,
       8,    2,   94,    2, 0x0a,    7 /* Public */,
      11,    0,   99,    2, 0x0a,   10 /* Public */,
      12,    0,  100,    2, 0x0a,   11 /* Public */,
      13,    0,  101,    2, 0x0a,   12 /* Public */,
      14,    1,  102,    2, 0x0a,   13 /* Public */,
      16,    3,  105,    2, 0x0a,   15 /* Public */,
      20,    1,  112,    2, 0x0a,   19 /* Public */,
      21,    1,  115,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   17,   18,   19,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject ControllerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSControllerWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControllerWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSControllerWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ControllerWorker, std::true_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalLightIsOff'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalWrite2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotInitWorker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotInitTcp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotInitUdp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyReadTcp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyReadUdp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotCmd2Controller'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotFlushAutoCheckCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotSendControlCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotSendCheckCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>
    >,
    nullptr
} };

void ControllerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControllerWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->signalLightIsOff((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->signalWrite2Kafka(); break;
        case 3: _t->slotInitWorker(); break;
        case 4: _t->slotInitTcp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->slotInitUdp(); break;
        case 6: _t->slotReadyReadTcp(); break;
        case 7: _t->slotReadyReadUdp(); break;
        case 8: _t->slotCmd2Controller((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->slotFlushAutoCheckCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 10: _t->slotSendControlCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 11: _t->slotSendCheckCmd((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ControllerWorker::*)(QString );
            if (_t _q_method = &ControllerWorker::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ControllerWorker::*)(int );
            if (_t _q_method = &ControllerWorker::signalLightIsOff; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ControllerWorker::*)();
            if (_t _q_method = &ControllerWorker::signalWrite2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ControllerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControllerWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ControllerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ControllerWorker::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControllerWorker::signalLightIsOff(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControllerWorker::signalWrite2Kafka()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
