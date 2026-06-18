#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insert-interval/
// Difficulty : Medium

/* CAREFUL BRUTE FORCE - FIND WHERE TO INSERT NEW INTERVAL FIRST AND THEN START MERGING INTERVALS FROM POINT OF INSERTION. */

/* FIRST BAD SOLUTION */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newintv) {

        if (intv.empty()) { return {newintv}; }
        
        vector<vector<int>> ans;
        int n = intv.size();
        int i = 0;

        while (i<n) {
            if (intv[i][0] <= newintv[0] and newintv[0] <= intv[i][1]) {
                if (intv[i][1] < newintv[1]) { ans.push_back({intv[i][0],newintv[1]}); }
                else { ans.push_back(intv[i]); }
                i++;
                break;
            }
            else if (newintv[0] < intv[i][0]) {
                ans.push_back(newintv);
                break;
            }
            else {
                ans.push_back(intv[i]);
                i++;
            }
        }

        if (i>=n and ans.back()[1] < newintv[0]) { ans.push_back(newintv); }

        while (i<n) {

            if (ans.back()[1] < intv[i][0]) {
                ans.push_back(intv[i]);
                i++;
            }
            else {
                if (intv[i][1] <= ans.back()[1]) { i++; } 
                else { ans.back()[1] = intv[i][1]; i++; } 
            }

        }

        return ans;
    }
};

/* REDUCED CODE SOLUTION */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newintv) {
        
        vector<vector<int>> ans;
        int n = intv.size();
        int i = 0;

        while (i<n) {
            if (intv[i][1] < newintv[0]) {
                ans.push_back(intv[i]);
                i++;
            }
            else {
                if (newintv[0] < intv[i][0]) { ans.push_back(newintv); }
                else {
                    if (intv[i][1] < newintv[1]) { ans.push_back({intv[i][0],newintv[1]}); } // Merge new interval with previous interval if possible before pushing to 'ans'
                    else { ans.push_back(intv[i]); }
                    i++;
                }
                break;
            }
        }

        if (i>=n and (ans.empty() or ans.back()[1] < newintv[0])) { ans.push_back(newintv); }

        while (i<n) {
            if (ans.back()[1] < intv[i][0]) { ans.push_back(intv[i]); }
            else if (ans.back()[1] < intv[i][1]) { ans.back()[1] = intv[i][1]; } 
            i++;
        }

        return ans;
    }
};