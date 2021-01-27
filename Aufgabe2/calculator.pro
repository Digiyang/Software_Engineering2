TEMPLATE = app
CONFIG += c++14
INCLUDEPATH += $$PWD/include
QT += widgets

HEADERS       += include/button.h \
                include/calculation.h \
                include/calculator.h \
                include/engine.h \
                include/operators.h
SOURCES       += src/button.cpp \
                src/calculation.cpp \
                src/calculator.cpp \
                src/main.cpp

DISTFILES +=
