#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/implement-queue-using-stacks/
// Difficulty : Easy

class MyQueue {
public:
    stack<int> sm, ss;
    
    MyQueue() {}
    
    void push(int x) {
        
        while (!sm.empty()) { ss.push(sm.top()); sm.pop(); }
        sm.push(x);
        while (!ss.empty()) { sm.push(ss.top()); ss.pop(); }
        
    }
    
    int pop() {
        int front = sm.top();
        sm.pop();
        return front;
    }
    
    int peek() {
        return sm.top();
    }
    
    bool empty() {
        return sm.empty();
    }
};