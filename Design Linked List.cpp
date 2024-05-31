#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/design-linked-list/
// Difficulty: Medium

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/* DESIGN THE LINKED LIST ADT (USING C++ OOPS) */
class Node {
    public:
    int val;
    Node* next;
    
    Node (int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    int size;
    Node* head;
    
    MyLinkedList () {
         ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
         this->size = 0;
         head = nullptr;
    }
    
    int get(int index) { 
        if (index >= size) { return -1; }
        Node* temp = head;
        for (int i=0;i<index;i++) { temp = temp->next; }
        return temp->val;
    }
    
    void addAtHead(int val) { 
         Node* node = new Node(val);
         node->next = head;
         head = node;
         size++;
    }
    
    void addAtTail(int val) { 
         Node* node = new Node(val);
         Node* temp = head;
         if (temp == NULL) { head = node; }
         else {
             while (temp->next != NULL) {
             temp = temp->next;
             }
             temp->next = node;
         }
         size++;
    }
    
    void addAtIndex(int index, int val) {
         if (index > size) { return; }
         Node* temp = head;
         if (index == 0) { addAtHead(val); return; }
         if (index == size) { addAtTail(val); return; }
         while (index-1 > 0) {
             temp = temp->next;
             index--;
         }
             Node* node = new Node(val); 
             node->next = temp->next;
             temp->next = node;
             size++;
    }
    
    void deleteAtIndex(int index) {
         if (index >= size) { return; }
         Node* temp = head;
         if (index == 0) { 
             temp = head; 
             head = head->next;  
             delete(temp);
             size--;
             return;
         }
         while (index-1 > 0) {
             temp = temp->next;
             index--;
         }
             Node* del_node = temp->next; 
             temp->next = temp->next->next; 
             delete(del_node);
             size--;
    }
};
