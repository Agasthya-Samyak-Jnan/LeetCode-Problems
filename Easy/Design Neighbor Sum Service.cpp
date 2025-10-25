#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-neighbor-sum-service/
// Difficulty : Easy  

/* SIMULATION */
class NeighborSum {
public:
    int m,n;
    vector<vector<int>> g;
    unordered_map<int,vector<int>> n2p;
    vector<vector<int>> adjs = {{1,0},{0,1},{-1,0},{0,-1}}, diags = {{-1,-1},{1,1},{-1,1},{1,-1}};

    NeighborSum(vector<vector<int>>& grid) { 
        g = grid; 
        m = g.size();
        n = g[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                n2p[g[i][j]] = {i,j};
            }
        }
    }

    int sum (int value, vector<vector<int>>& drxns) {
        int s = 0, i = n2p[value][0], j = n2p[value][1];
        for (auto d : drxns) {
            int di = i + d[0], dj = j + d[1];
            if (di >= 0 and dj >= 0 and di < m and dj < n) { s += g[di][dj]; }
        } 
        return s;
    }
    
    int adjacentSum(int value) { return sum(value,adjs); }
    
    int diagonalSum(int value) { return sum(value,diags); }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */