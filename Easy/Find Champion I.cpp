#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-champion-i/
// Difficulty : Easy

/* TC : O(N)  , SC : O(1) */
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int i = 0, j = 1, n = grid.size();       
        while (i<n) {
            if (!grid[i][j] && i!=j) { i++; }
            else if (j<n-1) { j++; }
            else { return i; }
        }
        return 0;          
    }
};