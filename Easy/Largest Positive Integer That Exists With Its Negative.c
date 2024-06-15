#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
//Difficulty: Easy

//My Solution (47ms, 6.1mb(98.00%) )
int findMaxK(int* nums, int numsSize) {
    
    if (numsSize < 2) { return -1; }
    
    int i=0,j=0, temp = -1;
    
    while (i < numsSize) {
         if (nums[i] < 0) 
         {
          j=0;
          while (j < numsSize) {
              if (nums[j] > 0) 
              {
               if (i == j) { j++; continue; }
               if (nums[i] == -nums[j] && abs(nums[i]) > temp) { temp = abs(nums[i]); }
              }
            j++;
          }
         }
        i++;
    }
    return temp;
}

//Best Solution (7ms(98.00%), >>>6.1mb)
//Using HASH TABLES 
int findMaxK (int* nums, int numsSize) {
    int temp = -1;
    int arr[1001] = {0};
    for (int i=0; i<numsSize; i++) 
    {
        if (nums[i] < 0) { arr[abs(nums[i])] = 1; }
    }
    for (int i=0; i<numsSize; i++) { if (arr[abs(nums[i])] == 1 && nums[i] > 0 && temp < nums[i]) {temp = nums[i]; }}
    return temp;
}

int main () {

    int temp =-1, nums[6] = {1,5,-3,4,3,-1}, n = 6;
    printf("%d", findMaxK(nums,n));
    return 0;
}