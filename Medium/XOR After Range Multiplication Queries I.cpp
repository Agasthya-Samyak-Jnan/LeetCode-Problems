#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Difficulty : Medium

/* BRUTE FORCE */
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int mod = 1e9 + 7;
        
        for (auto q : queries) {
            int i = q[0];
            while (i <= q[1]) {
                nums[i] = ((long)nums[i] * (long)q[3]) % mod;
                i += q[2];
            }
        }

        int XOR = 0;
        for (auto num : nums) { XOR ^= num; }

        return XOR;
    }
};