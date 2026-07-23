#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-sorted-vowel-strings/
// Difficulty : Medium

/* COMBAINATORICS MATH or DYNAMIC PROGRAMMING WITH MEMOIZATION */

/* DYNAMIC PROGRAMMING */

/* Recursion (Intuitive) */
class Solution {
public:
    int n;

    int solve (char last, int l) {
        if (l == n) { return 1; }
        int ways = 0;
        for (auto c : {'a','e','i','o','u'}) {
            if (c >= last) { ways += solve(c,l+1); }
        }
        return ways;
    }

    int countVowelStrings(int n) {
        
        this->n = n;

        return solve(' ',0);
    }
};

/* Recursion (Reduced) */
class Solution {
public:
    int n;

    int solve (int ch, int l) {
        if (l == n) { return 1; }
        int ways = 0;
        for (int i=ch;i<5;i++) {
            ways += solve(i,l+1);
        }
        return ways;
    }

    int countVowelStrings(int n) {
        this->n = n;
        return solve(0,0);
    }
};

/* Recursion + 2D Memoization */
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve (int ch, int l) {
        if (l == n) { return 1; }
        if (dp[ch][l] != -1) { return dp[ch][l]; }
        int ways = 0;
        for (int i=ch;i<5;i++) {
            ways += solve(i,l+1);
        }
        return dp[ch][l] = ways;
    }

    int countVowelStrings(int n) {
        this->n = n;
        dp = vector<vector<int>>(5,vector<int>(n+1,-1));
        return solve(0,0);
    }
};