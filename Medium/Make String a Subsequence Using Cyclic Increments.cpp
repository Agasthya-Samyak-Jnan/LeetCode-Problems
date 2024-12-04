#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
// Difficulty : Medium

/* TWO POINTERS */
class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        
        int m = s1.length(), n = s2.length(), i = 0, j = 0;
        
        while (i<m) {
            if (s1[i] == s2[j] || s1[i]+1 == s2[j] || (s1[i] == 'z' && s2[j] == 'a')) { j++; }
            i++;
            if (j == n) { return true; }
        }
        
        return j == n;
    }
};