#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure for parentheses
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push a character onto the stack
void push(struct Stack* stack, char ch) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = ch;
    }
}

// Pop a character from the stack
char pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to generate all combinations of parentheses
void generateParentheses(int n, int open, int close, char* str, int pos, struct Stack* stack) {
    // Base condition: If the current position equals 2*n, a valid combination is found
    if (pos == 2 * n) {
        str[pos] = '\0'; // Null-terminate the string
        printf("%s\n", str);
        return;
    }

    // If we can still add an open parenthesis
    if (open < n) {
        str[pos] = '(';       // Add an open parenthesis
        push(stack, '(');     // Push onto the stack
        generateParentheses(n, open + 1, close, str, pos + 1, stack);
        pop(stack);           // Backtrack
    }

    // If we can add a close parenthesis and it forms a valid sequence
    if (close < open) {
        str[pos] = ')';       // Add a close parenthesis
        push(stack, ')');     // Push onto the stack
        generateParentheses(n, open, close + 1, str, pos + 1, stack);
        pop(stack);           // Backtrack
    }
}

// Driver function
int main() {
    int n;
    printf("Enter the number of pairs of parentheses: ");
    scanf("%d", &n);

    char* str = (char*)malloc(2 * n + 1); // To store the current combination
    struct Stack stack;
    initStack(&stack);

    printf("All possible valid combinations of parentheses are:\n");
    generateParentheses(n, 0, 0, str, 0, &stack);

    free(str); // Free the allocated memory
    return 0;
}
