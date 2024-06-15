#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/diagonal-traverse/
// Difficulty: Medium


/* Time Complexity: Number of Elements in Matrix */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i=0, j=0, k=0, m=nums.size(), n=nums[0].size();
        vector<int> a;
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        while (k<(m*n)-1) {
            while (i>=0 && j<n) {
                a.push_back(nums[i][j]); 
                i--;j++;k++;
            } 
            if (j>=n) { j--; i++; }
            i++;
            if (k >= (m*n)-1) { break; }
            while (j>=0 && i<m) {
                a.push_back(nums[i][j]); 
                i++;j--;k++;
            }
            if (i>=m) { i--; j++; }
            j++;
        } 
        a.push_back(nums[i][j]);    
        return a;
   }
};
