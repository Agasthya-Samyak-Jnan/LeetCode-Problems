#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
// Difficulty : Hard

/* 
    IDEAS YOU NEED TO SOLVE THIS:
    - SPANNING TREE of a GRAPH
    - UNION FIND DATA STRUCTURE and its applications on GRAPH
    - SORTING WITH MAX and MIN HEAPS
    - GREEDY APPROACHES to MAXIMIZE,MINIMIZE target values. 
*/

class UFS {
public:
    vector<int> parent, rank;
    int n;

    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    bool Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return false; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        }
        return true;
    }

    int find (int a) { return parent[a] = (a == parent[a]) ? a : find(parent[a]); }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        UFS ufs(n); // Union Find Set represents our graph (used for cycle detection)
        priority_queue<vector<int>> pq_max; // Max-Heap we want Maximum Strength Edges to be in Spanning Tree, so that we maximize stability value.
        priority_queue<int,vector<int>,greater<int>> pq_min; // Min-Heap to get Minimum Strength Edges added to graph , so that we can double them and maximize the minimum strength (i.e Maximize Stability)
        int spanningTreeMinEdgeStrength = INT_MAX, edges_added = 0;

        for (auto e : edges) { 
            if (e[3] == 0) { pq_max.push({e[2],e[0],e[1]}); } // {strength, node1, node2} add upgradable edges to priority queue.
            // Add Non-upgradable edges to graph directly. 
            // Keep track of Minimum strength edge we add to spanning tree, this is stability of spanning tree we build.
            else if (ufs.Union(e[0],e[1])) { 
                spanningTreeMinEdgeStrength = min(spanningTreeMinEdgeStrength,e[2]);
                edges_added++;
            } 
            else { return -1; } // If edge cannot be added because it forms cycle, return -1.
            // since here all edges that formed cycle were compulsory edges and can't be removed from spanning tree.
        }

        while (!pq_max.empty()) {
            auto e = pq_max.top(); pq_max.pop(); // {strength, node1, node2}
            if (ufs.Union(e[1],e[2])) { 
                pq_min.push(e[0]); // {strength} Now we need only strengths of edges to find stability , these edges are already added to graph.
                edges_added++;
            }
        }

        if (edges_added < n-1) { return -1; }

        // Maximise the Minimum Edge Strengths in set of Top Strength Edges added to graph.
        // After Maximising minimum Edge Strengths, the final least Strength value is Stability.
        while(!pq_min.empty()) {
            auto strength = pq_min.top(); pq_min.pop();
            spanningTreeMinEdgeStrength = min(((k>0) ? strength*2 : strength), spanningTreeMinEdgeStrength);
            k--;
        }

        return spanningTreeMinEdgeStrength;
    }
};