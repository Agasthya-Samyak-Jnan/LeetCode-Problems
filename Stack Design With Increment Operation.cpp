#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Difficulty: Medium

// Problem Type : Designing
class CustomStack {
public:
    int size;
    vector<int> stack;
    int top = -1;
    
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
         if (top < size-1) { top++; stack.push_back(x); }
    }
    
    int pop() {
        if (top == -1) { return top; }
        int temp = stack[top--];
        stack.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        if (top == -1) { return; }
         for (int i=0;i<k&&i<=top;i++) {
             stack[i] += val;
         }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */