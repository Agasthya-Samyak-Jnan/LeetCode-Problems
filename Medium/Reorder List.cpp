#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : 
// Difficulty : Medium


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*  
    Question can be alternatively defined as : Modify a List by Interleaving First and Last Nodes of a Given List one after other.

    Use Two Pointers AND Stack. You can use Recursion as well.

*/
class Solution {
public:
    void reorderList(ListNode* head) {
        
        //if (!head || !head->next || !head->next->next) { return; }
        
        stack<ListNode*> s;
        
        ListNode* i = head, *j = head->next;
        
        // Reach Middle of List Using Slow-Fast Pointers Method. (1:2 Speed)
        while (j && j->next) { i = i->next; j = j->next->next; }
        
        // Disconnect the Other Half after Keeping Pointer to it.
        j = i; i = i->next; j->next = nullptr;
        
        // Push Other Half onto Stack.
        while (i) { 
            s.push(i); 
            //j = i; 
            i = i->next; 
            //delete j;
        }
        
        // Set Back to Start of List.
        i = head;
        
        // Pop Node from Stack and put each node next to a node in List.
        while (!s.empty()) {
            ListNode* temp = s.top(); s.pop();
            temp->next = i->next;
            i->next = temp;
            i = i->next->next;
        }
    }
};