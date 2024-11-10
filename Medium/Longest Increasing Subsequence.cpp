#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-increasing-subsequence/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTIONS below solves in O(N^2) Time. */

/* THIS CAN BE SOLVED BY USING BINARY SEARCH IN O(N*LOG(N)) Time. */

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    vector<int> nums;
    int n;
    
    int solve (int i, int len, int seq_max) {
        
        if (i == n) { return len; }
        
        int with_this = 0;
        int without_this = 0;
        
        if (nums[i] > seq_max) { with_this = solve(i+1,len+1,nums[i]); }
        without_this = solve(i+1,len,seq_max);
        
        return max(with_this,without_this);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();
        this->nums = nums;
        int ans = 1;
        
        ans = solve(0,0,INT_MIN);
        
        return ans;
    }
};

/* RECURSION WITH MEMOISATION SOLUTION - 2D MEMOISATION */
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int n;
    
    int solve (int i, int max_index) {
        
        if (i == n) { return 0; }
        
        if (dp[i][max_index+1] != -1) { return dp[i][max_index+1]; }
        
        int with_this = 0;
        int without_this = 0;
        
        if (max_index == -1 || nums[i] > nums[max_index]) { with_this = 1 + solve(i+1,i); }
        without_this = solve(i+1,max_index);
        
        dp[i][max_index+1] = max(with_this,without_this);
        return dp[i][max_index+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();
        this->nums = nums;
        dp  = vector<vector<int>>(n,vector<int>(n+1,-1));
        
        return solve(0,-1);
    }
};

/* ITERATIVE TABULATION SOLUTION - 1D TABULATION */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), max_len = INT_MIN;
        vector<int> dp(n,1);
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<i;j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            max_len = max(max_len,dp[i]);
        }
        
        return max_len;
    }
};