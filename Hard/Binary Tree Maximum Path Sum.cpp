#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Difficulty : Hard

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 /* DEPTH-FIRST SEARCH */
 /*
            There are 4 Possible Paths from each Node in a Binary Tree.
            1. A Path from Parent Node ends at this node. 
               Only this Node's value contributes to this Path Sum.
            2. A Path starts from this Node and ends at some Node in its Left Subtree. 
               Maximum Path present in Left Subtree and this Node's value contributes to this Path Sum.
            3. A Path start from this Node and ends at some Node in its Right Subtree. 
               Maximum Path present in Right Subtree and this Node's value contributes to this Path Sum.
            4. A Path starts from some Node in Left Subtree of this Node, includes this Node and ends at some Node in Right Subtree of this Node.
               Maximum Paths in Left Subtree, Right Subtree and Value of this Node contribute make this Path Sum.

            Now, choose the best of 1,2 and 3 for each Node and return to parent Node for it to build a Maximum Sum Path for itself.

            Do NOT return 4th Path Sum. It is a Path that does not start from this Node. Compare it globally with all the Paths you have found.
*/

class Solution {
    public:
    
        int nullval = 1e9; 
        int max_sum = INT_MIN;
    
        int dfs (TreeNode* node) {
    
            if (!node) { return nullval; }
    
            int left = dfs(node->left); // Find Maximum Path Sum we can get from Left Side.
            int right = dfs(node->right); // Find Maximum Path Sum we can get from Right Side.
            
            int max_path = node->val; // Case 1
            if (left != nullval) { max_path = max(max_path,node->val+left); } // Case 2
            if (right != nullval) { max_path = max(max_path,node->val+right); } // Case 3
            if (left != nullval and right != nullval) { max_sum = max(max_sum,left+node->val+right); } // Case 4 - Global Comparison - Because a path could start and end anywhere.
            max_sum = max(max_sum,max_path); // Global Comparison - Because a path could start and end anywhere.
    
            return max_path; // Best of 1,2 and 3 to return to Parent Node
        }
    
        int maxPathSum(TreeNode* root) {
    
            dfs(root);
    
            return max_sum;
        }
};