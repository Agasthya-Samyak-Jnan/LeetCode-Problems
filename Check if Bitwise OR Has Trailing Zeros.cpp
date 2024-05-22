#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/
// Difficulty : Easy

using namespace std;

/* Time Complexity : O(n) */
class Solution {
public:
    bool hasTrailingZeros(vector<int> &a) {
        int e = 0;
        for (int i=0;i<a.size();i++) {
             if (!(a[i]%2)) { e++; }
             if (e > 1) { return true; }
         }
        return false;
    }
};