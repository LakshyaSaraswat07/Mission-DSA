#include <stdbool.h>
#include <stdlib.h> // For malloc, free

typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int item) {
    stack->arr[++stack->top] = item;
}

int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    return stack->arr[stack->top];
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    if (pushedSize != poppedSize) {
        return false; // Sizes must be equal
    }

    Stack* stack = createStack(pushedSize);
    int j = 0; // Pointer for popped array

    for (int i = 0; i < pushedSize; i++) {
        push(stack, pushed[i]); // Push current element from pushed array

        // While stack is not empty, and top of stack matches current element in popped array
        while (!isEmpty(stack) && peek(stack) == popped[j]) {
            pop(stack); // Pop from stack
            j++;        // Move to next element in popped array
        }
    }

    bool result = isEmpty(stack); // If stack is empty, all elements were popped correctly
    freeStack(stack);
    return result;
}
