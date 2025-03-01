#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy

/* TWO POINTERS */
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            
            int n = nums.size(), j = 0;
    
            for (int i=0;i<n;i++) {
                if (nums[i] != 0) {
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
            
        }
};