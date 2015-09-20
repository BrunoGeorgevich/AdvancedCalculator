#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T08:25:20
#
#-------------------------------------------------

QT       += core qml quick widgets

TARGET = AdvancedCalculator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    calculator.cpp \
    expression.cpp \
    parentesis.cpp

HEADERS += \
    calculator.h \
    expression.h \
    parentesis.h \
    math_property.h

RESOURCES += \
    qml.qrc
