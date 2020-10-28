TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += $$PWD/include

SOURCES += \
    src/genre.cpp \
    src/metadata.cpp \
    src/song.cpp \
    src/main.cpp

HEADERS += \
    include/genre.h \
    include/song.h \
    include/metadata.h
