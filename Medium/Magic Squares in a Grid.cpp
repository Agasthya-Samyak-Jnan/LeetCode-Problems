#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/magic-squares-in-grid/
// Difficulty : Medium 

/* BRUTE FORCE SOLUTION - BASIC INTUITION - CAN BE GENERALISED TO N*N MAGIC SQUARES */
class Solution {
public:

    // Assuming Out-of-Bounds Safe Input to this function
    bool isMagic (vector<vector<int>>& mat, int x, int y, int n) {
        
        vector<int> rows(3,0), cols(3,0), diag(2,0);
        int nums[16] = {0}; // Check if Numbers are repeated inside Square
        
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (mat[x+i][y+j] > n*n or mat[x+i][y+j] == 0 or nums[mat[x+i][y+j]] == 1) { return false; }
                nums[mat[x+i][y+j]] = 1;
                rows[i] += mat[x+i][y+j];
                cols[j] += mat[x+i][y+j];
                if (i == j) { diag[0] += mat[x+i][y+j]; }
                if (i + j == 2) { diag[1] += mat[x+i][y+j]; }
            }
        }

        return (rows == cols) and (diag[0] == rows[0]) and (diag[1] == rows[0]);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int magicSquares = 0;

        for (int i=0;i<m-2;i++) {
            for (int j=0;j<n-2;j++) {
                magicSquares += isMagic(grid,i,j,3); // 3*3 Magic Square Check
            }
        }
        
        return magicSquares;
    }
};