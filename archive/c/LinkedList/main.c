#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main() {
    Node* node  = initNode(0);
    Node** head = &node;

    int nodeVal = getNodeVal(*head);
    printf("Test - get node value : %d\n", nodeVal);
    int nodeCount = getNodeCount(head);
    printf("Test - get node count : %d\n", nodeCount);
    printf("Test - INIT print node list:\n");
    printLinkedList(head);

    // TEST PUSH
    push(head, 4);
    push(head, 5);
    push(head, 6);
    nodeCount = getNodeCount(head);
    printf("Test PUSH \n - get node count after push : %d\n", nodeCount);
    printf("Print node list after pushing:\n");
    printLinkedList(head);

    // TEST APPEND
    append(head, 1);
    append(head, 2);
    append(head, 3);
    nodeCount = getNodeCount(head);
    printf("Test APPEND\n - get node count after append : %d\n", nodeCount);
    printf("Print node list after append:\n");
    printLinkedList(head);

    // TEST INSERT
    insert(head, 12, 0);
    insert(head, 15, 3);
    insert(head, 10, 9);
    insert(head, 11, 100);
    nodeCount = getNodeCount(head);
    printf("Test INSERT\n - get node count after insert : %d\n", nodeCount);
    printf("Print node list after insert:\n");
    printLinkedList(head);

    // TEST POP
    int poppedHead = pop(head);
    nodeCount      = getNodeCount(head);
    printf("Test POP\n - get node count after pop : %d\n", nodeCount);
    printf(" - popped value : %d\n", poppedHead);
    printf("Print node list after pop:\n");
    printLinkedList(head);

    // TEST DEQUEUE
    int checkDequeue = dequeue(head);
    nodeCount        = getNodeCount(head);
    printf("Test DEQUEUE\n - get node count after dequeue : %d\n", nodeCount);
    printf("- check dequeue val. Result : %d\n", checkDequeue);
    printf("Print node list after pushing:\n");
    printLinkedList(head);

    // TEST valueInLinkedList - IF IN LINKEDLIST
    int check = valueInLinkedList(head, 0);
    printf("Test IF VALUE IN LINKED LIST\n - check if value is linked list. Result : %d\n", check);

    // TEST valueInLinkedList - IF NOT IN LINKEDLIST
    check = valueInLinkedList(head, 11);
    printf("Test IF VALUE NOT IN LINKED LIST\n - check if value is NOT linked list. Result : %d\n", check);

    // TEST linear search linkedlist - if val is in
    Node* searchedNode = linearSearch(head, 15);
    printf("Test LINEARSEARCH\n - find if node w/ val in linkedlist. Result : %d\n", searchedNode->val);
    // TEST linear search linkedlist - if val is not in
    Node* notSearchedNode = linearSearch(head, 11);
    if (!notSearchedNode) {
        printf("Test LINEARSEARCH\n - find if node NOT w/ val in linkedlist. Result : NOT IN LINKED LIST\n");
    } else {
        printf("Test LINEARSEARCH\n - find if node NOT w/ val in linkedlist. Result :IS IN LINKED LIST?!\n");
    }

    // TEST DELETE
    deleteNodeAtPosition(head, 0);  // delete @ beginning
    nodeCount = getNodeCount(head);
    printf("Test DELETE\n - get node count after delete at position : %d\n", nodeCount);
    printf("Print node list after deletion:\n");
    printLinkedList(head);

    deleteNodeAtPosition(head, 7);  // delete @ end
    nodeCount = getNodeCount(head);
    printf("Test 14\n - get node count after delete at position : %d\n", nodeCount);
    printf("Print node list after deletion:\n");
    printLinkedList(head);

    deleteNodeAtPosition(head, 2);  // delete @ aribtrary location
    nodeCount = getNodeCount(head);
    printf("Test 15\n - get node count after delete at position : %d\n", nodeCount);
    printf("Print node list after deletion:\n");
    printLinkedList(head);

    // TEST - Empty out linkedlist using pop
    for (int i = 0; i < 6; i++) {
        pop(head);
    }
    nodeCount = getNodeCount(head);
    printf("Test EMPTY OUT W/ POP\n - get node count after pop : %d\n", nodeCount);
    printf("Print node list after POP:\n");
    printLinkedList(head);
    printf("NONE\n");

    // TEST - Empty out using dequeue
    for (int i = 0; i < 10; i++) {
        insert(head, i, i);
    }
    for (int i = 0; i < 10; i++) {
        dequeue(head);
    }
    nodeCount = getNodeCount(head);
    printf("Test EMPTY OUT W/ DEQUEUE\n - get node count after pop : %d\n", nodeCount);
    printf("Print node list after pushing:\n");
    printLinkedList(head);
    printf("NONE\n");

    // TEST - Empty out using DELETE AT POSITION
    for (int i = 0; i < 10; i++) {
        insert(head, i, i);
    }
    for (int i = 0; i < 10; i++) {
        deleteNodeAtPosition(head, 0);
    }
    nodeCount = getNodeCount(head);
    printf("Test EMPTY OUT W/ DELETE AT POSITION\n - get node count after pop : %d\n", nodeCount);
    printf("Print node list after DELETE AT POSITION:\n");
    printLinkedList(head);
    printf("NONE\n");

    linkedListDestructor(head);
    return 0;
}
