#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/pascals-triangle-ii/
// Difficulty : Easy

// Binomial Coefficient also known as Pascal's Triangle Using Dynamic Programming - TABULATION (BOTTOM-UP)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1,vector<int>(rowIndex+1,0));
        for (int i=0;i<=rowIndex;i++) {
            for (int j=0;j<=i;j++) {
                if (j==i || j==0) { dp[i][j] = 1; }
                else { dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; }
            }
        }
        return dp[rowIndex];
    }
};