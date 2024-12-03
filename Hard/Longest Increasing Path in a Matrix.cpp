#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Difficulty : Hard

/* PROBLEM IS A COMBINATION OF GRAPH AND DYNAMIC PROGRAMMING */

/* RECURSIVE SOLUTION - ONLY DEPTH-FIRST SEARCH - TC : O(M*N*K) */
class Solution {
public:
    int ans = 0,m,n;
    vector<int> dx,dy;
    vector<vector<int>> mat;
    
    void dfs (int i, int j, int len) {
        
        ans = max(ans,len);
        
        for (int k=0;k<4;k++) {
            int di = i + dx[k];
            int dj = j + dy[k];
            if (di >= 0 && dj >= 0 && di < m && dj < n && mat[di][dj] > mat[i][j]) {
                dfs(di,dj,len+1);
            }
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size(), n = matrix[0].size();
        mat = matrix;
        dx = {0,0,-1,+1};
        dy = {-1,+1,0,0};
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                dfs(i,j,1);
            }
        }
        
        return ans;
    }
};

/* RECURSION WITH MEMOIZATION - DFS + MEMOIZATION - DYNAMIC PROGRAMMING - TC : O(M*N) */
class Solution {
public:
    int ans = 0,m,n;
    vector<int> dx,dy;
    vector<vector<int>> mat,dp;
    
    int dfs (int i, int j) {
        
        if (dp[i][j] != -1) { return dp[i][j]; }
        
        dp[i][j] = 1;
        
        for (int k=0;k<4;k++) {
            int di = i + dx[k];
            int dj = j + dy[k];
            if (di >= 0 && dj >= 0 && di < m && dj < n) {
                if (mat[di][dj] > mat[i][j]) { dp[i][j] = max(dp[i][j],1+dfs(di,dj)); }
            }
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size(), n = matrix[0].size();
        mat = matrix;
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        dx = {0,0,-1,+1};
        dy = {-1,+1,0,0};
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                ans = max(ans,dfs(i,j));
            }
        }
        
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout<<j<<"\t";
        //     }
        //     cout<<"\n";
        // }
        
        return ans;
    }
};