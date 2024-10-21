#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rotate-image/
// Difficulty : Medium 

/* TRANSPOSE + MIRRORING (Left to Right Inversion)*/
class Solution {
public:
    int n;
    
    void transpose (vector<vector<int>>& matrix) {
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void mirror (vector<vector<int>>& matrix) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n/2;j++) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        transpose(matrix); 
        mirror(matrix); // Lateral Inversion (Real Life Mirror Image)
    }
};