#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-distance-in-arrays/
// Difficulty : Medium 

/* PRIORITY QUEUE (MIN AND MAX HEAP) + GREEDY */
class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrs) {
    
            int n = arrs.size(), mx, mn, ans;
            priority_queue<pair<int,int>> MAX;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> MIN;
            
            for (int i=0;i<n;i++) {
                MAX.push({arrs[i].back(),i});
                MIN.push({arrs[i].front(),i});
            }
    
            if (MAX.top().second == MIN.top().second) {
                mx = MAX.top().first;
                mn = MIN.top().first;
                MAX.pop(); MIN.pop();
                return max(abs(mx - MIN.top().first), abs(MAX.top().first - mn));
            }
    
            return abs(MAX.top().first - MIN.top().first);
        }
};