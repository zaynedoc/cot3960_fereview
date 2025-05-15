// Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack
typedef struct {
    Node* top;
} Stack;

// Queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Linked List operations
Node* insertNode(Node* head, int value);
Node* deleteNode(Node* head, int value);
void printList(Node* head);

// Stack operations
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);

// Queue operations
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);