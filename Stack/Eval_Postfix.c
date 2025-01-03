#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

int evaluate(char str[]){
int len = strlen(str);
struct Stack *stk = createStack(len);
for(int i=0;str[i]!='\0';i++){
    char ch = str[i];
    if(isdigit(ch))
        push(stk,ch-'0');
    else{
        int op2 = pop(stk);
        int op1 = pop(stk);
        switch(ch){
    case '+':
        //int res1 = op1+op2;
        push(stk,op1+op2);
        break;
    case '-':
       // int res2 = op1-op2;
        push(stk,op1-op2);
        break;
    case '*':
        //int res3 = op1*op2;
        push(stk,op1*op2);
        break;
    case '/':
        if(op2==0){
            printf("Div by zero Err");
            exit(0);
        }
        //int res4 = op1/op2;

        push(stk,op1/op2);
        break;
        }
    }
}
return pop(stk);
}

// Driver code
int main() {
    char expression[] = "53+62/*35*+"; // Example postfix expression

    printf("Postfix Expression: %s\n", expression);
    printf("Result: %d\n", evaluate(expression));

    return 0;
}

