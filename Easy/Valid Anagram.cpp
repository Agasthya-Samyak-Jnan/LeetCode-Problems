#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-anagram/
// Difficulty : Easy

/* Hash Table Method : Time Complexity O(N) */
class Solution {
public:
    bool isAnagram(string s, string t) {
        
         if (s.length() != t.length()) { return false; }
        
         int letters[26] = {};
         int n = s.length();
        
         for (int i=0;i<n;i++) { letters[s[i]-'a']++; }
         
         for (int i=0;i<n;i++) {
             letters[t[i]-'a']--;
             if (letters[t[i]-'a'] < 0) { return false; } 
         }
        
         return true;        
    }
};