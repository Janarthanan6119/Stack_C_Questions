#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024  // Maximum size of the stack

// Define a structure for stack-based memory allocation
struct StackMemory {
    void* memory[MAX_SIZE];  // Array to hold memory blocks
    int top;                  // Top pointer to track allocated memory
};

// Initialize the stack memory system
void initStackMemory(struct StackMemory* stack) {
    stack->top = -1;
}
void deallocateMemory(struct StackMemory* stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow (No memory to free).\n");
        return;
    }

    // Pop the top block and free the memory
    free(stack->memory[stack->top--]);
}

// Print current memory usage (for debugging)
void printMemoryUsage(struct StackMemory* stack) {
    printf("Current memory blocks allocated: %d\n", stack->top + 1);
}
void* allocate_mem(struct StackMemory *stk,int size){
void *block = malloc(size);
stk->memory[++stk->top]=block;
return block;
}

int main(){
struct StackMemory s;
initStackMemory(&s);
int *ptr = allocate_mem(&s,sizeof(int));
char *ptr1 = allocate_mem(&s,20*sizeof(char));
if(ptr!=NULL && ptr1!=NULL){
*ptr = 2;
ptr1=strcpy(ptr1,"Hello");
printf("%d\n",*ptr);
printf("%s\n",ptr1);
}
}
