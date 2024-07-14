#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/clear-digits/
// Difficulty : Easy

class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int n = s.length();
        int j = 0;
        for (int i = n-1;i>=0;i--) {
            if (isdigit(s[i])) { j++; }
            else if (j!=0) { j--; }
            else { ans = s[i] + ans; }
        }
        return ans;
    }
};