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

/* PYTHON3 VERSION 

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        m = len(matrix)
        n = len(matrix[0])
        left = 0
        right = n-1
        up = 0
        down = m-1
        i = 0
        j = 0
        ans = []
        
        while j < m*n:
            
            # Right 
            i = left
            while i <= right and j < m*n:
                ans.append(matrix[up][i]) 
                i += 1
                j += 1
            up += 1
            
            # Down
            i = up
            while i <= down and j < m*n:
                ans.append(matrix[i][right])
                i += 1
                j += 1
            right -= 1
            
            # Left
            i = right
            while i >= left and j < m*n:
                ans.append(matrix[down][i])
                i -= 1
                j += 1
            down -= 1
            
            # Up
            i = down
            while i >= up and j < m*n:
                ans.append(matrix[i][left])
                i -= 1
                j += 1
            left += 1
                
        return ans

*/