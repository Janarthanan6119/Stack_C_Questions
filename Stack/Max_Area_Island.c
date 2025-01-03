#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Define directions for movement (up, down, left, right)
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Stack structure for DFS
struct Stack {
    int x[MAX * MAX];
    int y[MAX * MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push coordinates onto the stack
void push(struct Stack* stack, int x, int y) {
    stack->x[++stack->top] = x;
    stack->y[stack->top] = y;
}

// Pop coordinates from the stack
void pop(struct Stack* stack, int* x, int* y) {
    *x = stack->x[stack->top];
    *y = stack->y[stack->top--];
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Perform DFS to calculate the area of an island
int dfs(int** grid, int rows, int cols, int startX, int startY) {
    struct Stack stack;
    initStack(&stack);

    // Push the starting cell
    push(&stack, startX, startY);
    grid[startX][startY] = 0; // Mark as visited
    int area = 0;

    while (!isEmpty(&stack)) {
        int x, y;
        pop(&stack, &x, &y);
        area++;

        // Check all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // If the neighbor is within bounds and is land
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                push(&stack, newX, newY);
                grid[newX][newY] = 0; // Mark as visited
            }
        }
    }
    return area;
}

// Find the maximum area of an island
int maxAreaOfIsland(int** grid, int rows, int cols) {
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) { // Found an unvisited island
                int area = dfs(grid, rows, cols, i, j);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}

int main() {
    int rows = 4, cols = 5;
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }

    // Example grid
    int input[4][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };

    // Copy input into dynamic grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = input[i][j];
        }
    }

    int result = maxAreaOfIsland(grid, rows, cols);
    printf("Maximum area of an island: %d\n", result);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

