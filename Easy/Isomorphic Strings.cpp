#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/isomorphic-strings/
// Difficulty : Easy

/* HASH TABLE SOLUTION */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        char mp1[256] = {'\0'}, mp2[256] = {'\0'} ;
        int n = s.length();
        
        for (int i=0;i<n;i++) {
            
            if (mp1[s[i]] == '\0' && mp2[t[i]] == '\0') { 
                mp1[s[i]] = t[i]; 
                mp2[t[i]] = s[i];
            }
            
            else if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i]) { return false; }
        }
        
        return true;
    }
};