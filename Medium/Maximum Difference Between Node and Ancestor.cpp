#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 
   DEPTH-FIRST SEARCH 
   - FIND MIN,MAX VALUES IN SUBTREE STARTING FROM EACH NODE.
   - DIFFERENCE BETWEEN ROOT OF SUBTREE AND ITS MIN,MAX VALUES ARE LARGEST POSSIBLE DIFFERENCES IN A SUBTREE BETWEEN ANCESTOR AND NODES. 
*/

class Solution {
public:
    int v = INT_MIN; 

    pair<int,int> dfs (TreeNode* root) {

        if (!root) { return {INT_MIN,INT_MAX}; }

        auto [Lmax,Lmin] = dfs(root->left);
        auto [Rmax,Rmin] = dfs(root->right);

        int MAX = max(max(Lmax,Rmax),root->val);
        int MIN = min(min(Lmin,Rmin),root->val);

        int Bmax = max(Lmax,root->val);
        int Bmin = min(Lmin,root->val);
        v = max(v,abs(Bmax-Bmin));

        Bmax = max(Rmax,root->val);
        Bmin = min(Rmin,root->val);
        v = max(v,abs(Bmax-Bmin));

        return {MAX,MIN};
    }

    int maxAncestorDiff(TreeNode* root) {

        dfs(root);

        return v;
    }
};