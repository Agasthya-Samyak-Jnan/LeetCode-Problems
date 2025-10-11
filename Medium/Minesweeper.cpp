#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minesweeper
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> drxns = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int m, n;

    // Utility to avoid exploring out-of-bounds 
    bool out_of_bounds (int x, int y) { return (x<0 or y<0 or x>=m or y>=n); }

    void dfs (vector<vector<char>>& board, vector<int> click) {
        
        // Clicked on Unrevealed Mine
        if (board[click[0]][click[1]] == 'M') { board[click[0]][click[1]] = 'X'; }
        
        // Clicked on Unrevealed Empty Cell
        else if (board[click[0]][click[1]] == 'E') {
            
            int adj_mines = 0;
            for (auto dx : drxns) { 
                if (!out_of_bounds(click[0]+dx[0],click[1]+dx[1])) {
                    adj_mines += (board[click[0]+dx[0]][click[1]+dx[1]] == 'M'); 
                }
            }

            // Adjacent Mines Present
            if (adj_mines > 0) {
                board[click[0]][click[1]] = ('0'+adj_mines);
            }
            // No Adjacent Mines
            else {
                board[click[0]][click[1]] = 'B';
                for (auto dx : drxns) { 
                    if (!out_of_bounds(click[0]+dx[0],click[1]+dx[1])) {
                        dfs(board,{click[0]+dx[0],click[1]+dx[1]}); 
                    }
                }
            }

        }

        // Already Revealed Blank Cell with or without adjacent Mines , simply return
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        dfs(board,click);
        return board;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> drxns = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int m, n;

    // Utility to avoid exploring out-of-bounds 
    bool out_of_bounds (int x, int y) { return (x<0 or y<0 or x>=m or y>=n); }

    void bfs (vector<vector<char>>& board, vector<int> click) {

        queue<vector<int>> q;

        q.push(click);
        
        while (!q.empty()) {

            click = q.front(); q.pop();

            // Clicked on Unrevealed Mine
            if (board[click[0]][click[1]] == 'M') { board[click[0]][click[1]] = 'X'; }
            
            // Clicked on Unrevealed Empty Cell
            else if (board[click[0]][click[1]] == 'E') {
                
                int adj_mines = 0;
                for (auto dx : drxns) { 
                    if (!out_of_bounds(click[0]+dx[0],click[1]+dx[1])) {
                        adj_mines += (board[click[0]+dx[0]][click[1]+dx[1]] == 'M'); 
                    }
                }

                // Adjacent Mines Present
                if (adj_mines > 0) {
                    board[click[0]][click[1]] = ('0'+adj_mines);
                }
                // No Adjacent Mines
                else {
                    board[click[0]][click[1]] = 'B';
                    for (auto dx : drxns) { 
                        if (!out_of_bounds(click[0]+dx[0],click[1]+dx[1])) {
                            q.push({click[0]+dx[0],click[1]+dx[1]}); 
                        }
                    }
                }

            }

            // Already Revealed Blank Cell with or without adjacent Mines , simply return

        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        bfs(board,click);
        return board;
    }
};