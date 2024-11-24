#include "unity.h"
#include <math.h>

void test_func1();
void test_func2();
void test_func3();
void test_func4();

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_func1);
    RUN_TEST(test_func2);
    RUN_TEST(test_func3);
    RUN_TEST(test_func4);
    return UNITY_END();
}