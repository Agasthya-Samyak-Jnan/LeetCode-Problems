#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Difficulty : Medium

/* Solution 1 : Brute Force Apporach - Linear Search O(M*N) (747ms Runtime)*/
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    for(int i=0;i<matrixSize;i++) {
        for(int j=0;j<matrixColSize[i];j++) {
            if (matrix[i][j]==target) { return true; }
        }
    }
    return false;
}

/* Solution 2 : Basic Searching Algorithms - 2D Binary Search O(logM + M*log(N)) (127ms Runtime) */
bool searchMatrix(int** a, int m, int* n, int k) {
     int r_low = 0, r_high = (*n)-1, mid, c_high = m-1, c_low=0;
     printf("%d %d\n", m, *n);
     if ((*n)<2) { goto here; } 
     while (r_low <= r_high) {
        mid = (r_low+r_high)/2;
        if (a[0][mid] == k) { return true; }
        if (r_low == r_high) { break; }
        if (a[0][mid] > k) { r_high = mid; }
        else { r_low = mid + 1; }
     }
     if (m<2) { goto here; }
     here:
     for (int i=0;i<=r_high;i++) {
        c_low = 0; c_high = m-1;
        while (c_low <= c_high) {
        mid = (c_low+c_high)/2;
        if (a[mid][i] == k) { return true; }
        if (c_low == c_high) { break; }
        if (a[mid][i] > k) { c_high = mid; }
        else { c_low = mid + 1; }
        }
     }
     return false;
}

/* Solution 3 : Best Solution (36ms Runtime) */
bool searchMatrix(int** a, int m, int* n, int k) {
     int i=0,j=(*n)-1;
     while (i < m && j > -1) {
         if (a[i][j] == k) { return true; }
         else if (a[i][j] > k) { j--; }
         else { i++; }
     }
    return false;
}

/*
    PYTHON3 VERSION of O(m+n) Solution

    class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        m = len(matrix)
        n = len(matrix[0])
        col = n-1
        row = 0

        while row < m and col >= 0 :

            if matrix[row][col] == target :
                return True

            if matrix[row][col] > target :
                col -= 1

            else :
                row += 1  

             
        return False
        
*/