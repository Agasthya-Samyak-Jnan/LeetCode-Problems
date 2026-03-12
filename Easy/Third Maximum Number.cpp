#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/third-maximum-number/
// Difficulty: Easy

/* O(N) SOLUTION IS DOABLE */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long _1st = -2147483649, _2nd = -2147483649, _3rd = -2147483649;
        for (auto num : nums) {
            if (num == _1st or num == _2nd or num == _3rd) { continue; }
            if (num > _1st) {
                _3rd = _2nd;
                _2nd = _1st;
                _1st = num;
            }
            else if (num > _2nd) {
                _3rd =_2nd;
                _2nd = num; 
            }
            else if (num > _3rd) { _3rd = num; }
        }

        return (_3rd >= INT_MIN) ? (int)_3rd : (int)_1st;
    }
};