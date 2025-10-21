#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-bits/
// Difficulty : Easy

/* BITWISE OPERATIONS */
class Solution {
public:
    int reverseBits(int n) {

        int r = 0, i = 0;

        while (i < 32) {
            r = r << 1;
            r = r | (n & 1);
            n = n >> 1;
            i++;
        }
        
        return r;
    }
};