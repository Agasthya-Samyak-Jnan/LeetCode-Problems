#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/license-key-formatting/
// Difficulty : Easy

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        int dashes = 0, n = 0, letters, first_len,i;
        
        for (int i=0;s[i];i++) {
            if (s[i] == '-') { dashes++; }
            else if (s[i] >= 'a' and s[i] <= 'z') { s[i] = s[i] - 32; }
            n++;
        }
        
        letters =  n - dashes;
        first_len = letters % k;
        i = 0;
        string lic = "";
        
        if (letters == 0) { return ""; }
        
        while (first_len) {
            if (s[i] != '-') { lic += s[i]; first_len--; }
            i++;
        }
        
        if (lic.length()) { lic += "-"; }
        
        while (i<n) {
            int temp = k;
            while (temp and i<n) {
                if (s[i] != '-') { lic += s[i]; temp--; }
                i++;
            }
            lic += "-";
        }
        
        while (lic.back() == '-') { lic.pop_back(); }
        
        return lic;
    }
};