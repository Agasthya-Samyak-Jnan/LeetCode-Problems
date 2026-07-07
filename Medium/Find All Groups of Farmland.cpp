#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-all-groups-of-farmland/
// Difficulty : Medium

/* Exploring MATRIX like a GRAPH */

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> visited;
    vector<vector<int>> drxns = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<int> searchCorners (int a, int b) {

        queue<pair<int,int>> q;
        vector<int> limits = {a,b,a,b};

        q.push({a,b});
        visited[a][b] = 1;

        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            limits = {min(limits[0],i),min(limits[1],j),max(limits[2],i),max(limits[3],j)};
            for (auto d : drxns) {
                int di = i + d[0], dj = j + d[1];
                if (di>=0 and dj>=0 and di<m and dj<n and g[di][dj] == 1 and !visited[di][dj]) {
                    q.push({di,dj});
                    visited[di][dj] = 1;
                }
            }
        }
        
        return limits;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        m = land.size(), n = land[0].size();
        g = land;
        visited = vector<vector<int>>(m,vector<int>(n,0));
        vector<vector<int>> landLimits;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 1 and !visited[i][j]) { landLimits.push_back(searchCorners(i,j)); }
            }
        }

        return landLimits;
    }
};

/* DEPTH-FIRST SEARCH - ITERATIVE */
class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> visited;
    vector<vector<int>> drxns = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<int> searchCorners (int a, int b) {

        stack<pair<int,int>> s;
        vector<int> limits = {a,b,a,b};

        s.push({a,b});
        visited[a][b] = 1;

        while (!s.empty()) {
            auto [i,j] = s.top(); s.pop();
            limits = {min(limits[0],i),min(limits[1],j),max(limits[2],i),max(limits[3],j)};
            for (auto d : drxns) {
                int di = i + d[0], dj = j + d[1];
                if (di>=0 and dj>=0 and di<m and dj<n and g[di][dj] == 1 and !visited[di][dj]) {
                    s.push({di,dj});
                    visited[di][dj] = 1;
                }
            }
        }
        
        return limits;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        m = land.size(), n = land[0].size();
        g = land;
        visited = vector<vector<int>>(m,vector<int>(n,0));
        vector<vector<int>> landLimits;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 1 and !visited[i][j]) { landLimits.push_back(searchCorners(i,j)); }
            }
        }

        return landLimits;
    }
};