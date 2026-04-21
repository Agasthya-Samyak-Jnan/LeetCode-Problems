#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimize-maximum-component-cost
// Difficulty : Medium 

/* 
    SORTING TO USE LEAST WEIGHTED EDGES FIRST + UNION FIND TO COUNT COMPONENTS IN GRAPH WHILE WE BUILD IT WITH LEAST WEIGHTED EDGES. 
    THIS IDEA IS VERY SIMILAR TO KRUSKAL'S ALGORITHM TO BUILD MINIMUM SPANNING TREE (MST) OF A GIVEN GRAPH.
*/
class UFS {
public:
    int n, components;
    vector<int> parent, rank;

    UFS (int n) {
        this->n = n;
        components = n;
        rank = vector<int>(n,0);
        parent = vector<int>(n);
        iota(parent.begin(),parent.end(),0);
    }

    void Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { 
            parent[B] = A; 
        }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        }
        components--;
    }

    int find (int a) {
        return parent[a] = (parent[a] == a) ? a : find(parent[a]);
    }

};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {

        if (edges.size() <= k-1) { return 0; }
        
        sort(edges.begin(),edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        int i = 0;
        UFS ufs(n);
        while (ufs.components > k) {
            ufs.Union(edges[i][0],edges[i][1]);
            i++;
        }

        return (i == 0) ? 0 : edges[i-1][2];
    }
};