#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :
// Difficulty : Medium 

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    int n,target;
    vector<int> nums;
    
    int solve (int i,int sum) {
        if (sum == target) { return 1; }
        if (sum > target) { return 0; }
        
        int ans = 0;
        for (int j=0;j<n;j++) { ans += solve(j,sum+nums[j]); }
        
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        this->target = target;
        this->nums = nums;
        int ans = 0;
        
        for (int i=0;i<n;i++) { ans += solve(i,nums[i]); }
        
        return ans;
    }
};

/* RECURSION WITH MEMOISATION (2D TABLE) */
class Solution {
public:
    int n,target;
    vector<int> nums;
    vector<vector<int>> dp;
    
    int solve (int i,int sum) {
        if (sum == target) { return 1; }
        if (sum > target) { return 0; }
        if (dp[i][sum] != -1) { return dp[i][sum]; }
        
        dp[i][sum] = 0;
        for (int j=0;j<n;j++) { dp[i][sum] += solve(j,sum+nums[j]); }
        
        return dp[i][sum];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        this->target = target;
        this->nums = nums;
        dp = vector<vector<int>>(n,vector<int>(target,-1));
        int ans = 0;
        
        for (int i=0;i<n;i++) { ans += solve(i,nums[i]); }
        
        return ans;
    }
};

/* RECURSION WITH MEMOISATION (1D TABLE) */
class Solution {
public:
    int n,target;
    vector<int> nums;
    vector<int> dp;
    
    int solve (int sum) {
        if (sum == target) { return 1; }
        if (sum > target) { return 0; }
        if (dp[sum] != -1) { return dp[sum]; }
        
        dp[sum] = 0;
        for (int j=0;j<n;j++) { dp[sum] += solve(sum+nums[j]); }
        
        return dp[sum];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        this->target = target;
        this->nums = nums;
        dp = vector<int>(target,-1);
        int ans = 0;
        
        for (int i=0;i<n;i++) { ans += solve(nums[i]); }

        return ans;
    }
};