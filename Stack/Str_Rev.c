#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
    int top;
    int capacity;
    char* array;
};


struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}


void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}
void reverse(char str[]){
int len = strlen(str);
struct Stack *stk=createStack(len);
for(int i=0;i<len;i++)
    push(stk,str[i]);
for(int i=0;i<len;i++)
    str[i]=pop(stk);
}
int main() {
    char str[] = "Hello, World!";
    reverse(str);
printf("%s",str);
}
