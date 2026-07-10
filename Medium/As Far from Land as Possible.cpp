#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/as-far-from-land-as-possible/
// Difficulty : Medium

/* LEVEL-ORDERED BREADTH-FIRST SEARCH to find distance or steps needed for anything in matrices and unweighted graphs. */
class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {

        int m = g.size(), n = g[0].size(), dist = 0;
        queue<pair<int,int>> q;
        vector<vector<int>> drxns = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> visited(m,vector<int>(n,0));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 1) { 
                    q.push({i,j}); 
                    visited[i][j] = 1;
                }
            }
        }
        
        while (!q.empty()) {
            int l = q.size();
            for (int k=0;k<l;k++) {
                auto [i,j] = q.front(); q.pop();
                for (auto d : drxns) {
                    int di = i + d[0], dj = j + d[1];
                    if (di>=0 and dj>=0 and di<m and dj<n and !visited[di][dj]) {
                        q.push({di,dj});
                        visited[di][dj] = 1;
                    }
                }
            }
            dist++;
        }

        return dist-1-(dist-1 == 0);
    }
};