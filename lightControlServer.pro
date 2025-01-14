QT       += core gui network serialport httpserver core5compat

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_PROJECT_DEPTH = 0

RC_ICONS = title.ico
VERSION = 2024.11.07_by:ls

SOURCES += \
    amplifier.cpp \
    amplifierworker.cpp \
    controller.cpp \
    controllermanager.cpp \
    controllerworker.cpp \
    lightcontroll.cpp \
    lightcontrollworker.cpp \
    main.cpp \
    myhttpserver.cpp \
    producer.cpp \
    producerworker.cpp \
    widget.cpp

HEADERS += \
    amplifier.h \
    amplifierworker.h \
    controller.h \
    controllermanager.h \
    controllerworker.h \
    lightCmdList.h \
    lightcontroll.h \
    lightcontrollworker.h \
    myhttpserver.h \
    producer.h \
    producerworker.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/./ -lrdkafka

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32: LIBS += -L$$PWD/./ -lrdkafka++

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

RESOURCES += \
    res.qrc

win32: LIBS += -L$$PWD/./ -lCtsSdk

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

