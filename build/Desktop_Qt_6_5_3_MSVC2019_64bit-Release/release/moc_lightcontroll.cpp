/****************************************************************************
** Meta object code from reading C++ file 'lightcontroll.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lightcontroll.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightcontroll.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlightcontrollENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSlightcontrollENDCLASS = QtMocHelpers::stringData(
    "lightcontroll",
    "signalInitWorker",
    "",
    "showMsg",
    "sigSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "siglSetIntervalAndCount",
    "m_sendingInterval",
    "m_sendingCount",
    "sigConnectToControl",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalLightPowerOn",
    "on",
    "signalOpenPathTracking",
    "mode",
    "signalCheckLightState",
    "ip",
    "port",
    "idlist",
    "slotReceiveTcpData",
    "slotIsCheckingLightState",
    "b",
    "slotUpdateProgress",
    "progress",
    "slotUpdateLightStateJson",
    "checkIdList",
    "checkResultListTmp"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlightcontrollENDCLASS_t {
    uint offsetsAndSizes[74];
    char stringdata0[14];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[16];
    char stringdata5[13];
    char stringdata6[9];
    char stringdata7[11];
    char stringdata8[8];
    char stringdata9[10];
    char stringdata10[10];
    char stringdata11[12];
    char stringdata12[11];
    char stringdata13[24];
    char stringdata14[18];
    char stringdata15[15];
    char stringdata16[20];
    char stringdata17[12];
    char stringdata18[6];
    char stringdata19[8];
    char stringdata20[7];
    char stringdata21[19];
    char stringdata22[3];
    char stringdata23[23];
    char stringdata24[5];
    char stringdata25[22];
    char stringdata26[3];
    char stringdata27[5];
    char stringdata28[7];
    char stringdata29[19];
    char stringdata30[25];
    char stringdata31[2];
    char stringdata32[19];
    char stringdata33[9];
    char stringdata34[25];
    char stringdata35[12];
    char stringdata36[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlightcontrollENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlightcontrollENDCLASS_t qt_meta_stringdata_CLASSlightcontrollENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "lightcontroll"
        QT_MOC_LITERAL(14, 16),  // "signalInitWorker"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 7),  // "showMsg"
        QT_MOC_LITERAL(40, 15),  // "sigSendDatagram"
        QT_MOC_LITERAL(56, 12),  // "sendDataList"
        QT_MOC_LITERAL(69, 8),  // "DeviceId"
        QT_MOC_LITERAL(78, 10),  // "ContentStr"
        QT_MOC_LITERAL(89, 7),  // "version"
        QT_MOC_LITERAL(97, 9),  // "fontColor"
        QT_MOC_LITERAL(107, 9),  // "Luminance"
        QT_MOC_LITERAL(117, 11),  // "FlickerList"
        QT_MOC_LITERAL(129, 10),  // "TermIdSize"
        QT_MOC_LITERAL(140, 23),  // "siglSetIntervalAndCount"
        QT_MOC_LITERAL(164, 17),  // "m_sendingInterval"
        QT_MOC_LITERAL(182, 14),  // "m_sendingCount"
        QT_MOC_LITERAL(197, 19),  // "sigConnectToControl"
        QT_MOC_LITERAL(217, 11),  // "write2Kafka"
        QT_MOC_LITERAL(229, 5),  // "topic"
        QT_MOC_LITERAL(235, 7),  // "strJson"
        QT_MOC_LITERAL(243, 6),  // "strKey"
        QT_MOC_LITERAL(250, 18),  // "signalLightPowerOn"
        QT_MOC_LITERAL(269, 2),  // "on"
        QT_MOC_LITERAL(272, 22),  // "signalOpenPathTracking"
        QT_MOC_LITERAL(295, 4),  // "mode"
        QT_MOC_LITERAL(300, 21),  // "signalCheckLightState"
        QT_MOC_LITERAL(322, 2),  // "ip"
        QT_MOC_LITERAL(325, 4),  // "port"
        QT_MOC_LITERAL(330, 6),  // "idlist"
        QT_MOC_LITERAL(337, 18),  // "slotReceiveTcpData"
        QT_MOC_LITERAL(356, 24),  // "slotIsCheckingLightState"
        QT_MOC_LITERAL(381, 1),  // "b"
        QT_MOC_LITERAL(383, 18),  // "slotUpdateProgress"
        QT_MOC_LITERAL(402, 8),  // "progress"
        QT_MOC_LITERAL(411, 24),  // "slotUpdateLightStateJson"
        QT_MOC_LITERAL(436, 11),  // "checkIdList"
        QT_MOC_LITERAL(448, 18)   // "checkResultListTmp"
    },
    "lightcontroll",
    "signalInitWorker",
    "",
    "showMsg",
    "sigSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "siglSetIntervalAndCount",
    "m_sendingInterval",
    "m_sendingCount",
    "sigConnectToControl",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalLightPowerOn",
    "on",
    "signalOpenPathTracking",
    "mode",
    "signalCheckLightState",
    "ip",
    "port",
    "idlist",
    "slotReceiveTcpData",
    "slotIsCheckingLightState",
    "b",
    "slotUpdateProgress",
    "progress",
    "slotUpdateLightStateJson",
    "checkIdList",
    "checkResultListTmp"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlightcontrollENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    1 /* Public */,
       3,    1,  105,    2, 0x06,    2 /* Public */,
       4,    8,  108,    2, 0x06,    4 /* Public */,
      13,    2,  125,    2, 0x06,   13 /* Public */,
      13,    1,  130,    2, 0x26,   16 /* Public | MethodCloned */,
      13,    0,  133,    2, 0x26,   18 /* Public | MethodCloned */,
      16,    0,  134,    2, 0x06,   19 /* Public */,
      17,    3,  135,    2, 0x06,   20 /* Public */,
      21,    1,  142,    2, 0x06,   24 /* Public */,
      23,    1,  145,    2, 0x06,   26 /* Public */,
      25,    3,  148,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      29,    1,  155,    2, 0x0a,   32 /* Public */,
      30,    1,  158,    2, 0x0a,   34 /* Public */,
      32,    1,  161,    2, 0x0a,   36 /* Public */,
      34,    2,  164,    2, 0x0a,   38 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,    5,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QStringList,   26,   27,   28,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   35,   36,

       0        // eod
};

