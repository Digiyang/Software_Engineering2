#################################################
# Exercise 3 for the SE2 course at Beuth Uni
#################

CONFIG += console c++14
INCLUDEPATH = $$PWD/include

test {

    message(TEST build)

    QT += testlib
    TARGET = a3-test
    INCLUDEPATH += $$PWD/include/test

    HEADERS = \
        include/parser.h \
        include/date.h \
        include/test/test_a.h \
        include/test/test_b.h \
        include/test/test_c.h

    SOURCES = \
        src/date.cpp \
        src/parser.cpp \        # This implementation needs to be substituted for mock-up
        src/test/test_a.cpp \
        src/test/test_b.cpp \
        src/test/test_c.cpp \
        src/test/test_main.cpp

} else {

    message(NORMAL build)

    TARGET = a3

    HEADERS = \
        include/parser.h \
        include/date.h

    SOURCES = \
        src/date.cpp \
        src/parser.cpp \
        src/main.cpp
}

