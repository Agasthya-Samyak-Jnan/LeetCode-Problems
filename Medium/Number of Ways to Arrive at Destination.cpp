#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Difficulty : Medium 

/* 
    SHORTEST PATH ALGORITHMS to find absolute shortest time paths
                                +
    DYNAMIC PROGRAMMING (DEPTH-FIRST SEARCH + MEMOIZATION) to count ways through shrotest paths you can reach destination. 

        - Find all shortest paths (paths that take least time to reach from 0 to n-1 node). (Dijkistra/Bellman-Ford/Warshall-Floyd Algorithms)
        - Build a Uni-directional DAG (Directed Acyclic Graph) containing only shortest path edges connecting 0 to n-1 node. (Dijkistra/Bellman-Ford/Warshall-Floyd Algorithms)
        - Travel through DAG counting number of ways from each node to reach 'n-1' node. (Depth-first Search/Recursion)
        - Sum of ways to reach 'n-1' node from each child node of a given node is TOTAL number of ways to reach 'n-1' node from a given node. (Depth-first Search/Recursion)
        - To avoid recomputation, when you visit an already visited node, store the number of ways to reach 'n-1' in a table,
          such that, table[node] = no.of.ways to reach 'n-1' from node. (Memoization)

    NOTE : 10^9 is not enough to represent INFINITY here, as the sum of time taken to reach 'n-1' exceeds it in certain cases. Use 10^12 or more.
*/
class Solution {
public:
    unordered_map<int,long> dp;
    vector<vector<long long>> g1;
    vector<vector<int>> g2;
    int n, mod = 1e9 + 7;
    long long INF = 1e15; // 10^15 as INFINITY

    // SHORTEST PATH ALGORITHMS to find absolute shortest time paths and build a DAG in Reverse Direction from 'n-1' to '0' node.
    void dijkistra (int src) {

        vector<long long> path (n,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        path[src] = 0;
        pq.push({0,src});

        while (!pq.empty()) {
            auto [time,curr] = pq.top(); pq.pop();
            if (time > path[curr]) { continue; }
            for (int i=0;i<n;i++) {
                if (path[curr] + g1[curr][i] == path[i]) {
                    g2[i].push_back(curr);
                }
                else if (path[curr] + g1[curr][i] < path[i]) {
                    g2[i] = {curr};
                    path[i] = path[curr] + g1[curr][i];
                    pq.push({path[i],i});
                }
            }
        }
    }

    // DYNAMIC PROGRAMMING (DEPTH-FIRST SEARCH + MEMOIZATION) to count ways through shrotest paths you can reach destination. 
    long solve (int i) {

        if (i == 0) { return 1; }
        if (dp.find(i) != dp.end()) { return dp[i]; }

        for (int j : g2[i]) { dp[i] = (dp[i] + solve(j)) % mod; }

        return dp[i];
    }

    // Final Logic
    int countPaths(int n, vector<vector<int>>& roads) {
        
        this->n = n;
        g1 = vector<vector<long long>>(n,vector<long long>(n,INF));
        g2 = vector<vector<int>>(n);
        
        for (auto& r : roads) { g1[r[0]][r[1]] = g1[r[1]][r[0]] = r[2]; }

        dijkistra(0);

        return solve(n-1);
    }
};