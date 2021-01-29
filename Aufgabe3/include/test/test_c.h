#pragma once

#include <QObject>
#include <QtTest>

///////////////////////////////////////
// c) Test Date::parse() in a sensible way.
// This is a unit test with no prescribed test case design method. Test in any way you see fit.
// In any case, make sure to mock the ParserFactory / Parser dependency, following a similar approach as demonstrated in the practical testing video.
// hint: Please use "magic" constants for the concrete test values and document each test case using a comment before the method itself
//
class TestExerciseC : public QObject {

    Q_OBJECT

public:

    TestExerciseC();

private slots:

    // One example test case - you will have many of these, please name them sensibly
    // Document here what you are testing (abstract)
    // Document here what values your are using (concrete)
    void testExample();
};


