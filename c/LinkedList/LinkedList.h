typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node* initNode(int val);
void nodeDestructor(Node *node);
int getNodeVal(Node *node);
void printLinkedList(Node** head);
void push(Node** head, int val);
int pop(Node** head);

