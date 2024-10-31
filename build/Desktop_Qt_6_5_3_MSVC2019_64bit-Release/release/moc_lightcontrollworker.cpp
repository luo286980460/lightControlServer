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
    "slotSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "slotReadyRead",
    "slotSetIntervalAndCount",
    "sendingInterval",
    "sendingCount",
    "slotConnectToControl"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlightControllWorkerENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[20];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[8];
    char stringdata7[7];
    char stringdata8[17];
    char stringdata9[13];
    char stringdata10[9];
    char stringdata11[11];
    char stringdata12[8];
    char stringdata13[10];
    char stringdata14[10];
    char stringdata15[12];
    char stringdata16[11];
    char stringdata17[14];
    char stringdata18[24];
    char stringdata19[16];
    char stringdata20[13];
    char stringdata21[21];
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
        QT_MOC_LITERAL(77, 16),  // "slotSendDatagram"
        QT_MOC_LITERAL(94, 12),  // "sendDataList"
        QT_MOC_LITERAL(107, 8),  // "DeviceId"
        QT_MOC_LITERAL(116, 10),  // "ContentStr"
        QT_MOC_LITERAL(127, 7),  // "version"
        QT_MOC_LITERAL(135, 9),  // "fontColor"
        QT_MOC_LITERAL(145, 9),  // "Luminance"
        QT_MOC_LITERAL(155, 11),  // "FlickerList"
        QT_MOC_LITERAL(167, 10),  // "TermIdSize"
        QT_MOC_LITERAL(178, 13),  // "slotReadyRead"
        QT_MOC_LITERAL(192, 23),  // "slotSetIntervalAndCount"
        QT_MOC_LITERAL(216, 15),  // "sendingInterval"
        QT_MOC_LITERAL(232, 12),  // "sendingCount"
        QT_MOC_LITERAL(245, 20)   // "slotConnectToControl"
    },
    "lightControllWorker",
    "showMsg",
    "",
    "sigReceiveData",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "slotSendDatagram",
    "sendDataList",
    "DeviceId",
    "ContentStr",
    "version",
    "fontColor",
    "Luminance",
    "FlickerList",
    "TermIdSize",
    "slotReadyRead",
    "slotSetIntervalAndCount",
    "sendingInterval",
    "sendingCount",
    "slotConnectToControl"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlightControllWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       3,    1,   59,    2, 0x06,    3 /* Public */,
       4,    3,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    8,   69,    2, 0x0a,    9 /* Public */,
      17,    0,   86,    2, 0x0a,   18 /* Public */,
      18,    2,   87,    2, 0x0a,   19 /* Public */,
      21,    0,   92,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,    9,   10,   11,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void,

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
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetIntervalAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotConnectToControl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        case 3: _t->slotSendDatagram((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotSetIntervalAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->slotConnectToControl(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
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
QT_WARNING_POP
