// Question Taken From:
//      https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=warmup
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long repeatedString(char* s, long n) {
    long arr_size = strlen(s);
    long num_of_a = 0;

    for (long i = 0; i < arr_size; i++) {
        if (s[i%arr_size] == 'a') {
            num_of_a++;
        }
    }

    long num_times_s_appears = n/arr_size;
    num_of_a *= num_times_s_appears;

    for (long i = 0; i < (n%arr_size); i++) {
        if (s[i%arr_size] == 'a') {
            num_of_a++;
        }
    }

    return num_of_a;
}

int main(){
    char s[] = "aba";
    long n = 10;
    printf("%ld\n", repeatedString(s, n));
    return 0;
}