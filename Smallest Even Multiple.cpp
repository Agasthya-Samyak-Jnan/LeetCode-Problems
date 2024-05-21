#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/smallest-even-multiple/
// Difficulty: Easy

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return !(n%2)?n:2*n;
    }
};
