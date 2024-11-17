#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void diffBetweenDiag(int rows, int column) {
    if (rows == column) {

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < column; c++) {
            matrix[r][c] = (rand() % 100) + 1;
            printf("%d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    int mainDiagSum = 0;
    int secondDiagSum = 0;

    for (int r = 0; r < rows; r++) {
        mainDiagSum += matrix[r][r];             
        secondDiagSum += matrix[r][column - r - 1]; 
    }


    printf("Main diagonal sum is %d \n", mainDiagSum);
        printf("Second diagonal sum is %d \n", secondDiagSum);
        printf("Difference between diagonals is %d \n", mainDiagSum - secondDiagSum);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    } else {
        printf("It's impossible to find diagonal value for matrix %d*%d", rows, column);
    }

    printf("\n");
}



void uniqueElemFinding(int rows, int columns) {

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            matrix[r][c] = (rand() % 100) + 1; 
            printf("%d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");

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

    printf("\n Unique elements in the matrix are: ");
    for (int i = 0; i < size; i++) {
        if (frequencyArray[i] == 1) {
            printf("%d ", matrixArray[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixArray);
    free(frequencyArray);

    printf("\n");
}



void calcOfNegativeElementsAverage(int numberOfElements) {
    int minValue = -10;
    int maxValue = 15;
    int sumOfNegNumbers = 0;
    int amOfNegativeNum = 0;

    int *array = (int *)malloc(numberOfElements * sizeof(int));

    srand(time(0));
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

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

    free(array);

    printf("\n");
}

void secondGreatest(int numberOfElements) {
    int minValue = -10;
    int maxValue = 15;
    int theGreatest = minValue;
    int secondGreatest = minValue;

    int *array = (int *)malloc(numberOfElements * sizeof(int));

    srand(time(0));
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    if (numberOfElements < 2) {
        printf("Array contains only one element: %d\n", array[0]);
        free(array);
        return;
    }

    theGreatest = array[0];
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

    free(array);

    printf("\n");
}

void arrayChanging(int numberOfElements) {
    int minValue = -10;
    int maxValue = 15;
    char inputOperation = 'a'; // a for addition, s for subtraction, m for multiplying, and d for dividing
    int valForModification = 3;

    int *array = (int *)malloc(numberOfElements * sizeof(int));

    srand(time(0));
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    printf("Old array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }

    switch (inputOperation) {
    case 'a':
        for (int i = 0; i < numberOfElements; i++) {
            array[i] += valForModification;
        }
        break;
    case 's':
        for (int i = 0; i < numberOfElements; i++) {
            array[i] -= valForModification;
        }
        break;
    case 'm':
        for (int i = 0; i < numberOfElements; i++) {
            array[i] *= valForModification;
        }
        break;
    case 'd':
        if (valForModification != 0) {
            for (int i = 0; i < numberOfElements; i++) {
                array[i] /= valForModification;
            }
        } else {
            printf("\nDivision by zero is not allowed.\n");
            free(array);
            return;
        }
        break;
    default:
        break;
    }

    printf("\nNew array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    printf("\n");
}

void sortedArraysMerging(int numberOfElements) {
    int minValue = -10;
    int maxValue = 15;

    int *array1 = (int *)malloc(numberOfElements * sizeof(int));
    int *array2 = (int *)malloc(numberOfElements * sizeof(int));
    int *mergedArray = (int *)malloc(2 * numberOfElements * sizeof(int));

    srand(time(0));
    for (int i = 0; i < numberOfElements; i++) {
        array1[i] = (rand() % (maxValue - minValue + 1)) + minValue;
        array2[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    for (int i = 0; i < numberOfElements - 1; i++) {
        for (int j = 0; j < numberOfElements - i - 1; j++) {
            if (array1[j] > array1[j + 1]) {
                int temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
            if (array2[j] > array2[j + 1]) {
                int temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    }

    printf("First array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array1[i]);
    }
    printf("\nSecond array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array2[i]);
    }

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

    free(array1);
    free(array2);
    free(mergedArray);

    printf("\n");
}


void evenAndOddNumbersDistributing(int numberOfElements) {
    int minValue = -10;
    int maxValue = 15;

    int *array = (int *)malloc(numberOfElements * sizeof(int));
    int *evenArray = (int *)malloc(numberOfElements * sizeof(int));
    int *oddArray = (int *)malloc(numberOfElements * sizeof(int));

    int evenCount = 0, oddCount = 0;

    srand(time(0));
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

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

    free(array);
    free(evenArray);
    free(oddArray);

    printf("\n");
}


int main() {
    srand(time(NULL));
     int numberOfElements = 10;
    calcOfNegativeElementsAverage(numberOfElements);
    secondGreatest(numberOfElements);
    arrayChanging(numberOfElements);
    sortedArraysMerging(numberOfElements);
    evenAndOddNumbersDistributing(numberOfElements);
    diffBetweenDiag(10, 10);
    uniqueElemFinding(10, 10);
}
