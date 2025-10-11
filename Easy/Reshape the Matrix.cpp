#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reshape-the-matrix/
// Difficulty : Easy   

/* SIMULATION */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {

        int m = a.size(), n = a[0].size();

        if (m*n != r*c) { return a; }

        vector<vector<int>> reshaped_matrix = {};
        int y = 0;
        vector<int> temp = {};

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                temp.push_back(a[i][j]);
                y++; 
                if (y == c) {
                    reshaped_matrix.push_back(temp);
                    temp = {};
                    y = 0;
                }
            }
        }

        return reshaped_matrix;
    }
};

/* PYTHON3 SOLUTION ( You can use numpy library to do it more easily )*/
class Solution:

    def matrixReshape(self, a: List[List[int]], r: int, c: int) -> List[List[int]]:

        reshaped_matrix = []

        if len(a)*len(a[0]) != r*c :
            return a

        y = 0
        temp = []

        for i in range(len(a)) :
            for j in range(len(a[i])) :
                temp.append(a[i][j])
                y += 1
                if y == c :
                    reshaped_matrix.append(temp)
                    temp = []
                    y = 0

        return reshaped_matrix
        