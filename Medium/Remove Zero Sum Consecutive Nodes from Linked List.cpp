#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Difficulty : Medium

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* LINKED LIST + HASH TABLE */

/* 
    - If you observe carefully, sum of node values from 0 to n Nodes REPEATS whenever a consecutive set of nodes sum to 0,
      Because they literally sum to 0 and sum before this Zero Sum consecutive numbers' reappears as a result of it.
    - Track if a sum value repeats using Hash Table. If a sum value repeats, remove the numbers that sum upto Zero, 
      by mapping sum upto a ListNode to that ListNode itself. (int -> ListNode*)
    - Keep a reverse mapping (ListNode* -> int) too, because when you remove all nodes that sum up to 0, you should also,
      remove sums and ListNodes mapping that came within those Zero Sum Nodes, otherwise future sums will refer to Old Removed Nodes, and cause errors.
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* HEAD = head;
        unordered_map<int,ListNode*> mp;
        unordered_map<ListNode*,int> mp_r;
        int sum = 0;

        while (head) {

            sum += head->val;

            if (mp.find(sum) != mp.end()) {
                ListNode* temp = mp[sum]->next;
                while (temp != head->next) {
                    mp.erase(mp_r[temp]);
                    mp_r.erase(temp);
                    temp = temp->next;
                }
                mp[sum]->next = head->next;
            }
            else if (sum == 0) { 
                HEAD = head->next; 
                mp.clear(); 
                mp_r.clear();  
            }
            else { 
                mp[sum] = head; 
                mp_r[head] = sum; 
            }

            head = head->next;

        }

        return HEAD;
    }
};