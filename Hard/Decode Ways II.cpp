#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/decode-ways-ii/
// Difficulty : Hard

/* DYNAMIC PROGRAMAMING QUESITON */

/* Read the Question CAREFULLY - EXTENSION TO "DECODE WAYS" PROBLEM. */
/* RECUSRION WITH MEMOISATION AND CAREFULLY APPLIED QUESTION RULES */
/* NOTE : '*' refers to set of characters [1-9] and '0' is EXCLUDED. */
class Solution {
public:
    vector<int> dp;
    int n, mod = 1e9 + 7;
    
    long long solve (string& s, int i) {
        
        // If we went Out-of-Bounds, string was decoded succesfully.
        if (i > n-1) { return 1; }
        
        // "0" cannot be decoded. All related possibilities are NOT checked.
        if (s[i] == '0') { return 0; }
        
        // Return computed result if computed previously.
        if (dp[i] != -1) { return dp[i]; }
        
        // Single Digit Decoding Ways
        int ways = 0;
        if (s[i] == '*') { ways += 9*solve(s,i+1) % mod; }
        else { ways += solve(s,i+1) % mod; }
        
        // Double Digit Decoding Ways [[*,digit],[digit,*],[*,*],[digit,digit]] Combinations.
        if (i+1 < n) {
            if (s[i] == '*' && s[i+1] != '*') { // [*,digit] Combinations.
                if (s[i+1] < '7') { ways += 2*solve(s,i+2) % mod; } // "1[digit]" to "2[digit]" (2) combinations replacing '*' are possible.
                else { ways += solve(s,i+2) % mod; }  // "1[digit]" combination replacing '*' is possible.
            }
            else if (s[i] != '*' && s[i+1] == '*') { // [digit,*] Combinations.
                if (s[i] == '1') { ways += 9*solve(s,i+2) % mod; }  // "11" to "19" (9) combinations.
                else if (s[i] == '2') { ways += 6*solve(s,i+2) % mod; } // "21" + "26" (6) = 15 combinations.
            }
            else if (s[i] == '*' && s[i+1] == '*') { // [*,*] Combinations.
                ways += 15*solve(s,i+2) % mod; // "11" to "19" (9) + "21" + "26" (6) = 15 combinations.
            }
            else if (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')) { // [digit,digit] Single Combination.
                ways += solve(s,i+2) % mod;
            }
        }

        // Memoise this result for future use.
        dp[i] = ways;
        
        return ways;
    }
    
    long long numDecodings(string s) {
        n = s.length();
        dp = vector<int>(n,-1);
        return solve(s,0) % mod;
    }
};