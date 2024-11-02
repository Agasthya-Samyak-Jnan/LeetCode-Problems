#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/perfect-squares/
// Difficulty : Medium 

/* RECURSION SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    bool is_square (long c) {
        long k = sqrt(c);
        return (k*k == c);       
    }
    
    int numSquares(int n) {
        if (is_square(n)) { return 1; }
        int ans = INT_MAX, k = sqrt(n);
        for (int i=1;i<=k;i++) {
            ans = min(ans,numSquares(n-i*i) + 1);
        }
        return ans;
    }
};

/* RECURSION WITH MEMOISATION (1D MEMOISATION) */
class Solution {
public:
    vector<int> dp;
    
    // Function to check if number is a square or not.
    bool is_square (long c) {
        long k = sqrt(c);
        return (k*k == c);       
    }
    
    int solve (int n) {
        // If number is a perfect Square, only 1 number is enough.
        if (is_square(n)) { return 1; }
        
        // If this result ws previously computed, give it.
        if (dp[n] != -1) { return dp[n]; }
        
        int ans = INT_MAX, k = sqrt(n);
        
        // Find minimum number of perfect squares that sum upto this current 'n' number.
        for (int i=1;i<=k;i++) {
            ans = min(ans,solve(n-i*i) + 1);
        }
        
        // Memoise the reuslt for future use.
        dp[n] = ans;
        return dp[n];
    }
    
    int numSquares(int n) {
        
        dp = vector<int>(n+1,-1);
        
        return solve(n);
    }
};

/* ITERATIVE - TABULATION SOLUTION - FASTER THAN MEMOISATION (1D TABULATION) */
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp = vector<int>(n+1,INT_MAX);
        
        for (int i=1;i<=n;i++) {
            int k  = sqrt(i);
            if (k*k == i) { dp[i] = 1; continue; }
            for (int j=1;j<=k;j++) {
                dp[i] = min(dp[i],1 + dp[i-j*j]);
            }
        }
        
        return dp[n];
    }
};