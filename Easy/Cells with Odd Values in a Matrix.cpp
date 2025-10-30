#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Difficulty : Easy  

/* SIMULATION */
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {

        int odds = 0;
        vector<vector<int>> mat(m, vector<int>(n,0));

        for (auto inc : indices) {
            for (int i=0;i<n;i++) { mat[inc[0]][i]++; }
            for (int i=0;i<m;i++) { mat[i][inc[1]]++; }
        }

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                odds += (mat[i][j] % 2);
            }
        }

        return odds;
    }
};