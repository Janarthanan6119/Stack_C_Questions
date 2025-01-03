#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> // For power calculation

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
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
void push(struct Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    printf("Stack underflow!\n");
    return 0;
}

// Peek the top of the stack
int peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return 0;
}
int eval(char str[]){
struct Stack stk;
initStack(&stk);
int len = strlen(str);
for(int i=len-1;i>=0;i--){
    char ch = str[i];
    if(isdigit(ch))
        push(&stk,ch-'0');
    else{
        int op1=pop(&stk);
        int op2 =pop(&stk);
        int res;
        switch(ch){
    case '+':
        res = op1+op2;
        break;
    case '-':
        res = op1-op2;
        break;
    case '*':
        res = op1*op2;
        break;
    case '/':
        if(op1!=0){
        res = op1/op2;
        }
        break;
    case '^':
        res = pow(op1,op2);
        break;
        }
        push(&stk,res);
    }
}
return pop(&stk);
}
int main(){
char str[] = "*+23^24";
int result = eval(str);
printf("%d",result);
}
