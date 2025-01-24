#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Difficulty : Medium

/* RECURSION (BACKTRACKING) */
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        if (n == 0) { return (target == 0); }
        
        int ans = 0;
        
        for (int i=1;i<=k;i++) {
            if (target-i >= 0) { ans += numRollsToTarget(n-1,k,target-i); }
        }
        
        return ans;
    }
};

/* RECURSION + MEMOIZATION (DYNAMIC PROGRAMMING) (TOP-DOWN) */
class Solution {
public:
    long long dp[31][1001];
    long long mod = 1e9 + 7;

    Solution () {
        for (int i=0;i<31;i++) {
            memset(dp[i],-1,sizeof(dp[i]));
        }
    }
    
    long long numRollsToTarget(int n, int k, int target) {
        
        if (n == 0) { return (target == 0); }
        
        if (dp[n][target] != -1) { return dp[n][target]; }

        dp[n][target] = 0;
        
        for (int i=1;i<=k;i++) {
            if (target-i >= 0) { 
                dp[n][target] = (dp[n][target] % mod + numRollsToTarget(n-1,k,target-i)) % mod; 
            }
        }
        
        return dp[n][target]; 
    }
};