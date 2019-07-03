#-------------------------------------------------
#
# Project created by QtCreator 2013-03-02T16:59:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
TEMPLATE = app


SOURCES += main.cpp\
    cardpack.cpp \
    configurationdialog.cpp \
    gamemanager.cpp \
    imagebutton.cpp \
    gamewidget.cpp \
    playerstatuswidget.cpp \
    mainwindow.cpp

HEADERS  += \
    cardpack.h \
    configurationdialog.h \
    gamemanager.h \
    imagebutton.h \
    gamewidget.h \
    playerstatuswidget.h \
    player.h \
    mainwindow.h

FORMS    += \
    configurationdialog.ui \
    playerstatuswidget.ui \
    gamewidget.ui

RESOURCES += \
    packs.qrc
