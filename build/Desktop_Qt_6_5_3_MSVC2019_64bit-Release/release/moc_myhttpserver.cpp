/****************************************************************************
** Meta object code from reading C++ file 'myhttpserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../myhttpserver.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myhttpserver.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMyHttpServerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMyHttpServerENDCLASS = QtMocHelpers::stringData(
    "MyHttpServer",
    "forTest",
    "",
    "showMsg",
    "msg",
    "sigleUpdateTermListUi",
    "sigleUpdateControllerUi",
    "sigalUpdateRoadState",
    "sigalUpdateScreenState",
    "TermIp",
    "state",
    "signalUpDateScreenDefauleContent",
    "upStr",
    "downStr",
    "upColor",
    "downColor",
    "signalUpdateFF88",
    "ff88",
    "signalWrite2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalUpdateTermList",
    "ipList",
    "codeList",
    "signalTTS",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyHttpServerENDCLASS_t {
    uint offsetsAndSizes[68];
    char stringdata0[13];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[4];
    char stringdata5[22];
    char stringdata6[24];
    char stringdata7[21];
    char stringdata8[23];
    char stringdata9[7];
    char stringdata10[6];
    char stringdata11[33];
    char stringdata12[6];
    char stringdata13[8];
    char stringdata14[8];
    char stringdata15[10];
    char stringdata16[17];
    char stringdata17[5];
    char stringdata18[18];
    char stringdata19[6];
    char stringdata20[8];
    char stringdata21[7];
    char stringdata22[21];
    char stringdata23[7];
    char stringdata24[9];
    char stringdata25[10];
    char stringdata26[8];
    char stringdata27[5];
    char stringdata28[5];
    char stringdata29[7];
    char stringdata30[6];
    char stringdata31[4];
    char stringdata32[11];
    char stringdata33[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyHttpServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyHttpServerENDCLASS_t qt_meta_stringdata_CLASSMyHttpServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "MyHttpServer"
        QT_MOC_LITERAL(13, 7),  // "forTest"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 7),  // "showMsg"
        QT_MOC_LITERAL(30, 3),  // "msg"
        QT_MOC_LITERAL(34, 21),  // "sigleUpdateTermListUi"
        QT_MOC_LITERAL(56, 23),  // "sigleUpdateControllerUi"
        QT_MOC_LITERAL(80, 20),  // "sigalUpdateRoadState"
        QT_MOC_LITERAL(101, 22),  // "sigalUpdateScreenState"
        QT_MOC_LITERAL(124, 6),  // "TermIp"
        QT_MOC_LITERAL(131, 5),  // "state"
        QT_MOC_LITERAL(137, 32),  // "signalUpDateScreenDefauleContent"
        QT_MOC_LITERAL(170, 5),  // "upStr"
        QT_MOC_LITERAL(176, 7),  // "downStr"
        QT_MOC_LITERAL(184, 7),  // "upColor"
        QT_MOC_LITERAL(192, 9),  // "downColor"
        QT_MOC_LITERAL(202, 16),  // "signalUpdateFF88"
        QT_MOC_LITERAL(219, 4),  // "ff88"
        QT_MOC_LITERAL(224, 17),  // "signalWrite2Kafka"
        QT_MOC_LITERAL(242, 5),  // "topic"
        QT_MOC_LITERAL(248, 7),  // "strJson"
        QT_MOC_LITERAL(256, 6),  // "strKey"
        QT_MOC_LITERAL(263, 20),  // "signalUpdateTermList"
        QT_MOC_LITERAL(284, 6),  // "ipList"
        QT_MOC_LITERAL(291, 8),  // "codeList"
        QT_MOC_LITERAL(300, 9),  // "signalTTS"
        QT_MOC_LITERAL(310, 7),  // "Content"
        QT_MOC_LITERAL(318, 4),  // "Name"
        QT_MOC_LITERAL(323, 4),  // "sbbh"
        QT_MOC_LITERAL(328, 6),  // "Volume"
        QT_MOC_LITERAL(335, 5),  // "Times"
        QT_MOC_LITERAL(341, 3),  // "Gap"
        QT_MOC_LITERAL(345, 10),  // "m_deviceId"
        QT_MOC_LITERAL(356, 3)   // "vol"
    },
    "MyHttpServer",
    "forTest",
    "",
    "showMsg",
    "msg",
    "sigleUpdateTermListUi",
    "sigleUpdateControllerUi",
    "sigalUpdateRoadState",
    "sigalUpdateScreenState",
    "TermIp",
    "state",
    "signalUpDateScreenDefauleContent",
    "upStr",
    "downStr",
    "upColor",
    "downColor",
    "signalUpdateFF88",
    "ff88",
    "signalWrite2Kafka",
    "topic",
    "strJson",
    "strKey",
    "signalUpdateTermList",
    "ipList",
    "codeList",
    "signalTTS",
    "Content",
    "Name",
    "sbbh",
    "Volume",
    "Times",
    "Gap",
    "m_deviceId",
    "vol"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyHttpServerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,
       5,    0,   84,    2, 0x06,    4 /* Public */,
       6,    1,   85,    2, 0x06,    5 /* Public */,
       7,    1,   88,    2, 0x06,    7 /* Public */,
       8,    2,   91,    2, 0x06,    9 /* Public */,
      11,    6,   96,    2, 0x06,   12 /* Public */,
      16,    1,  109,    2, 0x06,   19 /* Public */,
      18,    3,  112,    2, 0x06,   21 /* Public */,
      22,    2,  119,    2, 0x06,   25 /* Public */,
      25,    9,  124,    2, 0x06,   28 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   12,   13,   14,   15,    9,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   20,   21,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,    9,   26,   27,   28,   29,   30,   31,   32,   33,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyHttpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyHttpServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyHttpServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyHttpServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyHttpServer, std::true_type>,
        // method 'forTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sigleUpdateTermListUi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigleUpdateControllerUi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sigalUpdateRoadState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sigalUpdateScreenState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalUpDateScreenDefauleContent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalUpdateFF88'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalWrite2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalUpdateTermList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MyHttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyHttpServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->forTest(); break;
        case 1: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sigleUpdateTermListUi(); break;
        case 3: _t->sigleUpdateControllerUi((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->sigalUpdateRoadState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sigalUpdateScreenState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->signalUpDateScreenDefauleContent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 7: _t->signalUpdateFF88((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->signalWrite2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 9: _t->signalUpdateTermList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 10: _t->signalTTS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyHttpServer::*)();
            if (_t _q_method = &MyHttpServer::forTest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString );
            if (_t _q_method = &MyHttpServer::showMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)();
            if (_t _q_method = &MyHttpServer::sigleUpdateTermListUi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString );
            if (_t _q_method = &MyHttpServer::sigleUpdateControllerUi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString );
            if (_t _q_method = &MyHttpServer::sigalUpdateRoadState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString , QString );
            if (_t _q_method = &MyHttpServer::sigalUpdateScreenState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString , QString , QString , QString , QString , QString );
            if (_t _q_method = &MyHttpServer::signalUpDateScreenDefauleContent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString );
            if (_t _q_method = &MyHttpServer::signalUpdateFF88; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString , QString , QString );
            if (_t _q_method = &MyHttpServer::signalWrite2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QStringList , QStringList );
            if (_t _q_method = &MyHttpServer::signalUpdateTermList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MyHttpServer::*)(QString , QString , QString , QString , int , int , int , QString , int );
            if (_t _q_method = &MyHttpServer::signalTTS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *MyHttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyHttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyHttpServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyHttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MyHttpServer::forTest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyHttpServer::showMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyHttpServer::sigleUpdateTermListUi()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyHttpServer::sigleUpdateControllerUi(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyHttpServer::sigalUpdateRoadState(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyHttpServer::sigalUpdateScreenState(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyHttpServer::signalUpDateScreenDefauleContent(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyHttpServer::signalUpdateFF88(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyHttpServer::signalWrite2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyHttpServer::signalUpdateTermList(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyHttpServer::signalTTS(QString _t1, QString _t2, QString _t3, QString _t4, int _t5, int _t6, int _t7, QString _t8, int _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
