#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/base-7/
// Difficulty : Easy

class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        string base7;
        
        if (num == 0) { return "0"; } //Zero Case
        
        if (num<0) { neg = true; num *= -1; } // Negative Case
         
        while (num) {
            base7 += num%7 + '0';
            num = num/7;
        }
        
        if (neg) { base7 += '-'; }
        
        reverse(base7.begin(),base7.end()); //Reverse to get correct Number
        
        return base7;
    }
};