Q_CONSTINIT const QMetaObject lightcontroll::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSlightcontrollENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlightcontrollENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlightcontrollENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<lightcontroll, std::true_type>,
        // method 'signalInitWorker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sigSendDatagram'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'siglSetIntervalAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'siglSetIntervalAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'siglSetIntervalAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigConnectToControl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'write2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalLightPowerOn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalOpenPathTracking'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalCheckLightState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'slotReceiveTcpData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'slotIsCheckingLightState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotUpdateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotUpdateLightStateJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>
    >,
    nullptr
} };

void lightcontroll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lightcontroll *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalInitWorker(); break;
        case 1: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sigSendDatagram((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 3: _t->siglSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->siglSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->siglSetIntervalAndCount(); break;
        case 6: _t->sigConnectToControl(); break;
        case 7: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->signalLightPowerOn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->signalOpenPathTracking((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->signalCheckLightState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 11: _t->slotReceiveTcpData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 12: _t->slotIsCheckingLightState((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->slotUpdateProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->slotUpdateLightStateJson((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lightcontroll::*)();
            if (_t _q_method = &lightcontroll::signalInitWorker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QString );
            if (_t _q_method = &lightcontroll::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QStringList , QString , QString , int , int , int , QString , int );
            if (_t _q_method = &lightcontroll::sigSendDatagram; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(int , int );
            if (_t _q_method = &lightcontroll::siglSetIntervalAndCount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)();
            if (_t _q_method = &lightcontroll::sigConnectToControl; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QString , QString , QString );
            if (_t _q_method = &lightcontroll::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(bool );
            if (_t _q_method = &lightcontroll::signalLightPowerOn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(int );
            if (_t _q_method = &lightcontroll::signalOpenPathTracking; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QString , int , QStringList );
            if (_t _q_method = &lightcontroll::signalCheckLightState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *lightcontroll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lightcontroll::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlightcontrollENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int lightcontroll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void lightcontroll::signalInitWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void lightcontroll::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void lightcontroll::sigSendDatagram(QStringList _t1, QString _t2, QString _t3, int _t4, int _t5, int _t6, QString _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void lightcontroll::siglSetIntervalAndCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 6
void lightcontroll::sigConnectToControl()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void lightcontroll::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void lightcontroll::signalLightPowerOn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void lightcontroll::signalOpenPathTracking(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void lightcontroll::signalCheckLightState(QString _t1, int _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
