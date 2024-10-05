#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Difficulty : Hard

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BREADTH-FIRST SEARCH FOR SERIALIZATION AND DESERIALIZATION
// '.' AND '_' AS SEPERATORS FOR EACH DATA UNIT OR NODE.
class Codec {
    public:

    string custom_stoi (string& data, int& i) {
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

        TreeNode* root = new TreeNode(stoi(custom_stoi(data,i)));
        string nodeval;
        i++;
        q.push(root);

        while (!q.empty()) {

            TreeNode* curr = q.front(); q.pop();

            nodeval = custom_stoi(data,i);
            if (nodeval != "_") { 
                curr->left = new TreeNode(stoi(nodeval)); 
                q.push(curr->left);
            }
            i++;

            nodeval = custom_stoi(data,i);
            if (nodeval != "_") { 
                curr->right = new TreeNode(stoi(nodeval)); 
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Tester to Check Tree
void dfs (TreeNode* root) {
    if (!root) { return; }
    cout<<root->val<<" ";
    dfs(root->left);
    dfs(root->right);
}

// TESTER CODE
int main () {

    TreeNode a = {400,nullptr,nullptr};
    TreeNode b = {500,nullptr,nullptr};
    TreeNode c = {30,&a,&b};
    TreeNode d = {2,nullptr,nullptr};
    TreeNode root = {1000,&d,&c};

    Codec* codec = new Codec();

    TreeNode* Root = codec->deserialize(codec->serialize(&root));

    dfs(Root);

    return 0;
}