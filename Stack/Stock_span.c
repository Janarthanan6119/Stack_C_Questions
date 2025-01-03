#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack {
    int top;
    int data[100];
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    s->data[++s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        return -1; // Should not happen in this problem
    }
    return s->data[s->top--];
}

// Peek the top element of the stack
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        return -1; // Should not happen in this problem
    }
    return s->data[s->top];
}

// Function to calculate stock span
void calculateSpan(int prices[], int n, int span[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while the stack is not empty and the current
        // price is greater than the price at the index stored in the stack
        while (!isEmpty(&s) && prices[peek(&s)] <= prices[i]) {
            pop(&s);
        }

        // If the stack is empty, span is the entire range from 0 to i
        if (isEmpty(&s)) {
            span[i] = i + 1;
        } else {
            // Else, calculate the span as the difference of indices
            span[i] = i - peek(&s);
        }

        // Push the current index onto the stack
        push(&s, i);
    }
}

// Main function to test the stock span calculation
int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateSpan(prices, n, span);

    printf("Day\tPrice\tSpan\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, prices[i], span[i]);
    }

    return 0;
}

