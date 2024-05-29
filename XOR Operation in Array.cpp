#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/xor-operation-in-an-array/
// Difficulty: Easy

/* Time Complexity: O(N) */
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i=0;i<n;i++) { ans ^= (start+(2*i)); }
        return ans;
    }
};
