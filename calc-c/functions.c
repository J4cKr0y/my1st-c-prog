#include <math.h>
#include "functions.h" 

long double add(long double num1, long double num2) {
    return num1 + num2;
}

long double subtract(long double num1, long double num2) {
    return num1 - num2;
}

long double multiply(long double num1, long double num2) {
    return num1 * num2;
}

long double divide(long double numerator, long double denominator) {
    return (denominator != 0) ? numerator / denominator : 0.0;
}

long double power(long double base, long double exponent) {
    return powl(base, exponent);
}

long double squareRoot(long double value) {
    return (value >= 0) ? sqrtl(value) : -1.0;
}
