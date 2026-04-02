#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-adjacent-equal-elements/
// Difficulty : Medium

/* STACK BASED SIMULATION : USING VECTOR LIKE A STACK WHILE PEEKING 1 ELEMENT BELOW THE TOP FOR MERGING ELEMENTS. */
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        int n = nums.size(), i = 1;
        vector<long long> ans = {nums[0]};

        while (i<n) {
            if (ans.back() == nums[i]) { 
                ans.back() += nums[i];
                int idx = ans.size() - 1;
                while (idx > 0 and ans[idx] == ans[idx-1]) {
                    ans[idx-1] += ans[idx];
                    ans.pop_back();
                    idx--;
                } 
                i++;
            }
            else { 
                ans.push_back(nums[i]); 
                i++;
            }
        }

        return ans;
    }
};