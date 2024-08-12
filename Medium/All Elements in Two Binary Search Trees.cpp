#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Difficulty : Medium


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

/* SIMPLER BUT DOES MORE OPERATIONS - BUILD SORTED ARRAYS OF TWO TREES AND MERGE THEM.
   TC : m + n + (m+n)
   SC : m + n + (m+n) + (Stack : Height of Tree1) + (Stack : Height of Tree2)
*/
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int>& a) {
        if (!root) { return; }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> a,b,ans;
        inorder(root1,a);
        inorder(root2,b);
        
        int m = a.size(), n = b.size(),i=0,j=0;
        
        while (i<m && j<n) {
            if (a[i] < b[j]) { ans.push_back(a[i++]); }
            else { ans.push_back(b[j++]); }
        }
        
        while (i<m) { ans.push_back(a[i++]); }
        while (j<n) { ans.push_back(b[j++]); }
        
        return ans;
    }
};

/* COMPLICATED BUT EFFICIENT : INORDER TRAVERSE BOTH TREES ONE NODE AT A TIME BY COMPARING EACH NODE VALUE AND SELECTING
   ONE TO INCLUDE TO ANSWER ARRAY AT SAME TIME. 
   TC : Height of Tree1 + Height of Tree2 + (m+n)
   SC : (m+n) + (Stack : Height of Tree1) + (Stack : Height of Tree2)
*/

/* This Demonstrates how to split Inorder Traversal into one node at a time. */

class Solution {
public:
    stack<TreeNode*> s1,s2;
    vector<int> ans;
    
    void next () {
        
        
        TreeNode* t1 = nullptr, *t2 = nullptr;
        if (!s1.empty()) { t1 = s1.top(); }
        if (!s2.empty()) { t2 = s2.top(); }
        
        if (!t2 || (t1 && t1->val < t2->val)) {
            
            ans.push_back(t1->val);
            s1.pop();
            
            t1 = t1->right;
            while (t1) {
                s1.push(t1);
                t1 = t1->left;
            }
        }  
        
        else if (t2) {
            
            ans.push_back(t2->val);
            s2.pop();
            
            t2 = t2->right;
            while (t2) {
                s2.push(t2);
                t2 = t2->left;
            }
        }  
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        TreeNode* temp1 = root1, *temp2 = root2;
        
        if (!root1 && !root2) { return {}; }
        
        while (temp1) {
            s1.push(temp1);
            temp1 = temp1->left;
        }
        
        while (temp2) {
            s2.push(temp2);
            temp2 = temp2->left;
        }
        
        while (!s1.empty() || !s2.empty()) { next(); }
        
        return ans;
    }
};