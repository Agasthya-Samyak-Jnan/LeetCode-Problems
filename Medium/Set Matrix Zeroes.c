#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Link to the Problem: https://leetcode.com/problems/set-matrix-zeroes/
// Difficulty : Medium

// Time Complexity: O(n^2)
void setZeroes(int** a, int m, int* n) {
    int row[m],col[*n],i,j;
    for (i=0;i<m;i++) {
        for (j=0;j<(*n);j++) {
            if (a[i][j] == 0) { row[i]=1; col[j]=1; }
        }
    }
    for (i=0;i<m;i++) {
        for (j=0;j<(*n);j++) {
            if (row[i] == 1 || col[j] == 1) { a[i][j] = 0; }
        }
    }
}