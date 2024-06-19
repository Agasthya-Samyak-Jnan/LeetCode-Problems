#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/linked-list-random-node/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/* Reservoir Sampling Problem */

/* Linked List Method */
class Solution {
public:
    ListNode* head;
    int size;
    
    Solution(ListNode* head) {
        this->head = head;
        size = 0;
        while (head) {
            head = head->next;
            size++;
        }
    }
    
    int getRandom() {
        int k  = rand()%size;
        ListNode* temp = head;
        while (k != 0) {
            temp = temp->next;
            k--;
        }
        return temp->val;
    }
};

/* Unordered Map Method */
class Solution {
public:
    unordered_map<int,int> list;
    int size;
    
    Solution(ListNode* head) {
        size = 0;
        while (head) {
            list[size] = head->val;
            head = head->next;
            size++;
        }
    }
    
    int getRandom() {
        int k  = rand()%(size);
        return list[k];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */