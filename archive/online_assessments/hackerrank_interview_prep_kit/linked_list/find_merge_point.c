// Problem Taken from:
//
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* GIVEN CODE */
/**********************************************************************************/
typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}
/**********************************************************************************/

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;

    while (curr1 != curr2) {
        if (curr1->next == NULL) {
            curr1 = head2;
        }
        else{
            curr1 = curr1->next;
        }
        if (curr2->next == NULL) {
            curr2 = head1;
        }
        else {
            curr2 = curr2->next;
        }
    }
    return curr2->data;
}
