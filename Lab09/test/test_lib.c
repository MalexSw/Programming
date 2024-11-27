#include "unity.h"
#include "lib.h"

void setUp() {}
void tearDown() {}

void test_diffBetweenDiag() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    TEST_ASSERT_EQUAL_INT(0, diffBetweenDiag(3, 3, matrix));

    int matrix2[2][2] = {{10, 2}, {3, 5}};
    TEST_ASSERT_EQUAL_INT(10, diffBetweenDiag(2, 2, matrix2));

    int matrix3[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    TEST_ASSERT_EQUAL_INT(-1, diffBetweenDiag(3, 2, matrix3));
}


void test_averOfEachColumn() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int averages1[3] = {0};
    averOfEachColumn(3, 3, matrix1, averages1);
    int expected1[3] = {4, 5, 6};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected1, averages1, 3);

    int matrix2[2][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80}
    };
    int averages2[4] = {0};
    averOfEachColumn(2, 4, matrix2, averages2);
    int expected2[4] = {30, 40, 50, 60};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected2, averages2, 4);

    int matrix3[4][2] = {
        {1, 10},
        {2, 20},
        {3, 30},
        {4, 40}
    };
    int averages3[2] = {0};
    averOfEachColumn(4, 2, matrix3, averages3);
    int expected3[2] = {2, 25};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected3, averages3, 2);

    int matrix4[1][1] = {
        {5}
    };
    int averages4[1] = {0};
    averOfEachColumn(1, 1, matrix4, averages4);
    int expected4[1] = {5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected4, averages4, 1);

    int matrix5[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    int averages5[2] = {0};
    averOfEachColumn(3, 2, matrix5, averages5);
    int expected5[2] = {3, 4};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected5, averages5, 2);
}

void test_uniqueElemFinding() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {1, 8, 9}};
    TEST_ASSERT_EQUAL_INT(2, uniqueElemFinding(3, 3, matrix));

    int matrix2[2][2] = {{1, 1}, {1, 1}};
    TEST_ASSERT_EQUAL_INT(-1, uniqueElemFinding(2, 2, matrix2));
}

void test_findingTheMedian() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    TEST_ASSERT_EQUAL_INT(5, findingTheMedian(3, 3, matrix));

    int matrix2[2][2] = {{1, 3}, {5, 7}};
    TEST_ASSERT_EQUAL_INT(4, findingTheMedian(2, 2, matrix2));
}