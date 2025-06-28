#include <math.h>
#include "fonctions.h"

long double addition(long double a, long double b) {
    return a + b;
}

long double soustraction(long double a, long double b) {
    return a - b;
}

long double multiplication(long double a, long double b) {
    return a * b;
}

long double division(long double a, long double b) {
    return (b != 0) ? a / b : 0.0;
}

long double puissance(long double base, long double exp) {
    return powl(base, exp);
}

long double racineCarree(long double x) {
    return (x >= 0) ? sqrtl(x) : -1.0;
}

