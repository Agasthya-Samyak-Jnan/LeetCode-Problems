#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-palindromic-substring/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING APPROACH SINCE I WAS ABLE TO FIND THE RECURSIVE RULES FOR PALINDROME CHECKING. */

/* RECURSIVE SOLUTION - BRUTE FORCE METHOD - Time Complexity : O(N^3) */
class Solution {
public:
    bool isPalindrome (int i, int j, string& s) {
        return (i>=j) || ( s[i] == s[j] && isPalindrome(i+1,j-1,s) );
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        int start,end,max_len = INT_MIN;
        
        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                if (isPalindrome(i,j,s)) { 
                    if (j-i+1 > max_len) {
                        start = i; end = j; 
                        max_len = j-i+1;
                    }
                }
            }
        }
        
        return s.substr(start,end-start+1);
    }
};

/* RECURSION WITH MEMOISATION SOLUTION - Time Complexity : O(N^2) */
class Solution {
public:
    vector<vector<short>> dp;
    
    bool isPalindrome (int i, int j, string& s) {
        if (dp[i][j] == -1) { dp[i][j] = ((i>=j) || (s[i] == s[j] && isPalindrome(i+1,j-1,s))); }
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        int start,end,max_len = INT_MIN;
        
        dp = vector<vector<short>>(n,vector<short>(n,-1));
        
        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                if (isPalindrome(i,j,s)) { 
                    if (j-i+1 > max_len) {
                        start = i; end = j; 
                        max_len = j-i+1;
                    }
                }
            }
        }
        
        return s.substr(start,end-start+1);
    }
};