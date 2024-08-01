#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Diffculty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 
   Before You go below to Check Solution :

   PreOrder = Root(Present Node) --> Left Node --> Right Node  
   => First Value Of PreOrder is ALWAYS CURRENT NODE VALUE.

   InOrder = Left Node --> Root(Present Node) --> Right Node  
   => Values Left to CURRENT NODE VALUE all belong to LEFT SUBTREE in InOrder.
   => Values RIGHT to CURRENT NODE VALUE all belong to RIGHT SUBTREE in InOrder.
*/

/* DIVIDE AND CONQUER METHOD : 
   1. Find CURRENT NODE VALUE from PreOrder Array - Which is always the first value of preorder array.
   2. Find Position of this CURRENT NODE VALUE in Inorder array.      (this value is guaranteed to be in inorder. both orders are of same tree).
   3. Divide Inorder Array into Left and Right Partitions using CURRENT NODE VALUE.            (You NEED NOT divide Preorder Array, its your choice. ).
   4. Find CURRENT NODE VALUE'S Left and Right Node Values by Sending Partitoned Arrays to each Recursive Call.
   5. If Partition has NO ELEMENTS (Size = 0), Then RETURN null pointer. (End of a Subtree)
*/

/* RAW LOGIC IMPLEMENTATION : LOGIC DIRECTLY FROM BRAIN CONVERTED TO CODE - Space Complexity : O(2^N), Time Complexity : O(N) */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() < 1) { return nullptr; }
        
        int divide = 0;
        
        vector<int> pre,in;
        
        while (inorder[divide] != preorder[0]) { 
            in.push_back(inorder[divide]); 
            pre.push_back(preorder[divide+1]); 
            divide++; 
        }
        
        TreeNode* left = buildTree(pre,in);
        
        in.clear();
        pre.clear();
        divide++;
        while (divide < preorder.size()) {
            in.push_back(inorder[divide]);
            pre.push_back(preorder[divide]);
            divide++;
        }
         
        TreeNode* right = buildTree(pre,in);
        
        return new TreeNode(preorder[0],left,right);
    }
};

/* OPTIMIZED SPACE USAGE - Space Complexity : O(1), Time Complexity : O(N) */
class Solution {
public:
    vector<int> preorder;
    vector<int> inorder;
    
    TreeNode* builder (int prestart, int instart, int inend) {
        
        if (instart >= inend) { return nullptr; }
        
        int nodeval = preorder[prestart];
        
        int divide = instart;
        while (inorder[divide] != nodeval) { divide++; }
        
        int leftsize = divide-instart;
        
        TreeNode* left = builder(prestart+1,instart,divide);
        TreeNode* right = builder(prestart+1+leftsize,divide+1,inend);
        
        return new TreeNode(nodeval,left,right);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return builder(0,0,inorder.size());
    }
};