#include <stdio.h>
#include <math.h>


int main()
{
    //Set 1
    // double a = 2;
    // double b = 5;

    // double c = 4;
    // double d = 6;

    // double θ = M_PI/3;
    // result = 16,797

    // Set 2
    // double a = 3;
    // double b = 4;

    // double c = 2;
    // double d = 6;

    // double θ = M_PI/6;
    // result = 41,42

    // Set 3
    double a = 4;
    double b = 4;

    double c = 1;
    double d = 3;

    double θ = M_PI/2;
    // result = 41,42

    double result = (log(a*a + b*b))/(asin(c/d)) + exp(b*cos(θ));

    printf("Result: %f\n", result);

    return 0;
}

/*

   log: c*c + d*d > 0
   asin: -1<=c<=1    d ≠ 0
   cos: θ ≠ 0
*/