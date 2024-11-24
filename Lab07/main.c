#include <stdio.h>

void printSpaces(int count) {
    if (count <= 0) {
        return;
    }
    printf(" ");
    printSpaces(count - 1);
}


void printSymbols(int count) {
    if (count <= 0) {
        return;
    }
    printf("+");
    printSymbols(count - 1);
}


void drawPyramid(int n, int current) {
    if (current >= n) {
        return;
    }
    printSpaces(n - current - 1);      
    printSymbols(current * 2 + 1);
    printf("\n");
    drawPyramid(n, current + 1);   
}

int determinationForPrime(long n, long divisor) {
    if (n <= 1) return 0;              
    if (n <= 3) return 1;             
    if (divisor * divisor > n) return 1; 
    if (n % divisor == 0) return 0;     
    return determinationForPrime(n, divisor + 1); 
}

int main() {
    // long n = 74789380547;
    long n = 11;
    if (determinationForPrime(n, 2)) { 
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    printf("\n\n\n");
    printf("----------------------------------------------------- \n\n\n");
    drawPyramid(n, 0);

    return 0;
}
