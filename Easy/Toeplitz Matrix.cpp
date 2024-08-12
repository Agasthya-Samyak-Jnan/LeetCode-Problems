#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/toeplitz-matrix/
// Difficulty : Easy

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (a[i][j] != a[i-1][j-1]) { return false; }
            }
        }
        
        return true; 
    }
};