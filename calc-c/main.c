#include <stdio.h>
#include "functions.h" 

int main() {
    long double firstOperand, secondOperand, result;
    char operation;

    printf("Possible operations: addition +, subtraction -, multiplication *, division /, power ^, square root r.\n");
    printf("Enter an operation (e.g., 4.5 * 2 or r 9): ");
    scanf(" %c", &operation);

    // Square root only takes one number, handle it separately
    if (operation == 'r') {
        scanf("%Lf", &firstOperand);
        result = squareRoot(firstOperand);
        printf("Result = %Lf\n", result);
        return 0;
    }

    scanf("%Lf %Lf", &firstOperand, &secondOperand);

    switch (operation) {
        case '+': result = add(firstOperand, secondOperand); break;
        case '-': result = subtract(firstOperand, secondOperand); break;
        case '*': result = multiply(firstOperand, secondOperand); break;
        case '/': result = divide(firstOperand, secondOperand); break;
        case '^': result = power(firstOperand, secondOperand); break;
        default:
            printf("Unknown operator.\n");
            return 1;
    }

    printf("Result = %Lf\n", result);
    return 0;
}
