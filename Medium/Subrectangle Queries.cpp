#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/subrectangle-queries/
// Difficulty: Medium

using namespace std; 

/* SIMULATION - (FOR LARGER CONSTRAINTS, A QUAD TREE OR A 2D SEGMENT TREE IS THE BEST SCALABLE APPROACH) */
class SubrectangleQueries {
public:
    vector<vector<int>> r;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        r = rectangle; 
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i=row1;i<=row2;i++) {
            for (int j=col1;j<=col2;j++) {
                r[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return r[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */