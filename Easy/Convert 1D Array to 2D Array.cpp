#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/convert-1d-array-into-2d-array/
// Difficulty : Easy

/* Simulation : Do Exactly What They Ask You To Do ! */
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        
        int k = a.size(),x=0;
        
        if (m*n != k) { return {}; }
        
        vector<vector<int>> ans(m,vector<int>(n));
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                ans[i][j] = a[x++];
            }
        }
        
        return ans;
    }
};