#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
//It takes the responsibility to create a Node
struct Node* createNode(int data){
struct Node *newnode = malloc(sizeof(struct Node));
newnode->data=data;
newnode->next=NULL;
return newnode;
};
void insertAtEnd(struct Node **headad,int data)//(1000,10)
{
struct Node *newnode = createNode(data);//4002
//*(1000) means,value at 1000;
if(*headad==NULL){
    *headad=newnode;
    return;
}
struct Node *temp = *headad;//4000
//To find the Last Node of The List
while(temp->next!=NULL){
    temp=temp->next;//4001
}
temp->next = newnode;

}
void display(struct Node *head){
struct Node *temp = head;

while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}

}
int main(){
struct Node *head=NULL;
insertAtEnd(&head,10);//(1000,10)
insertAtEnd(&head,20);//(1000,20)
insertAtEnd(&head,30);//(1000,30)
//pointer variable store the address of another variable
//pointer variable is also used to store the value called NULL
display(head);
}
