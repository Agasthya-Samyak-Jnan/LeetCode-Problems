#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/equal-sum-grid-partition-i/
// Difficulty : Medium

/* OPTIMIZED BRUTE FORCE WITH PREFIX SUMS : CHECK ALL POSSIBLE HORIZONTAL AND VERTICAL SPLITS BY PRECOMPUTING ROW AND COLUMN SUMS. */
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        long total = 0;
        vector<long> rsum(m,0), csum(n,0);

        for (int i=0;i<m;i++) {
            if (i > 0) { rsum[i] += rsum[i-1]; }
            for (int j=0;j<n;j++) {
                rsum[i] += grid[i][j];
                csum[j] += grid[i][j];
                if (i == m-1 and j > 0) { csum[j] += csum[j-1]; }
            }
        }

        total = rsum[m-1]; // or total = csum[n-1], both are same.

        //

        if (total % 2 == 1) { return false; }

        for (int i=0;i<m-1;i++) {
            if (rsum[i] == total-rsum[i]) { return true; }
        }

        for (int j=0;j<n-1;j++) {
            if (csum[j] == total-csum[j]) { return true; }
        }

        return false;
    }
};

/* ABOVE SOLUTION BUT A BIT MORE OPTIMIZED : 
   IF ROWS' SUM OR COLUMNS' SUM GOES ABOVE HALF OF TOTAL (WHICH IS NEEDED FOR EQUAL SPLIT),
   STOP CHECKING FURTHER ROWS/COLUMNS. 
*/
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        long total = 0;
        vector<long> rsum(m,0), csum(n,0);

        for (int i=0;i<m;i++) {
            if (i > 0) { rsum[i] += rsum[i-1]; }
            for (int j=0;j<n;j++) {
                rsum[i] += grid[i][j];
                csum[j] += grid[i][j];
                if (i == m-1 and j > 0) { csum[j] += csum[j-1]; }
            }
        }

        total = rsum[m-1]; // or total = csum[n-1], both are same.

        //

        if (total % 2 == 1) { return false; }

        for (int i=0;rsum[i] <= total/2;i++) {
            if (rsum[i] == total-rsum[i]) { return true; }
        }

        for (int j=0;csum[j] <= total/2;j++) {
            if (csum[j] == total-csum[j]) { return true; }
        }

        return false;
    }
};