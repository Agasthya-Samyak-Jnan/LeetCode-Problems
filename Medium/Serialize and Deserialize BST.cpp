#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/serialize-and-deserialize-bst/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Seperation of Nodes using '.' and nullptr represented by '_'

// DEPTH-FIRST SEARCH SERIALIZATION
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) { return "_."; }
        return to_string(root->val) + "." + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* dfs (string& s, int& i) {
        
        string temp;
        while (s[i] != '.') { temp += s[i]; i++; }
        
        if (temp == "_") { return nullptr; }
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = dfs(s,++i);
        root->right = dfs(s,++i);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int i=0;
        return dfs(s,i);
    }
};


// BREADTH-FIRST SEARCH SERIALIZATION
class Codec {
public:

    
   string get_node (string& data, int& i) {
        int j = i;
        while (data[i] != '.') { i++; }
        return data.substr(j,i-j);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
       if (root == nullptr) { return {}; }
    
       string ans;
       queue<TreeNode*> q;
       q.push(root);
        
       while (!q.empty()) {

            root = q.front(); q.pop();

            if (!root) { ans += "_."; continue; }
            ans += (to_string(root->val)+'.');

            q.push(root->left); 
            q.push(root->right); 

       }

       return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize (string data) {

        if (data.length() == 0) { return nullptr; }

        queue<TreeNode*> q; 
        int i=0;

        TreeNode* root = new TreeNode(stoi(get_node(data,i)));
        string nodeval;
        i++;
        q.push(root);

        while (!q.empty()) {

            TreeNode* curr = q.front(); q.pop();

            nodeval = get_node(data,i);
            if (nodeval != "_") { 
                curr->left = new TreeNode(stoi(nodeval)); 
                q.push(curr->left);
            }
            i++;

            nodeval = get_node(data,i);
            if (nodeval != "_") { 
                curr->right = new TreeNode(stoi(nodeval)); 
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};