#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximal-square/
// Difficulty : Medium 

/* BRUTE FORCE - TIME LIMIT EXCEEDED */
class Solution {
public:
    vector<vector<char>> mat;
    int m,n;

    bool isSquare (int i, int j, int l) {

        if (l == 1) { return mat[i][j] == '1'; }

        for (int a=i;a<i+l;a++) {
            for (int b=j;b<j+l;b++) {
                if (mat[a][b] == '0') { return false; }
            }
        }

        return true;
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        mat = matrix;
        m = matrix.size(), n = matrix[0].size();

        for (int l=min(m,n);l>0;l--) {
            for (int i=0;i<=m-l;i++) {
                for (int j=0;j<=n-l;j++) {
                    if (isSquare(i,j,l)) { return l*l; }
                }
            }
        }

        return 0;
    }
};

/* PURE RECURSION */
/* RECURSIVE SQUARE CHECK (TOP-LEFT TO BOTTOM-RIGHT REDUCTION)  - (You can also do BOTTOM-RIGHT TO TOP-LEFT REDUCTION as well.) */
class Solution {
public:
    vector<vector<char>> mat;
    int m,n;

    bool isSquare (int i, int j, int l) {

        if (l == 1) { return mat[i][j] == '1'; }

        for (int a=i;a<i+l;a++) {
            if (mat[a][j] == '0') { return false; }
        }
        for (int b=j;b<j+l;b++) {
            if (mat[i][b] == '0') { return false; }
        }

        return isSquare(i+1,j+1,l-1);
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        mat = matrix;
        m = matrix.size(), n = matrix[0].size();

        for (int l=min(m,n);l>0;l--) {
            for (int i=0;i<=m-l;i++) {
                for (int j=0;j<=n-l;j++) {
                    if (isSquare(i,j,l)) { return l*l; }
                }
            }
        }

        return 0;
    }
};

/* RECURSION + 3D MEMOIZATION */
class Solution {
public:
    vector<vector<char>> mat;
    vector<vector<vector<int>>> dp;
    int m,n;

    int isSquare (int i, int j, int l) {

        if (l == 1) { return mat[i][j] == '1'; }
        if (dp[i][j][l] != -1) { return dp[i][j][l]; }

        for (int a=i;a<i+l;a++) {
            if (mat[a][j] == '0') { return dp[i][j][l] = 0; }
        }
        for (int b=j;b<j+l;b++) {
            if (mat[i][b] == '0') { return dp[i][j][l] = 0; }
        }

        return dp[i][j][l] = isSquare(i+1,j+1,l-1);
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        mat = matrix;
        m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(min(m,n)+1,-1)));

        for (int l=min(m,n);l>0;l--) {
            for (int i=0;i<=m-l;i++) {
                for (int j=0;j<=n-l;j++) {
                    if (isSquare(i,j,l)) { return l*l; }
                }
            }
        }

        return 0;
    }
};