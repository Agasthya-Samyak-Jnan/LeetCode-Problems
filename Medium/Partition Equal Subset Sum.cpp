#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/partition-equal-subset-sum/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING SOLUTION */

/* SUBSET = Inclusion of some elements from all elements of a Set - OR - Exclusion of some elements from all elements of a Set. */
/*
    - Build all possible subsets of a Set by including or not including each element. 
    - At the end of formation of each subset, check if sum is half of sum of all elements of set. 
    NOTE : - Equal Subsets always has its SUM equal to half of TOTAL SUM of ALL Elements of the Set, because they want TWO equal subsets.
           - Ignore any subset whose sum goes above half of TOTAL SUM of ALL Elements.
           - If TOTAL SUM of ALL Elements of the Set is ODD, its impossible to divide them into TWO EQUAL HALVES, since number is odd, hence return false.
*/

/* RECURSION ONLY - TIME LIMIT EXCEEDED */
class Solution {
    public:
        vector<int> a;
        int n, total_sum = 0;
    
        bool solve (int i, int sum) {
            if (i>=n or sum > total_sum/2) { return false; }
            if (sum == total_sum/2) { return true; }
            return solve(i+1,sum+a[i]) or solve(i+1,sum);
        }
    
        bool canPartition(vector<int>& nums) {
    
            a = nums;
            n = nums.size();
            
            for (auto num : nums) { total_sum += num; }
    
            if (total_sum % 2 == 1) { return false; }
    
            return solve(0,0);
        }
};

/* RECURSION WITH 2D-MEMOIZATION */
class Solution {
    public:
        unordered_map<int,unordered_map<int,bool>> dp;
        vector<int> a;
        int n, total_sum = 0;
    
        bool solve (int i, int sum) {
            if (i>=n or sum > total_sum/2) { return false; }
            if (sum == total_sum/2) { return true; }
            if (dp.find(i) != dp.end() and dp[i].find(sum) != dp[i].end()) { return dp[i][sum]; }
            return dp[i][sum] = solve(i+1,sum+a[i]) or solve(i+1,sum);
        }
    
        bool canPartition(vector<int>& nums) {
    
            a = nums;
            n = nums.size();
            
            for (auto num : nums) { total_sum += num; }
    
            if (total_sum % 2 == 1) { return false; }
    
            return solve(0,0);
        }
};

/* RECURSION WITH 2D-MEMOIZATION - USING VECTORS FOR DP TABLE INSTEAD OF MAPS - MOST OPTIMIZED */
class Solution {
    public:
        vector<vector<int>> dp;
        vector<int> a;
        int n, total_sum = 0;
    
        bool solve (int i, int sum) {
            if (i>=n or sum > total_sum/2) { return false; }
            if (sum == total_sum/2) { return true; }
            if (dp[i][sum] != -1) { return dp[i][sum]; }
            return dp[i][sum] = solve(i+1,sum+a[i]) or solve(i+1,sum);
        }
    
        bool canPartition(vector<int>& nums) {
    
            a = nums;
            n = nums.size();
            
            for (auto num : nums) { total_sum += num; }
    
            if (total_sum % 2 == 1) { return false; }
    
            dp = vector<vector<int>>(n,vector<int>((total_sum/2)+1,-1));
    
            return solve(0,0);
        }
};