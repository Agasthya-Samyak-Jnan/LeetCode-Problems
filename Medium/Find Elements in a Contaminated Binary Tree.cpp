#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH + HASH TABLE - O(N) Preprocessing and O(1) Find */
class FindElements {
    public:
        unordered_set<int> nodes;
    
        FindElements(TreeNode* root) {
            dfs(root,0);
        }
            
        void dfs (TreeNode* root, int x) {
            if (!root) { return; }
            dfs(root->left,2*x+1);
            nodes.insert(x);
            dfs(root->right,2*x+2);
        }
        
        bool find(int target) {
            return nodes.find(target) != nodes.end();
        }
};

/* BREADTH-FIRST SEARCH + HASH TABLE - O(N) Preprocessing and O(1) Find */
class FindElements {
    public:
        unordered_set<int> nodes;
    
        FindElements(TreeNode* root) {
    
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
    
            while (!q.empty()) {
                auto[root,x] = q.front(); q.pop();
                nodes.insert(x);
                if (root->left) { q.push({root->left,2*x+1}); }
                if (root->right) { q.push({root->right,2*x+2}); }
            }
            
        }
        
        bool find(int target) {
            return nodes.find(target) != nodes.end();
        }
};

/* ONLY DEPTH-FIRST SEARCH - O(N) Find */
class FindElements {
    public:
        TreeNode* root;
    
        FindElements(TreeNode* root) {
            this->root = root;
        }
    
        bool dfs (TreeNode* root, int x, int target) {
            if (!root or x > target) { return false; }
            if (x == target) { return true; }
            return dfs(root->left,2*x+1,target) or dfs(root->right,2*x+2,target);
        }
        
        bool find(int target) {
            return dfs(root,0,target);
        }
};

/* ONLY BREADTH-FIRST SEARCH - O(N) Find */
class FindElements {
    public:
        TreeNode* root;
    
        FindElements(TreeNode* root) {
            this->root = root;
        }
        
        bool find(int target) {
            
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
    
            while (!q.empty()) {
                auto[root,x] = q.front(); q.pop();
                if (x == target) { return true; }
                if (root->left and 2*x+1 <= target) { q.push({root->left,2*x+1}); }
                if (root->right and 2*x+2 <= target) { q.push({root->right,2*x+2}); }
            }
    
            return false;
        }
};
    