QT += core
QT -= gui

CONFIG += c++11

TARGET = single_objects
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp ../shared/player.cpp

HEADERS +=  ../shared/player.hpp

DEFINES += QT_DEPRECATED_WARNINGS #TIGER_SUPER_VERBOSE

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
