#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-circular-queue/
// Difficulty : Medium

/* Designing Problem: Circular Queue Using Linked List */
class Node {
    public:
    int a;
    Node* next;
    
    Node (int value) {
        a = value;
        next = nullptr;
    }
};

class MyCircularQueue {
public:
    
    int size;
    int nodes;
    Node* h_link;
    Node* rp;
    
    MyCircularQueue(int k) {
        size = k;
        nodes = 0;
        h_link = nullptr;
        rp = h_link;
    }
    
    bool enQueue(int value) {
         if (this->isFull()) { return false; }
         if (this->isEmpty()) {
            h_link = new Node(value);
            rp = h_link;
            rp->next = h_link;
         }
         else {
             Node* p = new Node(value);
             p->next = rp->next;
             rp->next = p;
             rp = rp->next;
         }
         this->nodes++;
         return true;
    }
    
    bool deQueue() {
        if (this->isEmpty()) { return false; }
        if (this->nodes == 1) {
            delete(h_link);
            h_link = nullptr;
        }
        else {
            rp->next = h_link->next;
            delete(h_link);
            h_link = rp->next;
        }
        this->nodes--;
        return true;
        
    }
    
    int Front() {
        if (this->isEmpty()) { return -1; }
        return this->h_link->a;
    }
    
    int Rear() {
        if (this->isEmpty()) { return -1; }
        return this->rp->a;
    }
    
    bool isEmpty() {
        return (!this->h_link);
    }
    
    bool isFull() {
        return (this->nodes == this->size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */