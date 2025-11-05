#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
// Difficulty: Medium

using namespace std;

/* DYNAMIC PROGRAMMING SOLUTION */

/* PURE RECURSION - BACKTRACKING SOLUTION - TRY ALL POSSIBLE SELECTIONS/COMBINATIONS OF NUMBERS FROM EACH ROW */
class Solution {
public:
    int m, n, t, minDiff = INT_MAX;
    vector<vector<int>> mat;

    void solve (int row, int sum) {
        if (row == m) { 
            minDiff = min(minDiff,abs(sum-t)); 
            return; 
        }
        for (int i=0;i<n;i++) { solve(row+1,sum+mat[row][i]); }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        m = mat.size();
        n = mat[0].size();
        t = target;
        this->mat = mat;

        solve(0,0);

        return minDiff;
    }
};

/* RECURSION WITH CACHING (2D MEMOIZATION)
   - SUM OF NUMBERS UNTIL CURRENT SELECTION ROW CAN REPEAT IN THAT ROW MULTIPLE TIMES BY DIFFERENT SELECTION OF NUMBERS IN PREVIOUS ROWS.
   - THE FUTURE RESULT BY SELECTION BEYOND THIS ROW AT THIS SUM WOULD BE SAME FOR ALL POSSIBLE SELECTIONS OF PREVIOUS NUMBERS THAT BUILD THIS SUM.
   - HENCE, IF YOU COME ACROSS SAME SUM WHILE SELECTING AT A SPECIFIC ROW MORE THAN ONCE, YOU NEED NOT COMPUTE IT AGAIN, JUST RETURN. (i.e PRUNE THE SEARCH IF IT REPEATS, DRAW SEARCH TREE TO UNDERSTAND) 
*/
class Solution {
public:
    int m, n, t, minDiff = INT_MAX;
    vector<vector<int>> mat;
    vector<vector<int>> done;

    void solve (int row, int sum) {
        if (done[row][sum]) { return; }
        done[row][sum] = 1;
        if (row == m) { minDiff = min(minDiff,abs(sum-t)); return; }
        for (int i=0;i<n;i++) { solve(row+1,sum+mat[row][i]); }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        m = mat.size();
        n = mat[0].size();
        t = target;
        this->mat = mat;
        done = vector<vector<int>>(71, vector<int>(4901,0));

        solve(0,0);

        return minDiff;
    }
};