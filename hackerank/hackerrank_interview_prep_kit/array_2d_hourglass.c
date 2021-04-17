// Problem Taken from:
//      https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hourglassSum(int arr_rows, int arr_columns, int **arr) {
    int row      = 0;
    int max_sum  = INT_MIN;
    int temp_sum = 0;

    for (int row = 0; row < arr_rows - 2; row++) {
        for (int col = 0; col < arr_columns - 2; col++) {
            temp_sum = arr[row][col] + arr[row][col + 1] + arr[row][col + 2] +
                       arr[row + 1][col + 1] +
                       arr[row + 2][col] + arr[row + 2][col + 1] + arr[row + 2][col + 2];
            max_sum = (temp_sum > max_sum) ? temp_sum : max_sum;
        }
    }

    return max_sum;
}

int main() {
    int arr_rows    = 6;
    int arr_columns = 6;

    // REFERENCE https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    int arr0[] = {-9, -9, -9, 1, 1, 1};
    int arr1[] = {0, -9, 0, 4, 3, 2};
    int arr2[] = {-9, -9, -9, 1, 2, 3};
    int arr3[] = {0, 0, 8, 6, 6, 0};
    int arr4[] = {0, 0, 0, -2, 0, 0};
    int arr5[] = {0, 0, 1, 2, 4, 0};

    int **arr = (int **)malloc(arr_rows*sizeof(int *));
    for (int i = 0; i < arr_rows; i++) {
        arr[i] = (int *)malloc(arr_columns*sizeof(int));
    }

    for (int i = 0; i < arr_columns; i++) {
        arr[0][i] = arr0[i];
        arr[1][i] = arr1[i];
        arr[2][i] = arr2[i];
        arr[3][i] = arr3[i];
        arr[4][i] = arr4[i];
        arr[5][i] = arr5[i];
    }

    printf("%d\n", hourglassSum(arr_rows, arr_columns, arr));

    for (int i = 0; i < arr_rows; i++) {
        int *curr = arr[i];
        free(curr);
    }
    free(arr);
}