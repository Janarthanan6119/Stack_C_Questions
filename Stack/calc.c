#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Operand stack
struct OperandStack {
    int arr[MAX];
    int top;
};

// Operator stack
struct OperatorStack {
    char arr[MAX];
    int top;
};

// Initialize the operand stack
void initOperandStack(struct OperandStack* stack) {
    stack->top = -1;
}

// Initialize the operator stack
void initOperatorStack(struct OperatorStack* stack) {
    stack->top = -1;
}

// Check if operand stack is empty
int isOperandStackEmpty(struct OperandStack* stack) {
    return stack->top == -1;
}

// Check if operator stack is empty
int isOperatorStackEmpty(struct OperatorStack* stack) {
    return stack->top == -1;
}

// Push to operand stack
void pushOperand(struct OperandStack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    }
}

// Push to operator stack
void pushOperator(struct OperatorStack* stack, char op) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = op;
    }
}

// Pop from operand stack
int popOperand(struct OperandStack* stack) {
    if (!isOperandStackEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return 0;
}

// Pop from operator stack
char popOperator(struct OperatorStack* stack) {
    if (!isOperatorStackEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Peek top of operator stack
char peekOperator(struct OperatorStack* stack) {
    if (!isOperatorStackEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return '\0';
}

// Get operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Perform the operation
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            printf("Error: Division by zero!\n");
            exit(1);
    }
    return 0;
}

// Evaluate the expression
int evaluate(char* expression) {
    struct OperandStack operands;
    struct OperatorStack operators;

    initOperandStack(&operands);
    initOperatorStack(&operators);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // Skip spaces
        if (ch == ' ') continue;

        // If digit, extract the full number and push to operand stack
        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;  // Adjust for the loop increment
            pushOperand(&operands, num);
        }
        // If '(', push to operator stack
        else if (ch == '(') {
            pushOperator(&operators, ch);
        }
        // If ')', solve the sub-expression within parentheses
        else if (ch == ')') {
            while (!isOperatorStackEmpty(&operators) && peekOperator(&operators) != '(') {
                int b = popOperand(&operands);
                int a = popOperand(&operands);
                char op = popOperator(&operators);
                pushOperand(&operands, applyOperation(a, b, op));
            }
            popOperator(&operators);  // Pop the '('
        }
        // If operator, apply precedence rules
        else {
            while (!isOperatorStackEmpty(&operators) &&
                   precedence(peekOperator(&operators)) >= precedence(ch)) {
                int b = popOperand(&operands);
                int a = popOperand(&operands);
                char op = popOperator(&operators);
                pushOperand(&operands, applyOperation(a, b, op));
            }
            pushOperator(&operators, ch);
        }
    }

    // Process remaining operators
    while (!isOperatorStackEmpty(&operators)) {
        int b = popOperand(&operands);
        int a = popOperand(&operands);
        char op = popOperator(&operators);
        pushOperand(&operands, applyOperation(a, b, op));
    }

    return popOperand(&operands);
}

// Main function
int main() {
    char expression[MAX];
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';  // Remove trailing newline

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}
