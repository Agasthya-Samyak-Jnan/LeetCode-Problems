#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/integer-break/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING - CHECK ALL POSSIBLE PRODUCTS AND CHOOSE THE MOST OPTIMAL PRODUCT AT EACH STATE. */

/* THERE IS A O(N) MATH FORMULA-BASED SOLUTION TO THIS. */

/* PURE RECURSION */
class Solution {
public:
    int N;

    int solve (int n, int product) {
        if (n == 0) { return product; }
        int max_product = 1;
        for (int i=1;i<=n and i<N;i++) { 
            max_product = max(max_product,solve(n-i,product*i)); 
        }
        return max_product;
    }

    int integerBreak(int n) {
        N = n;
        return solve(n,1);
    }
};

/* RECURSION + 2D MEMOISATION */
class Solution {
public:
    int N;
    vector<unordered_map<int,int>> dp;

    int solve (int n, int product) {
        if (n == 0) { return product; }
        if (dp[n][product] != 0) { return dp[n][product]; }
        int max_product = 1;
        for (int i=1;i<=n and i<N;i++) { 
            max_product = max(max_product,solve(n-i,product*i)); 
        }
        return dp[n][product] = max_product;
    }

    int integerBreak(int n) {
        N = n;
        dp = vector<unordered_map<int,int>>(n+1);
        return solve(n,1);
    }
};