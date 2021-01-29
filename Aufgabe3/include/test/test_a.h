#pragma once

#include <QObject>
#include <QtTest>
#include "date.h"
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
    Date *dt;

public:

    TestExerciseA();

    // special test values
    //const Date invalidYear = Date(20,12,3002);
    //const Date invliadMonth = Date(11,13,2015);
    //const Date leapInvalidDay = Date(30,02,2020);
    //const Date leapValidDate = Date(29,02,2000);
    //const Date notFebOrLeapValidDate = Date(12,12,2011);
    //const Date FebModulo4ButNotLeapValidDate = Date(28,02,1904);
    //const Date NotFebAndInvDayInvalidDate = Date(31,04,1995);
    //const Date FebModulo4ButNotLeapInvalidDate = Date(29,02,1900);

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init() {};
    void cleanup() {};

    // One example test case - you will have many of these, please name them sensibly
    // Document here what you are testing (abstract)
    // Document here what values your are using (concrete), e.g. 24.12.2020 -> Valid date

    // Have a look to Kontrollflußdiagramm.pdf for more details

    /* Invalid Year -> invalid Date
       20.12.3002 */
    void invalid_year();

    /* Invalid month -> invalid Date
       11.13.2015 */
    void invalid_month();

    /* leap year and February But invalid day -> invalid Date
       30.02.2020 */
    void leap_invalidDay();

    /* February, leap year and (year, month, day) are valid -> valid Date
       29.02.2000 */

    void leap_validDate();

    /* (year, month, day) are valid but not February and year % 4 == 0 -> valid Date
       12.12.2011 */

    void notFebOrLeap_validDate();

    /* (year, month, day) are valid, February and year % 4 = 0 but
       Year != 0 or year % 400 = 0 not valid -> valid Date but not a leap year
       28.02.1904 */
    void FebModulo4ButNotLeap_validDate();

    /* Not February or year % 4 == 0 but invalid day -> invalid Date
       31.04.1995 */
    void NotFebAndInvDay_invalidDate();

    /* Year and month valid, February and year % 4 == 0, but not year % 100 != 0
       Or year % 400 == 0 and invalid day -> invalid Date
       29.02.1900 */
    void FebModulo4ButNotLeap_invalidDate();
};

