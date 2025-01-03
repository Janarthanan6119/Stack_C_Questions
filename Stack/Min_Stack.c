#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top];
    }
    return -1;
}

struct MinStack {
    struct Stack* mainStack;
    struct Stack* minStack;
};

struct MinStack* createMinStack(int capacity) {
    struct MinStack* minStack = (struct MinStack*)malloc(sizeof(struct MinStack));
    minStack->mainStack = createStack(capacity);
    minStack->minStack = createStack(capacity);
    return minStack;
}

void pushMinStack(struct MinStack* minStack, int item) {
    push(minStack->mainStack, item);

    if (isEmpty(minStack->minStack) || item <= peek(minStack->minStack)) {
        push(minStack->minStack, item);
    }
}

int popMinStack(struct MinStack* minStack) {
    int poppedValue = pop(minStack->mainStack);
    if (poppedValue == peek(minStack->minStack)) {
        pop(minStack->minStack);
    }
    return poppedValue;
}

int getMin(struct MinStack* minStack) {
    return peek(minStack->minStack);
}

int main() {
    struct MinStack* minStack = createMinStack(10);

    pushMinStack(minStack, 5);
    printf("Current min: %d\n", getMin(minStack));

    pushMinStack(minStack, 3);
    printf("Current min: %d\n", getMin(minStack));

    pushMinStack(minStack, 7);
    printf("Current min: %d\n", getMin(minStack));

    popMinStack(minStack);
    printf("Current min: %d\n", getMin(minStack));

    popMinStack(minStack);
    printf("Current min: %d\n", getMin(minStack));

    return 0;
}

