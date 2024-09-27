#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-queens-ii/
// Difficulty : Hard

/* The DUMBED DOWN VERSION of BACKTRACKING SOLUTION FOR N-QUEENS PROBLEM */
/* REMOVED THE ACTUAL BOARD WHICH WAS USED TO ACTUALLY SHOW QUEEN PLACEMENTS */
/* OPTIMIZED TIME ANS SPACE SINCE ONLY COUNTING IS NEEDED */
class Solution {
    public:
    vector<int> col,dia,a_dia;
    int n,ans;

    void mark_and_place (int i, int j) {
        col[j] = 1;
        dia[i+j] = 1;
        a_dia[i-j+(n-1)] = 1;
    }
    
    void unmark_and_remove (int i, int j) {
        col[j] = 0;
        dia[i+j] = 0;
        a_dia[i-j+(n-1)] = 0;
    }

    void solve (int i) {

        if (i==n) { 
            ans++;
            return; 
        }

        for (int j=0;j<n;j++) {
            if (col[j] == 0 && dia[i+j] == 0 && a_dia[i-j+(n-1)] == 0) {
                mark_and_place(i,j);
                solve(i+1);
                unmark_and_remove(i,j);
            }
        }

    }

    int totalNQueens(int n) {

        this->n = n;
        col = vector<int>(n,0);
        a_dia = dia = vector<int>(2*n-1,0);
        ans = 0;

        solve(0);

        return ans;
    }

};