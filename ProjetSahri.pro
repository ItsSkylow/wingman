#-------------------------------------------------
#
# Project created by QtCreator 2021-02-21T15:41:11
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetSahri
TEMPLATE = app
s
INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"

LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"



SOURCES += main.cpp\
        mainwindow.cpp \
    story.cpp \
    gestionhaptique.cpp

HEADERS  += mainwindow.h \
    story.h \
    gestionhaptique.h

FORMS    += mainwindow.ui \
    story.ui

RESOURCES += \
    res.qrc
