#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T08:34:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentPlanner
TEMPLATE = app


SOURCES += main.cpp\
        homescreen.cpp \
    removeevent.cpp \
    addcourse.cpp \
    assignments.cpp

HEADERS  += homescreen.h \
    removeevent.h \
    addcourse.h \
    assignments.h

FORMS    += homescreen.ui \
    removeevent.ui \
    addcourse.ui \
    assignments.ui
