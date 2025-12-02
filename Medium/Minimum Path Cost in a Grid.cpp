#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/minimum-path-cost-in-a-grid/
// Difficulty: Medium

using namespace std;

/* DYNAMIC PROGRAMMING or BACKTRACKING SOLUTION */

/* BACKTRACKING SOLUTION (RECURSIVE) - FIND ALL POSSIBLE PATHS AND TRACK THE MINIMUM COST AMONG ALL POSSIBLE PATHS. */
class Solution {
public:
    int m, n, minCost;
    vector<vector<int>> g;
    vector<vector<int>> c;

    void solve (int row, int col, int cost) {
        if (row == m-1) { 
            // cout<<row<<" "<<col<<" "<<cost+g[row][col]<<"\n\n"; 
            minCost = min(minCost,cost+g[row][col]); 
            return; 
        }
        for (int j=0;j<n;j++) {
            int curr_val = g[row][col];
            // cout<<row<<" "<<col<<" "<<cost<<" -> ";
            solve(row+1,j,cost+curr_val+c[curr_val][j]);
        }
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        m = grid.size();
        n = grid[0].size();
        minCost = INT_MAX;
        g = grid;
        c = moveCost;

        for (int j=0;j<n;j++) { solve(0,j,0); }

        return minCost;
    }
};


/* DYNAMIC PROGRAMMING LIKE DIVIDING STYLE SOLUTION - DIVIDE TOTAL COST TO COST FROM EACH ROW AND FIND OPTIMAL COST AT EACH ROW AS YOU MOVE. */

/* PURE RECURSION */
class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> c;

    int solve (int row, int col, int cost) {

        int curr_val = g[row][col];

        if (row == m-1) { 
            // cout<<row<<" "<<col<<" "<<cost+g[row][col]<<"\n\n"; Debugging Statements
            return cost + g[row][col];  
        }

        int minimumCost = INT_MAX;

        for (int j=0;j<n;j++) {
            // cout<<row<<" "<<col<<" "<<cost<<" -> "; Debugging Statements
            minimumCost = min(minimumCost,solve(row+1,j,curr_val+c[curr_val][j]));
        }

        return cost + minimumCost;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        m = grid.size();
        n = grid[0].size();
        int minCost = INT_MAX;
        g = grid;
        c = moveCost;

        for (int j=0;j<n;j++) { minCost = min(minCost,solve(0,j,0)); }

        return minCost;
    }
};

/* RECURSION + MEMOIZATION (1D or 2D, Assume as you like) */
class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> c;
    vector<int> cache;

    int solve (int row, int col, int cost) {

        int curr_val = g[row][col];

        if (cache[curr_val] != INT_MAX) { return cost + cache[curr_val]; }

        if (row == m-1) { 
            // cout<<row<<" "<<col<<" "<<cost+g[row][col]<<"\n\n"; Debugging Statements
            return cost + g[row][col];  
        }

        for (int j=0;j<n;j++) {
            // cout<<row<<" "<<col<<" "<<cost<<" -> "; Debugging Statements
            cache[curr_val] = min(cache[curr_val],solve(row+1,j,curr_val+c[curr_val][j]));
        }

        return cost + cache[curr_val];
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        m = grid.size();
        n = grid[0].size();
        int minCost = INT_MAX;
        g = grid;
        c = moveCost;
        cache = vector<int>(m*n,INT_MAX);

        for (int j=0;j<n;j++) { minCost = min(minCost,solve(0,j,0)); }

        return minCost;
    }
};