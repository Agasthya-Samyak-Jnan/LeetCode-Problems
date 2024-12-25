#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-width-of-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        
       if (root == nullptr) { return {}; }
        
       unsigned long long left = 0 , right = 0, maxWidth = 0;
       queue<pair<TreeNode*,unsigned long long>> q;
        
       q.push({root,0});
        
       while (!q.empty() && right-left >= 0) {
           
           int l_size = q.size();
           left = q.front().second;
           right = q.back().second;
           
           maxWidth = max(maxWidth,right-left+1);
           
           for (int i=0;i<l_size;i++) {
               auto [root,pos] = q.front(); q.pop();
               if (root->left) { q.push({root->left,2*pos+1}); }
               if (root->right) { q.push({root->right,2*pos+2}); }
           }
       }
        
       return maxWidth;
    }
};

/* 
    PYTHON3 VERSION 

    class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        q = deque()
        maxWidth = 0
        left = 0
        right = 0
        
        q.append([root,0])
        
        
        while q :
            
            left = q[0][1]
            right = q[len(q)-1][1]
            
            maxWidth = max(maxWidth,right-left+1)
            l_size = len(q)
            
            for i in range(l_size) :
                [root,pos] = q.popleft()
                if root.left : 
                    q.append([root.left,2*pos+1])
                if root.right :
                    q.append([root.right,2*pos+2])
                    
                  
        return maxWidth

*/