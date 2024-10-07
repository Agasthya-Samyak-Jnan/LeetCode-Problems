#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/unique-paths/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION */

/* Recursive Solution */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if (m == 0 || n == 0) { return 0; }
//         if (m == 1 || n == 1) { return 1; }
//         // Up = m-1 , Left = n-1
//         return uniquePaths(m-1,n) + uniquePaths(m,n-1);
//     }
// };

/* Memoization Enabled Solution */
class Solution {
 public:
     vector<vector<int>> dp;
    
     int solver (int i, int j) {
         if (i == 0 || j == 0) { return 0; }
         if (i == 1 || j == 1) { return 1; }
         // Number of Ways to come here from...
         dp[i][j-1] = dp[i][j-1] == -1 ? solver(i,j-1) : dp[i][j-1]; // ...Left
         dp[i-1][j] = dp[i-1][j] == -1 ? solver(i-1,j) : dp[i-1][j]; // ...Up
         return dp[i][j-1] + dp[i-1][j]; // Total Ways
     }
    
     int uniquePaths(int m, int n) {
         dp = vector<vector<int>>(m+1,vector<int>(n+1,-1));
         return solver(m,n);
     }
 };

/* Tabluation Solution */
class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n,0));
        dp[0][0] = 1;
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i < m-1) { dp[i+1][j] += dp[i][j]; }
                if (j < n-1) { dp[i][j+1] += dp[i][j]; }
            }
        }
                 
        return dp[m-1][n-1];
    }
};

// TESTER CODE 
int main  () {
    Solution* A = new Solution();
    int a,b; 
    cin>>a>>b;
    cout<<A->uniquePaths(a,b);
    return 0;
}