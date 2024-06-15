#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/two-sum/
// Difficulty: Easy

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int i=0, j=0; *(returnSize) = 2;
    
    while (i<numsSize-1) 
    {
      j = i+1;
      while (j<numsSize) 
      {
         if (nums[i]+nums[j]==target) 
         {       
          nums = (int*)malloc(2*sizeof(int));
          *(nums) = i; *(nums+1) = j;          
          return nums;
        }
        j++;
        }
     i++;
    }   
   return NULL;
}   
   
    
