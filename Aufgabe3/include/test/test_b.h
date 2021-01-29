#pragma once

#include <QObject>
#include <QtTest>

///////////////////////////////////////
// b) Test Date::toString() with equivalence partitioning
//////////
// This is a black box test:
// 1. Do a equivalence partitioning for all of the input parameters
//    hint: you have to consider the object state (year, month, day), as well as the given format parameter
//          -> there are four parameters and you'll need to come up with the equivalence classes for each
// 2. Calculate abstract test cases on paper using the familiar table notation presented in the lecture video
// 3. Implement concrete test cases as methods in this class using each of the abstract test cases
//    hint: You'll need to use the ctor or setters to supply the year, month, and day parameters to the function
//          Please create "magic" constants as object attributes to store the employed sample values for each equivalence class.
//          Also document the equivalence class using a comment at the end of the line for each constant.
class TestExerciseB : public QObject {

    Q_OBJECT

public:

    TestExerciseB();

private slots:

    // One example test case - you will have many of these, please name them sensibly
    // Document here what you are testing (abstract), e.g. the used valid/invalid equivalence class samples
    // Document here what values your are using (concrete), e.g. 24.12.2020 in ISO -> 20201224
    void testExample();
};

