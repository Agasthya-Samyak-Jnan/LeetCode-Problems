#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/decode-ways/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING PROBLEM */

/* RECURSION */
class Solution {
public:
    
    int solve (string& s, int i, int n) {
        if (i > n-1) { return 1; }
        if (s[i] == '0') { return 0; }
        if (i+1<n && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) {
                return solve(s,i+1,n) + solve(s,i+2,n);
        }
        else { return solve(s,i+1,n); }
    }
    
    int numDecodings(string s) {
        return solve(s,0,s.length());
    }
};


/* RECURSION - MEMOISED - 1D ARRAY */
class Solution {
public:
    vector<int> dp;
    int n;
    
    int solve (string& s, int i) {
        
        // If we went Out-of-Bounds, string was decoded succesfully.
        if (i > n-1) { return 1; }
        
        // "0" cannot be decoded. All related possibilities are NOT checked.
        if (s[i] == '0') { return 0; }
        
        // If we already computed Number of Decoding Ways starting from this position, return computed result.
        if (dp[i] != -1) { return dp[i]; }
        // Otherwise compute it as below.
        
        // If Two-Digit Number within "10" - "26" can be formed - explore both possiblities - Single and Double Digit Consideration.
        // First MEMOIZE and then Return the computed value.
        if (i+1<n && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) {
                return dp[i] = solve(s,i+1) + solve(s,i+2);
        }
        
        // Otherwise, Consider only Single Digit.
        return dp[i] = solve(s,i+1); 
    }
    
    int numDecodings(string s) {
        n = s.length();
        dp = vector<int>(n,-1);
        return solve(s,0);
    }
}; 
