QT       += core gui

TARGET = LuhnAlgorithm
TEMPLATE = app
DESTDIR = ../bin

SOURCES += main.cpp\
        mainwindow.cpp \
    luhnalgorithm.cpp

HEADERS  += mainwindow.h \
    luhnalgorithm.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
