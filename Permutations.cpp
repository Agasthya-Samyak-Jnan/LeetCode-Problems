#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/permutations/
// Difficulty: Medium

using namespace std; 

void permutations(vector<vector<int> >& ans,vector<int> nums,int i) { 

    if (i == nums.size()-1) { 
        ans.push_back(nums); 
        return; 
    } 

    for (int j = i; j <= nums.size()-1; j++) { 

        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;

        permutations(ans, nums, i+1); 

        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    } 
} 

vector<vector<int>> permute (vector<int> &num) {
    vector<vector<int>> ans;
    permutations(ans,num,0);
    return ans;
}
