#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Difficulty : Easy

using namespace std;

/* Time Complexity : O(1) Math Facts */
class Solution {
public:
    int countOdds(int low, int high) {
        if (!(!(low&1) && !(high&1))) { return (high-low)/2 + 1; }
        return (high-low)/2;
    }
};