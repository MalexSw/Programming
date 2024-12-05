#include <stdio.h>
#include "lib.h"

int main() {

    int rows = 3, column = 3;
    int matrix[3][3] = {
        {23, 45, 12},
        {56, 78, 34},
        {89, 90, 67}
    };
    int averages[column];

    printf("Testing diagonal difference:\n");
    diffBetweenDiag(rows, column, matrix);

    printf("\nTesting column averages:\n");
    averOfEachColumn(rows, column, matrix, averages);

    printf("\nTesting unique elements:\n");
    uniqueElemFinding(rows, column, matrix);

    printf("\nTesting median value:\n");
    findingTheMedian(rows, column, matrix);

    return 0;
}