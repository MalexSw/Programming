#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to fill an array with random numbers within a given range
void fillArrayWithRandomNumbers(int *array, int size, int minValue, int maxValue) {
    printf("Array:  \n");
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
        printf("%d  ", array[i]);
    }
    printf("\n---------------------------------- \n");
}

// Function to calculate the average of negative numbers in an array
void calcOfNegativeElementsAverage(int *array, int size) {
    printf("\n");
    int sumOfNegNumbers = 0;
    int amOfNegativeNum = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            sumOfNegNumbers += array[i];
            amOfNegativeNum++;
        }
    }

    // Print the array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Calculate and print the average
    if (amOfNegativeNum != 0) {
        float averageValue = (float)sumOfNegNumbers / amOfNegativeNum;
        printf("Average of negative elements in this array is %0.2f \n", averageValue);
    } else {
        printf("In this array, there are no negative values \n");
    }
    printf("\n---------------------------------- \n");
}

// Function to find the second greatest element in an array
void secondGreatest(int *array, int size) {
    printf("\n");
    int theGreatest = -1000; // Placeholder for the greatest value
    int secondGreatest = -1000; // Placeholder for the second greatest value

    if (size < 2) {
        printf("Array contains fewer than two elements.\n");
        return;
    }

    // Find the greatest and second greatest elements
    for (int i = 0; i < size; i++) {
        if (array[i] > theGreatest) {
            secondGreatest = theGreatest;
            theGreatest = array[i];
        } else if (array[i] > secondGreatest && array[i] != theGreatest) {
            secondGreatest = array[i];
        }
    }

    // Print the array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the second greatest element
    printf("Second greatest element is %d \n", secondGreatest);
    printf("\n---------------------------------- \n");
}

// Function to modify an array based on a given operation
void arrayChanging(int *array, int size, char operation, int value) {
    printf("\n");
    printf("Old array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Apply the operation to each element
    switch (operation) {
        case 'a': // Addition
            for (int i = 0; i < size; i++) {
                array[i] += value;
            }
            break;
        case 's': // Subtraction
            for (int i = 0; i < size; i++) {
                array[i] -= value;
            }
            break;
        case 'm': // Multiplication
            for (int i = 0; i < size; i++) {
                array[i] *= value;
            }
            break;
        case 'd': // Division
            if (value == 0) {
                printf("\nImpossible operation (division by zero)\n");
                return;
            }
            for (int i = 0; i < size; i++) {
                array[i] /= value;
            }
            break;
        default:
            printf("\nInvalid operation\n");
            return;
    }

    printf("\nNew array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n---------------------------------- \n");
}

// Function to merge two sorted arrays
void sortedArraysMerging(int *array1, int *array2, int size) {
    printf("\n");
    int mergedArray[2 * size];

    // Sort both arrays
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
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

    // Merge the sorted arrays
    int i = 0, j = 0, k = 0;
    while (i < size && j < size) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while (i < size) mergedArray[k++] = array1[i++];
    while (j < size) mergedArray[k++] = array2[j++];

    printf("\nMerged array:\n");
    for (int i = 0; i < 2 * size; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n---------------------------------- \n");
}

// Function to distribute elements of an array into even and odd arrays
void evenAndOddNumbersDistributing(int *array, int size) {
    printf("\n");
    int evenArray[size], oddArray[size];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++) {
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
    printf("\n---------------------------------- \n");
}

int main() {
    int numberOfElements = 10;
    int array1[numberOfElements], array2[numberOfElements];
    int minValue = -10, maxValue = 15;

    srand(time(0));

    // Fill arrays with random numbers
    fillArrayWithRandomNumbers(array1, numberOfElements, minValue, maxValue);
    fillArrayWithRandomNumbers(array2, numberOfElements, minValue, maxValue);

    calcOfNegativeElementsAverage(array1, numberOfElements);
    secondGreatest(array1, numberOfElements);
    arrayChanging(array1, numberOfElements, 'a', 3);
    sortedArraysMerging(array1, array2, numberOfElements);
    evenAndOddNumbersDistributing(array1, numberOfElements);

}