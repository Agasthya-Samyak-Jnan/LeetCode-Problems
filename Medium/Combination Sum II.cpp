#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/combination-sum-ii/
// Difficulty : Medium

/* CLASSIC BACKTRACKING SOLUTION BUT SORT ARRAY TO FIND ONLY UNIQUE COMBINATIONS EASILY */
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> nums;
    int target,n;
    
    
    void solve (int i, int sum) {
        
        if (sum == target) { ans.push_back(temp); return; }
        
        if (i>=n || sum > target) { return; }
        
        int prev = -1;
        
        while (i<n-1) {
            i++;
            if (prev != nums[i]) {
                prev = nums[i];
                temp.push_back(nums[i]);
                solve(i,sum+nums[i]);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        this->target = target;
        nums = candidates;
        n = nums.size();
        int prev = -1;
        
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n;i++) { 
            if (nums[i] > target || prev == nums[i]) { continue; }
            else {
                prev = nums[i];
                temp.push_back(nums[i]);
                solve(i,nums[i]); 
                temp.pop_back();
            }
        }
        
        return ans;
    }
};