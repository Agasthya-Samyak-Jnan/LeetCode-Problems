#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/01-matrix/
// Difficulty : Medium

/* Dynamic Programming : Calculate Results Solving For Nearest Top and Left Zeroes.
                         Then use the pre-computed results to calculate Distance for Bottom and Right Zeroes. 
                         Always select minimum distance while doing second operation. 
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        int left = 0, top = 0, bottom = 0, right = 0, current = 0;
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j] == 1) {
                   left = top = m+n;
                   if (i>0) { top = mat[i-1][j]; } 
                   if (j>0) { left = mat[i][j-1]; }
                   mat[i][j] = min(left,top) + 1; 
                }
            }
        }
        
        for (int i=m-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                if (mat[i][j] != 0) { // Here Don't check mat[i][j] == 1 , because its not 01 matrix anymore. we have precomputed values now.
                    bottom = right = m+n;
                    if (i<m-1) { bottom = mat[i+1][j]; }
                    if (j<n-1) { right = mat[i][j+1]; }
                    mat[i][j] = min(mat[i][j],min(right,bottom)+1);
                }
            }
        }
        
        return mat;
        
    }
};