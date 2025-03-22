#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
// DIfficulty : Hard

/* UNION FIND (UNION BY RANK,PATH COMPRESSION) + PROPERTIES OF BITWISE 'AND' + GRAPH WAY OF THINKING */
/* MODIFIED UNION FIND FOR MAINTAINING 'AND' OF ALL EDGES IN A COMPONENT */
// PARENT NODE CONTAINS THE VALUE OF 'AND' OF WEIGHTS OF ALL EDGES IN A COMPONENT.
/* 'AND' OF ALL NUMBERS ENSURES THAT COST NUMBER IS MINIMAL, BECAUSE 'AND'ING ALL NUMBERS ENSURES HIGHEST NUMBER OF 0 BITS IN FINAL COST, ONCE YOU REACH 0 OR MINIMUM COST, YOU CAN TRAVERSE INFINITE NUMBER OF TIMES THROUGHOUT THE GRAPH, AND COST WON'T INCREASE, HENCE EVERY VERTEX IN COMPONENT IS STILL REACHABLE AFTER YOU ATTAIN MINIMAL COST. */
class UFS {
    public:
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<int> and_sum;
    
        UFS (int n) {
            this->n = n;
            parent = vector<int>(n);
            rank = vector<int>(n,0);
            and_sum = vector<int>(n,INT_MAX);
            iota(parent.begin(),parent.end(),0);
        }
    
        void Union (int a, int b, int w) {
            int A = find(a), B = find(b); 
            if (A == B) { 
                and_sum[A] &= w;
                and_sum[B] &= w;
                return; 
            }
            if (rank[A] > rank[B]) { 
                parent[B] = A; 
                and_sum[A] &= (and_sum[B] & w); 
            }
            else {
                if (rank[A] == rank[B]) { rank[B]++; }
                parent[A] = B;
                and_sum[B] &= (and_sum[A] & w);
            }
        }
    
        int find (int a) {
            return parent[a] = (a == parent[a]) ? a : find(parent[a]);
        }
    
    };
    
    class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    
            UFS ufs(n);
            vector<int> ans;
            
            for (auto& e : edges) { ufs.Union(e[0],e[1],e[2]); }
    
            for (auto& q : query) {
                if (ufs.find(q[0]) != ufs.find(q[1])) { ans.push_back(-1); } // Seperate Components - NOT REACHABLE.
                else { ans.push_back(ufs.and_sum[ufs.find(q[0])]); } // NOTE : 'AND' OF ALL EDGE WEIGHTS OF A COMPONENT IS STORED IN PARENT , HENCE WE DO find(q[0]) , THEN FIND ITS 'AND' SUM.
            }
    
            return ans;
        }   
};