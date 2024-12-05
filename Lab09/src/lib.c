#include "lib.h"
#include <math.h>
#include <limits.h>

// Function to calculate the difference between the diagonals
int diffBetweenDiag(int rows, int column, int matrix[rows][column]) {
    if (rows != column) {
        return INT_MIN; // For invalid matrix. It is a possibility, that diagonal difference will be INT_MIN, but such possibility is very low.
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

// Function to find the median of the matrix. Here it works by transforming matrix into array and then finding the median
int findingTheMedian(int rows, int column, int matrix[rows][column]) {
    int matrixArray[rows * column];

    //Here we transform matrix into array for further work
    for (int i = 0; i < rows * column; i++) {
        matrixArray[i] = matrix[i / column][i % column];
    }

    // Sort the array. I want to sort the array, because it will be much easier to find median.
    for (int i = 0; i < rows * column - 1; i++) {
        for (int j = i + 1; j < rows * column; j++) {
            if (matrixArray[i] > matrixArray[j]) {
                int temp = matrixArray[i];
                matrixArray[i] = matrixArray[j];
                matrixArray[j] = temp;
            }
        }
    }

    // Find the median. It amount of elements is even - we look for the middle index, if not - we take two elements in the middle and then finding the middle.
    if ((rows * column) % 2 == 1) {
        return matrixArray[(rows * column) / 2];
    } else {
        return (matrixArray[(rows * column) / 2 - 1] + matrixArray[(rows * column) / 2]) / 2;
    }
}