// Problem Taken from:
//      https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_val(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maxSubsetSum(int arr_count, int* arr) {
    int max_sum  = arr[0];
    int temp_sum = arr[0];

    if (arr_count == 1) {
        return max_val(arr[0], 0);
    }

    int temp          = 0;
    int prev_prev_max = max_val(0, arr[0]);
    int prev_max      = max_val(arr[0], arr[1]);

    for (int i = 2; i < arr_count; i++) {
        // printf("i : %d | %d %d\n", i, prev_max, arr[i] + prev_prev_max);
        temp          = prev_max;
        prev_max      = max_val(prev_max, arr[i] + prev_prev_max);
        prev_max      = max_val(prev_max, arr[i]);
        prev_prev_max = temp;
    }

    return max_val(prev_max, prev_prev_max);
}

int main() {
    int arr_count = 5;
    int arr[]     = {-2, 1, 3, -4, 5};
    printf("%d\n", maxSubsetSum(arr_count, arr));  // ans = 8

    arr_count  = 5;
    int arr1[] = {3, 7, 4, 6, 5};
    printf("%d\n", maxSubsetSum(arr_count, arr1));  // ans = 13

    arr_count  = 5;
    int arr2[] = {3, 5, -7, 8, 10};
    printf("%d\n", maxSubsetSum(arr_count, arr2));  // ans = 15

    arr_count  = 5;
    int arr3[] = {2, 1, 5, 8, 4};
    printf("%d\n", maxSubsetSum(arr_count, arr3));  // ans = 11
}