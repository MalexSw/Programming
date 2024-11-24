#include "lib.h"
#include <math.h>

int func1(int x, int y, int z, int w, int v) {
    return (exp(x) + y * y - z) * tan(w)/(sqrt(v) + 1); 
}

int func2(int x, int y, int z, int w, int v) {
    return (tan(x) - y * y) + ((cos(z) * sqrt(w)) / (exp(v) + 1));
}

int func3(int x, int y, int z, int w) {
    return x - sqrt(y) * (exp(z) + sin(w));
}

int func4(int x, int y, int z, int w) {
    return x + exp(y) * sqrt(z) - sin(w); 
}