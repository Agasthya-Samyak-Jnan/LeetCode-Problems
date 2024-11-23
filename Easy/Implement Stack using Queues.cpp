#include<bits/stdc++.h>

using namespace std;
 
// Link to the Problem : https://leetcode.com/problems/implement-stack-using-queues/
// Difficulty : Easy

/* USING 2 QUEUES */
class MyStack {
public:
    queue<int> q,sq;
    
    MyStack() {}
    
    void push(int x) {
        while (!q.empty()) { sq.push(q.front()); q.pop(); }
        q.push(x);
        while (!sq.empty()) { q.push(sq.front()); sq.pop(); }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/* USING 1 QUEUE */
class MyStack {
public:
    queue<int> q;
    
    MyStack() {}
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        while (n) {
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
