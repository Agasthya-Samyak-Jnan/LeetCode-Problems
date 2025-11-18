#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/min-max-game/
// Difficulty : Easy 

/* SIMULATION */
class Solution {
public:
    int minmax (int start, int end, string mode, vector<int>& nums) {
        if (start == end) { return nums[start]; }
        int mid = (start+end)/2;
        if (mode == "min") { return min(minmax(start,mid,"min",nums),minmax(mid+1,end,"max",nums)); }
        return max(minmax(start,mid,"min",nums),minmax(mid+1,end,"max",nums));
    }

    int minMaxGame(vector<int>& nums) {
        return minmax(0,nums.size()-1,"min",nums);
    }
};