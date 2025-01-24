#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-string-ii/
// Difficulty : Easy

class Solution {
public:
    
    void reverse (int a, int b, string& s) {
        int n = (b-a+1)/2;
        for (int i=0;i<n;i++) { swap(s[a+i],s[b-i]); }
    }
    
    string reverseStr(string s, int k) {
        
        int n = s.length();
        
        for (int i=0;i<n;i+=2*k) {
            if (i+k > n) { reverse(i,n-1,s); break; }
            reverse(i,i+k-1,s);
        }
        
        return s;
    }
};