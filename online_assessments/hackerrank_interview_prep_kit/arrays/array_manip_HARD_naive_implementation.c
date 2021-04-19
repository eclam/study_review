// Problem Taken from:
//      https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long arrayManipulation(int n, int q_rows, int q_columns, int **q) {  // NAIVE IMPLEMENTATION
    // REF: https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm
    long *arr = (long *)calloc(n, sizeof(long));

    int a = 0;
    int b = 0;
    int k = 0;

    for (int row = 0; row < q_rows; row++) {
        a = q[row][0]-1;
        b = q[row][1]-1;
        k = q[row][2];
        // printf("a: %d | b: %d | k: %d\n", a,b,k);
        for (int traversal = a; traversal <= b; traversal++) {
            arr[traversal] += k;
        }
    }

    long max_added_val = 0;
    // printf("array vals : ");
    for (int i = 0; i < n; i++) {
        // printf("%ld ", arr[i]);
        max_added_val = (arr[i] > max_added_val) ? arr[i] : max_added_val;
    }
    // printf("\n");

    free(arr);
    return max_added_val;
}

int main() { // EXAMPLE CASE
    int n         = 10;
    int q_rows    = 3;
    int q_columns = 3;
    int **q       = (int **)malloc(q_rows * sizeof(int *));

    for (int i = 0; i < q_columns; i++) {
        q[i] = (int *)malloc(q_columns * sizeof(int));
    }

    int q0[] = {1, 5, 3};
    int q1[] = {4, 8, 7};
    int q2[] = {6, 9, 1};

    for (int i = 0; i < q_columns; i++) {
        q[0][i] = q0[i];
        q[1][i] = q1[i];
        q[2][i] = q2[i];
    }

    printf("%ld\n", arrayManipulation(n, q_rows, q_columns, q));

    for (int i = 0; i < q_rows; i++) {
        int *curr = q[i];
        free(curr);
    }
    free(q);

    return 0;
}
