#include "lib.h"
#include <math.h>

// Function to calculate the difference between the diagonals
int diffBetweenDiag(int rows, int column, int matrix[rows][column]) {
    if (rows != column) {
        return -1; // Invalid matrix for diagonal difference
    }

    int mainDiagSum = 0;
    int secondDiagSum = 0;

    for (int r = 0; r < rows; r++) {
        mainDiagSum += matrix[r][r];
        secondDiagSum += matrix[r][column - r - 1];
    }
    return mainDiagSum - secondDiagSum;
}

// Function to calculate the average of each column
void averOfEachColumn(int rows, int column, int matrix[rows][column], int averages[column]) {
    for (int c = 0; c < column; c++) {
        int sumOfColumn = 0;
        for (int r = 0; r < rows; r++) {
            sumOfColumn += matrix[r][c];
        }
        averages[c] = sumOfColumn / rows;
    }
}

// Function to find the first unique element in the matrix
int uniqueElemFinding(int rows, int column, int matrix[rows][column]) {
    int matrixArray[rows * column];
    int frequencyArray[rows * column];

    for (int i = 0; i < rows * column; i++) {
        matrixArray[i] = matrix[i / column][i % column];
        frequencyArray[i] = 1;
    }

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

    for (int i = 0; i < rows * column; i++) {
        if (frequencyArray[i] == 1) {
            return matrixArray[i]; // First unique element
        }
    }
    return -1; // No unique elements
}

// Function to find the median of the matrix
int findingTheMedian(int rows, int column, int matrix[rows][column]) {
    int matrixArray[rows * column];

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

    // Find the median
    if ((rows * column) % 2 == 1) {
        return matrixArray[(rows * column) / 2];
    } else {
        return (matrixArray[(rows * column) / 2 - 1] + matrixArray[(rows * column) / 2]) / 2;
    }
}