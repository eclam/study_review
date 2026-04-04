// Problem Taken from:
//      https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumSwaps(int arr_count, int* arr) {
    int min_swaps = 0;

    int temp_swap = 0;
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] != i + 1) {  //swap process
            min_swaps++;
            temp_swap       = arr[arr[i] - 1];
            arr[arr[i] - 1] = arr[i];
            arr[i]          = temp_swap;
            i--;
        }
    }
    return min_swaps;
}

int main() {
    int arr_count = 7;
    int* arr      = (int*)malloc(sizeof(int) * arr_count);

    // for (int i = 0; i < q_count; i++) {
    //     q[i] = i + 1;
    // }
    arr[0] = 7;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;

    printf("%d\n", minimumSwaps(arr_count, arr));  // print int
}