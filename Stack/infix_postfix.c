#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, char ch) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = ch;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Get the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top];
}
int precedence(char ch){
switch(ch){
case '+':
case '-':
    return 1;
case '/':
case '*':
    return 2;
case '^':
    return 3;
default:
    return 0;
}
}
void convert(char str[],char postfix[MAX]){
struct Stack stk;
initStack(&stk);
int j=0;
for(int i=0;str[i]!='\0';i++){
    char ch = str[i];
    if(isalnum(ch))
        postfix[j++]=ch;
    else if(ch=='(')
                push(&stk,ch);
    else if(ch==')'){
        while(!isEmpty(&stk)&&peek(&stk)!='('){
              postfix[j++]=pop(&stk);
              }
              pop(&stk);
    }
        else{
        while(!isEmpty(&stk) && precedence(peek(&stk))>=precedence(ch)){
              postfix[j++]=pop(&stk);
        }
        push(&stk,ch);
    }
}
while(!isEmpty(&stk))
    postfix[j++]=pop(&stk);
}
int main(){
char str[]= "(A+B)*C-D/E";
char postfix[MAX];
convert(str,postfix);
printf("%s",postfix);
}
