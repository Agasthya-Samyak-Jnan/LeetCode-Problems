#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/snakes-and-ladders/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH AND BOUSTROPHEDON GRIDS */
class Solution {
public:
    
    // Boustrophedon Grid Position Calculator.
    array<int,2> get_pos (int i, int n) {
        int row = (n-1) - (i-1)/n;
        int col = (((i-1)/n)%2 == 0) ? (i-1)%n : (n-1) - (i-1)%n;
        return {row,col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size(),moves = 0;
        vector<int> pos,visited(n*n+1,0);
        
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        
        while (!q.empty()) {
            
            int l = q.size();
            
            for (int j=0;j<l;j++) {
                
                int curr = q.front(); q.pop();
                
                // Win Case
                if (curr == n*n) { return moves; }
                
                // Dice Roll
                for (int d=1;d<=6 && curr+d<=n*n;d++) {
                    auto [row,col] = get_pos(curr+d,n);
                    int next = board[row][col];
                    
                    if (!visited[curr+d]) {
                        visited[curr+d] = 1;
                        if (next == -1) { q.push(curr+d); } // Normal Cell
                        else { q.push(next); } // Snake or Ladder Cell
                    } 
                }
                       
            }
        
            moves++;
        }
        
        return -1;
    }
};