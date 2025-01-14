#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/redundant-connection/
// Difficulty : Medium 

/* UNION FIND BASED SOLUTION */

/* Union Find Object Template */
template <typename obj>
class UFS {
public:
    // Disjoint Set Data Structures
    unordered_map<obj,obj> parent;
    unordered_map<obj,int> rank;

    // Initialise Disjoint Set
    UFS () {}
    
    UFS (vector<obj>& nodes) {
        for (auto &i : nodes) {
            parent[i] = i;
            rank[i] = 0;
        }  
    }

    // Combine/Union thier Families
    void Union (obj a, obj b) {    
        obj A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        } 
    }

    // Find Upper-Most Parent 
    obj find (obj a) { 
        if (parent.find(a) == parent.end()) { 
            parent[a] = a; 
            rank[a] = 0;
        }
        return parent[a] = (a == parent[a]) ? a : find(parent[a]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        UFS<int> ufs;
        
        for (auto& e : edges) {
            if (ufs.find(e[0]) != ufs.find(e[1])) { ufs.Union(e[0],e[1]); }
            else { return e; }
        }

        return {-1,-1};
    }
};