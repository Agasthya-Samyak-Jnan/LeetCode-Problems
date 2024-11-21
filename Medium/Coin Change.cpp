#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/coin-change/
// Difficulty : Medium 

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    vector<int> coins;
    int n,target;
    
    long long solve (long long sum) {
        
        if (sum == target) { return 0; }
        
        if (sum > target) { return 1e9; }
        
        long long ans = INT_MAX;
        
        for (int j=0;j<n;j++) { ans = min(ans,1+solve(sum+coins[j])); }
        
        return ans;
    }
    
    long long coinChange(vector<int>& coins, int amount) {
        
        this->coins = coins;
        n = coins.size();
        target = amount;
        
        long long ans = solve(0);
        
        return ans >= 1e9 ? -1 : ans;
    }
};

/* RECURSION WITH MEMOISATION (1D MEMOISATION) */
class Solution {
public:
    vector<int> coins;
    vector<long long> dp;
    int n,target;
    
    long long solve (long long sum) {
        
        if (sum == target) { return 0; }
        
        if (sum > target) { return 1e9; }
        
        if (dp[sum] != -1) { return dp[sum]; }
        
        long long ans = INT_MAX;
        
        for (int j=0;j<n;j++) { ans = min(ans,1+solve(sum+coins[j])); }
        
        return dp[sum] = ans;
    }
    
    long long coinChange(vector<int>& coins, int amount) {
        
        this->coins = coins;
        n = coins.size();
        target = amount;
        
        dp = vector<long long>(amount+1,-1);
        
        int ans = solve(0);
        
        return ans >= 1e9 ? -1 : ans;
    }
};