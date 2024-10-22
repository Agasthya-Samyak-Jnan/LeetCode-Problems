#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/modify-the-matrix/
// Difficulty : Easy 

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<int> mx(n,0);
        
        for (int i=0;i<n;i++) {
            int x = -1, y = -1;
            for (int j=0;j<m;j++) {
                if (matrix[j][i] == -1) { x = j; y = i; }
                ans[j][i] = matrix[j][i];
                mx[i] = max(mx[i],matrix[j][i]);
            }
            if (x != -1) { ans[x][y] = mx[i]; }
        }
        
        return ans;
    }
};