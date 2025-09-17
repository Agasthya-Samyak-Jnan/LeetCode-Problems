#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/predict-the-winner/
// Difficulty : Medium

/* GAME THEORY - MIN-MAX PHILOSOPHY : MINIMIZE MAXIMUM LOSS, MAXIMIZE MINIMUM GAIN */
class Solution {
public:
    vector<int> nums;

    bool minmax (int turn, int sum1, int sum2, int start, int end) {
        if (start > end) { return (sum1 >= sum2); } 
        if (turn == 1) {
            if (minmax(2,sum1+nums[start],sum2,start+1,end) or minmax(2,sum1+nums[end],sum2,start,end-1)) { return true; }
            return false;
        }
        else {
            if (!minmax(1,sum1,sum2+nums[start],start+1,end) or !minmax(1,sum1,sum2+nums[end],start,end-1)) { return false; }
            return true;  
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        this->nums = nums;
        return minmax(1,0,0,0,nums.size()-1);
    }
};

