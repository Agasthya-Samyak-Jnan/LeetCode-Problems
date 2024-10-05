#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/combination-sum/
// Difficulty : Medium


/* CLASSICAL SOLUTION OF BACKTRACKING FOR COMBINATORIAL PROBLEMS */
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> nums;
    int target,n;
    
    
    void solve (int i, int sum) {
        
        if (sum == target) { ans.push_back(temp); return; }
        
        if (i>=n || sum > target) { return; }
        
        while (i<n) {
            temp.push_back(nums[i]);
            solve(i,sum+nums[i]);
            temp.pop_back();
            i++;
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        this->target = target;
        nums = candidates;
        n = nums.size();
        
        for (int i=0;i<n;i++) { 
            temp.push_back(nums[i]);
            solve(i,nums[i]); 
            temp.pop_back();
        }
        
        return ans;
    }
};