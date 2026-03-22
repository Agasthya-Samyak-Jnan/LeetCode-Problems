#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Difficulty : Easy

/* BRUTE FORCE - CHECK ALL 4 ROTATED STATES OF MATRIX WITH GIVEN MATRIX */
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {

        // No extra memory, clockwise 90 degree rotation function

        int n = matrix.size();

        // transpose
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // mirror
        for (int i=0;i<n;i++) {
            for (int j=0;j<n/2;j++) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }

    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for (int i=0;i<4;i++) {
            if (target == mat) { return true; }
            rotate(mat);
        }

        return false;
    }
};