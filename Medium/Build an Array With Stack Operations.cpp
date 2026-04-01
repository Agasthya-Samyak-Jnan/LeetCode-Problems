#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/build-an-array-with-stack-operations/
// Difficulty : Medium

/* SIMULATION OR BRUTE FORCE */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        int idx = 0, len = target.size();
        stack<int> s;
        vector<string> ops;
        
        for (int i=1;i<=n and idx<len;i++) {
            ops.push_back("Push");
            s.push(i);
            if (target[idx] == s.top()) { idx++; }
            else {
                ops.push_back("Pop");
                s.pop();
            }
        }

        return ops;
    }
};

/* YOU DON'T NEED STACK - REDUCING BRUTE FORCE SOLUTION */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        int idx = 0, len = target.size();
        vector<string> ops;
        
        for (int i=1;i<=n and idx<len;i++) {
            ops.push_back("Push");
            if (target[idx] == i) { idx++; }
            else { ops.push_back("Pop"); }
        }

        return ops;
    }
};