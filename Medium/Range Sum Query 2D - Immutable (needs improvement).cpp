#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-sum-query-2d-immutable/
// Difficulty : Medium

/* PREFIX SUM ARRAY BASED SOLUTION - NEEDS IMPROVEMENT ! */
class NumMatrix {
public:
    vector<vector<int>> r;
    int m,n;
    
    NumMatrix(vector<vector<int>>& mat) {
        
        // Initialising Prefix Sum Matrices Appropriately.
        m = mat.size();
        n = mat[0].size();
        
        r = vector<vector<int>>(m,vector<int>(n));
        
        for (int i=0;i<m;i++) { r[i][0] = mat[i][0]; }
        
        // Row Prefix Sum Matrix
        for (int i=0;i<m;i++) {
            for (int j=1;j<n;j++) {
                r[i][j] = r[i][j-1] + mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i=row1;i<=row2;i++) {
            if (col1 == 0) {
                sum += r[i][col2];
            }
            else {
                sum += r[i][col2] - r[i][col1-1];
            }
        }
        return sum;
    }
};
