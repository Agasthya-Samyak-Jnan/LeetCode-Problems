#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/validate-binary-tree-nodes/
// Difficulty : Medium 

// Union-Finder Disjoint Set (Rank Method + Path Compression)
class UFS {
public:
    // Disjoint Set Data Structures
    int components;
    int n;
    vector<int> parent;

    // Initialise Disjoint Set
    UFS (int n) {
        this->n = n;
        components = n;
        parent = vector<int>(n);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    bool Union (int a, int b) {  
        int A = find(a), B = find(b);
        // A == B means if cycles are present, B != b means we are trying to set Two parents to a single node.
        if (A == B || B != b) { return false; }
        parent[B] = A;
        components--;
        return true;
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        if (a == parent[a]) { return a;}
        parent[a] = find(parent[a]); // Compress the Recursive Path to parent by directly connecting this node to its parent.
        return parent[a];
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        UFS* ufs = new UFS(n);
        
        for (int i=0;i<n;i++) {
            if (leftChild[i] != -1 && !ufs->Union(i,leftChild[i])) { return false; }
            if (rightChild[i] != -1 && !ufs->Union(i,rightChild[i])) { return false; }
        }
        
        return ufs->components == 1;
    }
};