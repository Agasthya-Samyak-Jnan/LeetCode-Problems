#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rotate-string
// Difficulty : Easy

class Solution {
public:
    bool rotateString(string s, string g) {
        
        int n = s.length(), m = g.length(), j = 0;
        
        if (n != m) { return false; }
        
        for (int i=0;i<n;i++) {
            if (s[i] == g[j]) {
                int k = i, c = n;
                while (c and s[k%n] == g[j%m]) { k++; j++; c--; }
                if (!c) { return true; }
                j = 0;
            }
        }
        
        return false;
    }
};