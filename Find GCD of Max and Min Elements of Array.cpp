#include<bits/stdc++.h>
#include<vector>

// Link to the Problem: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Difficulty: Easy

class Solution {
public:
    int findGCD(vector<int> &a) {
        int i=0, max=INT_MIN, min=INT_MAX;
        while (i<a.size()) {
            if (a[i] > max) { max = a[i]; }
            if (a[i] < min) { min = a[i]; }
            i++;
        }
        while (min) {
            i = max%min;
            max = min;
            min = i;
        }
        return max;
    }
};