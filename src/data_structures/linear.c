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
    Node *top;
} LStack;       // Linked List Stack

typedef struct {
    int top;
    int size;
    int *array;
} AStack;       // Array Stack




void pushStackL(LStack* stack, int data) {
    return stack;
}

int popStackL(LStack* stack) {
    return -1;
}

int peakStackL(LStack* stack) {
    return -1;
}

int emptyStackL(LStack* stack) {
    return -1;
}

LStack *createLStack(void) {

}

void destroyLStack(LStack* stack) {
    return stack;
}




void pushStackA(AStack* stack, int data) {
    return stack;
}

int popStackA(AStack* stack) {
    return -1;
}

int peakStackA(AStack* stack) {
    return -1;
}

int emptyStackA(AStack* stack) {
    return -1;
}

int fullStackA(AStack* stack) {
    return -1;
}

AStack *createAStack(void) {

}

void destroyAStack(AStack* stack) {
    return stack;
}




int emptyL(LQueue* queue) {
    if (queue->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Circular linked list queues are like an ouroboros
void enqueueL(LQueue* queue, int data) {
    if(emptyL(queue)) {
        queue->head = malloc(sizeof(Node));
        queue->head->data = data;
        queue->head->next = queue->head;        // Queue is empty, therefore 1st node is both head & tail
        queue->tail = queue->head;
    } else {
        Node* temp = malloc(sizeof(Node));
        temp->data = data;
        temp->next = queue->head;               // Enqueued node will become the last in queue, meaning it points to the head (ciruclar queue)
        queue->tail->next = temp;               // Next node of current tail node is given data values
        queue->tail = temp;                     // And then tail is adjusted
    }
}

int dequeueL(LQueue* queue) {
    if (!emptyL(queue)) {
        int data = queue->head->data;       // So you know what value was removed from queue

        if (queue->head != queue->tail) {
            Node* temp = queue->head;           // Save the current front as temp

            queue->head = queue->head->next;    // Move head up one node
            queue->tail->next = queue->head;    // Point tail to new head

            free(temp);                         // Now that the previous head was separated, free the dequeued node
        } else {
            free(queue->head);

            queue->head = NULL;
            queue->tail = NULL;
        }

        return data;
    }

    return -1;
}

int frontL(LQueue* queue) {
    return queue->head->data;
}

LQueue* createLQueue(void) {
    LQueue* queue = malloc(sizeof(LQueue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void destroyLQueue(LQueue* queue) {
    Node* temp = queue->head;

    while (temp != queue->tail) {               // Until temp reaches the end of queue
        queue->head = queue->head->next;        // Move head to next node
        free(temp);                             // temp is the previous head, so remove it
        temp = queue->head;                     // Move temp up to new head
    }

    free(temp);
    free(queue);
}

void printLQueue(LQueue* queue) {
    if (emptyL(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->head;           // Temporary node at start of queue

    while (temp != queue->tail) {       // While temp node is not the tail
        printf("%d -> ", temp->data);
        temp = temp->next;              // Iterate up the queue
    }

    printf("%d\n", temp->data);         // Prints once temp node at the tail
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