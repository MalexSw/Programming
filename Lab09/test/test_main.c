#include "unity.h"
#include <math.h>

void test_diffBetweenDiag();
void test_averOfEachColumn();
void test_uniqueElemFinding();
void test_findingTheMedian();

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_diffBetweenDiag);
    RUN_TEST(test_averOfEachColumn);
    RUN_TEST(test_uniqueElemFinding);
    RUN_TEST(test_findingTheMedian);
    return UNITY_END();
}