#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T14:28:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Galgenraten
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    popupdialog.cpp \
    statistiksdialog.cpp

HEADERS  += mainwindow.h \
    popupdialog.h \
    statistiksdialog.h

FORMS    += mainwindow.ui \
    popupdialog.ui \
    statistiksdialog.ui

OTHER_FILES   += notes.txt\
         += woerter.csv
