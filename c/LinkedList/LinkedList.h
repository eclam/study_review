typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* initNode(int val);
void nodeDestructor(Node* node);
void linkedListDestructor(Node** head);
int getNodeVal(Node* node);
int getNodeCount(Node** head);
void printLinkedList(Node** head);
void push(Node** head, int val);
void append(Node** head, int val);
void insert(Node** head, int val, int position);
int pop(Node** head);
int dequeue(Node** head);
int deleteNodeAtPosition(Node** head, int position);
Node* linearSearch(Node** head, int searchVal);
int valueInLinkedList(Node** head, int searchVal);