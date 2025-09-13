#include <math.h>
#include "static_calc.h" 

long double staticAdd(long double num1, long double num2) {
    return num1 + num2;
}

long double staticSubtract(long double num1, long double num2) {
    return num1 - num2;
}

long double staticMultiply(long double num1, long double num2) {
    return num1 * num2;
}

long double staticDivide(long double numerator, long double denominator) {
    return (denominator != 0) ? numerator / denominator : 0.0;
}

long double staticPower(long double base, long double exponent) {
    return powl(base, exponent);
}

long double staticSquareRoot(long double value) {
    return (value >= 0) ? sqrtl(value) : -1.0;
}
