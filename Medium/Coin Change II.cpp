#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/coin-change-ii/
// Difficulty : Medium 

/* BACKTRACKING SOLUTION : CHECK SUM OF ALL COMBINATIONS. */
class Solution {
public:
    vector<int> coins;
    int n,target;
    
    int solve (int i, int sum) {
        
        if (sum == target) { return 1; }
        if (i == n || sum > target) { return 0 ; }
        
        int ans = 0;
        while (i<n) { ans += solve(i,sum+coins[i]); i++; }
        
        return ans;
    }
    
    int change(int amount, vector<int>& coins) {
        
        this->coins = coins;
        n = coins.size();
        target = amount;
        int ans = 0;
        
        if (amount == 0) { return 1; }
        
        for (int i=0;i<n;i++) { ans += solve(i,coins[i]); }
        
        return ans;
    }
};

/* DYNAMIC PROGRAMMING SOLUTION : PURE RECURSION - FIND NUMBER OF WAYS SMALLER AMOUNT CAN BE MADE USING COINS - RECURSE THIS TILL ZERO. */
class Solution {
public:
    vector<int> coins;
    int n;
    
    int solve (int i, int sum) {

        if (sum < 0) { return 0; }
        if (sum == 0) { return 1; }
        
        int ans = 0;
        while (i<n) { ans += solve(i,sum-coins[i]); i++; }
        
        return ans;
    }
    
    int change(int amount, vector<int>& coins) {
        
        this->coins = coins;
        n = coins.size();
        
        return solve(0,amount);
    }
};

/* DYNAMIC PROGRAMMING SOLUTION : RECURSION with MEMOIZATION - 2D MEMOIZATION */
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> coins;
    int n;
    
    int solve (int i, int sum) {
        
        if (sum < 0) { return 0; }
        if (sum == 0) { return 1; }
        if (dp[i][sum] != -1) { return dp[i][sum]; }
        
        int ans = 0, j = i;
        while (j<n) { ans += solve(j,sum-coins[j]); j++; }
        
        return dp[i][sum] = ans;
    }
    
    int change(int amount, vector<int>& coins) {
        
        this->coins = coins;
        n = coins.size();
        dp = vector<vector<int>>(n,vector<int>(amount+1,-1));
        
        return solve(0,amount);
    }
};

/* DYNAMIC PROGRAMMING SOLUTION : ITERATION with TABULATION - 2D TABULATION */
class Solution {
public:
    unsigned long long change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        
        for (int sum=0;sum<=amount;sum++) { dp[0][sum] = ((sum % coins[0]) == 0); }
        
        for (int i=1;i<n;i++) {
            for (int sum=0;sum<=amount;sum++) {
                if (coins[i] <= sum) { dp[i][sum] += dp[i][sum-coins[i]]; }
                dp[i][sum] += dp[i-1][sum];
            }
        }
        
        return dp[n-1][amount];
    }
};