#pragma once

#include <QObject>
#include <QtTest>


///////////////////////////////////////
// a) Test Date::isValid() with 100% path coverage
//////////
// This is a white box test:
// 1. Do a control flow graph of the algorithm on paper first
// 2. Calculate paths for full path coverage as abstract test cases
// 3. implement concrete test cases as methods in this class using each of the abstract test cases
//
class TestExerciseA : public QObject {

    Q_OBJECT

public:
    TestExerciseA();

private slots:

    // Executed by QtTest before and after test suite
    //void initTestCase() {};
    //void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    //void init() {};
    //void cleanup() {};

    // One example test case - you will have many of these, please name them sensibly
    // Document here what you are testing (abstract)
    // Document here what values your are using (concrete), e.g. 24.12.2020 -> Valid date
    void testExample();

};

