#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Difficulty : Hard

/* PRIORITY QUEUE TO ORDER TREES FROM SHORTEST TO TALLEST (MIN HEAP) + BREADTH-FIRST SEARCH FOR FINDING SHORTEST PATH BETWEEN TREES. */
class Solution {
    public:
        vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
        vector<vector<int>> forest;
        int m,n;
    
        /* Breadth-first Search to find shortest path between two positions in forest. */
        int minSteps (pair<int,int> start, pair<int,int> dest) {
    
            int steps = 0;
            queue<pair<int,int>> q;
            vector<vector<int>> visited(m,vector<int>(n,0));
    
            q.push(start);
            visited[start.first][start.second] = 1;
    
            while (!q.empty()) {
    
                int l = q.size();
        
                for (int k=0;k<l;k++) {
                    
                    auto [x,y] = q.front(); q.pop();
                    // When you reached Destination Tree Position, return number of steps taken from 'start'.
                    if (x == dest.first and y == dest.second) { return steps; }
    
                    for (int i=0;i<4;i++) {
                        /* 
                            Don't Visit the following :
                            1. Out-of-Bounds Positions (Negative indices or indices beyond forest size)
                            2. Positions you can't walk through (forest[i][j] == 0 positions)
                            3. Positions you already walked through Before (visited positions)
                        */
                        if (x+dx[i] >= 0 and y+dy[i] >= 0 and x+dx[i] < m and y+dy[i] < n and forest[x+dx[i]][y+dy[i]] != 0 and visited[x+dx[i]][y+dy[i]] == 0) { 
                            q.push({x+dx[i],y+dy[i]}); 
                            visited[x+dx[i]][y+dy[i]] = 1;
                        }
                    }
                }
    
                steps++;
            }
    
            return -1;
        }
    
        int cutOffTree(vector<vector<int>>& forest) {
            
            // Global Variables needed.
            this->forest = forest;
            m = forest.size();
            n = forest[0].size();
            int total_steps = 0, steps;

            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            pair<int,int> curr_pos = {0,0}, next_dest;  // Start from (0,0).
            
            // Ordering Trees from Shortest to Tallest by pushing onto Min Heap.
            // Each Heap Entry : {Height of Tree, X-position, Y-position} - Heap ALWAYS maintains Shortest Tree on TOP.
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (forest[i][j] > 1) { pq.push({forest[i][j],i,j}); }
                }
            }
            
            // Start calculating total steps.
            do {
                next_dest = {pq.top()[1],pq.top()[2]}; // Position of next tree to be cut is always on TOP of Min Heap.
                steps = minSteps(curr_pos,next_dest); // Find minimum steps to take from your current position (curr_pos) to next shortest tree.
                if (steps != -1) {  // If Tree is Reachable,
                    total_steps += steps; // Add steps taken.
                }
                else { return -1; } // If a Tree is Unreachable , it is impossible to prepare the forest for Golf. RETURN -1.
                curr_pos = {pq.top()[1],pq.top()[2]}; pq.pop(); // The Tree you cut just now is your current position in forest.
            } while (!pq.empty()); // Stop after cutting all Trees.
    
            return total_steps;
        }
};