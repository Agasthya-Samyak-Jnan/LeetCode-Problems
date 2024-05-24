#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
// Difficulty : Medium

/* Time Complexity: O((N-1)*(log(N)))*/
/* Best Solution on Runtime among Without Compiler Optimization Solutions */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int gcd (int m, int n) {
       int r = 0;
       while (n) {
        r=m%n;
        m=n;
        n=r;
       }
       return m;
    }    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if (!head || !(head->next)) { return head; }
        
        struct ListNode* prev = head, *cur = head->next;
        
        while (cur) {
            ListNode* newnode = new ListNode(__gcd(prev->val,cur->val),prev->next);
            prev->next = newnode;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

/* Same Solution in C (Best Solution on Runtime) */
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
int gcd (int m, int n) {
       int r = 0;
       while (n) {
        r=m%n;
        m=n;
        n=r;
       }
       return m;
    }
    
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
        
        if (!head || !(head->next)) { return head; }
        
        struct ListNode* prev = head, *cur = head->next, *newnode;
        
        while (cur) {
            newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val = gcd(prev->val,cur->val);
            newnode->next = prev->next;
            prev->next = newnode;
            prev = cur;
            cur = cur->next;
        }
        return head;
}
*/
