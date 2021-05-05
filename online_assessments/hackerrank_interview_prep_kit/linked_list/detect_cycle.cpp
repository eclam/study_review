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

bool has_cycle(Node* head) {
    Node* curr = head;
    for (int i = 0; i < 100; ++i) {
        if (curr == NULL) {
            // cout << "0\n";
            return false;
        }
        curr = curr->next;
    }
    // cout << "1\n";
    return true;
}