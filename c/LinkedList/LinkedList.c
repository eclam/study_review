#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* initNode(int val){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void nodeDestructor(Node *node){
    free(node);
}

int getNodeVal(Node *node){
    return node->val;
}

void printLinkedList(Node** head){
    Node* node = *head;

    while(node != NULL){
        printf("%d\n", node->val);
        node = node->next;
    }
}

void push(Node** head, int val){
    Node* node = initNode(val);
    node->next = *head;
    *head = node;
}

int pop(Node** head){
    if (*head == NULL) {
        return -1;
    }
    Node* node = (*head)->next;
    int val = (*head)->val;
    nodeDestructor(*head);
    *head = node;
    return val;
}