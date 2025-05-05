#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH :

    - WHEN YOU REMOVE AN EDGE, THE PRODUCT OF TWO SUBTREES FORMED SHOULD BE MAXIMIZED. 
    - THERE IS MATH TRICK TO FIND SUCH A PARTITION, SO CHECK FOR EVERY POSSIBLE PARTITION, BY FINDING PRODUCT FOR EACH EDGE REMOVAL.
    - IF YOU SPLIT TREE INTO TWO SUBTREES WHEN REMOVING AN EDGE - SUM OF ELEMENTS IN FIRST SUBTREE = (SUM OF ALL ELEMENTS IN TREE) - (SUM OF ALL ELEMENTS IN SECOND SUBTREE)

    - FINDING SUM EACH TIME FOR A SUBTREE FROM A NODE TAKES O(N) TIME FOR EACH EDGE RESULTING IN O(N^2) TOTAL TIME, 
      HENCE OPTIMIZE THIS PART BY FIRST GOING THROUGH FULL TREE AND BUILDING SUM FOR EACH SUBTREE STARTING FROM EACH NODE USING POSTORDER TRAVERSAL.
      THIS TAKES O(N) TIME AND THIS PREPROCESSING PART IS NEEDED.
    - THEN REMOVE EACH EDGE FROM EACH NODE IN TREE, CALCULATE PRODUCT OF SUBTREES AND KEEP COMPARING FOR MAX PRODUCT.
      THIS TAKES O(2N) TIME BECAUSE OF 2 EDGES PER NODE (THIS IS A BINARY TREE - EACH NODE HAS 2 EDGES), HENCE O(N) TIME.
    - THIS TAKES O(LogN) SPACE DUE TO RECURSION STACK STORING TREE NODES UPTO OF MAXIMUM DEPTH OF TREE WHEN BALANCED, O(N) IF TREE IS SKEWED.
*/

class Solution {
    public:
        int max_sum;
        long long mod = 1e9 + 7, max_product = 0;
    
        int postorder_sum (TreeNode* root) {
            if (!root) { return 0; }
            return root->val += postorder_sum(root->left) + postorder_sum(root->right);
        }
    
        void findMax (TreeNode* root) {
            if (root->left) {
                max_product = max(max_product,((long long)(max_sum-root->left->val)*(long long)(root->left->val)));
                findMax(root->left);
            }
            if (root->right) {
                max_product = max(max_product,((long long)(max_sum-root->right->val)*(long long)(root->right->val)));
                findMax(root->right);
            }
        }
    
        int maxProduct(TreeNode* root) {
            max_sum = postorder_sum(root);
            findMax(root);
            return max_product % mod;
        }
};