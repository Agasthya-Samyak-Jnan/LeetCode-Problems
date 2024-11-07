#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/operations-on-tree/
// Difficulty : Medium

/* HASH TABLE + DEPTH-FIRST SEARCH */

class LockingTree {
public:
    vector<int> locked, parent;
    vector<vector<int>> children;
    int n;
    
    LockingTree(vector<int>& parent) {
        n = parent.size();
        this->parent = parent;
        locked = vector<int>(n,0);
        children = vector<vector<int>>(n);
        for (int i=1;i<n;i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    // Check if ancestors are Locked or Not using Depth-First Search
    bool dfs (int i) {
        if (i == -1) { return true; }
        if (locked[i] != 0) { return false; }
        return dfs(parent[i]);
    }
    
    // Find Locked Descendants and Unlock them.
    bool findAndUnlock (int i) {
        bool found = false;  
        if (locked[i] != 0) { 
            locked[i] = 0;  
            found = true;
        }
        for (auto node : children[i]) { found = findAndUnlock(node) || found; }
        return found;
    }
    
    bool lock(int num, int user) {
        if (locked[num] == 0) {
            locked[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (locked[num] == 0 && dfs(num) && findAndUnlock(num)) {
            locked[num] = user;
            return true;
        }
        return false;
    }
};
