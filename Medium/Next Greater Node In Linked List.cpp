#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/next-greater-node-in-linked-list/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* BASIC SOLUTION - BRUTE FORCE */
class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            
            ListNode* temp;
            vector<int> ans;
    
            while (head) {
                temp = head;
                while (temp and temp->val <= head->val) { temp = temp->next; }
                ans.push_back(temp ? temp->val : 0);
                head = head->next;
            }
    
            return ans;
        }
};

/* MONOTONIC STACK BASED SOLUTION */
class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
    
            int n = 0;
            stack<int> s;
            vector<int> nums;
    
            while (head) { 
                nums.push_back(head->val); 
                head = head->next; 
                n++; 
            }
    
            vector<int> ans(n);
            
            for (int i=0;i<n;i++) {
                while (!s.empty() and nums[s.top()] < nums[i]) {
                    ans[s.top()] = nums[i];
                    s.pop();
                }
                s.push(i);
            }
    
            return ans;
        }
};

/* MONOTONIC STACK - OPTIMISED 1 PASS */
class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
    
            int i = 0;
            stack<pair<int,int>> s;
            vector<int> ans;
            
            while (head) {
                ans.push_back(0);
                while (!s.empty() and s.top().second < head->val) {
                    ans[s.top().first] = head->val;
                    s.pop();
                }
                s.push({i,head->val});
                head = head->next;
                i++;
            }
    
            return ans;
        }
    };