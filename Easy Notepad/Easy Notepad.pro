QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# If You can makes yours code fail to compile if it uses deprecated APIs.
# In the order to do so, uncomments the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calenderdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    calenderdialog.h \
    mainwindow.h

FORMS += \
    calenderdialog.ui \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons/Imgs.qrc
