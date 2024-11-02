#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/jump-game-iv/
// Difficulty : Hard

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    
    int minJumps(vector<int>& arr) {
        
        int n = arr.size(), jumps = 0;
        
        // Memorise all indices for Each Value.
        for (int i=1;i<n;i++) { mp[arr[i]].push_back(i); }
        
        queue<int> q;
        vector<int> visited(n,0);
        q.push(0);
        
        // Explore Each Possible Path Only Once - One Step at a Time in each Path.
        while (!q.empty()) {
            
            int k = q.size();
            
            while (k) {
                int i = q.front(); q.pop();
                
                // If you reach the end, return number of jumps taken. (Number of Levels from Root of a Graph)
                if (i == n-1) { return jumps; }
                
                // Explore Path going 1 Step Backward
                if (i-1 >= 0 && !visited[i-1]) { 
                    q.push(i-1); 
                    visited[i-1] = 1;
                }
                
                // Explore Path going 1 Step Forward
                if (i+1 < n && !visited[i+1]) { 
                    q.push(i+1);
                    visited[i+1] = 1;
                }
                
                // Explore Path going to arr[i] == arr[j] indices.
                for (int j : mp[arr[i]]) {
                    if (!visited[j]) { 
                        q.push(j); 
                        visited[j] = 1;
                    }
                }
                
                /* Clear these indices for the visited number, we will exlpore these since we pushed it to queue, we don't want to visit these again, since when array is large, checking if all of them are visited will also result in Huge Time Waste. */
                mp[arr[i]].clear();
                k--;
            }
            
            jumps++;
        }
        
        return -1;
    }
};