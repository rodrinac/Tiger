QT += core
QT -= gui

CONFIG += c++11 console

CONFIG -= app_bundle

TARGET = Tiger

VERSION = 1.0.1

TEMPLATE = lib # it's marked as a library, but you don't want to build it.

HEADERS += tiger.hpp reader.hpp writer.hpp     

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

