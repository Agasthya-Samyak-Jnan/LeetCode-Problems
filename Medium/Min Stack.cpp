#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :
// Difficulty : Medium

/* STACK APPLICATIONS */

class MinStack {
public:
    stack<pair<int,int>> s;
    
    MinStack() {
    }
    
    void push(int val) {
        int minimum = s.empty() ? val : min(s.top().first,val);
        s.push({minimum,val});  
    }
    
    void pop() {
        s.pop(); 
    }
    
    int top() {
        return s.top().second;
    }
    
    int getMin() {
        return s.top().first;
    }
};