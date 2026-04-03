#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/game-of-life/
// Difficulty : Medium

/* SIMULATION (This can be solved without using extra space in 2 manual passes, by using any type of encoding and extra computation to get old and new state from encoded format of cell value.)*/
// This solution uses extra space to store new state of board and completes in 1 manual pass.
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size(), n = board[0].size();
        vector<vector<int>> drxns = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}}; // All 8 directions.
        vector<vector<int>> updated(m, vector<int>(n));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int live_neighbors = 0, dx, dy;
                // Count live neighbor cells to this current cell. (0-8)
                for (auto d : drxns) {
                    dx = i + d[0], dy = j + d[1];
                    if (dx>=0 and dy>=0 and dx<m and dy<n) { live_neighbors += (board[dx][dy] == 1); }
                }
                // Rules to update existing dead cell
                if (board[i][j] == 0) { updated[i][j] = (live_neighbors == 3); }
                // Rules to update existing live cell
                else { updated[i][j] = (live_neighbors > 1 and live_neighbors < 4); }
            }
        }

        board = updated; // This is actually another pass, but assignment operations are quite optimized for vectors in comupters so it will be much faster.
        
    }
};