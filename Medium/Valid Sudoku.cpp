#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-sudoku/
// Difficulty : Medium



/* SOLUTION STEP - BY - STEP IMPROVEMENTS */

/* ITERATION - 4 --> LOOK BELOW TO SEE HOW I ARRIVED AT AND IMPROVISED SOLUTION STEP - BY - STEP */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rmp[9][9] = {0};
        int cmp[9][9] = {0};
        int subbox[3][3][9] = {0};
        
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (rmp[i][k-1]++ || cmp[j][k-1]++ || subbox[i/3][j/3][k-1]++) { return false; }
                }
            }
        }
    
        return true; 
    }
};

/* - - - ITERATION 1 - - -
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<pair<int,int>>> pos(10);
        unordered_map<int,int> rmp;
        unordered_map<int,int> cmp;
        
        // Memorize Positions of all Occurences of each number.
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') { pos[board[i][j]-'0'].push_back({i,j}); }
            }
        }
        
        // Validation Part
        for (int i=1;i<10;i++) {
            vector<vector<int>> in_sub_box(3,vector<int>(3,0));
            for (auto p : pos[i]) {
                // Row Check
                if (rmp[p.first]) { return false; }
                rmp[p.first] = 1;
                // Column  Check
                if (cmp[p.second]) { return false; }
                cmp[p.second] = 1;
                // Sub-Box Check
                if (in_sub_box[p.first/3][p.second/3]) { return false; }
                in_sub_box[p.first/3][p.second/3] = 1;
            }
            rmp.clear();
            cmp.clear();
        }
        
        return true; 
    }
};
*/

/*  - - - ITERATION 2 - - - 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<pair<int,int>>> pos(10);
        int rmp[9], cmp[9];

        // Memorize Positions of all Occurences of each number.
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') { pos[board[i][j]-'0'].push_back({i,j}); }
            }
        }
        
        // Validation Part
        for (int i=1;i<10;i++) {
            
            vector<vector<int>> in_sub_box(3,vector<int>(3,0));
            memset(rmp,0,sizeof(rmp));
            memset(cmp,0,sizeof(cmp));
            
            for (auto p : pos[i]) {
                // Row Check
                if (rmp[p.first]) { return false; }
                rmp[p.first] = 1;
                // Column  Check
                if (cmp[p.second]) { return false; }
                cmp[p.second] = 1;
                // Sub-Box Check
                if (in_sub_box[p.first/3][p.second/3]) { return false; }
                in_sub_box[p.first/3][p.second/3] = 1;
            }
        }
        
        return true; 
    }
};
*/

/* - - - ITERATION 3 - - - 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> rmp(10,vector<int>(10,0));
        vector<vector<int>> cmp(10,vector<int>(10,0));
        vector<vector<vector<int>>> subbox(3,vector<vector<int>>(3,vector<int>(10,0)));
        
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') {
                    
                    int k = board[i][j] - '0';
                    
                    if (rmp[i][k]) { return false; }
                    rmp[i][k] = 1;
                    
                    if (cmp[j][k]) { return false; }
                    cmp[j][k] = 1;
                    
                    if (subbox[i/3][j/3][k]) { return false; }
                    subbox[i/3][j/3][k] = 1;
                }
            }
        }
    
        return true; 
    }
};

*/
