#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/detonate-the-maximum-bombs/
// Difficulty : Medium

/* DEPTH-FIRST SEARCH */
class Solution {
public:

    // Checks if 'a' is in range of 'bomb'
    bool inRangeOf (vector<int>& bomb, vector<int>& a) {
        return (sqrt(pow(bomb[0]-a[0],2)+pow(bomb[1]-a[1],2)) <= (double)bomb[2]);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int maxCoverage = 0, n = bombs.size();
        vector<vector<int>> g(n);
        
        // Build Reachability Adjacency List / Directed Graph
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (inRangeOf(bombs[i],bombs[j])) { g[i].push_back(j); }
            }
        }
    
        // Depth-first search (simple graph traversal) from each bomb
        for (int i=0;i<n;i++) {
            int det_count = 0;
            stack<int> s;
            vector<int> visited(n,0);
            s.push(i); // {bomb_x, bomb_y, bomb_r, current_no_of_bombs_detontated}
            visited[i] = 1;
            while (!s.empty()) {
                auto curr = s.top(); s.pop();
                det_count++;
                for (auto next : g[curr]) {
                    if (!visited[next]) { s.push(next); visited[next] = 1; }
                }
            }
            maxCoverage = max(maxCoverage,det_count);
        }

        return maxCoverage;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:

    // Checks if 'a' is in range of 'bomb'
    bool inRangeOf (vector<int>& bomb, vector<int>& a) {
        return (sqrt(pow(bomb[0]-a[0],2)+pow(bomb[1]-a[1],2)) <= (double)bomb[2]);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int maxCoverage = 0, n = bombs.size();
        vector<vector<int>> g(n);
        
        // Build Reachability Adjacency List / Directed Graph
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (inRangeOf(bombs[i],bombs[j])) { g[i].push_back(j); }
            }
        }
    
        // Breadth-first search (simple graph traversal) from each bomb
        for (int i=0;i<n;i++) {
            int det_count = 0;
            queue<int> q;
            vector<int> visited(n,0);
            q.push(i); // {bomb_x, bomb_y, bomb_r, current_no_of_bombs_detontated}
            visited[i] = 1;
            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                det_count++;
                for (auto next : g[curr]) {
                    if (!visited[next]) { q.push(next); visited[next] = 1; }
                }
            }
            maxCoverage = max(maxCoverage,det_count);
        }

        return maxCoverage;
    }
};