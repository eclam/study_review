// Problem Taken from:
//       https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sockMerchant(int n, int ar_count, int* ar) {
    int sock_pairs[100] = {0};
    for (int i = 0; i < ar_count; i++) {
        int sock_found = ar[i]-1;
        sock_pairs[sock_found] += 1;
    }

    int num_sock_pairs = 0;
    for (int i = 0; i < 100; i++) {
        if (sock_pairs[i] != 0) {
            if (sock_pairs[i] % 2 == 0 || sock_pairs[i] > 1) {
                num_sock_pairs += sock_pairs[i]/2;
            }
        }
    }
    return num_sock_pairs;
}

int main() {
    int n = 7;
    int ar_count = n;
    int ar[] = {1,2,1,2,1,3,2};
    printf("%d\n", sockMerchant(n, ar_count, ar));
}