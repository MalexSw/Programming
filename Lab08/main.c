#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void calcOfNegativeElementsAverage(int numberOfElements) {
    int array[numberOfElements];
    int minValue = -10;
    int maxValue = 15;
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

    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }  
    printf("\n");
    if (amOfNegativeNum != 0) {
        float averageValue = (float)sumOfNegNumbers / amOfNegativeNum;
        printf("Average of negative elements in this array is %0.2f \n", averageValue);
        printf("---------------------------------- \n");
    } else {
       printf("In this array there is no negative values \n"); 
       printf("---------------------------------- \n");
    }

}





void secondGreatest(int numberOfElements) {
    int array[numberOfElements];
    int minValue = -10;
    int maxValue = 15;
    int theGreatest = minValue;
    int secondGreatest = minValue;

    srand(time(0));

    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    if (numberOfElements < 2) { 
        printf("Array comntain only one element %d \n", array[1]);
    } else {
    theGreatest = array[1];

    for(int i = 0; i < numberOfElements; i++) {
        if (array[i] > theGreatest) {
            secondGreatest = theGreatest;
            theGreatest = array[i];
        } else if ((array[i] < theGreatest) && ((array[i] > secondGreatest))) {
            secondGreatest = array[i];
        }
    }
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }  
    printf("\n");
    printf("Second greatest element is %d \n", secondGreatest);
    printf("---------------------------------- \n");
    }

}






void arrayChanging(int numberOfElements) {
    int array[numberOfElements];
    int minValue = -10;
    int maxValue = 15;
    char inputOperation = 'a'; // a fo addition, s for subtraction, m for multiplying and d for dividing
    int valForModification = 3;

     for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    printf("Old array \n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    } 

    switch (inputOperation)
    {
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
        printf("Impossible operation \n");
        printf("---------------------------------- \n");
        return;
    } else {
        for(int i = 0; i < numberOfElements; i++) {
        array[i] /= valForModification;
        }
    }
        break;

    default:
        break;
    }

    printf("\n New array \n");
    for(int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    } 
    printf("\n ---------------------------------- \n");
}




void sortedArraysMerging(int numberOfElements) {
    int array1[numberOfElements];
    int array2[numberOfElements];
    int minValue = -10;
    int maxValue = 15;
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

    printf("\n First array \n");
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

    printf("\n Second array \n");
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

    printf("\n Merged array \n");
    for(int i = 0; i < 2 * numberOfElements; i++) {
        printf("%d ", mergedArray[i]);
    }

}





void evenAndOddNumbersDistributing(int numberOfElements) {
    int array[numberOfElements];
    int evenArray[numberOfElements]; 
    int oddArray[numberOfElements];
    int minValue = -10;
    int maxValue = 15;
    int evenCount = 0;
    int oddCount = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }

    printf("\n Original array \n");
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
    printf("\n");
}

int main() {
    int numberOfElements = 10;
    // calcOfNegativeElementsAverage(numberOfElements);
    // secondGreatest(numberOfElements);
    // arrayChanging(numberOfElements);
    // sortedArraysMerging(numberOfElements);
    evenAndOddNumbersDistributing(numberOfElements);

}