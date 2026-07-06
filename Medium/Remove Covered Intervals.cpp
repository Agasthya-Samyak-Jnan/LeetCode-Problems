#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-covered-intervals/
// Difficulty : Medium

/* 
    SORTING + TWO POINTERS : Sort the intervals and then check for covered intervals. 
    If an interval covers another interval, check if same interval covers upcoming intervals, otherwise move on to check next pair of intervals.
*/

/* This solution always keeps 'j' ahead of 'i' pointer. You can swap the variables accordingly to keep 'i' pointer ahead of 'j'. */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intv) {

        int n = intv.size(), removed = 0, i = 0, j = 1; 

        sort(intv.begin(),intv.end());

        while (i<n and j<n) {
            if (intv[i][0] <= intv[j][0] and intv[j][1] <= intv[i][1]) {
                j++;
                removed++;
            }
            else if (intv[j][0] <= intv[i][0] and intv[i][1] <= intv[j][1]) {
                swap(i,j);
                j++;
                removed++;
            }
            else { i = j; }
            if (i == j) { j++; }
        }
        
        return (n - removed);
    }
};

/* This solution keeps either 'i' or 'j' pointer ahead, depending on input testcase. */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intv) {

        int n = intv.size(), removed = 0, i = 0, j = 1; 

        sort(intv.begin(),intv.end());

        while (i<n and j<n) {
            if (intv[i][0] <= intv[j][0] and intv[j][1] <= intv[i][1]) {
                j++;
                removed++;
            }
            else if (intv[j][0] <= intv[i][0] and intv[i][1] <= intv[j][1]) {
                i++;
                removed++;
            }
            else {
                if (i < j) { i = j; j++; }
                else { j = i; i++; }
            }
            if (i == j) { j++; }
        }
        
        return (n - removed);
    }
};