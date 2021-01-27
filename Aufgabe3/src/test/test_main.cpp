#include <QtTest>
#include "test_a.h"
#include "test_b.h"
#include "test_c.h"

// Run tests
int main(int argc, char** argv) {

    int result = 0;

    TestExerciseA a;
    result += QTest::qExec(&a, argc, argv);

    TestExerciseB b;
    result += QTest::qExec(&b, argc, argv);

    TestExerciseC c;
    result += QTest::qExec(&c, argc, argv);

    return result;
}

