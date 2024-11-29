#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/
// Difficulty : Medium


/* WARSHALL-FLOYD ALGORITHM - TIME LIMIT EXCEEDED : O(N^4) */
#define INF 1e9

class Solution {
public:
    
    void warshall_floyd (vector<vector<int>>& g, int n) {
        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> ans;
        vector<vector<int>> g(n,vector<int>(n,INF));
        
        for (int i=0;i<n-1;i++) { g[i][i+1] = 1; g[i][i] = 0; }
        
        for (auto& edge : queries) {
            g[edge[0]][edge[1]] = 1;
            warshall_floyd(g,n);
            ans.push_back(g[0][n-1]);
        }
         
        return ans;
    }
};

/* DIJKISTRA'S SHORTEST PATH ALGORITHM : O(N^2*log(N)) */
#define INF 1e9

class Solution {
public:
    
    void min_heapify_up (vector<pair<int,int>>& a, int i) {
        while (i>0) {
            int k = i;
            if (a[(i-1)/2].first > a[k].first) { k = (i-1)/2; }
            if (k != i) { swap(a[i],a[k]); i=k; }
            else { break; }
        }
    }

    void min_heapify_down (vector<pair<int,int>>& a, int i, int n) {
        while (1) {
            int k = i;
            if (2*i+1 < n && a[2*i+1].first < a[k].first) { k = 2*i+1; }
            if (2*i+2 < n && a[2*i+2].first < a[k].first) { k = 2*i+2; }
            if (k != i) { swap(a[i],a[k]); i=k; }
            else { break; }
        }
    }

    int dijkistra (vector<vector<int>>& g, int src, int n) {

        vector<int> path(n,INF);
        vector<pair<int,int>> pq; // {Edge Weight, End Vertex}

        path[src] = 0;
        pq.push_back({path[src],src});

        while (!pq.empty()) {

            int curr = pq[0].second, min_dist = pq[0].first; // Get Nearest Vertex and its Distance
            swap(pq[0],pq[pq.size()-1]);
            pq.pop_back();
            min_heapify_down(pq,0,pq.size());

            if (min_dist > path[curr]) { continue; } // Don't Find Paths for this. This is NOT valid entry. (Shortest Path was already found!)

            for (int i=0;i<n;i++) { // Check if you can find any Nearer Paths for Vertices that are Reachable from Current Vertex.
                if (g[curr][i] != INF && g[curr][i] != 0 && g[curr][i] + path[curr] < path[i]) { 
                    path[i] = g[curr][i] + path[curr]; 
                    pq.push_back({path[i],i});  // {Shortest Distance, Shortest Path or Nearest Vertex}
                    min_heapify_up(pq,pq.size()-1); // Maintain Nearest Element on Top(Root Position or pq[0]) Every Time.
                }
            }
        } 

        return path[n-1];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> ans;
        vector<vector<int>> g(n,vector<int>(n,INF));
        
        for (int i=0;i<n-1;i++) { g[i][i+1] = 1; g[i][i] = 0; }
        
        for (auto& edge : queries) {
            g[edge[0]][edge[1]] = 1;
            ans.push_back(dijkistra(g,0,n));
        }
         
        return ans;
    }
};

/* BREADTH-FIRST SEARCH WITH VISITED ARRAY TO AVOID INFINITE LOOPING : O(N^2) */
class Solution {
public:
    
    int bfs (vector<vector<int>>& g, int n) {
        
        vector<int> visited(n,0);
        queue<int> q;
        int dist = 0;
        
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()) {
            int l = q.size();
            
            for (int i=0;i<l;i++) {
                int curr = q.front(); q.pop();
                if (curr == n-1) { return dist; }
                for (auto& j : g[curr]) { 
                    if (!visited[j]) {
                        q.push(j); 
                        visited[j] = 1;
                    }
                }
            }
            
            dist++;
        }
        
        return dist;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> g(n);
        vector<int> ans;
        
        for (int i=0;i<n;i++) { g[i].push_back(i+1); }
        
        for (auto& edge : queries) {
            g[edge[0]].push_back(edge[1]);
            ans.push_back(bfs(g,n));
        }
        
        return ans;
    }
};