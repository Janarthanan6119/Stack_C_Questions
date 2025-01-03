#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the stack structure
struct Stack {
    int top;
    int capacity;
    int *array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
void displayStack(struct Stack* stack) {
    for (int i =0; i<=stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}
void Ins_sort(struct Stack *stk,int element){
if(isEmpty(stk) || element>peek(stk)){
    push(stk,element);
    return;
}
int temp = pop(stk);
Ins_sort(stk,element);
Ins_sort(stk,temp);
}
void sort(struct Stack *stk){
if(!isEmpty(stk)){
    int res = pop(stk);
    sort(stk);
    Ins_sort(stk,res);
}
}
// Main function
int main() {
    struct Stack* stack = createStack(10);

    push(stack, 30);
    push(stack, -5);
    push(stack, 18);
    push(stack, 14);
    push(stack, -3);
    sort(stack);
    displayStack(stack);
}
