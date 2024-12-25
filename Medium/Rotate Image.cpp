#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rotate-image/
// Difficulty : Medium 

/* TAKE TRANSPOSE (-90 Degree OR Left Rotation) then do LATERAL INVERSION - MIRROR (180 Degree Rotation). */
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
        mirror(matrix);
    }
};

/* 
    PYTHON3 VERSION

    class Solution:
    
    def __init__ (self) :
        self.m = 0
        self.n = 0
    
    def transpose (self, matrix) :
        for i in range(0,self.m) :
            for j in range (i+1,self.n) :
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        
    def mirror (self, matrix) :
        for j in range(0,self.n//2) :
            for i in range(0,self.m) :
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][self.n-j-1]
                matrix[i][self.n-j-1] = temp
    
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.m = len(matrix)
        self.n = len(matrix[0])
        
        self.transpose(matrix)
        self.mirror(matrix)
*/