#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-if-path-exists-in-graph/
// Difficulty : Easy

/* YOU CAN SOLVE THIS USING DEPTH-FIRST SEARCH AND BREADTH-FIRST SEARCH AS WELL. */

/* UNION FIND SOLUTION - JUST FIND IF SOURCE AND DESTINATION ARE IN SAME CONNECTED COMPONENT OF THE GRAPH. */

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
        if (a == parent[a]) { return a;}
        parent[a] = find(parent[a]); // Compress the Recursive Path to parent by directly connecting this node to its parent.
        return parent[a];
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        UFS ufs(n);
        
        for (auto& edge : edges) { ufs.Union(edge[0],edge[1]); }
        
        return ufs.find(source) == ufs.find(destination);
        
    }
};