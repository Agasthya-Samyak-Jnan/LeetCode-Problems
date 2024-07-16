#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/create-binary-tree-from-descriptions/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* NOTE : All Below Solutions have Time Complexity : O(N) , Space Complexity : O(N) */

/* Simple and Intuitive Solution to Understand */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        TreeNode* head;
        unordered_map<int,TreeNode*> mp;
        
        /* Taking Advantage of Fact that Child Nodes are Unique to each Parent in a TREE. */
        for (auto i : descriptions) {
            TreeNode* temp = new TreeNode(i[1]);
            mp[i[1]] = temp;
        }
        /* Which one was NOT created , was ROOT of TREE. Think Why! */
        for (auto i :descriptions) {
            if (mp[i[0]] == 0) { // Got the ROOT
                head = new TreeNode(i[0]);
                mp[i[0]] = head;
            }
            if (i[2] == 1) { mp[i[0]]->left = mp[i[1]]; }
            else { mp[i[0]]->right = mp[i[1]]; }
        }
        
        return head;
    }
};

/* LOW-LEVEL MEMORY ACCESS OPTIMISED SOLUTION - ARRAY AND DIRECT INDEXING */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        TreeNode* head;
        TreeNode* mp[100001]; // You can use HashMap here instead of Array.
        int isChild[100001];  // You can use HashMap here instead of Array.
        memset(mp,0,sizeof(mp));
        memset(isChild,0,sizeof(isChild));
        
        for (auto i : descriptions) {
            if (mp[i[0]] == 0) { TreeNode* parent = new TreeNode(i[0]); mp[i[0]] = parent; }
            if (mp[i[1]] == 0) { TreeNode* temp = new TreeNode(i[1]); mp[i[1]] = temp; }
            isChild[i[1]] = 1;
            if (i[2] == 1) { mp[i[0]]->left = mp[i[1]]; }
            else { mp[i[0]]->right = mp[i[1]]; }
        }
        
        for (auto i : descriptions) {
            if (isChild[i[0]] == 0) { head = mp[i[0]]; return head; }
        }
            
        return head;
    }
};