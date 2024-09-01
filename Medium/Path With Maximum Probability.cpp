#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-with-maximum-probability/
// Difficulty : Medium

/* 
    ** PATHS, CONNECTIVITY RELATE TO GRAPHS. 
    DFS,BFS - single source - single path.
    DIJKISTRA - single source shortest paths.
    FLOYD-WARSHALL - All pairs shortest paths.

    We need to find Max Probability Path from 'A Given Source Node' to 'A Given Destination Node'.
    This can be possible through multiple paths involving multiple node on the way.
    So, our need is 'Single Source Shortest Paths.' - that is DIJKISTRA ALGORITHM - but modify it or HACK it to meet our goals.
*/

/* FULLY ELABORATE SOLUTION WITH LOGIC EXPLICITLY WRITTEN FOR EACH STEP. - DIJKISTRA'S ALGORITHM */
class Solution {
public:
    //HEAPIFY FROM BOTTOM TO TOP , WHEN YOU ADD NEW NODE WITH HIGHER PROBABILITY PATH AT BOTTOM OF THE HEAP.
    void max_heapify_up (vector<pair<double,int>>& a, int i) {
        while (i>0) {
            int k = i;
            if (a[(i-1)/2].first < a[k].first) { k = (i-1)/2; }
            if (k != i) { swap(a[i],a[k]); i = k; }
            else { break; }   
        }
    }
       
    //HEAPIFY FROM TOP TO BOTTOM , WHEN YOU REMOVE THE NODE WITH MAXIMUM PROBABILITY PATH FROM TOP OF THE HEAP.
    void max_heapify_down (vector<pair<double,int>>& a, int n, int i) {
        while (1) {
            int k = i;
            if (2*i+1 < n && a[2*i+1].first > a[k].first) { k = 2*i+1; }
            if (2*i+2 < n && a[2*i+2].first > a[k].first) { k = 2*i+2; }
            if (k != i) { swap(a[i],a[k]); i=k; }
            else { break; }
        }   
    }

   // DIJKISTRA'S ALGORITHM - GREEDY FOR HIGH VALUE - USING MAX BINARY HEAP. (BINARY HEAP = BINARY TREE FORMAT)
    vector<double> dijkistra (vector<pair<int,double>> g[], int src, int n) {
        
        vector<double> path(n,0);
        vector<pair<double,int>> pq;
        
        path[src] = 1;
        pq.push_back({path[src],src});
        
        while (!pq.empty()) {
            
            int curr = pq[0].second; double max_prob = pq[0].first;
            pq.erase(pq.begin());
            max_heapify_down(pq,pq.size(),0);

            
            if (max_prob < path[curr]) { continue; }
            
            for (int i=0;i<g[curr].size();i++) {
                if (g[curr][i].second > 0.0  && g[curr][i].second*path[curr] > path[g[curr][i].first]) {
                    path[g[curr][i].first] = g[curr][i].second*path[curr];
                    pq.push_back({path[g[curr][i].first],g[curr][i].first});
                    max_heapify_up(pq,pq.size()-1);
                }
            }
            
        }
        
        return path;
    }
    
    //FIND THE MAXIMUM PROBABILITY TO REACH FROM START_NODE TO END_NODE.
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
           
        //BUILD ADJACENCY LIST OF GRAPH FOR EASY APPLICATION OF ALGORITHM AND EFFICIENT MEMORY USAGE TOGETHER.
        vector<pair<int,double>> g[n];
        
        int j = 0;
        for (auto i : edges) {
            g[i[0]].push_back({i[1],succProb[j]});
            g[i[1]].push_back({i[0],succProb[j++]});
        }

        //GET MAXIMUM PROBABILITIES TO REACH FROM START_NODE TO ALL NODES.
        vector<double> probs = dijkistra(g,start_node,n);

        //GIVE PROBABILITY TO REACH END_NODE
        return probs[end_node];
    }
};


/* SIMPLIFIED and OPTIMISED ABSTRACT SOLUTION USING READYMADE TEMPLATES for PRIORITY QUEUE */
class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end_node) {
        
        // BUILD ADJACENCY LIST OF GRAPH FOR EFFICIENT TRAVERSALS
        vector<pair<int,double>> g[n];
        
        int j = 0;
        for (auto i : edges) {
            g[i[0]].push_back({i[1],succProb[j]});
            g[i[1]].push_back({i[0],succProb[j++]});
        }
        
        // APPLY DIJKISTRA'S ALGORITHM WITH A CHANGE - ALWAYS SEEK FOR MAX PROBABILITY PATHS - GREEDY FOR HIGH VALUE.
        vector<double> path(n,0);
        priority_queue<pair<double,int>> pq;
        
        path[src] = 1;
        pq.push({path[src],src});
        
        while (!pq.empty()) {
            
            int curr = pq.top().second; double max_prob = pq.top().first;
            pq.pop();

            if (curr == end_node) { return max_prob; }
            
            if (max_prob < path[curr]) { continue; }
            
            for (int i=0;i<g[curr].size();i++) {
                if (g[curr][i].second > 0.0  && g[curr][i].second*path[curr] > path[g[curr][i].first]) {
                    path[g[curr][i].first] = g[curr][i].second*path[curr];
                    pq.push({path[g[curr][i].first],g[curr][i].first});
                }
            }
            
        }
        
        return path[end_node];
    }
};

// TESTER CODE
int main () {

    Solution* a = new Solution();

    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> probs = {0.5,0.5,0.3};
    int n = 3;
    int src = 0;
    int dest = 2;

    cout<<a->maxProbability(n,edges,probs,src,dest);

    return 0;
}