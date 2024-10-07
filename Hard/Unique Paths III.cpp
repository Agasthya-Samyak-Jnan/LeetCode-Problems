#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/unique-paths-iii/
// Diffculty : Hard

/* BACKTRACKING SOLUTION - IDENTIFY END CASES AND END TRACKING APPROPRIATELY */
class Solution {
public:
    vector<int> start,end;
    int s,m,n;
    vector<vector<int>> g;
    
    int solve (int i, int j, int wsp) {
        
        if (i == end[0] && j == end[1]) { return (wsp == 0); }
        
        g[i][j] = -1;
        
        int Right = (j<n-1 && g[i][j+1] != -1) ? solve(i,j+1,wsp-1) : 0;
        int Down = (i<m-1 && g[i+1][j] != -1) ? solve(i+1,j,wsp-1) : 0;
        int Left = (j>0 && g[i][j-1] != -1) ? solve(i,j-1,wsp-1) : 0;
        int Up = (i>0 && g[i-1][j] != -1) ? solve(i-1,j,wsp-1) : 0;
        
        g[i][j] = 0;
        
        return Right + Down + Left + Up;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        m = grid.size(); 
        n = grid[0].size();
        g = grid;
        s = 1;
        start = end = {0,0};
        
        // Find Start, End and Walkable Cells
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 0) { s++; }
                if (g[i][j] == 1) { start[0] = i; start[1] = j; }
                if (g[i][j] == 2) { end[0] = i; end[1] = j; }
            }
        }
        
        //cout<<s<<" "<<start[0]<<","<<start[1]<<" "<<end[0]<<","<<end[1];
        
        return solve(start[0],start[1],s);
    }
};