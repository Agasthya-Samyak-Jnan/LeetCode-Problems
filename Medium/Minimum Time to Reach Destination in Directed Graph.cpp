#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/
// Difficulty: Medium

using namespace std;

/* SHORTEST PATH ALGORITHMS ON GRAPH - DIJKISTRA'S ALGORITHM */
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        if (edges.empty()) { return (n<2) ? 0 : -1; }
        
        vector<vector<vector<int>>> g(n);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> path(n,1e9);
        
        for (auto e : edges) { g[e[0]].push_back({e[1],e[2],e[3]}); } // g[FROM] = {TO, start_time, end_time}

        g[0].push_back({0,0,INT_MAX});
        pq.push({0,0,0}); // {time, FROM, TO} - Choose paths that took less time first - Dijkistra Greediness
        path[0] = 0;

        while (!pq.empty()) {
            int time = pq.top()[0];
            int parent = pq.top()[1];
            int node = pq.top()[2]; pq.pop();
            if (time > path[node] or node == n-1) { continue; }
            for (auto v : g[node]) { // For every edge from this current node...
                int next_node = v[0];
                int next_start = v[1];
                int arrival = max(time,next_start) + 1;
                if (arrival < path[next_node] and time <= v[2]) { // If (you arrive to 'next_node' earlier than before AND before this edge's expiry time) 
                    path[next_node] = arrival;
                    pq.push({arrival,node,next_node});
                }
            }
        }

        return path[n-1] == 1e9 ? -1 : path[n-1];
    }
};