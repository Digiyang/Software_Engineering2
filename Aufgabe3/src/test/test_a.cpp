#include "test_a.h"

TestExerciseA::TestExerciseA() : QObject(nullptr) {}

void TestExerciseA::invalid_year() {
    const Date invalidYear = Date(3002,12,20);
    QVERIFY(invalidYear.year());
    //QVERIFY(true);
}

void TestExerciseA::invalid_month() {
    const Date invalidMonth = Date(2015,13,11);
    QVERIFY(invalidMonth.month());
    //QVERIFY(true);
}

void TestExerciseA::leap_invalidDay(){
    const Date leapInvalidDay = Date(2020,02,30);
    QVERIFY(leapInvalidDay.year());
    QVERIFY(leapInvalidDay.month());
    QVERIFY(leapInvalidDay.day());
    //QVERIFY(true);
}

void TestExerciseA::leap_validDate(){
    const Date leapValidDate = Date(2000,02,29);
    QVERIFY(leapValidDate.isValid());
}

void TestExerciseA::notFebOrLeap_validDate(){
    const Date notFebOrLeapValidDate = Date(2011,12,12);
    QVERIFY(notFebOrLeapValidDate.isValid());
}

void TestExerciseA::FebModulo4ButNotLeap_validDate(){
    const Date FebModulo4ButNotLeapValidDate = Date(1904,02,28);
    QVERIFY(FebModulo4ButNotLeapValidDate.isValid() == true);
}

void TestExerciseA::NotFebAndInvDay_invalidDate(){
    const Date NotFebAndInvDayInvalidDate = Date(1995,04,31);
    QVERIFY(NotFebAndInvDayInvalidDate.isValid() == false);
}

void TestExerciseA::FebModulo4ButNotLeap_invalidDate(){
    const Date FebModulo4ButNotLeapInvalidDate = Date(1900,2,29);
    QVERIFY(FebModulo4ButNotLeapInvalidDate.isValid() == false);
}
