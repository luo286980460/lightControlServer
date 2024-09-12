/****************************************************************************
** Meta object code from reading C++ file 'amplifierworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../amplifierworker.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'amplifierworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSamplifierWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSamplifierWorkerENDCLASS = QtMocHelpers::stringData(
    "amplifierWorker",
    "showMsg",
    "",
    "msg",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "forTest",
    "slotTTS",
    "TermIp",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol",
    "init",
    "slotUpdateTermList",
    "ipList",
    "codeList"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSamplifierWorkerENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[16];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[8];
    char stringdata7[7];
    char stringdata8[8];
    char stringdata9[8];
    char stringdata10[7];
    char stringdata11[8];
    char stringdata12[5];
    char stringdata13[5];
    char stringdata14[7];
    char stringdata15[6];
    char stringdata16[4];
    char stringdata17[11];
    char stringdata18[4];
    char stringdata19[5];
    char stringdata20[19];
    char stringdata21[7];
    char stringdata22[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSamplifierWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSamplifierWorkerENDCLASS_t qt_meta_stringdata_CLASSamplifierWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "amplifierWorker"
        QT_MOC_LITERAL(16, 7),  // "showMsg"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 3),  // "msg"
        QT_MOC_LITERAL(29, 11),  // "write2Kafka"
        QT_MOC_LITERAL(41, 5),  // "topic"
        QT_MOC_LITERAL(47, 7),  // "strJson"
        QT_MOC_LITERAL(55, 6),  // "strKey"
        QT_MOC_LITERAL(62, 7),  // "forTest"
        QT_MOC_LITERAL(70, 7),  // "slotTTS"
        QT_MOC_LITERAL(78, 6),  // "TermIp"
        QT_MOC_LITERAL(85, 7),  // "Content"
        QT_MOC_LITERAL(93, 4),  // "Name"
        QT_MOC_LITERAL(98, 4),  // "sbbh"
        QT_MOC_LITERAL(103, 6),  // "Volume"
        QT_MOC_LITERAL(110, 5),  // "Times"
        QT_MOC_LITERAL(116, 3),  // "Gap"
        QT_MOC_LITERAL(120, 10),  // "m_deviceId"
        QT_MOC_LITERAL(131, 3),  // "vol"
        QT_MOC_LITERAL(135, 4),  // "init"
        QT_MOC_LITERAL(140, 18),  // "slotUpdateTermList"
        QT_MOC_LITERAL(159, 6),  // "ipList"
        QT_MOC_LITERAL(166, 8)   // "codeList"
    },
    "amplifierWorker",
    "showMsg",
    "",
    "msg",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey",
    "forTest",
    "slotTTS",
    "TermIp",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol",
    "init",
    "slotUpdateTermList",
    "ipList",
    "codeList"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSamplifierWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    3,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   60,    2, 0x0a,    7 /* Public */,
       9,    9,   61,    2, 0x0a,    8 /* Public */,
      19,    0,   80,    2, 0x0a,   18 /* Public */,
      20,    2,   81,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,   10,   11,   12,   13,   14,   15,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   21,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject amplifierWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSamplifierWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSamplifierWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSamplifierWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<amplifierWorker, std::true_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'write2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'forTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotTTS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotUpdateTermList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>
    >,
    nullptr
} };

void amplifierWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<amplifierWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->forTest(); break;
        case 3: _t->slotTTS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 4: _t->init(); break;
        case 5: _t->slotUpdateTermList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (amplifierWorker::*)(QString );
            if (_t _q_method = &amplifierWorker::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (amplifierWorker::*)(QString , QString , QString );
            if (_t _q_method = &amplifierWorker::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *amplifierWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *amplifierWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSamplifierWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int amplifierWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void amplifierWorker::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void amplifierWorker::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
