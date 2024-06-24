#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flipping-an-image/
// Difficulty : Easy

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image[0].size();
        int k = (n%2==0)?n/2:n/2+1;
        for (int i=0;i<n;i++) {
            for (int j=0;j<k;j++) {
                if (image[i][j] == image[i][n-j-1]) { image[i][j] = image[i][n-j-1] = image[i][j]^1; }
            }
        }
        return image;
    }
};