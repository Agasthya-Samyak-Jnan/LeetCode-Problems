#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-the-number-of-complete-components/
// Difficulty : Medium 

/* A Complete Component containing 'V' Vertices must always have '(V*(V-1))/2' Edges. (Edge between every pair of vertices in a component) */

/* UNION FIND METHOD */
class UFS {
    public:
        vector<int> edges, vertices, comp;
        vector<int> parent, rank;
    
        UFS (int n) {
            vertices = vector<int>(n,1); // Count Vertices for every Component where a Vertex is head of Component.
            edges = vector<int>(n,0); // Count Edges for every Component where a Vertex is head of Component.
            parent = vector<int>(n);
            rank = vector<int>(n,0); 
            comp = vector<int>(n,1); // All Vertices are Head of thier own Component containing only themselves. All Vertices are Heads of Components.
            iota(parent.begin(),parent.end(),0);
        }
    
        void Union (int a, int b) {
            int A = find(a), B = find(b);
            if (A == B) { 
                edges[A]++; // Count Edges in a Component.
                return; 
            }
            if (rank[A] > rank[B]) { 
                parent[B] = A; 
                edges[A] += (edges[B] + 1); // Count Edges in a Component.
                vertices[A] += vertices[B]; // Count Vertices in a Component.
                comp[A] = 1; // Validate this vertex as Head of this Component.
                comp[B] = 0; // Invalidate this vertex as Head of this Component.
            }
            else {
                if (rank[A] == rank[B]) { rank[B]++; }
                parent[A] = B; 
                edges[B] += (edges[A] + 1); // Count Edges in a Component.
                vertices[B] += vertices[A]; // Count Vertices in a Component.
                comp[B] = 1; // Validate this vertex as Head of this Component.
                comp[A] = 0; // Invalidate this vertex as Head of this Component.
            }
        }
    
        int find (int a) {
            return parent[a] = (a == parent[a]) ? a : find(parent[a]);
        }
    };
    
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
    
            UFS ufs(n);
            int complete_comps = 0;
    
            for (auto& e : edges) { ufs.Union(e[0],e[1]); }
    
            for (int i=0;i<n;i++) {
                if (ufs.comp[i] == 1) {
                    int v = ufs.vertices[i], e = ufs.edges[i];
                    complete_comps += ((v*(v-1))/2 == e);
                }
            }
    
            return complete_comps;
        }
};

/* DEPTH-FIRST SEARCH METHOD */
class Solution {
    public:
        int v, e; // Count Vertices, Edges.
        vector<int> visited;
        vector<vector<int>> g;

        // Depth-first Search for each Component.
        void dfs (int i) {
            v++; // Count Vertices
            visited[i] = 1;
            for (auto& j : g[i]) {
                if (!visited[j]) { dfs(j); }
                e++; // Count Edges
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
    
            int complete_comps = 0;
            g = vector<vector<int>>(n);
            visited = vector<int>(n,0);
    
            for (auto& e : edges) {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
    
            for (int i=0;i<n;i++) {
                if (!visited[i]) {
                    v = 0, e = 0;
                    dfs(i); // Count Vertices and Edges in each Component.
                    e /= 2; // Bidirectional Edges , hence edge count would be double the number of total edges.
                    complete_comps += ((v*(v-1))/2 == e); // Complete Component has V*(V-1) / 2 Edges. Draw a complete component to understand why.
                    // cout<<i<<" "<<v<<" "<<e<<"\n";
                }
            }
    
            return complete_comps;
        }
};

/* BREADTH-FIRST SEARCH METHOD */
class Solution {
    public:
        int v, e; // Count Vertices, Edges.
        vector<int> visited;
        vector<vector<int>> g;

        // Breadth-first Search for each Component.
        void bfs (int i) {
            
            queue<int> q;
    
            q.push(i);
            visited[i] = 1;
    
            while (!q.empty()) {
                i = q.front(); q.pop();
                v++; // Count Vertices
                for (auto& j : g[i]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = 1;
                    }
                    e++; // Count Edges
                }
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
    
            int complete_comps = 0;
            g = vector<vector<int>>(n);
            visited = vector<int>(n,0);
    
            for (auto& e : edges) {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
    
            for (int i=0;i<n;i++) {
                if (!visited[i]) {
                    v = 0, e = 0;
                    bfs(i); // Count Vertices and Edges in each Component.
                    e /= 2; // Bidirectional Edges , hence edge count would be double the number of total edges.
                    complete_comps += ((v*(v-1))/2 == e); // Complete Component has V*(V-1) / 2 Edges. Draw a complete component to understand why.
                    // cout<<i<<" "<<v<<" "<<e<<"\n";
                }
            }
    
            return complete_comps;
        }
};