#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/accounts-merge/
// Difficulty : Medium 

/* UNION FIND (DISJOINT SET UNION) + HASH TABLE + SORTING */

template <typename obj>
class UFS {
public:
    // Disjoint Set Data Structures
    unordered_map<obj,obj> parent;
    unordered_map<obj,int> rank;

    // Initialise Disjoint Set
    UFS () {}
    
    UFS (vector<obj>& nodes) {
        for (auto &i : nodes) {
            parent[i] = i;
            rank[i] = 0;
        }  
    }

    // Combine/Union thier Families
    void Union (obj a, obj b) {    
        obj A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        } 
    }

    // Find Upper-Most Parent 
    obj find (obj a) { 
        if (parent[a] == "") { 
            parent[a] = a; 
            rank[a] = 0;
        }
        if (a == parent[a]) { return a; }          
        return parent[a] = find(parent[a]); // Compress the Recursive Path to parent by directly connecting this node to its parent.
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        
        UFS<string> ufs;
        int m = a.size(), n;
        vector<vector<string>> ans;
        unordered_map<string,int> mp1;
        
        unordered_map<string,set<string>> mp2;
        string temp;
        
        for (int i=0;i<m;i++) {
            n = a[i].size();
            for (int j=1;j<n;j++) {
                if (j>1) { ufs.Union(a[i][j-1],a[i][j]); }
                mp1[a[i][j]] = i;
            }
        }
        
        for (int i=0;i<m;i++) {
            n = a[i].size();
            for (int j=1;j<n;j++) {
                mp2[ufs.find(a[i][j])].insert(a[i][j]);
            }
        }
        
        int j = 0;
        for (auto i : mp2) {
            ans.push_back( {a[mp1[i.first]][0]} );
            for (auto email : i.second) { ans[j].push_back(email); }
            j++;
        }
        
        return ans;
    }
};