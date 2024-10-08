#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Difficulty : Easy 

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// TWO METHODS BELOW

/* BINARY TO INT MATHEMATICAL METHOD */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int num = 0;
        
        while (head) {
            num = (num*2) + head->val;
            head = head->next;
        }
        
        return num;
    }
};

/* BIT MANIPULATION METHOD */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int num = 0;
        
        while (head) {
            num = (num<<1)^(head->val);
            head = head->next;
        }
        
        return num;
    }
};