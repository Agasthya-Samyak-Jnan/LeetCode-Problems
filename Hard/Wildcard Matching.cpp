#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/wildcard-matching/
// Difficulty : Hard

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    string s,p;
    
    bool solve (int i, int j) {
        // if pattern ends, check if string also ended. String must end with pattern otherwise they don't match.
        if (!p[j]) { return !s[i]; }
        // if '*' match Zero Occurence of Characters OR 'N' number of occurences of ANY characters. You can't match if string ended before pattern.
        if (p[j] == '*') { return solve(i,j+1) || (s[i] && solve(i+1,j)); }
        // if Pattern and String characters match OR Pattern has '?' Character they can be matched and check for further characters.
        // Empty String and Empty Pattern can match.
        // Empty String but non-Empty Pattern cannot match.
        return (s[i] == p[j] || p[j] == '?') && s[i] && solve(i+1,j+1);
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        return solve(0,0);
    }
};

/* RECURSION WITH MEMOISATION - 2D TABLE */
class Solution {
public:
    string s,p;
    int n;
    vector<vector<int>> dp;
    
    bool solve (int i, int j) {
        if (!p[j]) { return !s[i]; }
        if (dp[i][j] != -1) { return dp[i][j]; }
        if (p[j] == '*') {
            return dp[i][j] = solve(i,j+1) || (s[i] && solve(i+1,j));
        }
        return dp[i][j] = (s[i] == p[j] || p[j] == '?') && s[i] && solve(i+1,j+1);
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        n = s.length();
        dp = vector<vector<int>>(n+1,vector<int>(p.length(),-1));
        return solve(0,0);
    }
};