#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


struct Stack {
    char pages[MAX][100];
    int top;
};


void initStack(struct Stack* stack) {
    stack->top = -1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, const char* page) {
    if (stack->top < MAX - 1) {
        strcpy(stack->pages[++stack->top], page);
    } else {
        printf("Stack overflow!\n");
    }
}


char* pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->pages[stack->top--];
    }
    return NULL;
}


char* peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->pages[stack->top];
    }
    return NULL;
}

void simulateBrowserNavigation() {
    struct Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);

    char currentPage[100] = "Home";
    char command[20], newPage[100];

    printf("Starting on page: %s\n", currentPage);

    while (1) {
        printf("\nCurrent page: %s\n", currentPage);
        printf("Enter command (visit <page>, back, forward, exit): ");
        scanf("%s", command);

        if (strcmp(command, "visit") == 0) {
            scanf("%s", newPage);


            push(&backStack, currentPage);


            initStack(&forwardStack);


            strcpy(currentPage, newPage);
            printf("Visited: %s\n", currentPage);
        } else if (strcmp(command, "back") == 0) {
            if (!isEmpty(&backStack)) {

                push(&forwardStack, currentPage);


                strcpy(currentPage, pop(&backStack));
                printf("Moved back to: %s\n", currentPage);
            } else {
                printf("No pages in the back history.\n");
            }
        } else if (strcmp(command, "forward") == 0) {
            if (!isEmpty(&forwardStack)) {

                push(&backStack, currentPage);


                strcpy(currentPage, pop(&forwardStack));
                printf("Moved forward to: %s\n", currentPage);
            } else {
                printf("No pages in the forward history.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting browser simulation.\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
}

int main() {
    simulateBrowserNavigation();
    return 0;
}

