#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/deepest-leaves-sum/
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
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        while (!q.empty()) {
            sum = 0;
            int l = q.size();
            for (int i=0;i<l;i++) {
                root  = q.front(); q.pop();
                sum += root->val;
                if (root->left) { q.push(root->left); }
                if (root->right) { q.push(root->right); }
            }
        }
        
        return sum;
    }
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    int maxDepth = 0, sum = 0;
    
    void dfs (TreeNode* root, int depth) {
        if (!root) { return; }
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                sum = root->val;
                maxDepth = depth;
            }
            else if (depth == maxDepth) { sum += root->val; }
        }
        else {
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};

/*
    PYTHON3 VERSION

    # BREADTH-FIRST SEARCH
    class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        
        q = deque()
        q.append(root)
        sum = 0
        
        while q :
            sum = 0
            l = len(q)
            for i in range(0,l):
                root = q[0]
                sum += q[0].val
                q.popleft()
                if root.left :
                    q.append(root.left)
                if root.right :
                    q.append(root.right)
        
        return sum

    # DEPTH-FIRST SEARCH
    class Solution:
    
    def __init__ (self) :
        self.maxDepth = 0
        self.sum = 0
        
    def dfs (self, root, depth) :
        
        if not root :
            return 
        
        if not root.left and not root.right :
            if depth > self.maxDepth :
                self.sum = root.val
                self.maxDepth = depth
            elif depth == self.maxDepth :
                self.sum += root.val
                
        else :
            self.dfs(root.left,depth+1)
            self.dfs(root.right,depth+1)
    
    
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        
        self.dfs(root,0)
        return self.sum


*/
