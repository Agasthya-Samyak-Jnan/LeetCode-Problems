#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-champion-ii/
// Difficulty : Medium 

/* GRAPH CONCEPTUAL SOLUTION - INDEGREE OF NODES */
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);
        
        for (auto& edge : edges) { indegree[edge[1]]++; }
        
        int champ = -1;
        
        for (int i=0;i<n;i++) {
            if (indegree[i] == 0) {
                if (champ == -1) { champ = i; }
                else { return -1; }
            }
        }
        
        return champ;
    }
};

/* UNION-FIND BASED SOLUTION */
class UFS {
public:
    // Disjoint Set Data Structure
    vector<int> parent;

    // Initialise Disjoint Set
    UFS (int n) {
        parent = vector<int>(n);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b) {  
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (B != b) { return; }
        parent[B] = A;
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        return parent[a] = (a == parent[a]) ? a : find(parent[a]);
    }
};

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        UFS ufs(n);
        
        for (auto& edge : edges) { ufs.Union(edge[0],edge[1]); }
        
        int champ = ufs.find(0);
        
        for (int i=1;i<n;i++) {
            if (ufs.find(i) != champ) { return -1; }
           }
        
        return champ;
    }
};
