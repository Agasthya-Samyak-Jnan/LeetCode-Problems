#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/type-of-triangle/
// Difficulty : Easy

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0]+nums[1]<=nums[2] || nums[1]+nums[2]<=nums[0] || nums[0]+nums[2]<=nums[1]) { return "none"; }
        if (nums[0] == nums[1] && nums[0] == nums[2]) { return "equilateral"; }
        if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) { return "isosceles"; }
        return "scalene";
    }
};