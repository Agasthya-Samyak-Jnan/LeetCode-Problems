#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
// Difficulty: Medium

using namespace std; 

/* SIMULATION - DO NORMALLY AS THEY TELL */
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int unguardedCells = 0;
        vector<vector<int>> mat(m, vector<int>(n,0));

        for (auto W : walls) { mat[W[0]][W[1]] = 2; }
        for (auto G : guards) { mat[G[0]][G[1]] = 2; }

        for (auto G : guards) {
            int x = G[0], y = G[1];
            for (int i=x-1;i>=0 and mat[i][y] != 2;i--) { mat[i][y] = 1; }
            for (int i=x+1;i<m and mat[i][y] != 2;i++) { mat[i][y] = 1; } 
            for (int i=y-1;i>=0 and mat[x][i] != 2;i--) { mat[x][i] = 1; }
            for (int i=y+1;i<n and mat[x][i] != 2;i++) { mat[x][i] = 1; }
        }

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                unguardedCells += (mat[i][j] == 0);
            }
        }

        return unguardedCells;
    }
};