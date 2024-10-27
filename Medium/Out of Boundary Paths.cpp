#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/out-of-boundary-paths/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING SOLUTION */

/*  
    BASIC RECURSION SOLUTION - EXCEEDS TIME LIMIT - GIVES AN IDEA OR FRAMEWORK OF REAL SOLUTION
    Time Complexity : O(4^(moves))
    Space Complexity : O(moves)
*/
class Solution {
public:
    int findPaths(int m, int n, int moves, int i, int j) {
        if (moves < 0) { return 0; }
        if ( i == m || j == n || i < 0 || j < 0 ) { return 1; }
        return findPaths(m,n,moves-1,i-1,j) + findPaths(m,n,moves-1,i,j+1) + findPaths(m,n,moves-1,i+1,j) + findPaths(m,n,moves-1,i,j-1);
    }
};

/* Space Complexity = Time Complexity = O(m*n*moves) - RECURSION WITH 3D MEMOISATION CUBE */
class Solution {
public:
    int m,n,mod = 1e9 + 7;
    
    long long solve (int moves, int i, int j, vector<vector<vector<long long>>>& dp) {
        if (moves < 0) { return 0; }
        if ( i == m || j == n || i < 0 || j < 0 ) { return 1; }
        if (dp[i][j][moves] != -1) { return dp[i][j][moves] % mod; }
        dp[i][j][moves] = solve(moves-1,i-1,j,dp) + solve(moves-1,i,j+1,dp) + solve(moves-1,i+1,j,dp) + solve(moves-1,i,j-1,dp);
        return dp[i][j][moves] % mod;
    }
    
    
    long long findPaths(int m, int n, int moves, int i, int j) {
        this->m = m;
        this->n = n;
        vector<vector<vector<long long>>> dp = vector<vector<vector<long long>>>(m,vector<vector<long long>>(n,vector<long long>(moves+1,-1)));
        return solve(moves,i,j,dp);
    }
};