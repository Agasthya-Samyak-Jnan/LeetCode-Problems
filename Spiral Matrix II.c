#include<stdio.h>
#include<stdlib.h>

// Link to the Problem: https://leetcode.com/problems/spiral-matrix-ii/
// Difficulty: Medium

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Time Complexity: O(n^2)
int** generateMatrix(int n, int* r, int** c) {
    // Setup Size Returning Values
    *r = n;  // Return Number of Rows.
    *c = (int*)calloc(n,sizeof(int));
    
    // Setup Variables
    int j=1, i=0, left=0, right=n-1, top=0, bottom=n-1;
    
    //  Allocate 2D Matrix
    int** a = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++) { 
        *(a+i) = (int*)calloc(n,sizeof(int)); 
        *(*c+i) = n;  // Return Number of Columns in each row.
    }
    
    // Spiral Traversal
    while (left <= right || top <= bottom) 
    {     
        // Move Left
        i = left;
        while (i <= right) { a[top][i] = j; i++; j++; }
        top++;
        
        // Move Down
        i = top;
        while (i <= bottom) { a[i][right] = j; i++; j++; }
        right--;
        
        // Move Right 
        i = right;
        while (i >= left) { a[bottom][i] = j; i--; j++; }
        bottom--;
        
        // Move Up 
        i = bottom;
        while (i >= top) { a[i][left] = j; i--; j++; }
        left++;
    }  
    return a;
}