#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations
// Difficulty : Medium 

/* GRAPH-LIKE MODELLING + UNION FIND + ARRAY DIFFERENCE */
class UFS {
public:
    int n;
    vector<int> parent, rank;
    unordered_map<int,vector<int>> groups;

    UFS (int n) {
        this->n = n;
        rank = vector<int>(n,0);
        parent = vector<int>(n);
        for (int i=0;i<n;i++) { groups[i] = {i}; }
        iota(parent.begin(),parent.end(),0);
    }

    void Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { 
            parent[B] = A; 
            for (auto mem : groups[B]) { groups[A].push_back(mem); }
            groups[B] = {};
        }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
            for (auto mem : groups[A]) { groups[B].push_back(mem); }
            groups[A] = {};
        }
    }

    int find (int a) {
        return parent[a] = (parent[a] == a) ? a : find(parent[a]);
    }

};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size(), hamming_distance = 0;
        UFS ufs(n);

        // Find index groups, since swaps imply indices can exchange values.
        // All such indices form a group or component in which elements can be swapped among indices in that group. 
        // Use UNION FIND DATA STRUCTURE to get all the groups (or simply, building the graph.) using the allowedSwaps.
        for (auto& edge : allowedSwaps) { ufs.Union(edge[0],edge[1]); }

        // Find number of different numbers among index groups of source and target arrays - Array difference - for every group. 
        // The size of difference for each group tells how many numbers can't be swapped to make target[idx] == source[idx]. 
        // Sum of those gives total unswappable numbers, that is hamming distance of source and target.
        for (auto& p : ufs.groups) {
            auto group = p.second;
            unordered_multiset<int> s, t;
            for (auto& idx : group) {
                auto it = t.find(source[idx]);
                if (it != t.end()) { t.erase(it); }
                else { s.insert(source[idx]); }
                it = s.find(target[idx]);
                if (it != s.end()) { s.erase(it); }
                else { t.insert(target[idx]); }
            }
            hamming_distance += s.size(); // or t.size()
        }

        return hamming_distance;
    }
};

/* GRAPH-LIKE MODELLING + DEPTH-FIRST SEARCH + ARRAY DIFFERENCE */
/* 
   This can be solved by building graph in form of adjacency list,
   then doing DEPTH-FIRST SEARCH on it to find groups,
   Then do array difference on each group of indices for source and target and sum sizes of those differences to get hamming distance.
*/

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size(), hamming_distance = 0; // or target.size()
        vector<vector<int>> g(n);

        // Build graph.
        for (auto& edge : allowedSwaps) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        // Find groups by DFS.
        vector<int> visited(n,0);
        vector<vector<int>> groups;
        for (int i=0;i<n;i++) {
            if (visited[i]) { continue; }
            stack<int> s;
            vector<int> group;
            s.push(i);
            visited[i] = 1;
            while (!s.empty()) {
                int curr = s.top(); s.pop();
                group.push_back(curr);
                for (auto neighbor : g[curr]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                        visited[neighbor] = 1;
                    }
                }
            }
            groups.push_back(group);
        }

        // Array difference per group and sum of sizes of differences of groups.
        for (auto& group : groups) {
            unordered_multiset<int> s, t;
            for (auto& idx : group) {
                auto it = t.find(source[idx]);
                if (it != t.end()) { t.erase(it); }
                else { s.insert(source[idx]); }
                it = s.find(target[idx]);
                if (it != s.end()) { s.erase(it); }
                else { t.insert(target[idx]); }
            }
            hamming_distance += s.size(); // or t.size()
        }

        return hamming_distance;
    }
};