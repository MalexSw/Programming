#include <stdio.h>


int main(int argc, char const *argv[])
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;

    float expr_1 = (((a * b - c) / d) + e * f);
    float expr_2 = a - b + c * d;
    float expr_3 = e * f;
    float expr_4 = (c * a - d)/(b + e * f - a);
    float result = expr_1 * expr_2 - expr_3 + expr_4;
    return 0;
}


/* expr_1: d ≠ 0
   expr_2: no restrictions
   expr_3: no restrictions
   expr_4: e * f ≠ a - b; b ≠ 0 and a ≠ 0 and e * f ≠ 0
   
   
   a = 3
   b = -6
   c = 0
   d = 8
   e = 10
   f = 2
   
   (((a * b - c) / d) + e * f) = (((3 * (-6) - 0) / 8) + 10 * 2) = 17,75
   a - b + c * d = 3 + 6 + 0 * 8 = 9
   e * f = 10 * 2 = 20
   (c * a - d)/(b + e * f - a) = (0 * 3 - 8)/(-6 + 10 * 2 - 3) = -8 / 11 = -0,7272
   expr_1 * expr_2 - expr_3 + expr_4 = 17,75 * 9 - 20 - 0,7272 = 139,0228
   */
