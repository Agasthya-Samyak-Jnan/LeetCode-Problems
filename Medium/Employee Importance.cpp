#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/employee-importance/
// Difficulty : Medium

/* EMPLOYEE CLASS */
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

/* HASH MAP + BREADTH-FIRST SEARCH - GRAPH */
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int,Employee*> g;
        for (auto& e : employees) { g[e->id] = e; }

        int Importance = 0;
        queue<int> q;
        q.push(id);

        while (!q.empty()) {
            id = q.front(); q.pop();
            Importance += g[id]->importance;
            for (auto subord : g[id]->subordinates) { q.push(subord); }
        }

        return Importance;
    }
};

/* HASH MAP + DEPTH-FIRST SEARCH - GRAPH */
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int,Employee*> g;
        for (auto& e : employees) { g[e->id] = e; }

        int Importance = 0;
        stack<int> s;
        s.push(id);

        while (!s.empty()) {
            id = s.top(); s.pop();
            Importance += g[id]->importance;
            for (auto subord : g[id]->subordinates) { s.push(subord); }
        }

        return Importance;
    }
};