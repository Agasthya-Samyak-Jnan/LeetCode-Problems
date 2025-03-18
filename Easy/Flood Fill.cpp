#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flood-fill/
// Difficulty : Easy

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            
            queue<pair<int,int>> q;
            vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
            int start_color = image[sr][sc], m = image.size(), n = image[0].size();
            q.push({sr,sc});
            image[sr][sc] = color;
    
            if (start_color == color) { return image; }
    
            q.push({sr,sc});
    
            while (!q.empty()) {
                auto [x,y] = q.front(); q.pop();
                for (int k=0;k<4;k++) {
                    if (x+dx[k] >= 0 and y+dy[k] >= 0 and x+dx[k] < m and y+dy[k] < n and image[x+dx[k]][y+dy[k]] == start_color) {
                        q.push({x+dx[k],y+dy[k]});
                        image[x+dx[k]][y+dy[k]] = color;
                    }
                }
            }
    
            return image;
        }
};

/* DEPTH-FIRST SEARCH */
class Solution {
    public:
        int m,n,start_color,color;
        vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
    
        void dfs (vector<vector<int>>& image, int i, int j) {
            if (i < 0 or j < 0 or i >= m or j >= n or image[i][j] != start_color) { return; }
            image[i][j] = color;
            for (int k=0;k<4;k++) { dfs(image,i+dx[k],j+dy[k]); }
        }
    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            
            m = image.size();
            n = image[0].size();
            start_color = image[sr][sc];
            this->color = color;
    
            if (start_color == color) { 
                image[sr][sc] = color;
                return image; 
            }
            dfs(image,sr,sc);
    
            return image;
        }
};