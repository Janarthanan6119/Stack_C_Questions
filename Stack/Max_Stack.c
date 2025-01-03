#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Stack structure
struct Stack {
    int* array;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}
struct MaxStack{
struct Stack *mainstack;
struct Stack *aux;
};
struct MaxStack* createMax(int capacity){
struct MaxStack *max= malloc(sizeof(struct MaxStack));
max->mainstack = createStack(capacity);
max->aux = createStack(capacity);
return max;
};
void pushmax(struct MaxStack *max,int value){
if(isFull(max->mainstack)){
    printf("Full");
    return;
    }
push(max->mainstack,value);
if(isEmpty(max->aux)||value>peek(max->aux))
    push(max->aux,value);
}
void popmax(struct MaxStack *max){
if(isEmpty(max->mainstack)){
    printf("Its Empty");
    return;
}
int popvalue=pop(max->mainstack);
if(popvalue==peek(max->aux))
    pop(max->aux);
}
int getmax(struct MaxStack *max){
return peek(max->aux);
 }
int main(){
struct MaxStack *maxstack = createMax(10);
pushmax(maxstack,10);
pushmax(maxstack,20);
pushmax(maxstack,5);
printf("%d\n",getmax(maxstack));
popmax(maxstack);
printf("%d\n",getmax(maxstack));
popmax(maxstack);
printf("%d",getmax(maxstack));
}
