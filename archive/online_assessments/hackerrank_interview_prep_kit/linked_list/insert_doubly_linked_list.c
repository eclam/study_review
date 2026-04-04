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
/*****************************************************************************************/
typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
};

DoublyLinkedListNode* create_doubly_linked_list_node(int node_data) {
    DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));

    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}
/*****************************************************************************************/

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node  = (DoublyLinkedListNode*)create_doubly_linked_list_node(data);
    DoublyLinkedListNode* curr_node = (DoublyLinkedListNode*)llist;

    if (curr_node == NULL) {
        return new_node;
    }

    DoublyLinkedListNode* prev_node = curr_node->prev;
    while (curr_node != NULL) {
        if (curr_node->data > data) {
            new_node->next  = curr_node;
            curr_node->prev = new_node;
            if (prev_node == NULL) {
                return new_node;
            }
            new_node->prev  = prev_node;
            prev_node->next = new_node;
            return llist;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    new_node->prev = prev_node;
    prev_node->next = new_node;
    return llist;
}