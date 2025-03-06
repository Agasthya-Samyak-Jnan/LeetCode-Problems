#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/add-two-numbers-ii/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* STACK FOR EVALUATING FROM RIGHT TO LEFT */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
            stack<int> s1, s2;
            ListNode* ans = nullptr;
            int sum;
    
            while (l1) { s1.push(l1->val); l1 = l1->next; }
            while (l2) { s2.push(l2->val); l2 = l2->next; }
    
            if (s1.size() < s2.size()) { swap(s1,s2); }
    
            while (!s1.empty() or !s2.empty()) {
    
                if (!s2.empty()) { 
                    sum = s1.top()+s2.top(); 
                    s2.pop();
                }
                else { sum = s1.top(); }
    
                s1.pop();
                ans = new ListNode(sum%10,ans);
                if (!s1.empty()) { s1.top() += sum/10; }
                else if (sum/10) { s1.push(1); }
    
            }
    
            return ans;
        }   
};