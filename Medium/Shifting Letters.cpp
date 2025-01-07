#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shifting-letters
// Difficulty : Medium

/* SUFFIX SUM OF SHIFT ARRAY (REVERSED PREFIX SUM) */
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.length();
        vector<long> psum(n,0);

        psum[n-1] = shifts[n-1];
        for (int i=n-2;i>=0;i--) { psum[i] = psum[i+1] + shifts[i]; }
        
        for (int i=0;i<n;i++) { s[i] = 'a' + ((s[i] - 'a' + (psum[i] % 26)) % 26); }

        return s;
    }
};

/* BETTER MEMORY EFFICIENCY USING SAME ABOVE IDEA */
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.length();
        long shift = shifts[n-1];
        
        for (int i=n-1;i>=0;i--) { 
            s[i] = 'a' + ((s[i] - 'a' + (shift % 26)) % 26); 
            if (i>0) { shift += shifts[i-1]; }
        }

        return s;
    }
};