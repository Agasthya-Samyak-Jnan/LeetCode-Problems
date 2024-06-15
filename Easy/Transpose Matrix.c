#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/transpose-matrix/
//Difficulty: Easy

int** transpose(int** a, int m, int* n, int* returnSize, int** returnColumnSizes) {
    
    int** ans = (int**)malloc((*n)*sizeof(int*));
    *(returnColumnSizes) = (int*)malloc((*n)*sizeof(int));
    *returnSize = (*n);

    for (int i=0; i<(*n); i++) {
        ans[i] = (int*)malloc(m*sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    for (int i=0;i<(*n);i++) {
        for (int j=0;j<m;j++) {
             ans[i][j] = a[j][i];
        }
    }
    return ans;
}