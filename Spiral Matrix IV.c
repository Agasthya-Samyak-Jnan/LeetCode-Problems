#include<stdio.h>
#include<stdlib.h>

// Link to the Problem: https://leetcode.com/problems/spiral-matrix-iv/
// Difficulty: Medium


struct ListNode {
     int val;
     struct ListNode *next;
};
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* Time Complexity: O(M*N) Best Solution (816ms Runtime Over all Testcases) */
int** spiralMatrix(int m, int n, struct ListNode* head, int* r, int** c) {
    *r = m;  // Return Number of Rows.
    *c = (int*)calloc(m,sizeof(int));
    
    // Setup Variables
    int i=0, left=0, right=n-1, top=0, bottom=m-1;
    //  Allocate 2D Matrix
    int** a = (int**)calloc(m,sizeof(int*));
    for(i=0;i<m;i++) { 
        *(a+i) = (int*)calloc(n,sizeof(int)); 
        *(*c+i) = n;  // Return Number of Columns in each row.
    }
    int k,q=0;
    // Spiral Traversal
    while (q<(m*n)) 
    {   
        // Move Left
        i = left;
        while (i <= right) { 
            if (head != NULL) { k = head->val; head=head->next; } else { k = -1; }
            a[top][i] = k; i++; q++; 
        }
        top++;
        if (q>=(m*n)) { break; }
        // Move Down
        i = top;
        while (i <= bottom) { 
            if (head != NULL) { k = head->val; head=head->next; } else { k = -1; }
            a[i][right] = k; i++; q++;
        }
        right--;
        if (q>=(m*n)) { break; }
        // Move Right 
        i = right;
        while (i >= left) { 
            if (head != NULL) { k = head->val; head=head->next; } else { k = -1; }
            a[bottom][i] = k; i--; q++;
        }
        bottom--;
        if (q>=(m*n)) { break; }
        // Move Up
        i = bottom;
        while (i >= top) { 
            if (head != NULL) { k = head->val; head=head->next; } else { k = -1; }
            a[i][left] = k; i--; q++;
        }
        left++;
    }  
    return a;
}