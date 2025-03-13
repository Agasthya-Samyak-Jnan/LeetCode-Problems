#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/battleships-in-a-board/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH FOR MARKING BATTLESHIPS FOUND */
class Solution {
    public:
        vector<vector<char>> b;
        int m,n;
        vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
    
        void dfs (int i, int j) {
            if (i>=m or j>= n or i<0 or j<0) { return; }
            b[i][j] = '.';
            for (int k=0;k<4;k++) {
                if (i+dx[k] < m and j+dy[k] < n and i+dx[k] >= 0 and j+dy[k] >= 0 and b[i+dx[k]][j+dy[k]] == 'X') {
                    dfs(i+dx[k],j+dy[k]);
                }
            }
        }
    
        int countBattleships(vector<vector<char>>& board) {
            
            b = board;
            m = b.size(), n = b[0].size();
            int battleships = 0;
    
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (b[i][j] == 'X') {
                        dfs(i,j);
                        battleships++;
                    }
                }
            }
    
            return battleships;
        }
};
