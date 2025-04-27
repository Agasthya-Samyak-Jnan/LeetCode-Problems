#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-cycle-in-a-graph/
// DIfficulty : Hard

/* GRAPH TRAVERSAL METHODS AND ESSENCE OF TOPOLOGICAL SORTING ON GRAPHS */
class Solution {
    public:
        /* Given : Only 0/1 outgoing edge from each Node to another Node.
           - It implies that a node cannot be a part of more than 1 cycle because that one outgoing edge goes for the cycle path it is present in. No other Edges left to have another cycle path from that node.
           - Find which cycle is longest.
           - Since there can be disconnected components, find longest cycles among components. 
        */
        int longestCycle(vector<int>& edges) {
    
            int n = edges.size(), cycleLength = 0;
            vector<int> incoming(n,0); /* To count incoming edges for every node */
    
            /* Analysing the Graph : Count incoming edges for every node */
            for (int i=0;i<n;i++) { if (edges[i] != -1) { incoming[edges[i]]++; } }
    
            /* Topological Sorting of Graph */
            /* 
                Step 1 : Remove all Nodes that are not a part of cycle. 
                - Nodes that are not a part of cycle are Source Nodes - Nodes with no incoming edges.
                - When you remove some of these "source" nodes, some OTHER nodes lose thier incoming edges and become "source" nodes.
                - Keep removing "source" nodes that are formed during this process, until you can't find any more "source" nodes.
                - We use BFS-based Topological Sorting here (Kahn's Algorithm), DFS-based also works.
            */
            queue<int> q;
            for (int i=0;i<n;i++) { if (incoming[i] == 0) { q.push(i); } }
    
            // Until we have "source" nodes - nodes with NO incoming edges,
            while (!q.empty()) {
                int i = q.front(); q.pop(); // Remove the "source" node.
                if (edges[i] != -1) {
                    incoming[edges[i]]--; // The edge between this 'i' node and 'edges[i]' node is lost since we are removing node 'i'.
                    if (incoming[edges[i]] == 0) { q.push(edges[i]); } // New "source" nodes formed because they have no more incoming edges now.
                    edges[i] = -1; // Remove the 'i' -> 'edges[i]' Edge.
                }
            }
    
            /* DFS throughout the Graph */
            // Check for every Component : Since Input Graph can be DISCONNECTED GRAPH having multiple disconnected components.
            for (int i=0;i<n;i++) {
                    // DFS to measure the length of cycle of this component - basically number of vertices in this component, since we trimmed all nodes that are not in cycle in every component.
                    int len = 0, node = i, temp;
                    while (edges[node] != -1) {
                        len++; // You travelled One Edge. So, +1
                        temp = edges[node]; // You remember where to go next - because you will remove the path from this node to next node. 
                        edges[node] = -1; // You remove the Edge/Path SO THAT you DON'T VISIT AGAIN.
                        node = temp; // You go the Next Node.
                        /* Note : You can maintain a VISITED array if this logic feels complicated. Make sure you DON'T REVISIT nodes. */
                    }  
                    // Keep the Longest Cycle Length.
                    cycleLength = max(cycleLength,len);
            }
    
            // As per the Question : if there are no cycles, cycle length would be 0 hence return -1, otherwise return longest cycle length.
            return cycleLength == 0 ? -1 : cycleLength;
        }
};