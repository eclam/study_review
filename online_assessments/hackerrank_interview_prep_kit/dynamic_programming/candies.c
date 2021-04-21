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

long candies(int n, int arr_count, int* arr) {
    long* right_traversal_candy_count = (long*)malloc(sizeof(long) * n);
    long* left_traversal_candy_count  = (long*)malloc(sizeof(long) * n);

    for (int i = 0; i < n; i++) {
        right_traversal_candy_count[i] = 1;
        left_traversal_candy_count[i]  = 1;
    }

    for (int i = 1; i < arr_count; i++) {  // LEFT TO RIGHT
        right_traversal_candy_count[i] = (arr[i] > arr[i - 1]) ? right_traversal_candy_count[i - 1] + 1 : 1;
    }

    for (int i = n - 1; i > 0; i--) {
        left_traversal_candy_count[i - 1] = (arr[i - 1] > arr[i]) ? left_traversal_candy_count[i] + 1 : 1;
    }

    long right_temp = 0;
    long left_temp  = 0;
    long sum        = 0;
    for (int i = 0; i < arr_count; i++) {  // SUM ALL
        right_temp = right_traversal_candy_count[i];
        left_temp  = left_traversal_candy_count[i];
        sum += (right_temp > left_temp) ? right_temp : left_temp;
    }

    free(right_traversal_candy_count);
    free(left_traversal_candy_count);

    return sum;
}

int main() {
    int arr_count = 6;
    int arr[]     = {4, 6, 4, 5, 6, 2};
    printf("%ld\n", candies(arr_count, arr_count, arr));  // ans = 10
    // Pattern : [1, 2, 1, 2, 3, 1]

    arr_count  = 3;
    int arr1[] = {1, 2, 2};
    printf("%ld\n", candies(arr_count, arr_count, arr1));  // ans = 4
    // Pattern : [1, 2, 1]

    arr_count  = 10;
    int arr2[] = {2, 4, 2, 6, 1, 7, 8, 9, 2, 1};
    printf("%ld\n", candies(arr_count, arr_count, arr2));  // ans = 19
    // Pattern : [1, 2, 1, 2, 1, 2, 3, 4, 2, 1]

    arr_count  = 8;
    int arr3[] = {2, 4, 3, 5, 2, 6, 4, 5};
    printf("%ld\n", candies(arr_count, arr_count, arr3));  // ans = 12
    // Pattern : [1, 2, 1, 2, 1, 2, 1, 2]

    return 0;
}