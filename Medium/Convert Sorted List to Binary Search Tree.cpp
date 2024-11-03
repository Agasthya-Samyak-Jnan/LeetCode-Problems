#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DIVIDE AND CONQUER METHOD */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if (!head) { return nullptr; }
        if (!head->next) { return new TreeNode(head->val); }
        
        ListNode *cut_list = head, *mid = head, *fast = head;
        
        // Find Middle Node of List
        while (fast && fast->next) {
            cut_list = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        
        /* Split the List into Two Halves at "mid" to avoid 
           Reusage of nodes in future recursive calls. */
        cut_list->next = nullptr;
        
        TreeNode* root = new TreeNode(mid->val);
        
        // Repeat same for Child Nodes until List is Completed.
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};