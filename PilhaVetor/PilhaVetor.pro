QT += core
QT -= gui

CONFIG += c++11

TARGET = PilhaVetor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    stack.cpp

HEADERS += \
    stack.h
