#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/spiral-matrix/
//Difficulty: Medium

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int left = 0, right = *matrixColSize - 1;
    int top = 0, bottom = matrixSize - 1;
    int i = 0, j = 0;
    
    //Returning Array Size through Pointer
    *returnSize = (*matrixColSize)*(matrixSize);
    
    int* ans = (int*)calloc(*returnSize, sizeof(int));
    
    while (j < *returnSize) 
    {     
        // Move Left
        i = left;
        while (i <= right && j < *returnSize) { ans[j] = matrix[top][i]; i++; j++; }
        top++;
        
        // Move Down
        i = top;
        while (i <= bottom && j < *returnSize) { ans[j] = matrix[i][right]; i++; j++; }
        right--;
        
        // Move Right 
        i = right;
        while (i >= left && j < *returnSize) { ans[j] = matrix[bottom][i]; i--; j++; }
        bottom--;
        
        // Move Up 
        i = bottom;
        while (i >= top && j < *returnSize) { ans[j] = matrix[i][left]; i--; j++; }
        left++;
    } 
    return ans;
}