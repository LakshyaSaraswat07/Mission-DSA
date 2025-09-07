#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
typedef struct StackNode {
    int index;
    struct StackNode* next;
} StackNode;

// Structure for a stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int index) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->index = index;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Or handle error appropriately
    }
    StackNode* temp = stack->top;
    int index = temp->index;
    stack->top = temp->next;
    free(temp);
    return index;
}

// Function to get the top element of the stack without popping
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Or handle error appropriately
    }
    return stack->top->index;
}

int largestRectangleArea(int* heights, int heightsSize) {
    Stack* stack = createStack();
    int maxArea = 0;
    int i = 0;

    while (i < heightsSize) {
        // If current bar is taller than or equal to the bar at stack top, push it
        if (isEmpty(stack) || heights[peek(stack)] <= heights[i]) {
            push(stack, i);
            i++;
        } else {
            // If current bar is smaller, pop from stack and calculate area
            int h = heights[pop(stack)];
            int w = isEmpty(stack) ? i : i - peek(stack) - 1;
            if (h * w > maxArea) {
                maxArea = h * w;
            }
        }
    }

    // Process remaining bars in the stack
    while (!isEmpty(stack)) {
        int h = heights[pop(stack)];
        int w = isEmpty(stack) ? i : i - peek(stack) - 1;
        if (h * w > maxArea) {
            maxArea = h * w;
        }
    }

    // Free the stack
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);

    return maxArea;
}
