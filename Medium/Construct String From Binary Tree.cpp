#include <bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-string-from-binary-tree/
// Difficulty : Medium

string ans;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* STRING MANIPULATION IDEAS + DEPTH-FIRST-SEARCH , THAT'S IT! */
 
    void dfs (TreeNode* root,string& ans) {
        
        if (!root) { return; }

        ans += "(" + to_string(root->val);
        if (!root->left && root->right) { ans += "()"; }

        dfs(root->left,ans);
        dfs(root->right,ans); 

        ans += ")";
    }
    
    string tree2str(TreeNode* root) {
        
        string ans = "";
        dfs(root,ans);
        
        return {ans.begin()+1,ans.end()-1};
        
    }

int main () {

    TreeNode a[4];
    for (int i=0;i<5;i++) { a[i].val = i+100; }

    a[0].left = &a[1];
    a[0].right = &a[2];
    a[1].left = &a[3];
    a[1].right = nullptr;
    a[4].left = a[4].right = nullptr;
    a[3].left = a[3].right = nullptr;
    a[2].left = a[2].right = nullptr;


    cout<<tree2str(&a[0])<<" ";

    return 0;
}