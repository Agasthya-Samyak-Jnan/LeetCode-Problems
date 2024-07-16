#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/to-lower-case/
// Difficulty : Easy

class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        for (int i=0;i<n;i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') { s[i] = s[i]+32; }
        }
        return s;
    }
};