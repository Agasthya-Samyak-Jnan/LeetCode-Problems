#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/power-grid-maintenance/
// Difficulty: Medium

using namespace std;

/* UNION FIND + PRIORITY QUEUE (MIN HEAP) + HASH TABLE OR SET + GRAPH */

/* 
    CONSIDERING THE QUESTION,
    - EACH STATION CAN BE TREATED AS A NODE AND GRID OF CONNECTED STATIONS AS A COMPONENT, AND THIS COLLECTION OF GRIDS AS A GRAPH. 
    - THE QUERIES GIVEN OPERATE ON A SPECIFIC COMPONENT NOT THE WHOLE GRAPH, HENCE USE UNION FIND SEPERATE COMPONENTS EASILY WITHOUT BUILDING ACTUAL GRAPH.
    - USE PRIORITY QUEUE (MIN HEAP) PER COMPONENT TO MAINTAIN LOWEST NUMBERED MEMBER FOR THAT COMPONENT ON TOP.
    - USE HASH TABLE OR SET PER COMPONENT TO REMEMBER WHICH MEMBERS ARE OFFLINE IN A COMPONENT, WHILE FINDING WHO CAN DO THE MAINTENANCE CHECK.
*/

/* MODIFIED UNION FIND DATA STRUCTURE */
class UFS {
public:
    int n;
    vector<int> parent, rank;
    vector<unordered_map<int,int>> offline;
    vector<priority_queue<int,vector<int>,greater<int>>> minMember;

    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        offline = vector<unordered_map<int,int>>(n);
        minMember = vector<priority_queue<int,vector<int>,greater<int>>>(n);
        for (int i=0;i<n;i++) { minMember[i].push(i); }
        iota(parent.begin(),parent.end(),0);
    }

    void Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { 
            while (!minMember[B].empty()) {
                minMember[A].push(minMember[B].top());
                minMember[B].pop();
            }
            parent[B] = A; 
        }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            while (!minMember[A].empty()) {
                minMember[B].push(minMember[A].top());
                minMember[A].pop();
            }
            parent[A] = B;
        }
    }

    int find (int a) {
        return parent[a] = (a == parent[a]) ? a : find(parent[a]);
    }

    void setOffline (int a) {
        int A = find(a);
        offline[A][a] = 1;
    }

    int findMaintainer (int a) {
        int A = find(a);
        if (!offline[A][a]) { return a; }
        while (!minMember[A].empty() and offline[A][minMember[A].top()]) { minMember[A].pop(); }
        return (minMember[A].empty()) ? -1 : minMember[A].top();
    }
};

class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        UFS ufs(n+1); // 1-based indexing, so 'n+1' instead of 'n', because my implementation of Union-Find DS uses 0-based indexing.
        vector<int> ans;

        for (auto c : connections) { ufs.Union(c[0],c[1]); }

        for (auto q : queries) {
            if (q[0] == 2) { ufs.setOffline(q[1]); }
            else { ans.push_back(ufs.findMaintainer(q[1])); }
        }

        return ans;
    }
};