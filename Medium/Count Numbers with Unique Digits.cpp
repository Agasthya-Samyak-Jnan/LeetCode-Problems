#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Difficulty : Medium

/* RECURSION SOLUTION : BASIC BACKTRACKING */
class Solution {
public:
    vector<int> used;
    
    int solve (int n, bool isFirst) {
        
        if (n == 0) { return 1; }
        
        int ans = 0;
        
        for (int i=isFirst;i<10;i++) {
            if (used[i] == 1) { continue; }
            used[i] = 1;
            ans += solve(n-1,false);
            used[i] = 0;
        }
        
        return ans;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        
        used = vector<int>(10,0);
        int ans = 1;
        
        // Account for all unique numbers of length 0-digit to n-digits.
        for (int i=1;i<=n;i++) { ans += solve(i,true); }
        
        return ans;
    }
};

/* DYNAMIC PROGRAMMING + MATH : PERMUTATIONS OF DIGITS + TABULATION */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if (n == 0) { return 1; }
        
        vector<int> dp(n+1,1);
        vector<int> m = {-1,9,9,8,7,6,5,4,3,2,1};
        
        dp[1] = 10;
        
        for (int i=2;i<=n;i++) {
            for (int j=1;j<=i;j++) {
                dp[i] *= m[j];
            }
            dp[i] += dp[i-1];
        }
        
        return dp[n];
    }
};