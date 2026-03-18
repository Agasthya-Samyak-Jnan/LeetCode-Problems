#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-the-matrix-diagonally/
// Difficulty : Medium

/* SIMULATION + SORTING */
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size(), i = m-1, j = 0;
        vector<int> temp;

        while (i>0) {
            int x = i, y = j;
            while (x<m and y<n) {
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x = i, y = j;
            int idx = 0;
            while (x<m and y<n) {
                mat[x][y] = temp[idx];
                x++;
                y++;
                idx++;
            }
            temp = {};
            i--;
        }

        i = 0;

        while (j<n) {
            int x = i, y = j;
            while (x<m and y<n) {
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x = i, y = j;
            int idx = 0;
            while (x<m and y<n) {
                mat[x][y] = temp[idx];
                x++;
                y++;
                idx++;
            }
            temp = {};
            j++;
        }

        return mat;
    }
};