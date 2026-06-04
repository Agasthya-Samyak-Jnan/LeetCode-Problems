#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/student-attendance-record-i/
// Difficulty: Easy

/* ITERATING OVER STRINGS */
class Solution {
public:
    bool checkRecord(string s) {
        
        int A = 0, L = 0;
        
        for (auto r : s) {
            if (r != 'L') { L=0; }
            else { L++; }
            A += (r == 'A');
            if (L == 3) { return false; }
        }
        
        return (A < 2);
    }
};