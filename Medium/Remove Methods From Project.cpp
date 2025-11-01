#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/remove-methods-from-project/
// Difficulty: Medium

using namespace std;

/* GRAPH - THINK PROJECT AS GRAPH OF METHODS, KEEP ALL NORMAL COMPONENTS + NORMAL-BUG MIXED COMPONENTS , DON'T KEEP FULLY BUG METHOD CONTAINING COMPONENTS */

/* DEPTH-FIRST SEARCH (ITERATIVE or RECURSIVE its your choice) */
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> g(n);
        stack<int> s;
        vector<int> visited(n,0);
        unordered_set<int> bugMethods;
        vector<int> project;
        bool keepBugMethods = false;

        for (auto e : invocations) { g[e[0]].push_back(e[1]); }

        s.push(k);
        visited[k] = 2;
        while (!s.empty()) {
            int curr = s.top(); s.pop();
            bugMethods.insert(curr);
            for (auto next : g[curr]) {
                if (!visited[next]) {
                    s.push(next);
                    visited[next] = 2;
                }
            }
        }

        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                s.push(i);
                visited[i] = 1;
                while (!s.empty()) {
                    int curr = s.top(); s.pop();
                    project.push_back(curr);
                    for (auto next : g[curr]) {
                        if (!visited[next]) {
                            s.push(next);
                            visited[next]++;
                        }
                        else if (visited[next] == 2) { keepBugMethods = true; }
                    }
                }
            }
        }

        if (keepBugMethods) {
            for (auto method : bugMethods) { project.push_back(method); }
        }

        return project;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> g(n);
        queue<int> q;
        vector<int> visited(n,0);
        unordered_set<int> bugMethods;
        vector<int> project;
        bool keepBugMethods = false;

        for (auto e : invocations) { g[e[0]].push_back(e[1]); }

        q.push(k);
        visited[k] = 2;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            bugMethods.insert(curr);
            for (auto next : g[curr]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = 2;
                }
            }
        }

        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
                while (!q.empty()) {
                    int curr = q.front(); q.pop();
                    project.push_back(curr);
                    for (auto next : g[curr]) {
                        if (!visited[next]) {
                            q.push(next);
                            visited[next]++;
                        }
                        else if (visited[next] == 2) { keepBugMethods = true; }
                    }
                }
            }
        }

        if (keepBugMethods) {
            for (auto method : bugMethods) { project.push_back(method); }
        }

        return project;
    }
};