QT += core
QT -= gui

CONFIG += c++11

TARGET = FilaEncadeada
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    node.cpp \
    queue.cpp

HEADERS += \
    node.h \
    queue.h
