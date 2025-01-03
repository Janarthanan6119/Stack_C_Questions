#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000 // Maximum stack size

// Stack structure
struct Stack {
    char data[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void push(struct Stack *stack, char ch) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = ch;
}

// Pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Peek at the top character of the stack
char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}
int reduced(char str1[]){
struct Stack s;
initStack(&s);
for(int i=0;i!='\0';i++){
if(!isEmpty(&s) && peek(&s)==str1[i])
    pop(&s);
else
    push(&s,str1[i]);
}
return isEmpty(&s);
}
int main(){
char str1[]="abba";
printf(reduced(str1)?"True":"False");
}
