#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/matrix-diagonal-sum/
// Difficulty: Easy


/* Time Complexity: O(N) = (2N) */
class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int n = a.size(),sum=0;
        for(int i=0,j=0;i<n,j<n;i++,j++) {
            sum += a[i][j];
        }
        for(int i=0,j=n-1;i<n,j>=0;i++,j--) {
            sum += a[i][j];
        }
        if (!(n%2)) { return sum; }
        return sum-a[n/2][n/2]; 
    }
};