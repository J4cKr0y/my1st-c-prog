#include <math.h>
#include "dynamic_calc.h" 

long double dynamicAdd(long double num1, long double num2) {
    return num1 + num2;
}

long double dynamicSubtract(long double num1, long double num2) {
    return num1 - num2;
}

long double dynamicMultiply(long double num1, long double num2) {
    return num1 * num2;
}

long double dynamicDivide(long double numerator, long double denominator) {
    return (denominator != 0) ? numerator / denominator : 0.0;
}

long double dynamicPower(long double base, long double exponent) {
    return powl(base, exponent);
}

long double dynamicSquareRoot(long double value) {
    return (value >= 0) ? sqrtl(value) : -1.0;
}
