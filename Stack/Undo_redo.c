#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum size for stacks

// Stack structure
struct Stack {
    char arr[MAX][MAX];  // Stack to store states as strings
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

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Push a state onto the stack
void push(struct Stack* stack, char* state) {
    if (!isFull(stack)) {
        strcpy(stack->arr[++stack->top], state);
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop a state from the stack
char* pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return NULL;
}

// Peek at the top state of the stack
char* peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return NULL;
}

// Display the current state
void displayState(char* state) {
    if (state) {
        printf("Current State: %s\n", state);
    } else {
        printf("No current state.\n");
    }
}

// Main undo/redo operations
void undo(struct Stack* undoStack, struct Stack* redoStack, char* currentState) {
    if (!isEmpty(undoStack)) {
        push(redoStack, currentState);          // Push current state to redo stack
        strcpy(currentState, pop(undoStack));  // Undo to the previous state
        printf("Undo performed.\n");
    } else {
        printf("No actions to undo.\n");
    }
}

void redo(struct Stack* undoStack, struct Stack* redoStack, char* currentState) {
    if (!isEmpty(redoStack)) {
        push(undoStack, currentState);          // Push current state to undo stack
        strcpy(currentState, pop(redoStack));  // Redo to the next state
        printf("Redo performed.\n");
    } else {
        printf("No actions to redo.\n");
    }
}

// Main function to demonstrate undo/redo
int main() {
    struct Stack undoStack, redoStack;
    char currentState[MAX] = "Initial State";

    initStack(&undoStack);
    initStack(&redoStack);

    int choice;
    char newState[MAX];

    while (1) {
        printf("\n1. Perform Action\n2. Undo\n3. Redo\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new state: ");
                scanf(" %[^\n]", newState);  // Read new state with spaces

                push(&undoStack, currentState);    // Save the current state to undo stack
                strcpy(currentState, newState);   // Update to the new state
                while (!isEmpty(&redoStack)) {    // Clear the redo stack after a new action
                    pop(&redoStack);
                }
                printf("Action performed.\n");
                break;

            case 2:
                undo(&undoStack, &redoStack, currentState);
                break;

            case 3:
                redo(&undoStack, &redoStack, currentState);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }

        displayState(currentState);  // Display the current state
    }

    return 0;
}
