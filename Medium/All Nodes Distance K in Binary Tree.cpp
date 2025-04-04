#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH + HASH TABLE + BREADTH-FIRST SEARCH : TRANSFORM AND CONQUER TYPE OF PROBLEMS */
class Solution {
    public:
        // Hash Table to store Reverse Links
        unordered_map<TreeNode*,TreeNode*> parent;
    
        // Create Back Links to Root Node from Target Node to enable backward traversal. (Use DFS or BFS doesn't matter)
        void dfs (TreeNode* root, TreeNode* target) {
            if (!root) { return; }
            // No need to make back links beyond Target Node.
            if (root == target) { return; }
            // Make Back Links
            parent[root->left] = root; 
            parent[root->right] = root;
            // DFS
            dfs(root->left,target);
            dfs(root->right,target);
        }
        
        // Use Breadth-First Search to count distance from Target Node.
        // Each Level of Nodes represents Nodes +1 unit distance away from Target Node.
        // Stop BFS after you reach Nodes that are K-units distance away from Target Node.
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            
            queue<TreeNode*> q;
            unordered_map<TreeNode*,int> visited;
            vector<int> ans;
    
            dfs(root,target);
    
            q.push(target);
            visited[target] = 1;
    
            while (!q.empty() and k > 0) {
                int l = q.size();
                // Level Seperation needed to count Distance from Target Nodes.
                for (int i=0;i<l;i++) {
                    root = q.front(); q.pop();
                    // Go in All Directions from CURRENT node.
                    // Back
                    if (parent[root] and !visited[parent[root]]) { 
                        q.push(parent[root]);
                        visited[parent[root]] = 1; 
                    }
                    // Left
                    if (root->left and !visited[root->left]) { 
                        q.push(root->left);
                        visited[root->left] = 1; 
                    }
                    // Right
                    if (root->right and !visited[root->right]) { 
                        q.push(root->right); 
                        visited[root->right] = 1;
                    }
                }
                // Moved 1 more unit distance from Target, decrease k.
                k--;
            }
            
            // Get All Nodes  that are distance K-Units from Target Node.
            while (!q.empty()) { 
                ans.push_back(q.front()->val); 
                q.pop(); 
            }
    
            return ans;
        }
};