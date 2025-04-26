#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/possible-bipartition/
// Difficulty : Medium 

/* 
   GRAPH COLORING METHOD - ADJACENT NODES REPRESENTS PAIR OF PEOPLE WHO DISLIKE EACH OTHER, AND THEY SHOULD BE COLORED DIFFERENT.
   IF YOU FIND SAME COLORS ON ADJACENT NODES ITS IMPOSSIBLE TO DIVIDE THEM INTO TWO GROUPS, NEEDS MORE GROUPS. 
   SINCE ONLY TWO COLORS ARE NEEDED TO IDENTIFY THE TWO DISLIKING GROUPS, CHECKING WITH ANY ONE STARTING COLOR IS ENOUGH.
*/

/* THIS CAN BE SOLVED BY : BREADTH-FIRST SEARCH, DEPTH-FIRST SEARCH AND UNION FIND METHODS */

/* GRAPH COLORING USING BREADTH-FIRST SEARCH (COLORS = 0,1) */
class Solution {
    public:

        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    
            vector<vector<int>> g(n+1);
            
            // Build Graph of Disliking People who have edges to each other.
            for (auto d : dislikes) {
                g[d[0]].push_back(d[1]);
                g[d[1]].push_back(d[0]);
            }
            
            // Color the graph with 0 and 1 using BFS.

            vector<int> visited(n+1,-1);
    
            for (int i=1;i<=n;i++) {
    
                if (visited[i] != -1) { continue; }
    
                queue<pair<int,int>> q; /* Stack for DFS | Queue for BFS -> Thats the only difference between BFS and DFS - The order of exploration of Graph. */
                q.push({i,0});
    
                while (!q.empty()) {
                    auto [curr,color] = q.front(); q.pop();
                    for (auto j : g[curr]) {
                        if (visited[j] == -1) {
                            q.push({j,!color});
                            visited[j] = !color;
                        }
                        else if (color == visited[j]) { return false; } // If you are revisiting this node with its same color, then you can't divide into two groups.
                    }
                }
    
            }
    
            return true;
        }
};

/* GRAPH COLORING USING DEPTH-FIRST SEARCH (COLORS = 0,1) */
class Solution {
    public:

        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    
            vector<vector<int>> g(n+1);
            
            // Build Graph of Disliking People who have edges to each other.
            for (auto d : dislikes) {
                g[d[0]].push_back(d[1]);
                g[d[1]].push_back(d[0]);
            }
            
            // Color the graph with 0 and 1 using DFS.

            vector<int> visited(n+1,-1);
    
            for (int i=1;i<=n;i++) {
    
                if (visited[i] != -1) { continue; }
    
                stack<pair<int,int>> s; // Stack for DFS | Queue for BFS -> Thats the only difference between BFS and DFS - The order of exploration of Graph.
                s.push({i,0});
    
                while (!s.empty()) {
                    auto [curr,color] = s.top(); s.pop();
                    for (auto j : g[curr]) {
                        if (visited[j] == -1) {
                            s.push({j,!color});
                            visited[j] = !color;
                        }
                        else if (color == visited[j]) { return false; } // If you are revisiting this node with its same color, then you can't divide into two groups.
                    }
                }
    
            }
    
            return true;
        }
};