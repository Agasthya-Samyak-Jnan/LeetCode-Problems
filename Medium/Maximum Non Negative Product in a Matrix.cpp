#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSION ONLY : TIME LIMIT EXCEEDED, BRUTE FORCE */
class Solution {
public:
    int m, n, mod = 1e9 + 7;
    long max_product;
    vector<vector<int>> g;

    void solve (int i, int j, long product) {
        if (i >= m or j >= n) { return; }
        product = (product*g[i][j]);
        if (i == m-1 and j == n-1) { 
            max_product = max(max_product,product); 
            return; 
        }
        // Down
        solve(i+1,j,product);
        // Right
        solve(i,j+1,product);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        max_product = -1;
        g = grid;
        solve(0,0,1);
        return max_product % mod;
    }
};

/* RECURSION + 2D MEMOIZATION : 
   YOU HAVE TO TRACK MINIMUM NEGATIVE PRODUCTS TOO BECAUSE 
   THEY COULD LEAD TO LARGER POSITIVE PRODUCTS IF SIGN FLIPPED ALONG THE PATH.
*/
class Solution {
public:
    int m, n, mod = 1e9 + 7;
    vector<vector<int>> g;
    vector<vector<long>> maxdp, mindp;

    void solve (int i, int j, long product) {
        if (i >= m or j >= n) { return; }
        product = (product*g[i][j]);
        if (maxdp[i][j] >= product and mindp[i][j] <= product) { return; }
        else {
            maxdp[i][j] = max(maxdp[i][j],product);
            mindp[i][j] = min(mindp[i][j],product);
            if (i == m-1 and j == n-1) { return; }
            // Down
            solve(i+1,j,product);
            // Right
            solve(i,j+1,product);
        }
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        maxdp = vector<vector<long>>(m, vector<long>(n, LONG_MIN));
        mindp = vector<vector<long>>(m, vector<long>(n, LONG_MAX));
        maxdp[m-1][n-1] = -1;
        solve(0,0,1);
        return maxdp[m-1][n-1] % mod;
    }
};