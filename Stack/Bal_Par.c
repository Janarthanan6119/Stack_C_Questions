#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
struct Stack {
    int top;
    int capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character if stack is empty
    }
    return stack->array[stack->top--];
}
bool balanced(char *str){
struct Stack *stk = createStack(100);
for(int i=0;str[i]!='\0';i++){
    char ch = str[i];
if(ch=='['||ch=='('||ch=='{')
    push(stk,ch);
else if(ch==')'||ch=='}'||ch==']'){
    if(isEmpty(stk))
        return false;
    else{
        char top = pop(stk);
        if((ch==')' && top!='(')||(ch==']' && top!='[')||(ch=='}' && top!='{'))
            return false;
    }
}
}
return isEmpty(stk);
}
int main() {
    char expression[] = "({[)]}";
    bool res=balanced(expression);
    if(res)
        printf("Balanced");
    else
        printf("Not Balanced");
}
