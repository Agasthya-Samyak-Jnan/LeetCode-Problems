#include<bits/stdc++.h>
#define INF 1e9

using namespace std;
 
// Link to the Problem : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
// Difficulty : Hard

// MINIMUM SPANNING TREE USING KRUSKAL'S ALGORITHM WITH UNION FIND

// Union-Finder Disjoint Set (Rank Method + Path Compression) 
class UFS {
    public:
    // Disjoint Set Data Structures
    int n;
    vector<int> parent;
    vector<int> rank;

    // Initialise Disjoint Set
    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b) {
        
        int A = find(a), B = find(b);

        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        } 
    }

    // Find Upper-Most Parent 
    int find (int a) {
        if (a == parent[a]) { return a; }
        parent[a] = find(parent[a]); // Compress the Recursive Path to parent by directly connecting this node to its parent.
        return parent[a];
    }
    
    void clear () {
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    
};

class Solution {
public:
    int MSTcost (int n,vector<vector<int>>& edges, vector<int> removed_edge, vector<int> included_edge) {

        UFS ufs(n);
        int cost = 0;

        if (!included_edge.empty()) {
            cost += included_edge[0];
            ufs.Union(included_edge[1],included_edge[2]);
        }

        for (auto& edge : edges) {
            if (edge == removed_edge) { continue; }
            if (ufs.find(edge[1]) != ufs.find(edge[2])) {
                ufs.Union(edge[1],edge[2]);
                cost += edge[0];
            }
        }

        for (int i=0;i<n;i++) {
            if (ufs.find(i) != ufs.find(0)) { return    INF; }
        }

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int e = edges.size();

        for (int i=0;i<e;i++) { edges[i] = {edges[i][2],edges[i][0],edges[i][1],i}; } 
        
        // Sort the Edges by Weight
        sort(edges.begin(),edges.end());
        
        // Find the minimum cost of any MST of this Graph.
        int min_cost = MSTcost(n,edges,{},{});

        vector<int> CriticalEdges, PseudoCriticalEdges;

        for (auto& removed_edge : edges) {
            // Exclude this Edge. If excluding this Costed more than before its Critical.
            if (min_cost < MSTcost(n,edges,removed_edge,{})) { CriticalEdges.push_back(removed_edge[3]); }
            // Otherwise forcibly include this Edge to our MST. If including this Costed SAME as before its Pseudo-Critical.
            else if (min_cost == MSTcost(n,edges,{},removed_edge)) { PseudoCriticalEdges.push_back(removed_edge[3]); }
            // Otherwise this Edge was NOT part of any MST than can be formed with this Graph.
        }

        return {CriticalEdges,PseudoCriticalEdges};
    }   
};

// TESTER CODE
int main () {

    Solution a;
    int n = 6;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    edges = a.findCriticalAndPseudoCriticalEdges(n,edges);

    for (auto i : edges) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }

}