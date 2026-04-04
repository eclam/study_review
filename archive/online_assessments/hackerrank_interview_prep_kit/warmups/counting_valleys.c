// Problem Taken from:
//       https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countingValleys(int steps, char* path) {
    int steps_position = 0;
    int valley_visited_count = 0;

    for (int step = 0; step < steps; step++) {
        if (path[step] == 'U') {
            steps_position++;
            if (steps_position == 0) {
                valley_visited_count++;
            }
        }
        else if (path[step] == 'D') {
            steps_position--;
        }
    }
    return valley_visited_count;
}

int main() {
    int n        = 7;
    int ar_count = n;
    int ar[]     = {1, 2, 1, 2, 1, 3, 2};
    printf("%d\n", sockMerchant(n, ar_count, ar));
}