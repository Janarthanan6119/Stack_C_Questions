#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure to track parentheses or specific characters
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char ch) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = ch;
    }
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';  // Return null character for underflow
}

// Peek the top of the stack
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return '\0';
}

// Check if the given string is a valid number
int isValidNumber(char* str,struct Stack *stack) {
   // struct Stack stack;
    //initStack(&stack);

    int hasDigit = 0;       // To check if at least one digit exists
    int hasDecimal = 0;     // To ensure at most one decimal point
    int hasExponent = 0;    // To track the presence of 'e' or 'E'

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Check if character is a digit
        if (isdigit(ch)) {
            hasDigit = 1;
            push(stack,ch); // Found at least one digit
        }
        // Check for a decimal point
        else if (ch == '.') {
            if (hasDecimal || hasExponent) {
                return 0;  // Invalid: More than one '.' or '.' after 'e'
            }
            hasDecimal = 1;
            push(stack,ch);
        }
        // Check for an exponent 'e' or 'E'
        else if (ch == 'e' || ch == 'E') {
            if (!hasDigit || hasExponent) {
                return 0;  // Invalid: 'e' without a number or multiple 'e'
            }
            hasExponent = 1;
            hasDigit = 0;  // Reset hasDigit to ensure digits exist after 'e'
            push(stack,ch);
        }
        // Check for a sign (+/-)
        else if (ch == '+' || ch == '-') {
            // Sign is valid only at the start or immediately after 'e'
            if (i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') {
                return 0;
            }
            push(stack,ch);
        }
        // Invalid character
        else {
            return 0;
        }
    }

    return hasDigit;  // Valid if at least one digit exists
}
void display(struct Stack *stk){
for(int i=stk->top;i>=0;i--)
    printf("%c ",stk->arr[i]);

}
// Main function to test the implementation
int main() {
    struct Stack stk;
    initStack(&stk);
    char input[MAX];
    printf("Enter a mathematical number: ");
    scanf("%s", input);

    if (isValidNumber(input,&stk)) {
        display(&stk);
        //printf("The string is a valid number.\n");
    } else {
        printf("The string is NOT a valid number.\n");
    }


    return 0;
}
