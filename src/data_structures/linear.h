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
    Node* top;
} Stack;

// Linked List operations
Node* insertNode(Node* head, int value);
Node* deleteNode(Node* head, int value);
void printList(Node* head);

// Stack operations
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);

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