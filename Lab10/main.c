#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array
void generateRandomArray(int *array, int numberOfElements, int minValue, int maxValue) {
    printf("Array:  \n");
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

// Function to generate a random matrix with multiple rows and columns
void generateRandomMatrix(int **matrix, int rows, int columns, int minValue, int maxValue) {
    printf("Matrix:  \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = (rand() % (maxValue - minValue + 1)) + minValue;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// Function to calculate the sum difference between the main diagonal and second diagonal of a square matrix
void diffBetweenDiag(int **matrix, int rows, int columns) {
    if (rows != columns) {
        printf("It's impossible to find diagonal values for a non-square matrix.\n");
        return;
    }

    int mainDiagSum = 0;
    int secondDiagSum = 0;

    for (int r = 0; r < rows; r++) {
        mainDiagSum += matrix[r][r]; // Main diagonal
        secondDiagSum += matrix[r][columns - r - 1]; // Secondary diagonal
    }

    printf("Main diagonal sum is %d \n", mainDiagSum);
    printf("Second diagonal sum is %d \n", secondDiagSum);
    printf("Difference between diagonals is %d \n", mainDiagSum - secondDiagSum);
}

// Function to calculate the average of negative elements in an array
void calcOfNegativeElementsAverage(int *array, int numberOfElements) {
    int sumOfNegNumbers = 0, amOfNegativeNum = 0;

    for (int i = 0; i < numberOfElements; i++) {
        if (array[i] < 0) {
            sumOfNegNumbers += array[i];
            amOfNegativeNum++;
        }
    }

    printf("Array: ");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    if (amOfNegativeNum != 0) {
        float averageValue = (float)sumOfNegNumbers / amOfNegativeNum;
        printf("Average of negative elements in this array is %.2f\n", averageValue);
    } else {
        printf("In this array, there are no negative values\n");
    }

    printf("\n");
}

// Function to find the second greatest element in an array
void secondGreatest(int *array, int numberOfElements) {
    if (numberOfElements < 2) {
        printf("Array contains only one element: %d\n", array[0]);
        return;
    }

    int theGreatest = array[0], secondGreatest = array[0];

    for (int i = 0; i < numberOfElements; i++) {
        if (array[i] > theGreatest) {
            secondGreatest = theGreatest;
            theGreatest = array[i];
        } else if (array[i] > secondGreatest && array[i] < theGreatest) {
            secondGreatest = array[i];
        }
    }

    printf("Array: ");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Second greatest element is %d\n", secondGreatest);

    printf("\n");
}

// Function to modify an array based on an operation
void arrayChanging(int *array, int numberOfElements, char inputOperation, int valForModification) {
    printf("Old array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }

    switch (inputOperation) {
        case 'a':  // Addition
            for (int i = 0; i < numberOfElements; i++) {
                array[i] += valForModification;
            }
            break;
        case 's':  // Subtraction
            for (int i = 0; i < numberOfElements; i++) {
                array[i] -= valForModification;
            }
            break;
        case 'm':  // Multiplication
            for (int i = 0; i < numberOfElements; i++) {
                array[i] *= valForModification;
            }
            break;
        case 'd':  // Division
            if (valForModification != 0) {
                for (int i = 0; i < numberOfElements; i++) {
                    array[i] /= valForModification;
                }
            } else {
                printf("\nDivision by zero is not allowed.\n");
                return;
            }
            break;
        default:
            printf("\nInvalid operation.\n");
            return;
    }

    printf("\nNew array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

// Function to find unique elements in a matrix
void uniqueElemFinding(int **matrix, int rows, int columns) {
    int size = rows * columns;
    int *matrixArray = (int *)malloc(size * sizeof(int));
    int *frequencyArray = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        matrixArray[i] = matrix[i / columns][i % columns];
        frequencyArray[i] = 1;
    }

    for (int i = 0; i < size; i++) {
        if (frequencyArray[i] == 1) {
            for (int j = i + 1; j < size; j++) {
                if (matrixArray[i] == matrixArray[j]) {
                    frequencyArray[i]++;
                    frequencyArray[j] = 0;
                }
            }
        }
    }

    printf("\nUnique elements in the matrix are: ");
    for (int i = 0; i < size; i++) {
        if (frequencyArray[i] == 1) {
            printf("%d ", matrixArray[i]);
        }
    }
    printf("\n");

    free(matrixArray);
    free(frequencyArray);
}

// Function to merge two sorted arrays into a single sorted array
void sortedArraysMerging(int *array1, int *array2, int numberOfElements) {
    int *mergedArray = (int *)malloc(2 * numberOfElements * sizeof(int));

    int i = 0, j = 0, k = 0;
    while (i < numberOfElements && j < numberOfElements) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while (i < numberOfElements) {
        mergedArray[k++] = array1[i++];
    }
    while (j < numberOfElements) {
        mergedArray[k++] = array2[j++];
    }

    printf("\nMerged array:\n");
    for (int i = 0; i < 2 * numberOfElements; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);
}

// Function to distribute even and odd numbers into separate arrays
void evenAndOddNumbersDistributing(int *array, int numberOfElements) {
    int *evenArray = (int *)malloc(numberOfElements * sizeof(int));
    int *oddArray = (int *)malloc(numberOfElements * sizeof(int));

    int evenCount = 0, oddCount = 0;

    printf("Original array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
        if (array[i] % 2 == 0) {
            evenArray[evenCount++] = array[i];
        } else {
            oddArray[oddCount++] = array[i];
        }
    }

    printf("\nEven elements:\n");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenArray[i]);
    }

    printf("\nOdd elements:\n");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddArray[i]);
    }
    printf("\n");

    free(evenArray);
    free(oddArray);
}

// Main function
int main() {
    srand(time(NULL));

    int numberOfElements = 10;
    int rows = 5, columns = 5;
    int minValue = -10, maxValue = 15;

    int *array = (int *)malloc(numberOfElements * sizeof(int));
    generateRandomArray(array, numberOfElements, minValue, maxValue);

    // Matrix generation
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    generateRandomMatrix(matrix, rows, columns, minValue, maxValue);

    // Function calls
    calcOfNegativeElementsAverage(array, numberOfElements);
    secondGreatest(array, numberOfElements);
    arrayChanging(array, numberOfElements, 'a', 5); // Example: addition with 5
    sortedArraysMerging(array, array, numberOfElements); // Merging two same arrays
    evenAndOddNumbersDistributing(array, numberOfElements);
    uniqueElemFinding(matrix, rows, columns);
    diffBetweenDiag(matrix, rows, columns);

    // Clean up
    free(array);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
