// Problem Taken from:
//      https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* rotLeft(int a_count, int* a, int d, int* result_count) {
    int temp_arr[a_count];  //temporary array
    for (int i = 0; i < a_count; i++) {
        // printf("%d\n", a[i]);
        temp_arr[i] = a[(i + d) % a_count];
    }
    for (int i = 0; i < a_count; i++) {
        a[i] = temp_arr[i];
        // printf("%d\n", a[i]);
    }

    // *result_count = a_count;

    return a;
}

int main() {
    // printf("%d\n",); // print int
    // printf("%ld\n",); // print long
    int a_count = 5;
    int* a      = (int *)malloc(sizeof(int) * a_count);
    int d       = 4;
    int* result_count;

    for (int i = 1; i <= a_count; i++) {
        a[i-1] = i;
    }

    a = rotLeft(a_count, a, d, result_count);
    for (int i = 0; i < a_count; i++) {
        printf("%d\n", a[i]);
    }
    free(a);
}