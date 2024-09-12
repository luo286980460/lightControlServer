/****************************************************************************
** Meta object code from reading C++ file 'amplifier.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../amplifier.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'amplifier.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSamplifierENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSamplifierENDCLASS = QtMocHelpers::stringData(
    "amplifier",
    "forTest",
    "",
    "showMsg",
    "msg",
    "signalTTS",
    "TermIp",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol",
    "signalInitWorker",
    "signalUpdateTermList",
    "ipList",
    "codeList",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSamplifierENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[10];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[4];
    char stringdata5[10];
    char stringdata6[7];
    char stringdata7[8];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[7];
    char stringdata11[6];
    char stringdata12[4];
    char stringdata13[11];
    char stringdata14[4];
    char stringdata15[17];
    char stringdata16[21];
    char stringdata17[7];
    char stringdata18[9];
    char stringdata19[12];
    char stringdata20[6];
    char stringdata21[8];
    char stringdata22[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSamplifierENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSamplifierENDCLASS_t qt_meta_stringdata_CLASSamplifierENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "amplifier"
        QT_MOC_LITERAL(10, 7),  // "forTest"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 7),  // "showMsg"
        QT_MOC_LITERAL(27, 3),  // "msg"
        QT_MOC_LITERAL(31, 9),  // "signalTTS"
        QT_MOC_LITERAL(41, 6),  // "TermIp"
        QT_MOC_LITERAL(48, 7),  // "Content"
        QT_MOC_LITERAL(56, 4),  // "Name"
        QT_MOC_LITERAL(61, 4),  // "sbbh"
        QT_MOC_LITERAL(66, 6),  // "Volume"
        QT_MOC_LITERAL(73, 5),  // "Times"
        QT_MOC_LITERAL(79, 3),  // "Gap"
        QT_MOC_LITERAL(83, 10),  // "m_deviceId"
        QT_MOC_LITERAL(94, 3),  // "vol"
        QT_MOC_LITERAL(98, 16),  // "signalInitWorker"
        QT_MOC_LITERAL(115, 20),  // "signalUpdateTermList"
        QT_MOC_LITERAL(136, 6),  // "ipList"
        QT_MOC_LITERAL(143, 8),  // "codeList"
        QT_MOC_LITERAL(152, 11),  // "write2Kafka"
        QT_MOC_LITERAL(164, 5),  // "topic"
        QT_MOC_LITERAL(170, 7),  // "strJson"
        QT_MOC_LITERAL(178, 6)   // "strKey"
    },
    "amplifier",
    "forTest",
    "",
    "showMsg",
    "msg",
    "signalTTS",
    "TermIp",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol",
    "signalInitWorker",
    "signalUpdateTermList",
    "ipList",
    "codeList",
    "write2Kafka",
    "topic",
    "strJson",
    "strKey"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSamplifierENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    1,   51,    2, 0x06,    2 /* Public */,
       5,    9,   54,    2, 0x06,    4 /* Public */,
      15,    0,   73,    2, 0x06,   14 /* Public */,
      16,    2,   74,    2, 0x06,   15 /* Public */,
      19,    3,   79,    2, 0x06,   18 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,    6,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   17,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   21,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject amplifier::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSamplifierENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSamplifierENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSamplifierENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<amplifier, std::true_type>,
        // method 'forTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalTTS'
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
        // method 'signalInitWorker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalUpdateTermList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'write2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void amplifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<amplifier *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->forTest(); break;
        case 1: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->signalTTS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 3: _t->signalInitWorker(); break;
        case 4: _t->signalUpdateTermList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 5: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (amplifier::*)();
            if (_t _q_method = &amplifier::forTest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (amplifier::*)(QString );
            if (_t _q_method = &amplifier::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (amplifier::*)(QString , QString , QString , QString , int , int , int , QString , int );
            if (_t _q_method = &amplifier::signalTTS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (amplifier::*)();
            if (_t _q_method = &amplifier::signalInitWorker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (amplifier::*)(QStringList , QStringList );
            if (_t _q_method = &amplifier::signalUpdateTermList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (amplifier::*)(QString , QString , QString );
            if (_t _q_method = &amplifier::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *amplifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *amplifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSamplifierENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int amplifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void amplifier::forTest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void amplifier::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void amplifier::signalTTS(QString _t1, QString _t2, QString _t3, QString _t4, int _t5, int _t6, int _t7, QString _t8, int _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void amplifier::signalInitWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void amplifier::signalUpdateTermList(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void amplifier::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
