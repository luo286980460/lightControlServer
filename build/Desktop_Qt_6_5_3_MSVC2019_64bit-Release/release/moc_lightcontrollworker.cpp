/****************************************************************************
** Meta object code from reading C++ file 'lightcontrollworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lightcontrollworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightcontrollworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSlightControllWorkerENDCLASS = QtMocHelpers::stringData(
    "lightControllWorker",
    "showMsg",
    "",
    "sigReceiveData",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalFinishUpdateLightState",
    "signalIsCheckingLightState",
    "b",
    "signalUpdateProgress",
    "progress",
    "signalTest",
    "ba",
    "signalUpdateLightStateJson",
    "checkIdList",
    "checkResultListTmp",
    "slotInit",
    "slotSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "slotReadyReadTcp",
    "slotReadyReadUdp",
    "slotSetIntervalAndCount",
    "sendingInterval",
    "sendingCount",
    "slotConnectToControl",
    "slotLightPowerOn",
    "on",
    "slotOpenPathTracking",
    "mode",
    "slotCheckLightState",
    "ip",
    "port",
    "idlist",
    "slotTest"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t {
    uint offsetsAndSizes[86];
    char stringdata0[20];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[8];
    char stringdata7[7];
    char stringdata8[29];
    char stringdata9[27];
    char stringdata10[2];
    char stringdata11[21];
    char stringdata12[9];
    char stringdata13[11];
    char stringdata14[3];
    char stringdata15[27];
    char stringdata16[12];
    char stringdata17[19];
    char stringdata18[9];
    char stringdata19[17];
    char stringdata20[13];
    char stringdata21[9];
    char stringdata22[11];
    char stringdata23[8];
    char stringdata24[10];
    char stringdata25[10];
    char stringdata26[12];
    char stringdata27[11];
    char stringdata28[17];
    char stringdata29[17];
    char stringdata30[24];
    char stringdata31[16];
    char stringdata32[13];
    char stringdata33[21];
    char stringdata34[17];
    char stringdata35[3];
    char stringdata36[21];
    char stringdata37[5];
    char stringdata38[20];
    char stringdata39[3];
    char stringdata40[5];
    char stringdata41[7];
    char stringdata42[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t qt_meta_stringdata_CLASSlightControllWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "lightControllWorker"
        QT_MOC_LITERAL(20, 7),  // "showMsg"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 14),  // "sigReceiveData"
        QT_MOC_LITERAL(44, 11),  // "write2Kafka"
        QT_MOC_LITERAL(56, 5),  // "topic"
        QT_MOC_LITERAL(62, 7),  // "strJson"
        QT_MOC_LITERAL(70, 6),  // "strKey"
        QT_MOC_LITERAL(77, 28),  // "signalFinishUpdateLightState"
        QT_MOC_LITERAL(106, 26),  // "signalIsCheckingLightState"
        QT_MOC_LITERAL(133, 1),  // "b"
        QT_MOC_LITERAL(135, 20),  // "signalUpdateProgress"
        QT_MOC_LITERAL(156, 8),  // "progress"
        QT_MOC_LITERAL(165, 10),  // "signalTest"
        QT_MOC_LITERAL(176, 2),  // "ba"
        QT_MOC_LITERAL(179, 26),  // "signalUpdateLightStateJson"
        QT_MOC_LITERAL(206, 11),  // "checkIdList"
        QT_MOC_LITERAL(218, 18),  // "checkResultListTmp"
        QT_MOC_LITERAL(237, 8),  // "slotInit"
        QT_MOC_LITERAL(246, 16),  // "slotSendDatagram"
        QT_MOC_LITERAL(263, 12),  // "sendDataList"
        QT_MOC_LITERAL(276, 8),  // "DeviceId"
        QT_MOC_LITERAL(285, 10),  // "ContentStr"
        QT_MOC_LITERAL(296, 7),  // "version"
        QT_MOC_LITERAL(304, 9),  // "fontColor"
        QT_MOC_LITERAL(314, 9),  // "Luminance"
        QT_MOC_LITERAL(324, 11),  // "FlickerList"
        QT_MOC_LITERAL(336, 10),  // "TermIdSize"
        QT_MOC_LITERAL(347, 16),  // "slotReadyReadTcp"
        QT_MOC_LITERAL(364, 16),  // "slotReadyReadUdp"
        QT_MOC_LITERAL(381, 23),  // "slotSetIntervalAndCount"
        QT_MOC_LITERAL(405, 15),  // "sendingInterval"
        QT_MOC_LITERAL(421, 12),  // "sendingCount"
        QT_MOC_LITERAL(434, 20),  // "slotConnectToControl"
        QT_MOC_LITERAL(455, 16),  // "slotLightPowerOn"
        QT_MOC_LITERAL(472, 2),  // "on"
        QT_MOC_LITERAL(475, 20),  // "slotOpenPathTracking"
        QT_MOC_LITERAL(496, 4),  // "mode"
        QT_MOC_LITERAL(501, 19),  // "slotCheckLightState"
        QT_MOC_LITERAL(521, 2),  // "ip"
        QT_MOC_LITERAL(524, 4),  // "port"
        QT_MOC_LITERAL(529, 6),  // "idlist"
        QT_MOC_LITERAL(536, 8)   // "slotTest"
    },
    "lightControllWorker",
    "showMsg",
    "",
    "sigReceiveData",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalFinishUpdateLightState",
    "signalIsCheckingLightState",
    "b",
    "signalUpdateProgress",
    "progress",
    "signalTest",
    "ba",
    "signalUpdateLightStateJson",
    "checkIdList",
    "checkResultListTmp",
    "slotInit",
    "slotSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "slotReadyReadTcp",
    "slotReadyReadUdp",
    "slotSetIntervalAndCount",
    "sendingInterval",
    "sendingCount",
    "slotConnectToControl",
    "slotLightPowerOn",
    "on",
    "slotOpenPathTracking",
    "mode",
    "slotCheckLightState",
    "ip",
    "port",
    "idlist",
    "slotTest"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlightControllWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,
       3,    1,  125,    2, 0x06,    3 /* Public */,
       4,    3,  128,    2, 0x06,    5 /* Public */,
       8,    0,  135,    2, 0x06,    9 /* Public */,
       9,    1,  136,    2, 0x06,   10 /* Public */,
      11,    1,  139,    2, 0x06,   12 /* Public */,
      13,    1,  142,    2, 0x06,   14 /* Public */,
      15,    2,  145,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    0,  150,    2, 0x0a,   19 /* Public */,
      19,    8,  151,    2, 0x0a,   20 /* Public */,
      28,    0,  168,    2, 0x0a,   29 /* Public */,
      29,    0,  169,    2, 0x0a,   30 /* Public */,
      30,    2,  170,    2, 0x0a,   31 /* Public */,
      33,    0,  175,    2, 0x0a,   34 /* Public */,
      34,    1,  176,    2, 0x0a,   35 /* Public */,
      36,    1,  179,    2, 0x0a,   37 /* Public */,
      38,    3,  182,    2, 0x0a,   39 /* Public */,
      42,    1,  189,    2, 0x0a,   43 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   16,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,   20,   21,   22,   23,   24,   25,   26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QStringList,   39,   40,   41,
    QMetaType::Void, QMetaType::QByteArray,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject lightControllWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSlightControllWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlightControllWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<lightControllWorker, std::true_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sigReceiveData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'write2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalFinishUpdateLightState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalIsCheckingLightState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalUpdateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'signalUpdateLightStateJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotInit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSendDatagram'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotReadyReadTcp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyReadUdp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetIntervalAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotConnectToControl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotLightPowerOn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotOpenPathTracking'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotCheckLightState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
    >,
    nullptr
} };

void lightControllWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lightControllWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sigReceiveData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->signalFinishUpdateLightState(); break;
        case 4: _t->signalIsCheckingLightState((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->signalUpdateProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->signalTest((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 7: _t->signalUpdateLightStateJson((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 8: _t->slotInit(); break;
        case 9: _t->slotSendDatagram((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 10: _t->slotReadyReadTcp(); break;
        case 11: _t->slotReadyReadUdp(); break;
        case 12: _t->slotSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->slotConnectToControl(); break;
        case 14: _t->slotLightPowerOn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->slotOpenPathTracking((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->slotCheckLightState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 17: _t->slotTest((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lightControllWorker::*)(QString );
            if (_t _q_method = &lightControllWorker::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(QByteArray );
            if (_t _q_method = &lightControllWorker::sigReceiveData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(QString , QString , QString );
            if (_t _q_method = &lightControllWorker::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)();
            if (_t _q_method = &lightControllWorker::signalFinishUpdateLightState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(bool );
            if (_t _q_method = &lightControllWorker::signalIsCheckingLightState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(QString );
            if (_t _q_method = &lightControllWorker::signalUpdateProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(QByteArray );
            if (_t _q_method = &lightControllWorker::signalTest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (lightControllWorker::*)(QStringList , QStringList );
            if (_t _q_method = &lightControllWorker::signalUpdateLightStateJson; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *lightControllWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lightControllWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlightControllWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int lightControllWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void lightControllWorker::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lightControllWorker::sigReceiveData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void lightControllWorker::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void lightControllWorker::signalFinishUpdateLightState()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void lightControllWorker::signalIsCheckingLightState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void lightControllWorker::signalUpdateProgress(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void lightControllWorker::signalTest(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void lightControllWorker::signalUpdateLightStateJson(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
