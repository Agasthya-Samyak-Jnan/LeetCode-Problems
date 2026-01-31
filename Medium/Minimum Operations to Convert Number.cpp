#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/minimum-operations-to-convert-number/description/
// Difficulty: Medium

using namespace std;

/* 
   MINIMUM STEPS TAKEN OR SHORTEST PATH USING BREADTH-FIRST SEARCH.
   ALL POSSIBLITIES FROM A STATE IS ONE STEP FROM IT. CHECK ALL POSSIBILITIES FIRST AND PROCEED FURTHER IF YOU DON'T FIND GOAL STATE THERE.
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        queue<int> q;
        vector<int> visited(1001, 0);
        int steps = 0, n = nums.size();

        q.push(start);

        while (!q.empty()) {
            int l = q.size();
            for (int k=0;k<l;k++) {
                int curr = q.front(); q.pop();
                if (curr == goal) { return steps; }
                for (int i=0;i<n;i++) {
                    if (curr+nums[i] >= 0 and curr+nums[i] <= 1000) {
                        if (!visited[curr+nums[i]]) { 
                            q.push(curr+nums[i]); 
                            visited[curr+nums[i]] = 1; 
                        }
                    }
                    else if (curr+nums[i] == goal) { return steps+1; }
                    if (curr-nums[i] >= 0 and curr-nums[i] <= 1000) {
                        if (!visited[curr-nums[i]]) { 
                            q.push(curr-nums[i]); 
                            visited[curr-nums[i]] = 1; 
                        }
                    }
                    else if (curr-nums[i] == goal) { return steps+1; }
                    if ((curr^nums[i]) >= 0 and (curr^nums[i]) <= 1000) {
                        if (!visited[curr^nums[i]]) { 
                            q.push(curr^nums[i]); 
                            visited[curr^nums[i]] = 1; 
                        }
                    }
                    else if ((curr^nums[i]) == goal) { return steps+1; }
                }
            }
            steps++;
        }

        return -1;
    }
};