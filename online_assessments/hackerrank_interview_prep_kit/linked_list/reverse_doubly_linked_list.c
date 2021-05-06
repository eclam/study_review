// Problem Taken from:
//      https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
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

void insert_node_into_doubly_linked_list(DoublyLinkedList** doubly_linked_list, int node_data) {
    DoublyLinkedListNode* node = create_doubly_linked_list_node(node_data);

    if (!(*doubly_linked_list)->head) {
        (*doubly_linked_list)->head = node;
    } else {
        (*doubly_linked_list)->tail->next = node;
        node->prev                        = (*doubly_linked_list)->tail;
    }

    (*doubly_linked_list)->tail = node;
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node                       = node->next;

        free(temp);
    }
}

/*****************************************************************************************/

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist == NULL) {
        return llist;
    }

    DoublyLinkedListNode* prev_node = (DoublyLinkedListNode*)llist;
    DoublyLinkedListNode* temp_node;
    while (prev_node != NULL) {
        temp_node       = prev_node->next;
        prev_node->next = prev_node->prev;
        prev_node->prev = temp_node;

        if (temp_node == NULL) {
            return prev_node;
        }
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    return prev_node;
}

int main() {
    DoublyLinkedList* llist = malloc(sizeof(DoublyLinkedList));
    llist->head             = NULL;
    llist->tail             = NULL;

    for (int i = 0; i < 5; i++) {
        insert_node_into_doubly_linked_list(&llist, i);
    }

    DoublyLinkedListNode* temp_node = llist->head;

    // DEBUG
    printf("BEFORE : ");
    while (temp_node != NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");

    llist->head = reverse(llist->head);
    temp_node   = llist->head;

    // DEBUG
    printf("REVERSE : ");
    while (temp_node != NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");

    free_doubly_linked_list(llist->head);
}