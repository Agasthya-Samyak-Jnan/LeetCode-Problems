#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/
// Difficulty : Medium 

/* GRAPH + SHORTEST PATH ALGORITHMS (BREADTH-FIRST SEARCH/DIJKISTRA/WARSHALL-FLOYD/BELLMAN-FORD Algorithms) */
// The Graph is a simple doubly-linked list with a random pointer connecting two random nodes.
// Find Shortest Path Costs from every node to every other node and count how many times each cost has occured.

/* BREADTH-FIRST SEARCH SOLUTION - BFS with Level Seperation represents each level as a step towards goal and considers all possibilities before going next step. */
class Solution {
public:
    // You can move 1 step in either backward or forward direction due to nature of graph.
    // At X,Y nodes you can move to X or Y other than forward and backward.
    vector<int> bfs (int src, int n, int x, int y) {

        const int INF = 1000;
        vector<int> path(n+1,INF);
        queue<pair<int,int>> q;

        path[src] = 0;
        q.push({src,0});

        while (!q.empty()) {
            int l = q.size();
            for (int i=0;i<l;i++) {
                auto [curr,cost] = q.front(); q.pop();
                if (curr == x and path[y] > cost+1) { path[y] = cost+1; q.push({y,cost+1}); }
                if (curr == y and path[x] > cost+1) { path[x] = cost+1; q.push({x,cost+1}); }
                if (curr+1 <= n and path[curr+1] > cost + 1) { path[curr+1] = cost+1; q.push({curr+1,cost+1}); }
                if (curr-1 >= 1 and path[curr-1] > cost + 1) { path[curr-1] = cost+1; q.push({curr-1,cost+1}); }
            }
        }

        path.erase(path.begin());

        return path;
    } 

    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> count(n+1,0);

        for (int i=1;i<=n;i++) { 
            auto temp = bfs(i,n,x,y); 
            for (auto num : temp) { count[num]++; }
        }
        
        count.erase(count.begin());

        return count;
    }
};

/* DIJKISTRA's ALGORITHM SOLUTION */
class Solution {
public:
    // You can move 1 step in either backward or forward direction due to nature of graph.
    // At X,Y nodes you can move to X or Y other than forward and backward.
    vector<int> dijkistra (int src, int n, int x, int y) {

        const int INF = 1000;
        vector<int> path(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,src});
        path[src] = 0;

        while (!pq.empty()) {
            auto [cost,src] = pq.top(); pq.pop();
            if (cost > path[src]) { continue; }
            if (x != y) {
                if (src == x and path[x] + 1 < path[y]) {
                    pq.push({cost+1,y});
                    path[y] = path[x] + 1;
                } 
                if (src == y and path[y] + 1 < path[x]) {
                    pq.push({cost+1,x});
                    path[x] = path[y] + 1;
                } 
            }
            if (src+1 <= n and path[src+1] > cost + 1) {
                pq.push({cost+1,src+1});
                path[src+1] = cost + 1; 
            }
            if (src-1 >= 0 and path[src-1] > cost + 1) {
                pq.push({cost+1,src-1});
                path[src-1] = cost + 1; 
            }
        }

        path.erase(path.begin());

        return path;
    } 

    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> count(n+1,0);

        for (int i=1;i<=n;i++) { 
            auto temp = dijkistra(i,n,x,y); 
            for (auto num : temp) { count[num]++; }
        }
        
        count.erase(count.begin());

        return count;
    }
};

/* WARSHALL-FLOYD ALGORITHM SOLUTION */
class Solution {
public:
    // You can move 1 step in either backward or forward direction due to nature of graph.
    // At X,Y nodes you can move to X or Y other than forward and backward.
    vector<vector<int>> warshall_floyd (int n, int x, int y) {
        
        const int INF = 1000;
        vector<vector<int>> path(n+1,vector<int>(n+1,INF));

        for (int i=1;i<n;i++) { path[i][i+1] = path[i+1][i] = 1; path[i][i] = 0; }
        if (x != y) { path[x][y] = 1; path[y][x] = 1; }
        path[n][n] = 0;

        for (int k=1;k<=n;k++) {
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    if (path[i][k] + path[k][j] < path[i][j]) {
                        path[i][j] = path[i][k] + path[k][j];
                    }
                }
            }
        }

        return path;
    } 

    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> count(n+1,0);

        auto temp = warshall_floyd(n,x,y);

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                count[temp[i][j]]++;
            }
        }
        
        count.erase(count.begin());

        return count;
    }
};

/* BELLMAN-FORD ALGORITHM SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    // You can move 1 step in either backward or forward direction due to nature of graph.
    // At X,Y nodes you can move to X or Y other than forward and backward.
    vector<int> bellman_ford (int src, int n, int x, int y) {

        const int INF = 1000;
        vector<int> path(n+1,INF);
        path[src] = 0;

        for (int t=0;t<n-1;t++) {
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    // Representing Whole Graph in a Boolean Expression so we decrease memory for storing a graph in a matrix.
                    // A doubly linked list connecting 'i' node to 'i+1' node and random pointer connecting two random nodes.
                    int edge_cost = ((i == j+1) or (j == i+1) or (i==x and j==y) or (i==y and j==x)) ? 1 : INF; 
                    if (path[i] + edge_cost < path[j]) {
                        path[j] = path[i] + edge_cost;
                    }
                }
            }
        }

        path.erase(path.begin());

        // Since its guaranteed there will be no negative edges in graph due to nature of problem given,
        // We don't do negative cycle check we noramlly do in Bellman-Ford Algorithm.

        return path;
    } 

    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> count(n+1,0);

        for (int i=1;i<=n;i++) { 
            auto temp = bellman_ford(i,n,x,y); 
            for (auto num : temp) { count[num]++; }
        }
        
        count.erase(count.begin());

        return count;
    }
};