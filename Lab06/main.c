#include <stdio.h>
#include "lib.h"

int main(int argc, char const *argv[]) {
int res1 = func1(1,1,1,1,1);
printf("Func 1 result is %d \n", res1);
int res2 = func2(0,1,0,0,1);
printf("Func 2 result is %d \n", res2);
int res3 = func3(1,0,0,0);
printf("Func 3 result is %d \n", res3);
int res4 = func4(1,1,1,1);
printf("Func 4 result is %d \n", res4);
// Example call to a library function , replace with actual function calls.
return 0;
}