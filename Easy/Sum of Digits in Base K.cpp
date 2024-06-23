#include<bits/stdc++.h>

// Link to the Problem : https://leetcode.com/problems/sum-of-digits-in-base-k/
// Difficulty : Easy

/* Time Complexity : O(logk(N)+1) */
class Solution {
public:
    int sumBase(int n, int k) {
        if (n==0) { return 0; }
        return n%k + sumBase(n/k,k);
    }
};