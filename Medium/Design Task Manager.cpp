#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-task-manager/
// Difficulty : Medium

/* YOU CAN DESIGN THIS DATA STRUCTURE USING ORDERED HASHMAP, PRIORITY QUEUE AND ORDERED SETS. */

/* DESIGN - ORDERED HASHMAP */
class TaskManager {
public:

    // Priority , taskId -> UserId
    map<int,map<int,int>> Q1;
    // taskId -> Priority
    unordered_map<int,int> Q2;


    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            Q1[task[2]][task[1]] = task[0];
            Q2[task[1]] = task[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Q1[priority][taskId] = userId;
        Q2[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int priority = Q2[taskId];
        int userId = Q1[priority][taskId];
        Q1[priority].erase(taskId);
        if (Q1[priority].empty()) { Q1.erase(priority); }
        Q1[newPriority][taskId] = userId;
        Q2[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = Q2[taskId];
        Q1[priority].erase(taskId);
        Q2.erase(taskId);
        if (Q1[priority].empty()) { Q1.erase(priority); }
    }
    
    int execTop() {
        if (!Q1.empty()) {
            int userId = ((Q1.rbegin()->second).rbegin())->second;
            int taskId = ((Q1.rbegin()->second).rbegin())->first;
            int priority = Q1.rbegin()->first;

            Q1[priority].erase(taskId);
            Q2.erase(taskId);
            if (Q1[priority].empty()) { Q1.erase(priority); }

            return userId;
        }
        
        return -1;
    }
};