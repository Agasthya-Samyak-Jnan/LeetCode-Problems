#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* MATHEMATICAL SOLUTION BASED ON PROPERTIES OF BINARY TREE DESCRIBED IN THE PROBLEM. (COMPLETE BINARY TREE WITH ODD LEVELS REVERSED) */
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> path;
        int level = log2(label);

        // By Observing given Binary Tree Structure, (COMPLETE BINARY TREE WITH ODD LEVELS REVERSED), 
        // we get level = log2(label), level_start = 2^(level-1), level_end = 2^(level)
        // next_node = level_start + offset from start 
        // offset from start  = level_end - (curr_val/2)
        // next_node = level_start + level_end - (curr_val/2) (floor division)


        while (level > 0) {
            path.push_back(label);
            label = (pow(2,level-1)) + (pow(2,level)-1) - (label/2); 
            level--;
        }

        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};