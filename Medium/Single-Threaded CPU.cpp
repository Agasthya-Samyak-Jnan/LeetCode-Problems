#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/single-threaded-cpu/
// Difficulty : Medium 

/* PRIORITY QUEUE (MIN HEAP) BASED SOLUTION */
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> procq;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> cpuq;
        vector<int> order;
        int n = tasks.size();
        long long time = 0;

        for (int i=0;i<n;i++) { procq.push({tasks[i][0],tasks[i][1],i}); }

        while (!procq.empty()) {

            time = procq.top()[0]; 
            cpuq.push({procq.top()[1],procq.top()[2]});
            procq.pop();

            while (!cpuq.empty()) {
                auto curr = cpuq.top(); cpuq.pop();
                time += curr[0];
                while (!procq.empty() and procq.top()[0] <= time) {
                    cpuq.push({procq.top()[1],procq.top()[2]});
                    procq.pop();
                }
                order.push_back(curr[1]);
            } 
            
        }

        return order;
    }
};