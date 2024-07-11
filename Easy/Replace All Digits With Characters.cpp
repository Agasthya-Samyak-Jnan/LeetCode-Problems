#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/replace-all-digits-with-characters/
// Difficulty : Easy

class Solution {
public:
    string replaceDigits(string s) {
           int n = s.length();
           for (int i=1;i<n;i+=2) { s[i] = s[i-1]+(s[i]-'0'); }
           return s;
    }
};