#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-with-maximum-gold/
// Difficulty : Medium 

/* BACKTRACKING AS DEPTH-FIRST SEARCH */
class Solution {
    public:
        int m,n;
        vector<vector<int>> mine;
    
        int dfs (int i, int j) {
            
            // Out-of-Bounds or Visited Cell (Use 0 to mark all cells that you don't want to go and those already visited - save space used to maintain visited cells table)
            if (i >= m or j >= n or i < 0 or j < 0 or mine[i][j] == 0) { return 0; }
    
            int ans = 0;
    
            swap(ans,mine[i][j]); // Mark as Visited
            int dirs[4] = {dfs(i,j-1),dfs(i,j+1),dfs(i-1,j),dfs(i+1,j)}; // Left,Right,Up,Down
            swap(ans,mine[i][j]); // Unmark 
            
            for (auto& i : dirs) { ans = max(ans,i); } // Find possible maximum gold.
            
            return mine[i][j] + ans;
        }
    
        int getMaximumGold(vector<vector<int>>& mine) {
    
            m = mine.size();
            n = mine[0].size();
            this->mine = mine;
            int ans = 0;
    
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (mine[i][j] > 0) {
                        ans = max(ans,dfs(i,j));
                    }
                }
            }
    
            return ans;
        }
};