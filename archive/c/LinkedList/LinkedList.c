#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

Node* initNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode) {
        return NULL;
    }

    newNode->val  = val;
    newNode->next = NULL;
    return newNode;
}

void nodeDestructor(Node* node) {
    if (!node) {
        return;
    }

    free(node);
}

void linkedListDestructor(Node** head) {
    if (!head) {
        return;
    }

    Node* node = *head;
    while (node != NULL) {
        Node* temp = node->next;
        nodeDestructor(node);
        node = temp;
    }
    *head = NULL;
}

int getNodeCount(Node** head) {
    if (!head) {
        return -1;
    }
    Node* node  = *head;
    int counter = 0;
    while (node != NULL) {
        counter++;
        node = node->next;
    }
    return counter;
}

int getNodeVal(Node* node) {
    if (!node) {
        return -1;
    }
    return node->val;
}

void printLinkedList(Node** head) {
    Node* node = *head;
    while (node != NULL) {
        printf("%d\n", node->val);
        node = node->next;
    }
}

void push(Node** head, int val) {
    Node* node = initNode(val);
    if (!node) {
        return;
    }
    node->next = *head;
    *head      = node;
}

void append(Node** head, int val) {
    Node* node = initNode(val);
    if (!node) {
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

int pop(Node** head) {
    if (*head == NULL) {
        return -1;
    }
    Node* node = (*head)->next;
    int val    = (*head)->val;
    nodeDestructor(*head);
    *head = node;
    return val;
}

int dequeue(Node** head) {
    if (head == NULL || (*head) == NULL) {
        return -1;
    }

    Node* node = *head;
    Node* prev = node;

    if (node->next == NULL) {
        *head = NULL;
    }

    while (node->next != NULL) {
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    int val    = node->val;
    nodeDestructor(node);

    return val;
}

int deleteNodeAtPosition(Node** head, int position) {
    if (!head) {
        return -1;
    }
    Node* node  = *head;
    Node* prev  = node;
    int counter = 0;
    if (position == 0) {
        int returnVal = pop(head);
        if (returnVal != -1) {
            return returnVal;
        }
        else {
            return -1;
        }
    }

    while (node != NULL) {
        if (counter == position) {  // Insert Node
            prev->next = node->next;
            int val    = node->val;
            nodeDestructor(node);
            return val;
        }
        prev = node;
        node = node->next;
        counter++;
    }
    return -1;
}

void insert(Node** head, int val, int position) {
    if (!head) {
        return;
    }

    if (position == 0) {
        push(head, val);
        return;
    }

    Node* node  = *head;
    Node* prev  = node;
    int counter = 0;
    while (prev != NULL) {
        if (counter == position || (!node && counter < position)) {  // Insert Node
            Node* newNode = initNode(val);
            prev->next    = newNode;
            newNode->next = node;
            return;
        }

        prev = node;
        node = node->next;
        counter++;
    }
}

Node* linearSearch(Node** head, int searchVal) {
    if (!head) {
        return NULL;
    }
    Node* node = *head;
    while (node != NULL) {
        if (node->val == searchVal) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int valueInLinkedList(Node** head, int searchVal) {
    if (!head) {
        return 0;
    }
    Node* node = *head;
    while (node != NULL) {
        if (node->val == searchVal) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}