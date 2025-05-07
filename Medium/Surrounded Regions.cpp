#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/surrounded-regions/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH */
class Solution {
    public:
        int m,n;

        // Find all cells in this Border connecting Region and Mark them.
        void dfs (int i, int j, vector<vector<char>>& b, vector<vector<int>>& visited) {
            if (i<0 or j<0 or i>=m or j>=n or b[i][j] == 'X' or visited[i][j]) { return; }
            visited[i][j] = 1;
            dfs(i+1,j,b,visited); // Up
            dfs(i,j+1,b,visited); // Right
            dfs(i-1,j,b,visited); // Down
            dfs(i,j-1,b,visited); // Left
        }
    
        void solve(vector<vector<char>>& board) {
            
            m = board.size();
            n = board[0].size();
            vector<vector<int>> visited(m,vector<int>(n,0));
            
            // Mark Border Bottom and Top Row connected regions.
            for (int j=0;j<n;j++) {
                dfs(0,j,board,visited);
                dfs(m-1,j,board,visited);
            }
            
            // Mark Border Leftmost and Rightmost Column connected regions.
            for (int i=0;i<m;i++) {
                dfs(i,0,board,visited);
                dfs(i,n-1,board,visited);
            }
            
            // Now, unvisited 'O' cells are those that can't be reached by border connecting regions, hence can be surrounded.
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (board[i][j] == 'O' and !visited[i][j]) { board[i][j] = 'X'; }
                }
            }
    
        }
};

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        int m,n;
        vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
    
        void bfs (int i, int j, vector<vector<char>>& b, vector<vector<int>>& visited) {
    
            if (b[i][j] != 'O') { return; }
    
            queue<pair<int,int>> q;
    
            q.push({i,j});
            visited[i][j] = 1;
    
            while (!q.empty()) {
    
                auto [i,j] = q.front(); q.pop();
    
                for (int k=0;k<4;k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x>=0 and y>=0 and x<m and y<n and b[x][y] == 'O' and !visited[x][y]) {
                        visited[x][y] = 1;
                        q.push({x,y});
                    }
                }
                
            }
        }
    
        void solve(vector<vector<char>>& board) {
            
            m = board.size();
            n = board[0].size();
            vector<vector<int>> visited(m,vector<int>(n,0));
    
            for (int j=0;j<n;j++) {
                bfs(0,j,board,visited);
                bfs(m-1,j,board,visited);
            }
    
            for (int i=0;i<m;i++) {
                bfs(i,0,board,visited);
                bfs(i,n-1,board,visited);
            }
    
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (board[i][j] == 'O' and !visited[i][j]) { board[i][j] = 'X'; }
                }
            }
    
        }
};