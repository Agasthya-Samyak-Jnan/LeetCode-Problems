#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
// Difficulty : Medium

/* 
   GRAPH THEORY CONCEPTS
   The component containing '1' and 'n' will contain all edges forming all possible paths from '1' to 'n'. Find the minimum distance edge in that component. 
*/

/* UNION FIND based method */
// Union-Finder Disjoint Set (Rank Method + Path Compression)
class UFS {
private:
    // Disjoint Set Data Structures
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> min_dist;

public:
    // Initialise Disjoint Set
    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        min_dist = vector<int>(n,INT_MAX);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b, int w) {  
        int A = find(a), B = find(b);
        // if (A == B) { return; } // WE SHOULD ADD CYCLE CREATING EDGES BECAUSE THEY MIGHT BE MINIMUM EDGE ON A POSSIBLE PATH THROUGH THEM.
        if (rank[A] > rank[B]) { 
            parent[B] = A;
            min_dist[A] = min({min_dist[A],min_dist[B],w}); 
        }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
            min_dist[B] = min({min_dist[A],min_dist[B],w});
        } 
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        return parent[a] = (a == parent[a]) ? a : find(parent[a]);
    }

    // Get minimum distance edge in component containing source and destination
    int minDist (int src, int dest) {
        return min_dist[find(src)];
    }

};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        UFS ufs(n+1);

        for (auto e : roads) { ufs.Union(e[0],e[1],e[2]); }
        
        return ufs.minDist(1,n);
    }
};

/* BREADTH-FIRST SEARCH based method (just swap QUEUE with STACK to make it ITERATIVE DEPTH-FIRST SEARCH, look next method below this) */
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        int minDist = INT_MAX;
        queue<int> q;
        vector<vector<vector<int>>> g(n+1);
        vector<int> visited(n+1,0);

        for (auto e : roads) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }

        q.push({1});
        visited[1] = 1;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto next : g[node]) {
                int nextnode = next[0], edgeDist = next[1];
                minDist = min(minDist,edgeDist);
                if (!visited[nextnode]) {
                    q.push(nextnode);
                    visited[nextnode] = 1;
                }
            }
        }
        
        return minDist;
    }   
};

/* ITERATIVE DEPTH-FIRST SEARCH based method */
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        int minDist = INT_MAX;
        stack<int> s;
        vector<vector<vector<int>>> g(n+1);
        vector<int> visited(n+1,0);

        for (auto e : roads) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }

        s.push({1});
        visited[1] = 1;

        while (!s.empty()) {
            int node = s.top(); s.pop();
            for (auto next : g[node]) {
                int nextnode = next[0], edgeDist = next[1];
                minDist = min(minDist,edgeDist);
                if (!visited[nextnode]) {
                    s.push(nextnode);
                    visited[nextnode] = 1;
                }
            }
        }
        
        return minDist;
    }   
};

/* RECURSIVE DEPTH-FIRST SEARCH based method */
class Solution {
public:

    int minDist = INT_MAX;
    vector<int> visited;
    vector<vector<vector<int>>> g;

    void dfs (int node) {
        visited[node] = 1;
        for (auto next : g[node]) {
            int nextnode = next[0], edgeDist = next[1];
            minDist = min(minDist,edgeDist);
            if (!visited[nextnode]) { dfs(nextnode); }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        g = vector<vector<vector<int>>>(n+1);
        visited = vector<int>(n+1,0);

        for (auto e : roads) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }

        dfs(1);

        return minDist;
    }   
};