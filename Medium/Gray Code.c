#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/gray-code/
//Difficulty: Medium

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* BEST SOLUTION (SOMEONE ELSE PUT IT UP ON SUBMISSIONS) 81ms Runtime */
int* grayCode(int n, int* returnSize){
    int s = pow(2,n);
    int* res = calloc(s, sizeof(int));
    for(int i=1; i<s; i++) res[i] = i^(i>>1);
    *returnSize = s;
    return res;
}
/*My Solution (Traditional Binary to Gray Converter Circuit Based) 83ms Runtime */
int grayCodeOf (int a) {
    int i = 0;
    int n = (int)log2(a) + 1;
    int temp = 0;
    while (i < n) {
        temp ^= ( (1 & (a>>i)) ^ (1 & (a>>(i+1))) )<<i;
        i++;
    }
    return temp;
}

int* grayCode(int n, int* r) {
    *r = pow(2,n);
    int* ans = (int*)malloc((*r)*sizeof(int));
    for (int i=0;i< (*r); i++) {
        ans[i] = grayCodeOf(i);
    }
    return ans;
}