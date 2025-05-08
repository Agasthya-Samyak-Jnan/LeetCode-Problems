#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* PROPERTIES OF BINARY SEARCH TREE */

/* 
    DON'T DIRECTLY TRY SEARCHING VALUE WITHOUT BUILDING ARRAY : TWO REASONS 
    1. YOU WILL NEED TO TRACK PREVIOUS OR NEXT VALUE (DEPENDING ON YOUR TYPE OF BINARY SEARCH) WHICH MAKES INORDER TRAVERSAL METHOD COMPLICATED.
    2. SKEWED TREES (TREES THAT ARE KINDA LIKE LONG LINKED LIST IN SOME PARTS OR AS A WHOLE) WILL ANYWAYS CAUSE O(N) TIME INSTEAD OF O(logN) TIME.
       TESTCASES CAN HAVE ANY KIND OF TREE (SKEWED OR BALANCED OR SKEWED IN SOME PARTS), SO BETTER BUILD A SORTED ARRAY AND DO BINARY SEARCH ON IT.
*/

/* INORDER TRAVERSAL OF BST TO GET SORTED ARRAY OF BST + BINARY SEARCH ON SORTED ARRAY OF BST - TIME (N + QlogN) , SPACE (N) */
class Solution {
    public:
        vector<int> bst;
        int n;

        // INORDER TRAVERSAL ON BST = SORTED ARRAY OF NUMBERS IN BST
        void inorder (TreeNode* root) {
            if (!root) { return; }
            inorder(root->left);
            bst.push_back(root->val);
            inorder(root->right);
        }
    
        int bin_search (int target) {
    
            int low = 0, high = n, mid;
    
            while (low < high) {
                mid = (low+high)/2;
                if (bst[mid] == target) { return -1; }
                if (bst[mid] < target) { low = mid + 1; }
                else { high = mid; }
            }
    
            return low;
        }
    
        vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    
            vector<vector<int>> ans;
    
            inorder(root);
            n = bst.size();
    
            for (auto q : queries) {
                int idx = bin_search(q);
                if (idx == -1) { ans.push_back({q,q}); }
                else if (idx == n) { ans.push_back({bst[n-1],-1}); }
                else if (idx == 0) { ans.push_back({-1,bst[0]}); }
                else { ans.push_back({bst[idx-1],bst[idx]}); }
            }
            
            return ans;
        }
};