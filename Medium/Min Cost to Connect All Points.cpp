#include<bits/stdc++.h>
#define INF 1e9

using namespace std;

// Link to the Problem : https://leetcode.com/problems/min-cost-to-connect-all-points/
// Difficulty : Medium

/* SOLUTION IS FINIDING MINIMUM SPANNING TREE OF INPUT - IMAGINE INPUT AS A GRAPH. */
/* E = Number of Edges , V = Number of Vertices */

/* PRIM'S ALGORITHM TO FIND MINIMUM SPANNING TREE - Time : E*log(V) */
#define INF 1e9

class Solution {
public:

    int dist (vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size(), cost = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> inMST(n,0);
        vector<int> minEdge(n,INF);
        vector<int> toVertex(n,-1);

        pq.push({INF,0});

        while (!pq.empty()) {

            int curr = pq.top().second; pq.pop();

            if (inMST[curr]) { continue; }
            inMST[curr] = true;

            if (toVertex[curr] != -1) {
                cost += minEdge[curr];
            }

            for (int i=0;i<n;i++) {
                int w = dist(points[curr],points[i]);
                if (i != curr && w < minEdge[i]) {
                    minEdge[i] = w;
                    toVertex[i] = curr;
                    pq.push({minEdge[i],i});
                }
            }
            
        }
        
        return cost;
    }
};


/* KRUSKAL'S ALGORITHM TO FIND MINIMUM SPANNING TREE - Time : E*Log(E) + E*Log(V) */

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
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // Build the Graph. 
        int n = points.size();
        vector<vector<int>> g(n,vector<int>(n,INF));
        vector<vector<int>> weightList;
        int i = 0, cost = 0;
        
        // Build all Manhattan Distance Edges. 
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                g[i][j] = g[j][i] = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                weightList.push_back({g[i][j],i,j});
            }
        }

        // for (auto i : g) {
        //     for (auto j : i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        sort(weightList.begin(),weightList.end());

        // for (auto edge : weightList) { cout<<edge[0]<<","<<edge[1]<<","<<edge[2]<<"\n"; }
        // cout<<"\n";

        i=0;
        UFS* ufs = new UFS(n);
        
        while (n-1) {
            if (ufs->find(weightList[i][1]) != ufs->find(weightList[i][2])) {
                ufs->Union(weightList[i][1],weightList[i][2]);
                cost += weightList[i][0];
                //cout<<weightList[i][0]<<"\n";
                n--;
            }
            i++;
        }
        
        return cost;
    }
};