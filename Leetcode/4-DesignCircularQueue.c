#include <stdbool.h>
#include <stdlib.h> // For malloc and free

typedef struct {
    int* data;
    int capacity;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->front = 0;
    obj->rear = -1; // Indicates an empty queue
    obj->size = 0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false; // Queue is full
    }
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->data[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false; // Queue is empty
    }
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; // Queue is empty
    }
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; // Queue is empty
    }
    return obj->data[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
*/
