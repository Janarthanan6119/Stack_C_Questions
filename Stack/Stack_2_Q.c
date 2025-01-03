#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define a structure for the queue
struct Queue {
    int front, rear, size;
    int data[MAX];
};

// Initialize a queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->size == 0;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->size == MAX;
}

// Enqueue an element into the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

// Dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    if (q->size == 0) {
        q->front = q->rear = -1;
    }
    return value;
}

// Peek the front element of the queue
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

// Define a structure for the stack
struct Stack {
    struct Queue q1;
    struct Queue q2;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    initQueue(&stack->q1);
    initQueue(&stack->q2);
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    enqueue(&stack->q2, value);

    // Transfer all elements from q1 to q2
    while (!isEmpty(&stack->q1)) {
        int temp = dequeue(&stack->q1);
        enqueue(&stack->q2, temp);
    }

    // Swap q1 and q2
    struct Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    printf("Pushed %d\n", value);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(&stack->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&stack->q1);
}

// Peek the top element of the stack
int top(struct Stack* stack) {
    return front(&stack->q1);
}

// Check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return isEmpty(&stack->q1);
}

// Main function to test the stack
int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Top element after pop: %d\n", top(&stack));

    push(&stack, 40);
    printf("Top element: %d\n", top(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Stack empty: %s\n", isStackEmpty(&stack) ? "Yes" : "No");

    return 0;
}

