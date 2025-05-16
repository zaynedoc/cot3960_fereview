/*
Runtime Complexities:

Linked List Operations:
- Insert: O(1) best/avg, O(n) worst
- Delete: O(1) best, O(n) avg/worst
- Print: O(n) all cases

Stack Operations (both Array and Linked List):
- Push: O(1) all cases
- Pop: O(1) all cases
- Peak: O(1) all cases

Queue Operations:
Array Implementation:
- Enqueue: O(1) all cases
- Dequeue: O(n) all cases (shift elements)
- Front: O(1) all cases

Linked List Implementation:
- Enqueue: O(1) all cases
- Dequeue: O(1) all cases
- Front: O(1) all cases
*/

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LQueue;       // Linked List Queue

typedef struct {
    int rear;
    int size;
    int* array;
} AQueue;       // Array Queue

typedef struct {
    Node *top;
} LStack;       // Linked List Stack

typedef struct {
    int top;
    int size;
    int *array;
} AStack;       // Array Stack

// Linked List operations
Node* insertNode(Node* head, int value);
Node* deleteNode(Node* head, int value);
void printList(Node* head);

// Linked List Stack operations
void pushStackL(LStack* stack, int data);
int popStackL(LStack* stack);
int peaStackkL(LStack* stack);
int emptyStackL(LStack* stack);
LStack *createLStack();
void destroyLStack(LStack* stack);
void printLStack(LStack* stack);

// Array Stack operations
void pushStackA(AStack* stack, int data);
int popStackA(AStack* stack);
int peakStackA(AStack* stack);
int emptyStackA(AStack* stack);
int fullStackA(AStack* stack);
AStack *createAStack(int size);
void destroyAStack(AStack* stack);
void printAStack(AStack* stack);

// Linked List Queue operations
void enqueueL(LQueue* queue, int data);
int dequeueL(LQueue* queue);
int frontL(LQueue* queue);
int emptyL(LQueue* queue);
LQueue* createLQueue(void);
void destroyLQueue(LQueue* queue);
void printLQueue(LQueue* queue);

// Array Queue operations
void enqueueA(AQueue* queue, int data);
int dequeueA(AQueue* queue);
int frontA(AQueue* queue);
int emptyA(AQueue* queue);
int fullA(AQueue* queue);
AQueue* createAQueue(int size);
void destroyAQueue(AQueue* queue);
void printAQueue(AQueue* queue);