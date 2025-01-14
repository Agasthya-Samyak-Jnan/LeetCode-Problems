#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> g;
    vector<int> visited;
    int n;

    int dfs (int i) {

        visited[i] = 1;
        int nodes = 1;

        for (auto& j : g[i]) {
            if (j != i and !visited[j]) { nodes += dfs(j); }
        }

        return nodes;
    }

    long long countPairs(long long n, vector<vector<int>>& edges) {
        
        this->n = n;
        long long pairs = (n*(n-1))/(long long)2;
        // long long pairs = 0;
        // int remaining = n;

        /* Note : Adjacency Matrix exceeds Memory limits for large inputs. Use Adjacency List format. */
        g = vector<vector<int>>(n);
        for (auto& e : edges) { 
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }   

        /* Basic Maths and Graph Ideas */
        visited = vector<int>(n,0);
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                long long comp_size = dfs(i);
                // remaining -= comp_size;
                // pairs += comp_size * remaining;
                pairs -= (comp_size*(comp_size-1))/(long long)2 ;
            }
        }

        return pairs;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> g;
    vector<int> visited;
    int n;

    int bfs (int i) {

        queue<int> q;
        
        q.push(i);
        visited[i] = 1;
        int nodes = 0;

        while (!q.empty()) {
            i = q.front(); q.pop();
            nodes++;
            for (auto& j : g[i]) {
                if (j != i and !visited[j]) { 
                    q.push(j); 
                    visited[j] = 1; 
                }
            }
        }

        return nodes;
    }

    long long countPairs(long long n, vector<vector<int>>& edges) {
        
        this->n = n;
        long long pairs = (n*(n-1))/(long long)2;
        // long long pairs = 0;
        // int remaining = n;

        /* Note : Adjacency Matrix exceeds Memory limits for large inputs. Use Adjacency List format. */
        g = vector<vector<int>>(n);
        for (auto& e : edges) { 
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }   

        visited = vector<int>(n,0);
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                long long comp_size = bfs(i);
                // remaining -= comp_size;
                // pairs += comp_size * remaining;
                pairs -= (comp_size*(comp_size-1))/(long long)2 ;
            }
        }

        return pairs;
    }
};