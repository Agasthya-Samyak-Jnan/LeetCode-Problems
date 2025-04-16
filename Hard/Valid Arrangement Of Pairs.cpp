#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-arrangement-of-pairs/
// Difficulty : Hard

/* DEPTH-FIRST SEARCH | POSTORDER TRAVERSAL | GRAPH THEORY - PROPERTIES OF EULERIAN TRAIL/WALK IN A GRAPH */

// Problem basically says : "Find us an Eulerian Trail if given pairs are edges of a graph. Eulerian Trail is guaranteed in the graph."

class Solution {
    public:
        unordered_map<int,queue<int>> g; // Graph built using Pairs.
        unordered_map<int,int> incoming; // Incoming Edges count for each Node.
        vector<int> node_seq; // Valid Arrangement of Nodes here.
        int start = -1;
    
        // WHY POSTORDER WORKS? 
        /* 
            POSTORDER WORKS because when traverse through the graph node-by-node,
            - if a node has one or more outgoing paths(edges) remaining, it can come later 
            our way since we want to traverse through ALL edges in our EULER TRAIL and to do
            so we have to visit this node again.
    
            - END node in an EULER TRAIL is the node from which there are no edges remianing
            to go to another node. By traversing through edges and removing those edges we
            traversed on the way, we eventually make every node an END node removing all
            edges outgoing from it.
    
            - Now, we need to reach 'n'th END node from 'n-1'th END nod, 'n-1'th node from 
            'n-2'th node and so on until we are able to reach 'n-(n-1)'th node from START
            node. This completes the path.
    
            - To do ordering as explained above POSTORDER is the method, it first explores
            all outgoing edges from the node, and when there are none remaining, this node
            would be the END node, and then it is put into sequence of nodes.
            This sequence would be like : { (n)th -> (n-1)th -> (n-2)th -> ... -> (n-(n-1))th -> START }
    
        */
        void dfs (int node) {
    
            while (!g[node].empty()) {
                int next = g[node].front();
                g[node].pop();
                dfs(next);
            }
    
            node_seq.push_back(node);
        }
    
        vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    
            // Building Graph from given pairs, each pair is a directed edge from start value to end value.
            for (auto& e : pairs) { 
                g[e[0]].push(e[1]);
                incoming[e[1]]++;
            }
    
            /* Find the Start Node : 
                Since its provided that every input ALWAYS HAS a Valid Arrangement,
                Find any node that has Outgoing Edges >= Incoming Edges because if we start from Nodes that don't satisfy above condition, we will definitely miss some Incoming Edges because there is no way out remaining to go out of this node and come back in.
            */
            for (auto& node : g) {
                if (node.second.size() > incoming[node.first]) {
                    start = node.first;
                    break;
                }
            }
            if (start == -1) { start = (*g.begin()).first; }
    
            // PostOrder DFS for Tracing Euler Trail as Sequence of Nodes.
            dfs(start);
    
            // Since sequence of Nodes is from END TO START (reverse order), we start from LAST element of node_seq to build pairs.
            vector<vector<int>> arrangement;
            for (int i=node_seq.size()-1;i>0;i--) {
                arrangement.push_back( {node_seq[i],node_seq[i-1]} );
            }
    
            return arrangement;
        }
};