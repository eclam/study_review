#include <stdio.h>
#include <stdlib.h>
#include "bruteConversion.h"
#include "bitshiftConversion.h"

int main(){
    int num;
    printf("Input Number: ");
    scanf("%d", &num);

    // RESULT
    runBruteConversionTest(num);
    printf("\n");
    runBitShiftMethodTest(num);

    return 0;
}