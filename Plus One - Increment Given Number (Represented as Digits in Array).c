#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/plus-one/
//Difficulty: Easy

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    *(returnSize) = digitsSize+1;
    int i = digitsSize-1;
    
    int* ans = (int*)calloc( *(returnSize),sizeof(int));
    
    while (i > -1) 
    {   
        if (digits[i] == 9) { ans[i] = 0; i--; continue; }
        else { ans[i] = digits[i] + 1; i--; break; }
    }
    while (i > -1)
    {
        ans[i] = digits[i];
        i--;
    }
    
    if (ans[0] == 0) { ans[0] = 1; }
    else { --(*(returnSize)); }
    
    return  ans;
}