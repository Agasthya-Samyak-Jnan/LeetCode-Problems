#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
// Difficulty : Medium

/* Greedy - Time Complexity - O(M*N) */
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum, vector<int>& colsum) {
        
        int m = rowsum.size(), n = colsum.size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                ans[i][j] = min(rowsum[i],colsum[j]);
                rowsum[i] -= ans[i][j];
                colsum[j] -= ans[i][j];
                if (rowsum[i] == 0) { break; }
            }
        }
        
        return ans; 
    }
};