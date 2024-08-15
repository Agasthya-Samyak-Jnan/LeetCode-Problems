#include <bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/partition-list/
// Difficulty : Medium 

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* YOUR OWN INTUITION WORKS HERE. FIRST TRY TO SIMULATE OR VISUALISE WHAT YOU NEED TO DO. USE TWO POINTERS. */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if (!head || !head->next) { return head; }
        
        ListNode* t1 = head, *t2, *newnode = nullptr;
        
        if (head->val >= x) { 
            newnode = new ListNode(0,head);
            t1 = newnode;
        }
        
        else { 
            while (t1->next && t1->next->val < x) { t1 = t1->next; }
        }
        
        t2 = t1;
        
        while (t2->next) {
            if (t2->next->val < x) {
                ListNode* temp = t2->next;
                t2->next = t2->next->next;
                temp->next = t1->next;
                t1->next = temp;
                t1 = t1->next;
            }
            else { t2 = t2->next; }
        }
        
        if (newnode) { return newnode->next; }
        return head;
    }
};

int main () {

    ListNode* a[6];
    a[5] = new ListNode(2,nullptr);
    a[4] = new ListNode(2,a[5]);
    a[3] = new ListNode(3,a[4]);
    a[2] = new ListNode(2,a[3]);
    a[1] = new ListNode(2,a[2]);
    a[0] = new ListNode(5,a[1]);

    Solution* obj = new Solution();

    ListNode* temp = obj->partition(a[0],5);

    while (temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    return 0;
}