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




LStack *createLStack(void) {
    LStack* stack = (LStack* )malloc(sizeof(LStack));
    stack->top = NULL;                  // Empty stack
    return stack;                       // Notice, unlike array stacks, there is no capacity-limit for amount of nodes
}

int emptyStackL(LStack* stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}


void pushStackL(LStack* stack, int data) {
    Node* node = (Node* )malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;            // New top node points to previous top node
    stack->top = node;                  // New node becomes top node

    /* Visual of push[8] > pushStackL(stack, 8);

        data            >       data
        [3] <- top              [8] <- new top node
         v                       v
        [6]             >       [3] <- previous top node
         v                       v
        [0]                     [6]
         v                       v
        [5]             >       [0]
         v                       v
        NULL                    [5]
                                 v
                        >       NULL
    
    Nodes in a linked list stack point downwards; top node points to 2nd highest in stack, and so on
    In this type of stack, the top node will never be the node->next of another node, unless a new node is being pushed
    The bottom node will point to NULL
    */
}

int popStackL(LStack* stack) {
    if (emptyStackL(stack)) {              // Can't pop a node if there are no nodes
        return INT_MIN;
    }

    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return data;                        // Return value of popped node
}

int peakStackL(LStack* stack) {
    if (!emptyStackL(stack)) {              // Can't return a value of a node if there are no nodes
        return stack->top->data;
    }
    return INT_MIN;
}

void destroyLStack(LStack* stack) {
    Node* current = stack->top;
    Node* next;

    while (current != NULL) {
        next = current->next;               // In a sense, stack->top is another name for a specific node, without calling it "Node" (side note for me)
        free(current);                      // Because we moved the top node down the stack, we can free temp since it's holding onto the old top node
        current = next;
    }
    free(stack);                            // Free the placeholder of the stack once all nodes are freed
}

void printLStack(LStack* stack) {
    Node* temp = stack->top;

    if (!emptyStackL(stack)) {
        while (temp->next != NULL) {            // Slight adjustment, saying "have temp keep going until it sees the next node is NULL (the last node)"
            printf("[%d]\n v\n", temp->data);
            temp = temp->next;
        }

        printf("[%d]\n", temp->data);           // Print the final node, just without the arrow visual from the loop
    } else {
        printf("Stack is empty\n");
    }
}




AStack *createAStack(int size) {
    AStack* stack = (AStack* )malloc(sizeof(AStack));
    stack->size = size;                                         // The fixed, maximum capacity
    stack->top = -1;                                            // Index value for the first node
    stack->array = (int*)malloc(sizeof(int) * stack->size);     // Memory allocated = int * number of items in array
    return stack;
}

int emptyStackA(AStack* stack) {
    if (stack->top == -1) {     // If top index is -1 (DNE)
        return 1;               // Empty; true
    }
    return 0;                   // Not empty; false
}

int fullStackA(AStack* stack) {
    if (stack->top == stack->size - 1) {    // If top index is equal to length of stack
        return 1;                           // Full; true
    }
    return 0;                               // Not full; false
}

void pushStackA(AStack* stack, int data) {
    if (fullStackA(stack)) {
        return;
    }
    stack->array[++stack->top] = data;      // Pre-increment is fine, but make sure top starts at -1
    /* Visual of push[8]

        i   data            >      i   data
        4   [3] <- top             5   [8] <- new top
        3   [6]             >      4   [3] <- previous top
        2   [0]                    3   [6]
        1   [5]             >      2   [0]
        0   [1]                    1   [5]
                            >      0   [1]
    
    stack->top will always be the highest index in the stack
    */
}

int popStackA(AStack* stack) {
    if (emptyStackA(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];      // Index lower from previous top value
}

int peakStackA(AStack* stack) {
    if (emptyStackA(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];        // Return current top value
}

void destroyAStack(AStack* stack) {
    free(stack->array);         // Free the list of values
    free(stack);                // Free the stack itself
}

void printAStack(AStack* stack) {
    if (emptyStackA(stack)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--) {    // Changed from i >= -1 to i >= 0
        printf("[%d]\n", stack->array[i]);
    }
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