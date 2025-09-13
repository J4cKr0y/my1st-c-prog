#include <stdio.h>
#include <stdlib.h> // for use exit()
#include "static_calc.h"
#include "dynamic_calc.h"


int main() {
	long double firstOperand, secondOperand, staticResult, dynamicResult;
	char operation;

	printf("Possible operations: addition +, subtraction -, multiplication *, division /, power ^, square root r.\n");
	printf("Enter an operation (e.g., 4.5 * 2 or r 9): ");
	scanf(" %c", &operation);

	// Square root only takes one number, handle it separately
	if (operation == 'r') {
		scanf("%Lf", &firstOperand);
	if (firstOperand < 0) {
		printf("Error : The square root of a negative number is not a real number.\n");
		exit(1);
	}
	staticResult = staticSquareRoot(firstOperand);
	dynamicResult = dynamicSquareRoot(firstOperand);
	printf("Static result = %Lf\n", staticResult);
	printf("Dynamic Result = %Lf\n", dynamicResult);
	return 0;
	}

	scanf("%Lf %Lf", &firstOperand, &secondOperand);

	switch (operation) {
		case '+':
			staticResult = staticAdd(firstOperand, secondOperand);
			dynamicResult = dynamicAdd(firstOperand, secondOperand);
			break;
		case '-':
			staticResult = staticSubtract(firstOperand, secondOperand);
			dynamicResult = dynamicSubtract(firstOperand, secondOperand);
			break;
		case '*':
			staticResult = staticMultiply(firstOperand, secondOperand);
			dynamicResult = dynamicMultiply(firstOperand, secondOperand);
			break;
		case '/':
			if (secondOperand == 0) {
				printf("Error: Division by zero.\n");
				return 1;
			}
			staticResult = staticDivide(firstOperand, secondOperand);
			dynamicResult = dynamicDivide(firstOperand, secondOperand);
			break;
		case '^':
			staticResult = staticPower(firstOperand, secondOperand);
			dynamicResult = dynamicPower(firstOperand, secondOperand);
			break;
		default:
			printf("Unknown operator.\n");
			return 1;
			}

	printf("Static result = %Lf\n", staticResult);
	printf("Dynamic result = %Lf\n", dynamicResult);

	return 0;
}
