#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/unique-binary-search-trees/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING - OPTIMIZING RECURSIVE CALLS */
/*
    BASE CASE : 1 node = 1 Unique BST
    OTHER CASES : 
        - You can build at least 1 Unique BST by taking each node from 1 to N as the root node.
        - After you take 'x' as the root node (1 <= x <= n), there will be 'x-1' nodes to be added on left branch of 'x'.
          (because there are 'x-1' values lesser than 'x', and in a BST values less than a node go to its left branch).
        - After you take 'x' as the root node (1 <= x <= n), there will be 'n-x-1' nodes to be added on right branch of 'x'.
          (because there are 'n-x-1' values greater than 'x', and in a BST values greater than a node go to its right branch).
        - The number of Unique BSTs with 'x' as root is product of Unique BSTs possible with number of nodes on its left
          and Unique BSTs possible with number of nodes on its right. (Because we want to consider all combinations, hence product)
        - The sum of Number of Unique BSTs that can be formed by each value 'x' taken as root node until 'N', gives total Number of Unique BSTs
          we can make using 1 to N nodes.
*/

/* PURE RECURSION */
class Solution {
public:
    int numTrees(int n) {
        if (n < 2) { return 1; }
        int trees = 0;
        for (int i=0;i<n;i++) {
            int left = numTrees(i);
            int right = numTrees(n-i-1);
            trees += left*right;
        }
        return trees;
    }
};

/* RECURSION + CACHING (1D-MEMOIZATION) */
class Solution {
public:
    unordered_map<int,int> cache;
    int numTrees(int n) {
        if (n < 2) { return 1; }
        if (cache[n]) { return cache[n]; }
        int trees = 0;
        for (int i=0;i<n;i++) {
            int left = numTrees(i);
            int right = numTrees(n-i-1);
            trees += left*right;
        }
        return cache[n] = trees;
    }
};

