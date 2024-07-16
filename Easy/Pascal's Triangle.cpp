#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/pascals-triangle/
// Difficulty : Easy

// Binomial Coefficient also known as Pascal's Triangle Using Dynamic Programming - TABULATION (BOTTOM-UP)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows,vector<int>(numRows,0));
        vector<vector<int>> ans;
        vector<int> row;
        for (int i=0;i<numRows;i++) {
            for (int j=0;j<=i;j++) {
                if (j==i || j==0) { dp[i][j] = 1; }
                else { dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; }
                row.push_back(dp[i][j]);
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};

// TESTER
int main () {
    vector<vector<int>> ans;
    int n;
    cin>>n;
    Solution* a = new Solution();
    ans = a->generate(n);
    // Print Answer for your Reference
    for (int i=0;i<n;i++) {
        for (int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<"-";
        }
        cout<<" , ";
    }
}