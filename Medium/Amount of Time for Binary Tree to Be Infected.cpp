#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
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
    HASH TABLE FOR MAKING THIS TREE A GRAPH FOR MOVING BACKWARDS + BREADTH-FIRST SEARCH ON LOGICAL GRAPH FROM INFECTED POINT.
    NUMBER OF STEPS TAKEN TO REACH FARTHEST NODES IS THE TIME TAKEN TO INFECT ALL. 
*/
class Solution {
    public:
        unordered_map<TreeNode*,TreeNode*> back;
        TreeNode* infected;
    
        void build_graph (TreeNode* root, int start) {
            if (!root) { return; }
            if (root->val == start) { infected = root; }
            if (root->left) { 
                back[root->left] = root; 
                build_graph(root->left,start);
            }
            if (root->right) { 
                back[root->right] = root; 
                build_graph(root->right,start);
            }
        }
    
        int bfs () {
    
            queue<TreeNode*> q;
            unordered_map<TreeNode*,int> visited;
            int time = -1;
    
            q.push(infected);
            visited[infected] = 1;
    
            while (!q.empty()) {
                int l = q.size();
                for (int k=0;k<l;k++) {
                    infected = q.front(); q.pop();
                    if (infected->left and !visited[infected->left]) { 
                        q.push(infected->left); 
                        visited[infected->left] = 1;
                    } 
                    if (infected->right and !visited[infected->right]) { 
                        q.push(infected->right); 
                        visited[infected->right] = 1;
                    } 
                    if (back[infected] and !visited[back[infected]]) {
                        q.push(back[infected]); 
                        visited[back[infected]] = 1;
                    }
                }
                time++;
            }
    
            return time;
        }
    
        int amountOfTime(TreeNode* root, int start) {
            build_graph(root,start);
            return bfs();
        }
};