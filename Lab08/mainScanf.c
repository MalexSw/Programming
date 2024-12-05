#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calcOfNegativeElementsAverage() {
    int numberOfElements;
    int minValue;
    int maxValue;
    
    printf("Enter the number of elements: ");
    scanf(" %d", &numberOfElements);
    printf("Enter the minimum value: ");
    scanf(" %d", &minValue);
    printf("Enter the maximum value: ");
    scanf(" %d", &maxValue);
    
    int array[numberOfElements];
    int sumOfNegNumbers = 0;
    int amOfNegativeNum = 0;

    srand(time(0));

    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    for(int i = 0; i < numberOfElements; i++) {
        if (array[i] < 0) {
            sumOfNegNumbers += array[i];
            amOfNegativeNum++;
        }
    }

    printf("\n Original array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }  
    printf("\n");

    if (amOfNegativeNum != 0) {
        float averageValue = (float)sumOfNegNumbers / amOfNegativeNum;
        return averageValue;
    } else {
       return 1; //average of negative elements cannot be >; 0;
    }
}

int secondGreatest() {
    int numberOfElements;
    int minValue;
    int maxValue;
    
    printf("Enter the number of elements: ");
    scanf(" %d", &numberOfElements);
    printf("Enter the minimum value: ");
    scanf(" %d", &minValue);
    printf("Enter the maximum value: ");
    scanf(" %d", &maxValue);

    int array[numberOfElements];
    int theGreatest = minValue;
    int secondGreatest = minValue;

    srand(time(0));

    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    if (numberOfElements < 2) { 
        return array[0];
    } else {
        theGreatest = array[0];

        for(int i = 0; i < numberOfElements; i++) {
            if (array[i] > theGreatest) {
                secondGreatest = theGreatest;
                theGreatest = array[i];
            } else if ((array[i] < theGreatest) && ((array[i] > secondGreatest))) {
                secondGreatest = array[i];
            }
        }
    }

    printf("\n Array elements:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }  
    return secondGreatest;
}

void arrayChanging() {
    int numberOfElements;
    int minValue;
    int maxValue;
    
    printf(" Enter the number of elements: ");
    scanf(" %d", &numberOfElements);
    printf("Enter the minimum value: ");
    scanf(" %d", &minValue);
    printf("Enter the maximum value: ");
    scanf(" %d", &maxValue);

    int array[numberOfElements];
    char inputOperation;
    int valForModification;

    printf("Enter the value for modification: ");
    scanf(" %d", &valForModification);
    printf("Enter operation (a for addition, s for subtraction, m for multiplication, d for division): ");
    scanf(" %c", &inputOperation);

    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    printf("Old array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    } 

    switch (inputOperation) {
    case 'a':
        for(int i = 0; i < numberOfElements; i++) {
            array[i] += valForModification;
        }
        break;

    case 's':
        for(int i = 0; i < numberOfElements; i++) {
            array[i] -= valForModification;
        }
        break;

    case 'm':
        for(int i = 0; i < numberOfElements; i++) {
            array[i] *= valForModification;
        }
        break;

    case 'd':
        if (valForModification == 0) {
            printf("Impossible operation: Division by zero \n");
            return;
        } else {
            for(int i = 0; i < numberOfElements; i++) {
                array[i] /= valForModification;
            }
        }
        break;

    default:
        printf("Invalid operation\n");
        return;
    }

    printf("New array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    } 
    printf("\n---------------------------------- \n");
}

void sortedArraysmerging() {
    int numberOfElements;
    int minValue;
    int maxValue;
    
    printf("Enter the number of elements: ");
    scanf(" %d", &numberOfElements);
    printf("Enter the minimum value: ");
    scanf(" %d", &minValue);
    printf("Enter the maximum value: ");
    scanf(" %d", &maxValue);

    int array1[numberOfElements];
    int array2[numberOfElements];
    int mergedArray[2 * numberOfElements];

    for(int i = 0; i < numberOfElements; i++) {
        array1[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    for (int i = 0; i < numberOfElements - 1; i++) {
        for (int j = 0; j < numberOfElements - i - 1; j++) {
            if (array1[j] > array1[j + 1]) {
                int change = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = change;
            }
        }
    }

    printf("\n First sorted array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array1[i]);
    } 

    for(int i = 0; i < numberOfElements; i++) {
        array2[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    for (int i = 0; i < numberOfElements - 1; i++) {
        for (int j = 0; j < numberOfElements - i - 1; j++) {
            if (array2[j] > array2[j + 1]) {
                int change = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = change;
            }
        }
    }

    printf("\n Second sorted array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array2[i]);
    } 

    int mergedArrPointer = 0;
    int i = 0;
    int j = 0;

    while (i < numberOfElements && j < numberOfElements) {
        if (array1[i] < array2[j]) {
            mergedArray[mergedArrPointer++] = array1[i++];
        } else {
            mergedArray[mergedArrPointer++] = array2[j++];
        }
    }

    while (i < numberOfElements) {
        mergedArray[mergedArrPointer++] = array1[i++];
    }

    while (j < numberOfElements) {
        mergedArray[mergedArrPointer++] = array2[j++];
    }

    printf("\n Merged sorted array:\n");
    for(int i = 0; i < 2 * numberOfElements; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n---------------------------------- \n");
}

void evenAndOddNumbersDistributing() {
    int numberOfElements, minValue, maxValue;
    
    printf("Enter the number of elements: ");
    scanf(" %d", &numberOfElements);
    printf("Enter the minimum value: ");
    scanf(" %d", &minValue);
    printf("Enter the maximum value: ");
    scanf(" %d", &maxValue);

    int array[numberOfElements];
    int evenArray[numberOfElements]; 
    int oddArray[numberOfElements];
    int evenCount = 0;
    int oddCount = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }


    printf("\n Original array:\n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    } 

    for(int i = 0; i < numberOfElements; i++) {
        if (array[i] % 2 == 0) {
            evenArray[evenCount++] = array[i];
        } else {
            oddArray[oddCount++] = array[i];
        }
    }

    printf("\n Even elements:\n");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenArray[i]);
    }

    printf("\n Odd elements:\n");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddArray[i]);
    }
    printf("\n---------------------------------- \n");
}



int main() {
    float average = calcOfNegativeElementsAverage();
    if (average == 1) {
        printf("There is no negative elements in this array");
    } else {
        printf("Average of negative elements in this array is %0.2f \n", average);
    }
    printf("\n---------------------------------- \n");
    int secondBiggest = secondGreatest();
    printf("\n Second greatest element is %d \n", secondBiggest);
    printf("\n---------------------------------- \n");
    arrayChanging();
    sortedArraysmerging();
    evenAndOddNumbersDistributing();

}