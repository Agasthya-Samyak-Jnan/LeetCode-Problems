#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/linked-list-components/
// Difficulty : Medium 

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* HASH TABLE METHOD */

/* Solution 1 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        bool mp[10001] = {0};
        int components = 0;
        
        for (auto i : nums) { mp[i] = 1; }
        
        while (head) { 
            if (mp[head->val]) { components++; }
            while (head && mp[head->val]) { head = head->next; }
            if (head) { head = head->next; }
        }
        
        return components;
    }
};

/* Solution 2 : Better Solution */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        bool mp[10001] = {0};
        bool in_component = false;
        int components = 0;
        
        for (auto i : nums) { mp[i] = 1; }
        
        while (head) { 
            // Entering a new Component
            if (mp[head->val] && !in_component) { components++; in_component = true; }
            // Went Out of this Component
            else if (!mp[head->val]) { in_component = false; }
            head = head->next;
        }
        
        return components;
    }
};