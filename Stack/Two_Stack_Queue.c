#include <stdio.h>
#include <stdlib.h>
#define Max 100
struct Stack{
int top;
int data[Max];
};
struct Queue{
struct Stack s1;
struct Stack s2;
};
void initStack(struct Stack *stk){
stk->top=-1;
}
void initQueue(struct Queue *queue){
initStack(&queue->s1);
initStack(&queue->s2);
}
int isFull(struct Stack *stk){
return stk->top==Max-1;
}
void push(struct Stack *stk,int data){
    if(isFull(stk)){
        printf("Its Full");
        return;
    }
stk->data[++stk->top]=data;
}
void enqueue(struct Queue *queue,int data){
push(&queue->s1,data);
printf("Enqueue %d\n",data);
}
int isEmpty(struct Stack *stk){
return stk->top==-1;
}
int pop(struct Stack *stk){
if(isEmpty(stk)){
    //printf("Its Empty");
    return -1;
}
return stk->data[stk->top--];
}
void dequeue(struct Queue *queue){
if(isEmpty(&queue->s2)){
    while(!isEmpty(&queue->s1)){
        int store=pop(&queue->s1);
        push(&queue->s2,store);
    }
}
    int store2 = pop(&queue->s2);
    if(store2 !=-1)
        printf("Dequeue %d\n",store2);
    else
        printf("Its Empty");
}
int main(){
struct Queue queue;
initQueue(&queue);
enqueue(&queue,10);
enqueue(&queue,20);
enqueue(&queue,30);
dequeue(&queue);
dequeue(&queue);
dequeue(&queue);
dequeue(&queue);
}
