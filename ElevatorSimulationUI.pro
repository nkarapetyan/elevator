#-------------------------------------------------
#
# Project created by QtCreator 2014-05-16T06:36:26
#
#-------------------------------------------------

QT       += core gui
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ElevatorSimulationUICell
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


SOURCES += src/gui/main.cpp\
        src/gui/mainwindow.cpp \
    src/gui/elevatorsimulationuicell.cpp \
    src/core/Door.cpp \
    src/core/Button.cpp \
    src/gui/incabinecontrollerui.cpp \
    src/core/Floor.cpp \
    src/core/Subject.cpp \
    src/core/ElevatorSystem.cpp \
    src/core/Elevator.cpp \
    src/core/Scheduler.cpp \
    src/core/Display.cpp \
    src/core/Sensor.cpp \
    src/core/Engine.cpp \
    src/gui/doorui.cpp \
    src/gui/displayui.cpp \
    src/core/Building.cpp \
    src/core/Observer.cpp \
    src/gui/elevatortimer.cpp

HEADERS  += include/gui/mainwindow.h \
    include/gui/elevatorsimulationuicell.h \
    include/core/Door.h \
    include/core/Button.h \
    include/gui/incabinecontrollerui.h \
    include/core/Floor.h \
    include/core/Display.h \
    include/core/Subject.h \
    include/core/ElevatorSystem.h \
    include/core/Elevator.h \
    include/core/Sensor.h \
    include/core/Scheduler.h \
    include/core/Engine.h \
    include/gui/doorui.h \
    include/gui/displayui.h \
    include/core/Building.h \
    include/core/Observer.h \
    include/gui/elevatortimer.h

FORMS    += src/gui/mainwindow.ui \
    src/gui/elevatorsimulationuicell.ui \
    src/gui/incabinecontrollerui.ui \
    src/gui/doorui.ui \
    src/gui/displayui.ui
