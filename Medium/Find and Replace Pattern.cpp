#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-and-replace-pattern/
// Difficulty : Medium 

/* HASH TABLE METHOD */
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
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for (auto word : words) {
            if (isIsomorphic(word,pattern)) { ans.push_back(word); }
        }
        
        
        return ans;
    }
};