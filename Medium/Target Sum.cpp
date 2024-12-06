#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/target-sum/
// Difficulty : Medium 

/* BACKTRACKING FOR CHECKING ALL POSSIBLE EXPRESSIONS THAT CAN BE FORMED WITH GIVEN NUMBERS USING '+' AND '-' */

// Expanded Solution for Understanding
class Solution {
public:
    int target,n;
    vector<int> nums;
    
    int solve (int i,int sum) {
        if (i == n) { return (sum == target); }
        return solve(i+1,sum+nums[i]) + solve(i+1,sum-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        n = nums.size();
        
        return solve(0,0);
    }
};

// Concise Solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target, int i = 0, int sum = 0) {
        if (i == nums.size()) { return (sum == target); }
        return findTargetSumWays(nums,target,i+1,sum+nums[i]) + findTargetSumWays(nums,target,i+1,sum-nums[i]);
    }
};


/* BACKTRACKING + MEMOIZATION FOR REUSING PREVIOUSLY COMPUTED CALCULATIONS */

// Expanded Solution for Understanding
class Solution {
public:
    int target,n;
    vector<int> nums;
    unordered_map<int,unordered_map<int,int>> dp;
    
    int solve (int i,int sum) {
        if (i == n) { return (sum == target); }
        if (dp[i].find(sum) != dp[i].end()) { return dp[i][sum]; }
        dp[i][sum] = solve(i+1,sum+nums[i]) + solve(i+1,sum-nums[i]);
        return dp[i][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        n = nums.size();
        
        return solve(0,0);
    }
};

// Concise Solution
class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    
    int findTargetSumWays(vector<int>& nums, int target, int i = 0, int sum = 0) {
        if (i == nums.size()) { return (sum == target); }
        if (dp[i].find(sum) != dp[i].end()) { return dp[i][sum]; }
        return dp[i][sum] = findTargetSumWays(nums,target,i+1,sum+nums[i]) + findTargetSumWays(nums,target,i+1,sum-nums[i]);
    }
};