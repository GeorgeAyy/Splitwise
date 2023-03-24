QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    debt.cpp \
    entername.cpp \
    enterowes.cpp \
    main.cpp \
    mainwindow.cpp \
    outputscreen.cpp \
    splitwise.cpp

HEADERS += \
    debt.h \
    entername.h \
    enterowes.h \
    mainwindow.h \
    outputscreen.h \
    splitwise.h

FORMS += \
    entername.ui \
    enterowes.ui \
    mainwindow.ui \
    outputscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
