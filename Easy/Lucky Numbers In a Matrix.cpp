#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// Difficulty : Easy

/* Time Complexity : O(M*N) */
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> RowMins;
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size(),i,j;
        
        for (i=0;i<m;i++) {
            int minimum = 100000,k = 0;
            for (j=0;j<n;j++) {
                if (minimum > matrix[i][j]) { minimum = matrix[i][j]; k = j; };
            }
            RowMins.push_back(make_pair(minimum,k));
        }
        
        for (i=0;i<m;i++) {
            int k = RowMins[i].second;
            for (j=0;j<m;j++) {
                if (matrix[j][k] > RowMins[i].first) { break; }
            }
            if (j>=m) { ans.push_back(RowMins[i].first); }
        }
                  
        return ans;
    }
};