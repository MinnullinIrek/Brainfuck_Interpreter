TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    parser.cpp \
    codegetter.cpp \
    visualizer.cpp \
    commands.cpp \
    memory.cpp

HEADERS += \
    parser.h \
    codegetter.h \
    visualizer.h \
    commands.h \
    memory.h
