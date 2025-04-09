#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
// Difficulty: Easy

/* SORTING BASED SOLUTION */
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
    
            int n = nums.size();
            sort(nums.begin(),nums.end());
    
            // Any Number thats in middle of sorted sequence would stop the operation in between, making it impossible to make all numbers equal.
            if (k > nums[0]) { return -1; }
    
            int operations = 0;
    
            // Count all distinct numbers, each distinct number takes one operation.
            for (int i=n-1;i>0;i--) {
                if (nums[i] != nums[i-1]) { operations++; }
            }
    
            // If 'k' is smaller than smallest number in array, one extra operation to convert all numbers to 'k'.
            return operations + (k<nums[0]);
        }
};

/* HASH SET BASED SOLUTION */
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
    
            int min_val = INT_MAX;
            unordered_set<int> HS;
    
            // Add all elements to hash set.
            for (auto num : nums) {
                HS.insert(num);
                min_val = min(min_val,num);
            }
    
            if (k > min_val) { return -1; }
            
            return (HS.size()-1) + (k < min_val);
        }
};