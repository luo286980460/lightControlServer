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
    "showMsg",
    "",
    "sigSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "siglSetIntervalAndCount",
    "m_sendingInterval",
    "m_sendingCount",
    "sigConnectToControl",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "slotReceiveTcpData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlightcontrollENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[14];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[13];
    char stringdata5[9];
    char stringdata6[11];
    char stringdata7[8];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[12];
    char stringdata11[24];
    char stringdata12[18];
    char stringdata13[15];
    char stringdata14[20];
    char stringdata15[12];
    char stringdata16[6];
    char stringdata17[8];
    char stringdata18[7];
    char stringdata19[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlightcontrollENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlightcontrollENDCLASS_t qt_meta_stringdata_CLASSlightcontrollENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "lightcontroll"
        QT_MOC_LITERAL(14, 7),  // "showMsg"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 15),  // "sigSendDatagram"
        QT_MOC_LITERAL(39, 12),  // "sendDataList"
        QT_MOC_LITERAL(52, 8),  // "DeviceId"
        QT_MOC_LITERAL(61, 10),  // "ContentStr"
        QT_MOC_LITERAL(72, 7),  // "version"
        QT_MOC_LITERAL(80, 9),  // "fontColor"
        QT_MOC_LITERAL(90, 9),  // "Luminance"
        QT_MOC_LITERAL(100, 11),  // "FlickerList"
        QT_MOC_LITERAL(112, 23),  // "siglSetIntervalAndCount"
        QT_MOC_LITERAL(136, 17),  // "m_sendingInterval"
        QT_MOC_LITERAL(154, 14),  // "m_sendingCount"
        QT_MOC_LITERAL(169, 19),  // "sigConnectToControl"
        QT_MOC_LITERAL(189, 11),  // "write2Kafka"
        QT_MOC_LITERAL(201, 5),  // "topic"
        QT_MOC_LITERAL(207, 7),  // "strJson"
        QT_MOC_LITERAL(215, 6),  // "strKey"
        QT_MOC_LITERAL(222, 18)   // "slotReceiveTcpData"
    },
    "lightcontroll",
    "showMsg",
    "",
    "sigSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "siglSetIntervalAndCount",
    "m_sendingInterval",
    "m_sendingCount",
    "sigConnectToControl",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "slotReceiveTcpData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlightcontrollENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       3,    7,   65,    2, 0x06,    3 /* Public */,
      11,    2,   80,    2, 0x06,   11 /* Public */,
      11,    1,   85,    2, 0x26,   14 /* Public | MethodCloned */,
      11,    0,   88,    2, 0x26,   16 /* Public | MethodCloned */,
      14,    0,   89,    2, 0x06,   17 /* Public */,
      15,    3,   90,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,   97,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

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
        // method 'slotReceiveTcpData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
    >,
    nullptr
} };

void lightcontroll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lightcontroll *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sigSendDatagram((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7]))); break;
        case 2: _t->siglSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->siglSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->siglSetIntervalAndCount(); break;
        case 5: _t->sigConnectToControl(); break;
        case 6: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 7: _t->slotReceiveTcpData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lightcontroll::*)(QString );
            if (_t _q_method = &lightcontroll::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QStringList , QString , QString , int , int , int , QString );
            if (_t _q_method = &lightcontroll::sigSendDatagram; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(int , int );
            if (_t _q_method = &lightcontroll::siglSetIntervalAndCount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)();
            if (_t _q_method = &lightcontroll::sigConnectToControl; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (lightcontroll::*)(QString , QString , QString );
            if (_t _q_method = &lightcontroll::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void lightcontroll::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lightcontroll::sigSendDatagram(QStringList _t1, QString _t2, QString _t3, int _t4, int _t5, int _t6, QString _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void lightcontroll::siglSetIntervalAndCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 5
void lightcontroll::sigConnectToControl()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void lightcontroll::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
