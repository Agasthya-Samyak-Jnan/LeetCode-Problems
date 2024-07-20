#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Difficulty : Medium 

/* Recursion + Simulation - Do Exactly  What they say in Description */
class Solution {
public:
    string SN (int n) {
        if (n==1) { return "0"; }
        string ans = SN(n-1);
        string temp = invert(ans);
        reverse(temp.begin(),temp.end());
        ans = ans + "1" + temp;
        return ans;
    }
    
    string invert(string a) {
        int n = a.length();
        for (int i=0;i<n;i++) { a[i] = '0' + (a[i]-'0')^1; }
        return a;
    }
    
    char findKthBit(int n, int k) {
         return SN(n)[k-1];
    }
};