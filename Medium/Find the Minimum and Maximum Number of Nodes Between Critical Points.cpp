#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Difficulty : Medium

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* SINGLY LINKED LIST MINDSET - ONLY MOVE FORWARD, THERE'S NO WAY BACK ! */
class Solution {
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            
            int prevCrit = -1, minDist = INT_MAX;
            int firstCrit = INT_MAX, lastCrit = INT_MIN, curr_pos = 1;
            bool Minima , Maxima;
            ListNode* prev = head;
    
            head = head->next;
    
            while (head->next) {
    
                Minima = prev->val > head->val and head->val < head->next->val;
                Maxima = Minima or (prev->val < head->val and head->val > head->next->val);
    
                if (Minima or Maxima) {
                    if (prevCrit != -1) { minDist = min(minDist,curr_pos-prevCrit); }
                    prevCrit = curr_pos;
                    firstCrit = min(firstCrit,curr_pos);
                    lastCrit = max(lastCrit,curr_pos);
                }
    
                prev = head;
                head = head->next;
                curr_pos++;
            }
    
            if (firstCrit == INT_MAX and lastCrit == INT_MIN or (firstCrit == lastCrit)) { 
                return {-1,-1}; 
            }
    
            return {minDist,lastCrit - firstCrit};
        }
};