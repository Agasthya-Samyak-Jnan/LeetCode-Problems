#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH - ALWAYS EXPLORE SAME CELLS AGAIN IF YOU REACH THEM WITH A BETTER HEALTH VALUE THAN HEALTH VALUE IN PREVIOUS VISIT TO THE SAME CELL. */
class Solution {
    public:
        vector<int> drx = {-1,0,1,0};
        vector<int> dry = {0,-1,0,1};
    
        bool findSafeWalk(vector<vector<int>>& g, int health) {
    
            int m = g.size(), n = g[0].size();
            queue<vector<int>> q;
            vector<vector<int>> visited(m,vector<int>(n,0));
    
            q.push({health,0,0});
    
            while (!q.empty()) {
    
                int health = q.front()[0], x = q.front()[1], y = q.front()[2]; q.pop();
    
                health -= g[x][y];
    
                if (health < 1) { continue; }
                if (x == m-1 and y == n-1) { return true; }
    
                for (int i=0;i<4;i++) {
                    int dx = x+drx[i], dy = y+dry[i];
                    if (dx >= 0 and dy >= 0 and dx < m and dy < n and visited[dx][dy] < health) {
                        q.push({health,dx,dy});
                        visited[dx][dy] = health;
                    }
                }
    
            }
    
            return false;
        }
};