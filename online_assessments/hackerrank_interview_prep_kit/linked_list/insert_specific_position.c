// Problem Taken from:
//      https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
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
/*-----------------------------------------------------------------------------------------------------*/
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

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node                       = node->next;

        free(temp);
    }
}
/*-----------------------------------------------------------------------------------------------------*/

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)create_singly_linked_list_node(data); // create new node
    SinglyLinkedListNode* curr_node = (SinglyLinkedListNode*)llist;

    if (position == 0) {
        node->next = curr_node;
        return node;
    }
    else{
        int position_counter            = 0;
        SinglyLinkedListNode* head_node = (SinglyLinkedListNode*)llist;
        SinglyLinkedListNode* prev_node = curr_node;

        while (curr_node != NULL) {
            if (position_counter == position) {
                node->next = curr_node;
                prev_node->next = node;
                return head_node;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
            position_counter++;
        }
    }
    return curr_node;
}

int main() {

}