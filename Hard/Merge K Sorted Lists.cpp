#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :
// Difficulty : Hard

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* BRUTE FORCE METHOD - MERGE RESULTING LIST WITH EACH FOLLOWING LIST - TIME LIMIT EXCEEDED */
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1 && !list2) { return nullptr; }
        
        if (list1 && !list2) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        
        if (!list1 && list2) { return new ListNode(list2->val,mergeTwoLists(list1,list2->next)); }
        
        if (list1->val < list2->val) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        return new ListNode(list2->val,mergeTwoLists(list1,list2->next));
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* sorted_list = nullptr;
            
        for (auto list : lists) { sorted_list = mergeTwoLists(sorted_list,list); }
        
        return sorted_list;
        
    }
};

/* MERGE SORT CONCEPT APPLIED TO LIST OF LISTS AND FOR MERGING TWO LISTS AS WELL RECURSIVELY - DIVIDE AND CONQUER METHOD */
class Solution {
public:
    vector<ListNode*> lists;
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1 && !list2) { return nullptr; }
        
        if (list1 && !list2) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        
        if (!list1 && list2) { return new ListNode(list2->val,mergeTwoLists(list1,list2->next)); }
        
        if (list1->val < list2->val) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        return new ListNode(list2->val,mergeTwoLists(list1,list2->next));
        
    }
    
    ListNode* merge_sort (int start, int end) {
        if (start < end) {
            int mid = (start+end)/2;
            ListNode* left = merge_sort(start,mid);
            ListNode* right = merge_sort(mid+1,end);
            return mergeTwoLists(left,right);
        }
        return lists[end];
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        this->lists = lists;
            
        return merge_sort (0,lists.size()-1);
    }
};

/* HEAP METHOD - PRIORITY QUEUE - MOST OPTMISED SOLUTION */
/* DRY RUN AND THINK MORE TO UNDERSTAND */
// FIRST THOUGHTS : PUSH EACH NODE TO HEAP AND POP OUT ONE-BY-ONE TO FORM SORTED LIST
/* SECOND THOUGHTS : SINCE HEAP MAINTAINS RELATIVE ORDER AND LISTS ARE ALREADY SORTED, PUSH EACH LIST TO HEAP
                     THEN, POP A LIST , INSERT ITS CURRENT NODE TO ANSWER AND PUSH REMAINING PART OF LIST BACK TO HEAP.
                     REPEAT THIS UNTIL HEAP BECOMES EMPTY.
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*,vector<ListNode*>,decltype(compare)> pq(compare);
        
        for (ListNode* list : lists) {
            if (list == nullptr) { continue; }
            pq.push(list);
        }
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(!pq.empty()) {
            curr->next = pq.top(); pq.pop();
            if (curr->next->next != nullptr) { pq.push(curr->next->next); }
            curr = curr->next;
        }
        
        return head->next;
    }
};