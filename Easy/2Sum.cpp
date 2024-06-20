#include<bits/stdc++.h>

using namespace std;

//Link to the Problem: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
   
/* Hash Map Method : Time Complexity O(n) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            if (mp.find(nums[i]) != mp.end()) { return {i,mp[nums[i]]}; }
            mp[target-nums[i]] = i;
        }
        return {-1,-1};
    }
};

/* Brute Force : Time Complexity O(n^2) */
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