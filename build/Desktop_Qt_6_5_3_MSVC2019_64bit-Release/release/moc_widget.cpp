/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../widget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "write2Kafka",
    "",
    "topic",
    "strJson",
    "strKey",
    "write2Screen",
    "ip",
    "type",
    "plate",
    "write2Light",
    "sendDataList",
    "sbbh",
    "name",
    "version",
    "color",
    "light",
    "pl",
    "setLightIntAndCount",
    "sendingInterval",
    "sendingCount",
    "signalUpDateScreenDefauleContent",
    "state",
    "defaultContent",
    "TermIp",
    "signalUpDateScreenState",
    "on_clearBtn_clicked",
    "on_OpenBtn_clicked",
    "showMsg",
    "slotUpdateRoadState",
    "iconActivated",
    "QSystemTrayIcon::ActivationReason",
    "reason",
    "soltUpdateTermListUi",
    "slotUpdateControllerUi",
    "slotUpdateFF88",
    "ff88",
    "on_testBtn_clicked",
    "dealPicFiles",
    "path",
    "requestFinished",
    "QNetworkReply*",
    "reply"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[86];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[8];
    char stringdata5[7];
    char stringdata6[13];
    char stringdata7[3];
    char stringdata8[5];
    char stringdata9[6];
    char stringdata10[12];
    char stringdata11[13];
    char stringdata12[5];
    char stringdata13[5];
    char stringdata14[8];
    char stringdata15[6];
    char stringdata16[6];
    char stringdata17[3];
    char stringdata18[20];
    char stringdata19[16];
    char stringdata20[13];
    char stringdata21[33];
    char stringdata22[6];
    char stringdata23[15];
    char stringdata24[7];
    char stringdata25[24];
    char stringdata26[20];
    char stringdata27[19];
    char stringdata28[8];
    char stringdata29[20];
    char stringdata30[14];
    char stringdata31[34];
    char stringdata32[7];
    char stringdata33[21];
    char stringdata34[23];
    char stringdata35[15];
    char stringdata36[5];
    char stringdata37[19];
    char stringdata38[13];
    char stringdata39[5];
    char stringdata40[16];
    char stringdata41[15];
    char stringdata42[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 11),  // "write2Kafka"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 5),  // "topic"
        QT_MOC_LITERAL(26, 7),  // "strJson"
        QT_MOC_LITERAL(34, 6),  // "strKey"
        QT_MOC_LITERAL(41, 12),  // "write2Screen"
        QT_MOC_LITERAL(54, 2),  // "ip"
        QT_MOC_LITERAL(57, 4),  // "type"
        QT_MOC_LITERAL(62, 5),  // "plate"
        QT_MOC_LITERAL(68, 11),  // "write2Light"
        QT_MOC_LITERAL(80, 12),  // "sendDataList"
        QT_MOC_LITERAL(93, 4),  // "sbbh"
        QT_MOC_LITERAL(98, 4),  // "name"
        QT_MOC_LITERAL(103, 7),  // "version"
        QT_MOC_LITERAL(111, 5),  // "color"
        QT_MOC_LITERAL(117, 5),  // "light"
        QT_MOC_LITERAL(123, 2),  // "pl"
        QT_MOC_LITERAL(126, 19),  // "setLightIntAndCount"
        QT_MOC_LITERAL(146, 15),  // "sendingInterval"
        QT_MOC_LITERAL(162, 12),  // "sendingCount"
        QT_MOC_LITERAL(175, 32),  // "signalUpDateScreenDefauleContent"
        QT_MOC_LITERAL(208, 5),  // "state"
        QT_MOC_LITERAL(214, 14),  // "defaultContent"
        QT_MOC_LITERAL(229, 6),  // "TermIp"
        QT_MOC_LITERAL(236, 23),  // "signalUpDateScreenState"
        QT_MOC_LITERAL(260, 19),  // "on_clearBtn_clicked"
        QT_MOC_LITERAL(280, 18),  // "on_OpenBtn_clicked"
        QT_MOC_LITERAL(299, 7),  // "showMsg"
        QT_MOC_LITERAL(307, 19),  // "slotUpdateRoadState"
        QT_MOC_LITERAL(327, 13),  // "iconActivated"
        QT_MOC_LITERAL(341, 33),  // "QSystemTrayIcon::ActivationRe..."
        QT_MOC_LITERAL(375, 6),  // "reason"
        QT_MOC_LITERAL(382, 20),  // "soltUpdateTermListUi"
        QT_MOC_LITERAL(403, 22),  // "slotUpdateControllerUi"
        QT_MOC_LITERAL(426, 14),  // "slotUpdateFF88"
        QT_MOC_LITERAL(441, 4),  // "ff88"
        QT_MOC_LITERAL(446, 18),  // "on_testBtn_clicked"
        QT_MOC_LITERAL(465, 12),  // "dealPicFiles"
        QT_MOC_LITERAL(478, 4),  // "path"
        QT_MOC_LITERAL(483, 15),  // "requestFinished"
        QT_MOC_LITERAL(499, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(514, 5)   // "reply"
    },
    "Widget",
    "write2Kafka",
    "",
    "topic",
    "strJson",
    "strKey",
    "write2Screen",
    "ip",
    "type",
    "plate",
    "write2Light",
    "sendDataList",
    "sbbh",
    "name",
    "version",
    "color",
    "light",
    "pl",
    "setLightIntAndCount",
    "sendingInterval",
    "sendingCount",
    "signalUpDateScreenDefauleContent",
    "state",
    "defaultContent",
    "TermIp",
    "signalUpDateScreenState",
    "on_clearBtn_clicked",
    "on_OpenBtn_clicked",
    "showMsg",
    "slotUpdateRoadState",
    "iconActivated",
    "QSystemTrayIcon::ActivationReason",
    "reason",
    "soltUpdateTermListUi",
    "slotUpdateControllerUi",
    "slotUpdateFF88",
    "ff88",
    "on_testBtn_clicked",
    "dealPicFiles",
    "path",
    "requestFinished",
    "QNetworkReply*",
    "reply"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  116,    2, 0x06,    1 /* Public */,
       6,    3,  123,    2, 0x06,    5 /* Public */,
      10,    7,  130,    2, 0x06,    9 /* Public */,
      18,    2,  145,    2, 0x06,   17 /* Public */,
      21,    3,  150,    2, 0x06,   20 /* Public */,
      25,    2,  157,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    0,  162,    2, 0x08,   27 /* Private */,
      27,    0,  163,    2, 0x08,   28 /* Private */,
      28,    1,  164,    2, 0x08,   29 /* Private */,
      29,    1,  167,    2, 0x08,   31 /* Private */,
      30,    1,  170,    2, 0x08,   33 /* Private */,
      33,    0,  173,    2, 0x08,   35 /* Private */,
      34,    1,  174,    2, 0x08,   36 /* Private */,
      35,    1,  177,    2, 0x08,   38 /* Private */,
      37,    0,  180,    2, 0x08,   40 /* Private */,
      38,    1,  181,    2, 0x08,   41 /* Private */,
      40,    1,  184,    2, 0x08,   43 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   11,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   22,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   24,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, 0x80000000 | 41,   42,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'write2Kafka'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'write2Screen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'write2Light'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setLightIntAndCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalUpDateScreenDefauleContent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signalUpDateScreenState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_clearBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_OpenBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotUpdateRoadState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'iconActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::ActivationReason, std::false_type>,
        // method 'soltUpdateTermListUi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotUpdateControllerUi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotUpdateFF88'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_testBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dealPicFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'requestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->write2Kafka((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->write2Screen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->write2Light((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7]))); break;
        case 3: _t->setLightIntAndCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->signalUpDateScreenDefauleContent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->signalUpDateScreenState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->on_clearBtn_clicked(); break;
        case 7: _t->on_OpenBtn_clicked(); break;
        case 8: _t->showMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->slotUpdateRoadState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->iconActivated((*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::ActivationReason>>(_a[1]))); break;
        case 11: _t->soltUpdateTermListUi(); break;
        case 12: _t->slotUpdateControllerUi((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->slotUpdateFF88((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->on_testBtn_clicked(); break;
        case 15: _t->dealPicFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->requestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QString , QString , QString );
            if (_t _q_method = &Widget::write2Kafka; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QString , int , QString );
            if (_t _q_method = &Widget::write2Screen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QStringList , QString , QString , int , int , int , QString );
            if (_t _q_method = &Widget::write2Light; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Widget::*)(int , int );
            if (_t _q_method = &Widget::setLightIntAndCount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QString , QString , QString );
            if (_t _q_method = &Widget::signalUpDateScreenDefauleContent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QString , QString );
            if (_t _q_method = &Widget::signalUpDateScreenState; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Widget::write2Kafka(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::write2Screen(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::write2Light(QStringList _t1, QString _t2, QString _t3, int _t4, int _t5, int _t6, QString _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget::setLightIntAndCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Widget::signalUpDateScreenDefauleContent(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Widget::signalUpDateScreenState(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
