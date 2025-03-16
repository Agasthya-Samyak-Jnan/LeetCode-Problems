#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/house-robber-ii/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSION */
class Solution {
    public:
        vector<int> a;
    
        int solve (int i, int n) {
            if (i>=n) { return 0; }
            return max(a[i]+solve(i+2,n),solve(i+1,n));
        }
    
        int rob (vector<int>& nums) {
            a = nums;
            int n = nums.size();
            return n == 1 ? a[0] : max(solve(0,n-1),solve(1,n));
        }
};

/* RECURSION WITH MEMOISATION */
class Solution {
    public:
        vector<int> dp;
        vector<int> a;
    
        int solve (int i, int n) {
            if (i>=n) { return 0; }
            if (dp[i] != -1) { return dp[i]; }
            return dp[i] = max(a[i]+solve(i+2,n),solve(i+1,n));
        }
    
        int rob (vector<int>& nums) {

            a = nums;
            int n = nums.size();

            dp = vector<int>(n,-1);
            int ans = solve(0,n-1);

            dp = vector<int>(n,-1);
            ans = max(ans,solve(1,n));
            
            return n == 1 ? a[0] : ans;
        }
};