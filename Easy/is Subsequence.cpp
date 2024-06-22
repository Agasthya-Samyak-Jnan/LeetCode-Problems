#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/is-subsequence/
// Difficulty : Easy

class Solution {
public:
    bool isSubsequence(string s, string t) {
         int i=0,j=0;
        
         while (t[i]) {
             if (!s[j]) { return true; }
             if (s[j] == t[i]) { j++; }
             i++;
         }
         if (s[j]) { return false; }
         return true;
    }
};