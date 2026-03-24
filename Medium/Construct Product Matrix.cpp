#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-product-matrix/
// Difficulty : Medium

/* PREFIX AND SUFFIX PRODUCTS : SIMILAR TO QUESTION 238 : O(2*M*N) SPACE (EXCLUDING OUTPUT), O(2*M*N) TIME */
class Solution {
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), p = 1, s = 1, mod = 12345;
        vector<int> pre(m*n), suf(m*n);
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                pre[i*n+j] = ((p % mod)*(grid[i][j] % mod)) % mod;
                p = pre[i*n+j];
                suf[(m-1-i)*n+(n-1-j)] = ((s % mod)*(grid[m-1-i][n-1-j] % mod)) % mod;
                s = suf[(m-1-i)*n+(n-1-j)];
            }
        }

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i == 0 and j == 0) { ans[i][j] = suf[i*n+j+1] % mod; }
                else if (i == m-1 and j == n-1) { ans[i][j] = pre[i*n+j-1] % mod; }
                else { ans[i][j] = (pre[i*n+j-1] * suf[i*n+j+1]) % mod; }
            }
        }

        return ans;
    }
};

/* SAME SOLUTION BUT NO SPACE USED FOR STORING PREFIX AND SUFFIX BECAUSE ITS NOT NEEDED : O(1) SPACE (EXCLUDING OUTPUT), O(2*M*N) TIME */
class Solution {
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), pre = 1, suf = 1, mod = 12345;
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                ans[i][j] =  pre;
                pre = ((pre % mod) * (grid[i][j] % mod)) % mod;
            }
        }

        for (int i=m-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                ans[i][j] = ((ans[i][j] % mod) * (suf % mod)) % mod;
                suf = ((suf % mod) * (grid[i][j] % mod)) % mod;
            }
        }

        return ans;
    }
};