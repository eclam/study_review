#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char* bruteConvertToBinary(int num){
    int size = log2(num);
    char* arr = (char *)malloc(sizeof(char)*size);

    int idx = 0;
    int n = num;
    while(n>0){
        if(n%2 == 0) {
            arr[size-idx] = '0';
        }
        else if (n%2 == 1) {
            arr[size-idx] = '1';
        }
        n = n/2;
        idx++;
    }

    arr[size] = '\0';
    return arr;
}

char* bruteConvert2BinaryAndReverse(int num){
    int size = log2(num)+1;
    char* arr = (char *)malloc(sizeof(char)*size);

    int idx = 0;
    int n = num;
    int catchFlag = 0;
    while(n>0){
        if(n%2 == 0) {
            if (catchFlag == 0) {
                n=n/2;
                continue;
            }
            arr[idx] = '0';
        } else if (n%2 == 1) {
            arr[idx] = '1';
            catchFlag = 1;
        }
        n = n/2;
        idx++;
    }

    char* result = (char *)malloc(sizeof(char)*(idx));
    for (int i = 0; i < (idx); i++) {
        result[i] = arr[i];
    }
    free(arr);
    result[idx] = '\0';
    return result;
}

int bruteGetLargestOneBinaryAndConvertBackToDecimal(int num){
    int idx = 0;
    int n = num;

    while(n>0){
        n = n/2;
        idx++;
    }

    int result = pow(2, idx-1);
    return result;
}

void runBruteConversionTest(int num){
    printf("Test - Running Brute Force Conversion Method:\n");

    char* result1 = bruteConvertToBinary(num);
    printf("\tDecimal to binary Conversion :\n\t\t%d = %s\n", num, result1);

    char* result2 = bruteConvert2BinaryAndReverse(num);
    printf("\tDecimal to binary then reverse it and cut out zeros :\n\t\t%d => %s\n", num, result2);

    int result3 = bruteGetLargestOneBinaryAndConvertBackToDecimal(num);
    printf("\tConvert decimal to binary then find left most 1 in binary num then convert back to decimal :\n\t\t%d => %d\n", num, result3);

    free(result1);
    free(result2);
}