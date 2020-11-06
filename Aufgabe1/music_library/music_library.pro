TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += $$PWD/include

SOURCES += \
        src/artist.cpp \
        src/genre.cpp \
        src/group.cpp \
        src/main.cpp \
        src/metadata.cpp \
        src/person.cpp \
        src/song.cpp

HEADERS += \
    include/artist.h \
    include/genre.h \
    include/group.h \
    include/metadata.h \
    include/person.h \
    include/song.h \

