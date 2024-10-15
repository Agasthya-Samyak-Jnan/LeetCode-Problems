#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-circular-deque/
// Difficulty : Medium 

/* You can use In-Built Deque Templates as Well. */

/* Singly-Linked List Design : InsertLast and DeleteLast run in O(N) Time , all others in O(1) Time. */
class Node {
public:
    int val;
    Node* next;
    
    Node () { val = -1; next = nullptr; }
    
    Node (int val) { this->val = val; next = nullptr; }
    
    Node (int val, Node* next) { this->val = val; this->next = next; }
};

class MyCircularDeque {
public:
    Node *head, *tail;
    int n,size;
    
    MyCircularDeque(int k) {
        head = new Node();
        tail = new Node();
        n = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        
        if (size == n) { return false; }
        
        Node* newnode = new Node(value,head->next);
        head->next = newnode;
        size++;
        
        if (size == 1) { tail->next = newnode; }
        
        return true;
    }
    
    bool insertLast(int value) {
        
        if (size == n) { return false; }
        
        
        Node* temp = head;
        while (temp->next) { temp = temp->next; }
        temp->next = new Node(value);
        tail->next = temp->next;
        size++;
        
        if (size == 1) { head->next = temp->next; }
        
        return true;
    }
    
    bool deleteFront() {
    
        if (size == 0) { return false; }
        
        Node* temp = head->next->next;
        delete head->next;
        head->next = temp;
        size--;
        
        if (size == 0) { tail->next = head->next = nullptr; }
        
        return true;
    }
    
    bool deleteLast() {
        
        if (size == 0) { return false; }
        
        Node* temp = head;
        while (temp->next && temp->next->next) { temp = temp->next; }
        if (temp->next) { delete temp->next; }
        temp->next = nullptr;
        tail->next = temp;
        size--;
        
        if (size == 0) { tail->next = head->next = nullptr; }
        
        return true;
    }
    
    int getFront() {
        return head->next ? head->next->val : -1;
    }
    
    int getRear() {
        return tail->next ? tail->next->val : -1;
    }
    
    bool isEmpty() {
        return !head->next;
    }
    
    bool isFull() {
        return size == n;
    }
};