#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void printIntArray(int* arr, int num){
    for (int i = 0; i < ceil(log2(num)); i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int* bitshiftConvertToBinaryReturnNum(int num){
    int size = ceil(log2(num));
    int* arr = (int *)malloc(size*sizeof(int));

    int idx = size-1;
    while(idx>=0){
        arr[idx] = num & 1;
        idx--;
        num >>= 1;
    }
    return arr;
}

char* bitshiftConvertToBinaryReturnString(int num){
    int size = ceil(log2(num));
    char* arr = (char *)malloc(size*sizeof(char));

    int idx = size-1;
    while(idx>=0){
        int bitwiseResult = (num & 1);
        if (bitwiseResult == 1) {
            arr[idx] = '1';
        } else if (bitwiseResult == 0) {
            arr[idx] = '0';
        }
        idx--;
        num >>= 1;
    }
    arr[size] = '\0';
    return arr;
}

int bitshiftConvert2BinaryAndReverseReturnNum(int num){
    int size = ceil(log2(num));
    int* arr = (int *)malloc(size*sizeof(int));
    int idx = size-1;

    int catchFlag = 0;
    int adjustment = 0;
    while(idx>=0){
        int bitwiseResult = (num & 1);
        if (bitwiseResult == 0 && catchFlag == 0) {
            adjustment++;
            num >>= 1;
            continue;
        } else if (bitwiseResult == 1) {
            catchFlag = 1;
        }
        arr[size-idx-1] = bitwiseResult;
        idx--;
        num >>= 1;
    }

    int result = 0;
    for (int i = 0; i < size-adjustment; i++) {
        result = 10*result+arr[i];
    }
    free(arr);

    return result;
}

char* bitshiftConvert2BinaryAndReverseReturnString(int num){
    int size = ceil(log2(num));
    char* arr = (char *)malloc(size*sizeof(char));
    int idx = size-1;

    int catchFlag = 0;
    int adjustment = 0;
    while(idx>=0){
        int bitwiseResult = (num & 1);
        if (bitwiseResult == 0 && catchFlag == 0) {
            adjustment++;
            num >>= 1;
            continue;
        }
        else if (bitwiseResult == 0 && catchFlag != 0) {
            arr[size-idx-1] = '0';
        }
        else if (bitwiseResult == 1) {
            catchFlag = 1;
            arr[size-idx-1] = '1';
        }
        idx--;
        num >>= 1;
    }

    char* result = (char *)malloc(size*sizeof(char));
    for (int i = 0; i < size-adjustment; i++) {
        result[i] = arr[i];
    }
    free(arr);
    result[size] = '\0';
    return result;
}

int bitshiftGetLargestOneBinaryAndConvertBackToDecimal(int num){
    int idx = 0;
    while(num>0){
        idx++;
        num >>= 1;
    }

    int result = pow(2, idx-1);
    return result;
}


void runBitShiftMethodTest(int num){
    printf("Test - Running BitShift Conversion Method:\n");

    int* result1 = bitshiftConvertToBinaryReturnNum(num);
    printf("\tDecimal to binary Conversion (INT Array Version):\n\t\t%d = ", num);
    printIntArray(result1, num);

    char* result1str = bitshiftConvertToBinaryReturnString(num);
    printf("\tDecimal to binary Conversion (String Version) :\n\t\t%d = %s\n", num, result1str);

    int result2 = bitshiftConvert2BinaryAndReverseReturnNum(num);
    printf("\tDecimal to binary then reverse it and cut out zeros (INT Array Version) :\n\t\t%d => %d\n", num, result2);

    char* result2str = bitshiftConvert2BinaryAndReverseReturnString(num);
    printf("\tDecimal to binary then reverse it and cut out zeros (String Version) :\n\t\t%d => %s\n", num, result2str);

    int result3 = bitshiftGetLargestOneBinaryAndConvertBackToDecimal(num);
    printf("\tConvert decimal to binary then find left most 1 in binary num then convert back to decimal :\n\t\t%d => %d\n", num, result3);

    free(result1);
    free(result1str);

    free(result2str);
    printf("\n\n");
}