#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/champagne-tower/
// Difficulty : Medium

/* SIMULATION */
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        int r = 0;
        vector<vector<double>> glasses(101, vector<double>(101,0)); // 101 is problem constraint limiting "query_glass" value to 100
        glasses[0][0] = poured;

        while (r < query_row) {
            for (int i=0;i<=r;i++) {
                double overflow_per_glass = max(glasses[r][i]-1,0.0)/2;
                glasses[r+1][i] += overflow_per_glass;
                glasses[r+1][i+1] += overflow_per_glass;
            }
            r++;
        }
        
        return min(1.0,glasses[query_row][query_glass]);
    }
};

/* SIMULATION OPTIMIZED : YOU NEED PRESENT ROW TO CALCULATE AND NEXT ROW TO STORE RESULTS - ONLY 2 ROWS ARE ENOUGH */
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        int r = 0;
        vector<vector<double>> glasses(2, vector<double>(101,0)); // 101 is problem constraint limiting "query_glass" value to 100
        glasses[0][0] = poured;

        while (r < query_row) {
            for (int i=0;i<=min(r,query_glass);i++) {
                double overflow_per_glass = max(glasses[0][i]-1,0.0)/2;
                glasses[1][i] += overflow_per_glass;
                glasses[1][i+1] += overflow_per_glass;
            }
            glasses[0] = glasses[1];
            glasses[1] = vector<double>(101,0);
            r++;
        }
        
        return min(1.0,glasses[0][query_glass]);
    }
};

/* 
   SIMULATION FURTHER OPTIMIZED : OTHER THAN NEEDING ONLY 2 ROWS,
   YOU NEED TO CALCULATE ONLY UPTO "query_glass" glasses in each row - glasses beyond don't contribute to our glass.
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        int r = 0;
        vector<vector<double>> glasses(2, vector<double>(query_glass+2,0));
        glasses[0][0] = poured;

        while (r < query_row) {
            for (int i=0;i<=min(r,query_glass);i++) {
                double overflow_per_glass = max(glasses[0][i]-1,0.0)/2;
                glasses[1][i] += overflow_per_glass;
                glasses[1][i+1] += overflow_per_glass;
            }
            glasses[0] = glasses[1];
            glasses[1] = vector<double>(query_glass+2,0);
            r++;
        }
        
        return min(1.0,glasses[0][query_glass]);
    }
};

/* 
    SIMULATION FURTHER MORE OPTIMIZED : We don't even need "query_glass" glasses in each row of calculation until we reach "query_glass" sized row.
    Stopped using unnecessary space.
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        int r = 0;
        vector<vector<double>> glasses(2, vector<double>(r+2,0));
        glasses[0][0] = poured;

        while (r < query_row) {
            for (int i=0;i<=min(r,query_glass);i++) {
                double overflow_per_glass = max(glasses[0][i]-1,0.0)/2;
                glasses[1][i] += overflow_per_glass;
                glasses[1][i+1] += overflow_per_glass;
            }
            r++;
            glasses[0] = glasses[1];
            glasses[1] = vector<double>(min(r+2,query_glass+2),0);
        }
        
        return min(1.0,glasses[0][query_glass]);
    }
};