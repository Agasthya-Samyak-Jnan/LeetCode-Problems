#include<bits/stdc++.h>
#include<vector>

// Link to the Problem: https://leetcode.com/problems/permutations-ii/
// Difficulty: Medium

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(ans,nums,0);
        return ans;
    }
    
    void permutations(vector<vector<int>> &ans,vector<int> nums,int i) { 

    if (i == nums.size()-1) { 
        ans.push_back(nums);
        return; 
    } 
    
    unordered_map<int,int> dupes;

    for (int j = i; j <= nums.size()-1; j++) { 
        
        if (dupes.find(nums[j]) != dupes.end()) { continue; }
            
        dupes[nums[j]] = 1;    
        
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;

        permutations(ans, nums, i+1); 

        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    } 
   } 
};