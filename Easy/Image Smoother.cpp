#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/image-smoother/
// Difficulty : Easy

/* MATRIX TRAVERSALS */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size(), n = img[0].size();
        vector<vector<int>> new_img(m, vector<int>(n));
        vector<vector<int>> drxns = {{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int sum = 0, cells = 0;
                for (auto d : drxns) {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 and y >= 0 and x < m and y < n) { sum += img[x][y]; cells++; }
                }
                // cout<<i<<" "<<j<<" "<<sum<<" "<<cells<<"\n"; // debug line
                new_img[i][j] = sum / cells;
            }
        }

        return new_img;
    }
};