#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/throne-inheritance/
// Difficulty : Medium 

/* DESIGN PROBLEM - HASH MAP INDEXING TO N-ARY TREE + DEPTH-FIRST SEARCH */

// Custom N-ary TreeNode Definition
class Treenode {
    public:
        string val;
        bool alive;
        vector<Treenode*> children;

        Treenode (string x) { val = x; alive = true; }
}; 

class ThroneInheritance {
public:
    Treenode* KING;
    unordered_map<string,Treenode*> mp;

    ThroneInheritance(string kingName) {
        KING = new Treenode(kingName);
        mp[kingName] = KING;
    }

    //  Add new  Family Members to Family Tree as well as Hash Map.
    void birth(string parentName, string childName) {
        mp[childName] = new Treenode(childName);
        mp[parentName]->children.push_back(mp[childName]);
    }
    
    // Mark Dead Family Members in Tree Node itself.
    void death(string name) {
        mp[name]->alive = false; 
    }
    
    // Depth-First Search to get Inheritance Order.
    void getOrder (Treenode* root, vector<string>& Order) {
        if (!root) { return; }
        if (root->alive) { Order.push_back(root->val); }
        for (auto child : root->children) { getOrder(child,Order); }
    }

    vector<string> getInheritanceOrder() {
        vector<string> Order;
        getOrder(KING,Order);
        return Order;
    }
};