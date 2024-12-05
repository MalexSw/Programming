#include <stdio.h>


void diffBetweenDiag(int rows, int column, int matrix[rows][column]) {
    if (rows == column) {
        int mainDiagSum = 0;
        int secondDiagSum = 0;

        for (int r = 0; r < rows; r++) {
            mainDiagSum += matrix[r][r];
            secondDiagSum += matrix[r][column - r - 1];
        }

        printf("Main diagonal sum is %d \n", mainDiagSum);
        printf("Second diagonal sum is %d \n", secondDiagSum);
        printf("Difference between diagonals is %d \n", mainDiagSum - secondDiagSum);
    } else {
        printf("It's impossible to find diagonal value for matrix %d*%d\n", rows, column);
    }
}

void averOfEachColumn(int rows, int column, int matrix[rows][column]) {
    for (int c = 0; c < column; c++) {
        int sumOfColumn = 0;
        for (int r = 0; r < rows; r++) {
            sumOfColumn += matrix[r][c];
        }
        int average = sumOfColumn / rows;
        printf("Column №%d average value is equal to %d \n", c + 1, average);
    }
}

void uniqueElemFinding(int rows, int column, int matrix[rows][column]) {
    int matrixArray[rows * column];
    int frequencyArray[rows * column];

    // Transform matrix into array
    for (int i = 0; i < rows * column; i++) {
        matrixArray[i] = matrix[i / column][i % column];
        frequencyArray[i] = 1;
    }

    // Check if element is unique
    for (int i = 0; i < rows * column; i++) {
        if (frequencyArray[i] == 1) {
            for (int j = i + 1; j < rows * column; j++) {
                if (matrixArray[i] == matrixArray[j]) {
                    frequencyArray[i]++;
                    frequencyArray[j] = 0;
                }
            }
        }
    }

    // Print unique elements
    printf("Unique elements in the matrix are: ");
    for (int i = 0; i < rows * column; i++) {
        if (frequencyArray[i] == 1) {
            printf("%d ", matrixArray[i]);
        }
    }
    printf("\n");
}

void findingTheMedian(int rows, int column, int matrix[rows][column]) {
    int matrixArray[rows * column];

    // Transform matrix into array
    for (int i = 0; i < rows * column; i++) {
        matrixArray[i] = matrix[i / column][i % column];
    }

    // Sort the array
    for (int i = 0; i < rows * column - 1; i++) {
        for (int j = i + 1; j < rows * column; j++) {
            if (matrixArray[i] > matrixArray[j]) {
                int temp = matrixArray[i];
                matrixArray[i] = matrixArray[j];
                matrixArray[j] = temp;
            }
        }
    }

    // Find median
    int medianValue;
    if ((rows * column) % 2 == 1) {
        medianValue = matrixArray[(rows * column) / 2];
    } else {
        medianValue = (matrixArray[(rows * column) / 2 - 1] + matrixArray[(rows * column) / 2]) / 2;
    }

    printf("Median value of this matrix is %d \n", medianValue);
}

void printMatrix(int rows, int column, int matrix[rows][column]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < column; c++) {
            printf("%d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    int rows = 3, column = 3;
    int matrix[3][3] = {
        {23, 45, 12},
        {56, 78, 34},
        {89, 90, 67}
    };

    printMatrix(rows, column, matrix);

    printf("Testing diagonal difference:\n");
    diffBetweenDiag(rows, column, matrix);

    printf("\nTesting column averages:\n");
    averOfEachColumn(rows, column, matrix);

    printf("\nTesting unique elements:\n");
    uniqueElemFinding(rows, column, matrix);

    printf("\nTesting median value:\n");
    findingTheMedian(rows, column, matrix);

    return 0;
}