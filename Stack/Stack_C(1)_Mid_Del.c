#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Define a structure for the stack
struct Stack {
    struct Node *head;   // Pointer to the top of the stack
    struct Node *middle; // Pointer to the middle of the stack
    int count;           // Count of elements in the stack
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->middle = NULL;
    stack->count = 0;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->head;

    if (stack->head != NULL) {
        stack->head->prev = newNode;
    }

    stack->head = newNode;
    stack->count++;

    // Update the middle pointer
    if (stack->count == 1) {
        stack->middle = newNode;
    } else if (stack->count % 2 == 0) {
        stack->middle = stack->middle->prev;
    }

    printf("Pushed %d\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack underflow\n");
        return -1;
    }

    struct Node* temp = stack->head;
    int data = temp->data;
    stack->head = stack->head->next;

    if (stack->head != NULL) {
        stack->head->prev = NULL;
    }

    free(temp);
    stack->count--;

    // Update the middle pointer
    if (stack->count % 2 == 1 && stack->middle != NULL) {
        stack->middle = stack->middle->next;
    }

    printf("Popped %d\n", data);
    return data;
}

// Function to get the middle element
int getMiddle(struct Stack* stack) {
    if (stack->middle == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->middle->data;
}

// Function to delete the middle element
void deleteMiddle(struct Stack* stack) {
    if (stack->middle == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = stack->middle;
    int data = temp->data;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (stack->count % 2 == 0) {
        stack->middle = stack->middle->next;
    } else {
        stack->middle = stack->middle->prev;
    }

    stack->count--;
    free(temp);

    printf("Deleted middle element: %d\n", data);
}

// Main function to test the stack
int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Middle element: %d\n", getMiddle(stack));
    deleteMiddle(stack);
    printf("Middle element after deletion: %d\n", getMiddle(stack));
    push(stack, 40);
    push(stack, 50);
    printf("Middle element: %d\n", getMiddle(stack));
    pop(stack);
    printf("Middle element after popping: %d\n", getMiddle(stack));

    return 0;
}
