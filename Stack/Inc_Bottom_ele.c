#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int increment[MAX]; // Increment array to track pending increments
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
    memset(stack->increment, 0, sizeof(stack->increment));
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
void push(struct Stack *stk,int value){
if(isFull(stk)){
    printf("Its Full");
    return;
}
stk->arr[++stk->top]=value;
}
void increment(struct Stack *stk,int k,int value){
int limit =(k<stk->top+1)?k:stk->top+1;
if(limit>0){
    stk->increment[limit-1]+=value;
}
}
int pop(struct Stack *stk){
if(isEmpty(stk)){
    printf("Its Empty");
    return -1;
}
int topindex = stk->top;
int res = stk->arr[topindex]+stk->increment[topindex];
stk->increment[topindex-1]+=stk->increment[topindex];
stk->top--;
return res;

}
// Display the stack contents for debugging
void display(struct Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i] + stack->increment[i]);
    }
    printf("\n");
}

// Main function to demonstrate the stack
int main() {
    struct Stack stack;
    initStack(&stack);

    // Demonstration
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Initial stack:\n");
    display(&stack);

    increment(&stack, 2, 10); // Increment bottom 2 elements by 10
    printf("After incrementing bottom 2 elements by 10:\n");
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Stack after popping:\n");
    display(&stack);

    increment(&stack, 1, 5); // Increment bottom 1 element by 5
    printf("After incrementing bottom 1 element by 5:\n");
    display(&stack);

    return 0;
}
