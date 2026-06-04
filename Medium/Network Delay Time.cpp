#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/network-delay-time/
// Difficulty : Medium

/* Floyd-Warshall Algorithm - All Pairs Shortest Times */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int z) {
        
        int g[101][101];
        int minTime = 0;
        
        // O(E) - Build Adjacency Matrix from Edge-List.
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i==j) { g[i][j] = 0; }
                else { g[i][j] = 1e9; }
            }
        }  
        int e = times.size();
        for (int i=0;i<e;i++) { g[times[i][0]][times[i][1]] = times[i][2]; }

        
        // Floyd-Warshall Algorithm - Find All Pairs' Shortest Times.
        for (int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        
        // Check if Signal is NOT REACHABLE to any Node. If so, Return -1, ELSE RETURN GRAPH.
        /* Simultaneously, Check Maximum Time Taken by Signal to reach a NODE. This is the maximum time to reach all nodes. */
        for (int i=1;i<=n;i++) {
            //cout<<g[z][i]<<" ";
            minTime = max(minTime,g[z][i]);
        }
        
        return (minTime >= 1e9 ? -1 : minTime);
    }
};

/* Dijkistra's Algorithm - Single Source Shortest Paths to all. The maximum out of all shortest paths is the max time to reach all nodes since before that everything else will be reached. */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        const int INF = 1e9;
        vector<vector<int>> g(n+1, vector<int>(n+1,INF));

        // Build the graph
        for (auto e : times) { g[e[0]][e[1]] = e[2]; }


        // Use Dijkistra Algorithm to find single source shortest paths to all other nodes. Our source is 'k'.
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> time(n+1,INF);

        time[0] = 0;
        time[k] = 0;
        pq.push({0,k});

        while (!pq.empty()) {
            
            auto [cost,curr] = pq.top(); pq.pop();

            if (cost > time[curr]) { continue; }

            for (int i=1;i<=n;i++) {
                if ((time[curr] + g[curr][i]) < time[i]) {
                    time[i] = time[curr] + g[curr][i];
                    pq.push({time[i],i});
                }
            }

        }

        // The maximum time to reach all nodes from 'k' is the maximum time out of all shortest paths' times to other nodes.
        int mx = *max_element(time.begin(),time.end());

        return (mx == INF) ? -1 : mx;
    }
};