#include <stdio.h> #include <stdlib.h> #include <time.h>

Function to generate a random number between 1 and maxNum int generateRandomNumber(int maxNum) { return rand() % maxNum + 1; }

Function to generate a random operator (+, -, , /) char generateRandomOperator(int allowDivision) { char operators[] = {'+', '-', '', '/'}; int index; if (allowDivision) { index = rand() % 4; } else { index = rand() % 3; } return operators[index]; }

Function to generate a random arithmetic expression void generateArithmeticExpression(int numQuestions, int maxNum, int allowDecimal, int allowParentheses, int allowDivision) { int i; for (i = 0; i < numQuestions; i++) { int num1 = generateRandomNumber(maxNum); int num2 = generateRandomNumber(maxNum); char op = generateRandomOperator(allowDivision);

if (allowDecimal) {
    float result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = (float)num1 / num2;
        break;
    }
    printf("%.2f %c %.2f = %.2f\n", (float)num1, op, (float)num2, result);
}
else {
    int result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }
    printf("%d %c %d = %d\n", num1, op, num2, result);
}
}
}

int main() {
    int numQuestions, maxNum, allowDecimal, allowParentheses, allowDivision;

    // Seed the random number generator
    srand(time(NULL));

    // Get user input
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    printf("Enter the maximum number: ");
    scanf("%d", &maxNum);

    printf("Allow decimals? (1 for yes, 0 for no): ");
    scanf("%d", &allowDecimal);

    printf("Allow parentheses? (1 for yes, 0 for no): ");
    scanf("%d", &allowParentheses);

    printf("Allow division? (1 for yes, 0 for no): ");
    scanf("%d", &allowDivision);

    // Generate arithmetic expressions
    generateArithmeticExpression(numQuestions, maxNum, allowDecimal, allowParentheses, allowDivision);

    return 0;
}

