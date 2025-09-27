#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-addition-ii/
// Difficulty : Easy 

/* BRUTE FORCE - TLE and MLE - Don't do this */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        if (ops.empty()) { return m*n; }

        vector<vector<int>> mat = vector<vector<int>>(m, vector<int>(n,1));

        for (auto op : ops) {
            for (int i=0;i<op[0];i++) {
                for (int j=0;j<op[1];j++) {
                    mat[i][j]++;
                }
            }
        }

        int maxNum = 0, maxNumCount = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j] == maxNum) { maxNumCount++; }
                else if (mat[i][j] > maxNum) { maxNum = mat[i][j]; maxNumCount = 1; }
            }
        }

        return maxNumCount;
    }
};

/* INTUITIVE OPTIMIZATION - THINK CAREFULLY WHAT WE ARE TRYING TO FIND AND WHAT ARE ACTUALLY NEEDED TO FIND IT */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        if (ops.empty()) { return m*n; }
        
        int minX = INT_MAX, minY = INT_MAX;
        for (auto op : ops) {
            minX = min(minX,op[0]);
            minY = min(minY,op[1]);
        }

        return minX*minY;
    }
};