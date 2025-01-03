#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a stack node
struct Node {
    int data;          // Stores the modified value
    struct Node* next; // Pointer to the next node
};
struct Stack{
struct Node *top;
int min;
};
struct Stack* createStack(){
struct Stack *newstack =malloc(sizeof(struct Stack));
newstack->top=NULL;
newstack->min=INT_MIN;
return  newstack;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Stack *stk,int value){
if(stk->top==NULL){
    stk->top = createNode(value);
    stk->min=value;
}
else{
    struct Node *newnode;
    if(value<stk->min){
        newnode = createNode(2*value - stk->min);
        stk->min = value;
    }
    else{
        newnode = createNode(value);
    }
    newnode->next = stk->top;
    stk->top = newnode;
}
}
int getmin(struct Stack *stk){
if(stk==NULL){
    printf("It is Empty");
    return;
}
return stk->min;
}
int pop(struct Stack *stk){
struct Node *temp = stk->top;
int pop_value=temp->data;
if(pop_value<stk->min){
    int org_min = stk->min;
    stk->min = 2*stk->min - pop_value;
    pop_value = org_min;
}
stk->top = stk->top->next;
free(temp);
return pop_value;
}
void display(struct Stack *stk){
struct Node *temp = stk->top;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
}
int main(){
struct Stack *stk = createStack();
push(stk,5);
printf("%d\n",getmin(stk));
push(stk,3);
printf("%d\n",getmin(stk));
pop(stk);
printf("%d\n",getmin(stk));
push(stk,8);
display(stk);
}
