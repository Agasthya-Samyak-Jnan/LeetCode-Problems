#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sudoku-solver/
// Difficulty : Hard

/* BACKTRACKING + HASH TABLE */
/* Ideas Used Here:
   1. Search Pruning by checking Hash Table if number has previously occured in Row or Column or Sub-Matrix.
   2. Handling propogation of return values in recursive function calls moving upwards.
   3. Handling changes in board state and Hash Table State - BACKTRACKING.
*/

/* Time Complexity : m*n + 9^(m*n) => O (9^(m*n)) (Here, m = n = 9) but it will be a lot less because,
   1. We don't check combinations for a number if it repeated in row OR column OR submatrix.
   2. Some cells will be filled in given input, so we need not check all m*n cells.
*/

class Solution {
public:
    int rmp[9][10] = {0}; // rmp[i][n] = 1 means number 'n' has occured in 'i'th row.
    int cmp[9][10] = {0}; // cmp[i][n] = 1 means number 'n' has occured in 'i'th column.
    int subbox[3][3][10] = {0}; // subbox[i/3][j/3][n] = 1 means 'n' has occured in (i/3,j/3)th sub-matrix in board.
    
    bool solve (vector<vector<char>>& b, int i, int j) {
        
        
        // To check Output
        // cout<<"\n - - - - \n\n";
        
        // for (auto i : b) {
        //     for (auto j : i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        // End-of-Board Reached - Completely Solved.
        if (i == 9) { return true; }
        
        // Out-of-Bounds - go to next row.
        if (j == 9) { return solve(b,i+1,0); }
        
        // IF this is an EMPTY cell, try out all solution combinations that have all possible numbers in this cell.
        if (b[i][j] == '.') {
            for (int k=1;k<=9;k++) {
                if (rmp[i][k] == 0 && cmp[j][k] == 0 && subbox[i/3][j/3][k] == 0) {
                    // Try this Number in this cell.
                    b[i][j] = '0' + k;
                    // Mark it as used.
                    rmp[i][k] = 1;
                    cmp[j][k] = 1;
                    subbox[i/3][j/3][k] = 1;
                    // Try solving this combination. DO NOT GO TO NEXT BACKTRACKING STEPS IF SOLUITON STATE OF BOARD IS ATTAINED, HENCE RETURN IMMEDIATELY AND PROPOGATE SAME TO PREVIOUS FUNCTION CALLS.
                    if (j<8) {  if(solve(b,i,j+1)) { return true;  } }
                    else if (solve(b,i+1,0)) { return true; }
                    // If didn't find a solution, unmark this number and cell.
                    b[i][j] = '.';
                    // Unamrk it as its not used now. (BACKTRACKING)
                    rmp[i][k] = 0;
                    cmp[j][k] = 0;
                    subbox[i/3][j/3][k] = 0;
                 }
            }
        }
        // Continue to next cell, if this cell has numbers already.
        else { return solve(b,i,j+1); }
        
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& b) {
        
        // Memorize Starting State of Board.
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (b[i][j] != '.') {
                    int k = b[i][j] - '0';
                    rmp[i][k] = 1;
                    cmp[j][k] = 1;
                    subbox[i/3][j/3][k] = 1;
                }
            }
        }
        
        // Solve the Board in-place.
        solve(b,0,0);
        
    }
};

// TESTER CODE 
int main () {

    Solution a;
    vector<vector<char>> board = 
 {{'5','3','.','.','7','.','.','.','.'},
 {'6','.','.','1','9','5','.','.','.'},
 {'.','9','8','.','.','.','.','6','.'},
 {'8','.','.','.','6','.','.','.','3'},
 {'4','.','.','8','.','3','.','.','1'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','6','.','.','.','.','2','8','.'},
 {'.','.','.','4','1','9','.','.','5'},
 {'.','.','.','.','8','.','.','7','9'}};

    a.solveSudoku(board);

    cout<<"\n - - - - \n\n";
        
    for (auto i : board) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }

}