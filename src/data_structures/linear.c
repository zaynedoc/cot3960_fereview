#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LQueue;       // Linked List Queue

typedef struct {
    int* array;
    int rear;   // An index value of the last item in the array
    int size;   // Fixed "size" (capacity of queue)
} AQueue;       // Array Queue

typedef struct {
    Node* top;
} Stack;

void enqueueL(LQueue* queue, int data) {

}

int dequeueL(LQueue* queue) {

}

int frontL(LQueue* queue) {

}

int emptyL(LQueue* queue) {

}

LQueue* createLQueue(void) {

}

void destroyLQueue(LQueue* queue) {

}

void printLQueue(LQueue* queue) {

}



AQueue* createAQueue(int size) {
    AQueue* queue = malloc(sizeof(AQueue));
    queue->size = size;
    queue->rear = -1;
    queue->array = malloc(sizeof(int) * size);
    return queue;
}

int fullA(AQueue* queue) {
    return (queue->rear == queue->size - 1);
}

int emptyA(AQueue* queue) {
    return (queue->rear == -1);
}

void enqueueA(AQueue* queue, int data) {
    if (fullA(queue)) {
        printf("Queue is full\n");
        return;
    }
    
    queue->array[++queue->rear] = data;
}

int dequeueA(AQueue* queue) {
    if (emptyA(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue->array[0];

    for (int i = 0; i < queue->rear; i++) {
        queue->array[i] = queue->array[i + 1];
    }

    queue->rear--;
    return data;
}

int frontA(AQueue* queue) {
    if (emptyA(queue)) {
        return INT_MIN;
    }

    return queue->array[0];
}

void destroyAQueue(AQueue* queue) {
    free(queue->array);
    free(queue);
}

void printAQueue(AQueue* queue) {
    if (emptyA(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i <= queue->rear; i++) {
        if (i != queue->rear)
            printf("%d-->", queue->array[i]);
        else
            printf("%d\n", queue->array[i]);
    }
}