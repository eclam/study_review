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

long arrayManipulation(int n, int q_rows, int q_columns, int **q) {  // Optimized
    long *arr = (long *)calloc(n, sizeof(long));

    int a = 0;
    int b = 0;
    int k = 0;
    for (int row = 0; row < q_rows; row++) {
        a = q[row][0] - 1;
        b = q[row][1];
        k = q[row][2];

        arr[a] += k;
        arr[b] -= k;
    }

    long max_added_val = 0;
    long temp          = 0;
    for (int i = 0; i < n; i++) {
        temp += arr[i];
        max_added_val = (temp > max_added_val) ? temp : max_added_val;
    }

    free(arr);
    return max_added_val;
}

int main() {  // EXAMPLE CASE
    int n         = 10;
    int q_rows    = 3;
    int q_columns = 3;
    int **q       = (int **)malloc(q_rows * sizeof(int *));

    for (int i = 0; i < q_columns; i++) {
        q[i] = (int *)malloc(q_columns * sizeof(int));
    }

    int q_0[] = {1, 5, 3};
    int q_1[] = {4, 8, 7};
    int q_2[] = {6, 9, 1};

    for (int i = 0; i < q_columns; i++) {
        q[0][i] = q_0[i];
        q[1][i] = q_1[i];
        q[2][i] = q_2[i];
    }

    printf("%ld\n", arrayManipulation(n, q_rows, q_columns, q));

    for (int i = 0; i < q_rows; i++) {
        int *curr = q[i];
        free(curr);
    }
    free(q);

    // Test Case 1

    n         = 4;
    q_rows    = 3;
    q_columns = 3;
    int **q1       = (int **)malloc(q_rows * sizeof(int *));

    for (int i = 0; i < q_columns; i++) {
        q1[i] = (int *)malloc(q_columns * sizeof(int));
    }

    int q_3[] = {2, 3, 603};
    int q_4[] = {1, 1, 286};
    int q_5[] = {4, 4, 882};

    for (int i = 0; i < q_columns; i++) {
        q1[0][i] = q_3[i];
        q1[1][i] = q_4[i];
        q1[2][i] = q_5[i];
    }

    printf("%ld\n", arrayManipulation(n, q_rows, q_columns, q1));

    for (int i = 0; i < q_rows; i++) {
        int *curr = q1[i];
        free(curr);
    }
    free(q1);

    return 0;
}