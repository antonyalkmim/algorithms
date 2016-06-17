QT += core
QT -= gui

CONFIG += c++11

TARGET = ListaDuplamenteEncadeada
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    node.cpp \
    list.cpp

HEADERS += \
    node.h \
    list.h
