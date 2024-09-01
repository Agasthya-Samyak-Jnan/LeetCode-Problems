#include<bits/stdc++.h>

using namespace std;

// THIS IS THE SAME PROBLEM AS " FIND PIVOT INDEX "

// Link to the Problem : https://leetcode.com/problems/find-the-middle-index-in-array/
// Difficulty : Easy

/* Simple Prefix Sum Concept Application */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int left_sum = 0;
        
        for (int i=0;i<n;i++) { sum += nums[i]; }
        
        for (int i=0;i<n;i++) {
            sum -= nums[i];
            if (left_sum - sum == 0) { return i; }
            left_sum += nums[i];
        }
        
        return -1;       
    }
};