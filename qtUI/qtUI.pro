#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T16:17:32
#
#-------------------------------------------------

QT       += core gui qml quick widgets
#QT       += core gui
QT       += declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MyDockWidgetDemo.cpp

HEADERS  += mainwindow.h \
    MyDockWidgetDemo.h

FORMS    += mainwindow.ui


OTHER_FILES += \
    application.qml \
    main.qml

RESOURCES += \
    res.qrc
