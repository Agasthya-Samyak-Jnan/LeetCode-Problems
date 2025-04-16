#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reconstruct-itinerary/
// Difficulty : Hard

/* DEPTH-FIRST SEARCH | POSTORDER TRAVERSAL | GRAPH THEORY - PROPERTIES OF EULERIAN TRAIL/WALK IN A GRAPH */

// Problem basically says : "Find us an Eulerian Trail if given pairs are edges of a graph, but in lexical order. Eulerian Trail is guaranteed in the graph."

class Solution {
    public:
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> g; // Graph built using "tickets". Priority Queue (MIN heap for Lexical Ordering)
        vector<string> itinerary;
    
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
        void dfs (string node) {
    
            while(!g[node].empty()) {
                string next = g[node].top();
                g[node].pop();
                dfs(next);
            }
    
            itinerary.push_back(node);
        }
    
        vector<string> findItinerary(vector<vector<string>>& tickets) {

            // Building Graph from given pairs, each pair is a directed edge from start place name to end place name.
            for (auto ticket : tickets) { g[ticket[0]].push(ticket[1]); }
            
            // PostOrder DFS for Tracing Euler Trail as Sequence of Nodes.
            dfs("JFK");
            
            // Since sequence of Nodes is from END TO START, reverse the list to get correct order.
            reverse(itinerary.begin(),itinerary.end());
            
            return itinerary;
        }
};