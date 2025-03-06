#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Difficulty : Medium

/* SIMULATION (BRUTE FORCE) + TWO POINTERS */

/* 1-PASS TIME - 3-ARRAY SPACE (EXCLUDE ANS ARRAY) */
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
    
            vector<int> lesser,equal,greater,ans;
            int n = nums.size();
    
            for (int i=0;i<n;i++) {
                if (nums[i] < pivot) { lesser.push_back(nums[i]); }
                if (nums[i] == pivot) { equal.push_back(nums[i]); }
                if (nums[i] > pivot) { greater.push_back(nums[i]); }
            }
    
            for (int i : lesser) { ans.push_back(i); }
            for (int i : equal) { ans.push_back(i); }
            for (int i : greater) { ans.push_back(i); }
            
            return ans;
        }
};

/* 3-PASS TIME - 1-ARRAY SPACE (EXCLUDE ANS ARRAY) */
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
    
            int n = nums.size(), i = 0, p = 0;
            vector<int> ans(n), greater;
    
            for (int k=0;k<n;k++) {
                if (nums[k] < pivot) { ans[i] = nums[k]; i++; }
                if (nums[k] == pivot) { p++; }
                if (nums[k] > pivot) { greater.push_back(nums[k]); }
            }
    
            while (p) { ans[i] = pivot; i++; p--; }
    
            for (int& num : greater) { ans[i] = num; i++; }
            
            return ans;
        }
};

/* 2-PASS - NO ARRAY SPACE (EXCLUDE ANS ARRAY) */
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            
            int n = nums.size(), i=0, j, k, smaller = 0, larger = 0;
            vector<int> ans(n);
    
            for (int& num : nums) {
                if (num < pivot) { smaller++; }
                if (num > pivot) { larger++; }
            }
    
            k = smaller;
            j = n-larger;
    
            for (int& num : nums) {
                if (num < pivot) { ans[i] = num; i++; }
                if (num == pivot) { ans[k] = num; k++; }
                if (num > pivot) { ans[j] = num; j++; }
            }
    
            return ans;
        }
};