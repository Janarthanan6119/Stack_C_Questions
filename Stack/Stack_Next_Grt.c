#include<stdio.h>
#include<stdlib.h>
void find_Greater(int arr[],int n){
int *res = malloc(n*sizeof(int));
int *stack = malloc(n*sizeof(int));
int top=-1;
for(int i=n-1;i>=0;i--){
    while(top!=-1 && stack[top]<=arr[i]){
        top--;
    }
    if(top==-1)
        res[i]=-1;
    else{
        res[i]=stack[top];
    }
    stack[++top]=arr[i];
}
for(int i=0;i<n;i++)
    printf("%d   %d\n",arr[i],res[i]);
}
int main(){
int arr[] = {4, 5, 2, 25, 7, 8};
int n = sizeof(arr) / sizeof(arr[0]);
find_Greater(arr, n);

}
