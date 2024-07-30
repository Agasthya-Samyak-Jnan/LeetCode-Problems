#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Difficulty : Easy

/* Simply a String Problem */
class Solution {
public:
    bool checkString(string s) {
         int n = s.length();
         int found_a = 0;
         for (int i = n-1;i>=0;i--) {
             if (s[i] == 'a') { found_a = 1; }
             else if (found_a) { return false; }
         }
         return true;
    }
};