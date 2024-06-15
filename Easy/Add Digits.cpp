#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/add-digits/
// Difficulty: Easy


// O(1) Solution : Math Facts
class Solution {
public:
    int addDigits(int n) {
        if (!n) { return 0; }
        if (n%9) { return n%9; }
        else { return 9; }
    }
};

/* Recursive Solution is worse than this */