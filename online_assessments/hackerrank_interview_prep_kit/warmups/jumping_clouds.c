// Question taken From:
//      https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=warmup
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jumpingOnClouds(int c_count, int* c) {
    int safezone_cloud_flag = 0;
    int num_jumps = 0;
    int second_jump_flag = 0;

    for (int i = 0; i < c_count; i++){
        if (c[i] == 0){
            if (safezone_cloud_flag == 0) {
                safezone_cloud_flag = 1;
                printf("c[i] = %d\n", i);
                num_jumps++;
                if (i+1 < c_count && c[i+1] == 0 &&
                    i+2 < c_count && c[i+2] == 0) {
                    second_jump_flag = 1;
                }
            }
            else if (second_jump_flag == 1) {
                second_jump_flag = 0;
            }
            else {
                printf("c[i] = %d\n", i);
                num_jumps++;
                if (i+1 < c_count && c[i+1] == 0 &&
                    i+2 < c_count && c[i+2] == 0) {
                    second_jump_flag = 1;
                }
            }
        }
        else {
            safezone_cloud_flag = 0;
        }
    }
    return num_jumps-1;
}

int main(){
    // int c_count = 6;
    // int c[] = {0,0,0,0,1,0};
    // int c_count = 7;
    // int c[] = {0,0,1,0,0,1,0};
    int c_count = 7;
    int c[] = {0,1,0,0,0,1,0};
    printf("%d\n", jumpingOnClouds(c_count, c));
    return 0;
}