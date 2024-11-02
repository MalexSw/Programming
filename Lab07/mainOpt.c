#include <stdio.h>

int pyramidDrawing(int n) {
    for (int amOfSymbols = 0; amOfSymbols < n; amOfSymbols++ ) {
   for(int i = 0; i < n - amOfSymbols - 1; i++) {
    printf(" ");
   }
  for(int m = 0; m < amOfSymbols * 2 + 1; m++) {
    printf("+");
  }
    printf("\n");
    }
}

int determinationForPrime(long n) {
    if (n <= 1) { 
        return 0; 
    }          
    if (n <= 3) {
        return 1;
    }

    for (long divisor = 2; divisor < n; divisor++) {            
    if (divisor * divisor > n) {
     return 1; 
     } 
    if (n % divisor == 0) {
        return 0;  
    }   
}
}

int main() {
    // long n = 74789380547;
    long n = 1;
    if (determinationForPrime(n)) { 
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    printf("\n\n\n");
    printf("----------------------------------------------------- \n\n\n");
    pyramidDrawing(n);

    return 0;
}
