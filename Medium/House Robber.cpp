#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/house-robber/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSION */
class Solution {
    public:
        vector<int> a;
        int n;
    
        int solve (int i) {
            if (i>=n) { return 0; }
            return max(a[i]+solve(i+2),solve(i+1));
        }
    
        int rob (vector<int>& nums) {
            a = nums;
            n = nums.size();
            return solve(0);
        }
};

// Concise Recursion
class Solution {
    public:
        int rob (vector<int>& nums, int i = 0) {
            if (i>= nums.size()) { return 0; }
            return max(nums[i]+rob(nums,i+2),rob(nums,i+1));
        }
};

/* RECURSION WITH MEMOISATION */
class Solution {
    public:
        vector<int> dp;
        vector<int> a;
        int n;
    
        int solve (int i) {
            if (i>=n) { return 0; }
            if (dp[i] != -1) { return dp[i]; }
            return dp[i] = max(a[i]+solve(i+2),solve(i+1));
        }
    
        int rob (vector<int>& nums) {
            a = nums;
            n = nums.size();
            dp = vector<int>(n,-1);
            return solve(0);
        }
};