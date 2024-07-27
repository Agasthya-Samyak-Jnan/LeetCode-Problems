#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/network-delay-time/
// Difficulty : Medium

/* Application of Floyd-Warshall Algorithm - All Pairs Shortest Times */
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
        /* Simultaneously, Check Maximum Time Taken by Signal to reach a NODE. This is the minimum            to reach all nodes. */
        for (int i=1;i<=n;i++) {
            //cout<<g[z][i]<<" ";
            minTime = max(minTime,g[z][i]);
        }
        
        return (minTime >= 1e9 ? -1 : minTime);
    }
};