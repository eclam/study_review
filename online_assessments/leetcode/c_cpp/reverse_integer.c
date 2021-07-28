// Problem Taken from:
//      https://leetcode.com/problems/reverse-integer/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) {

}

int main() {
    int32_t x = 123;
    printf("%d\n", reverse(x));

    x = -123;
    printf("%d\n", reverse(x));

    x = 0;
    printf("%d\n", reverse(x));

    x = 120;
    printf("%d\n", reverse(x));

    return 0;
}

// https://pubs.opengroup.org/onlinepubs/009696799/basedefs/stdint.h.html
// https://stackoverflow.com/questions/6360049/what-are-arithmetic-underflow-and-overflow-in-c
// https://codingfox.com/3-7-data-types-putting-all-together/