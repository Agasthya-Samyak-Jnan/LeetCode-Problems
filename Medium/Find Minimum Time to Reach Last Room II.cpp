#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/
// Difficulty : Medium 

/* APPROACH : BACKTRACKING (DEPTH-FIRST SEARCH) AND FINDING OPTIMAL PATH -> BREADTH-FIRST SEARCH WITH VISITED TIME TRACKING FOR CELL -> DIJKISTRA SEARCH WITH LEAST TIME PATHS */
class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            
            int m = moveTime.size(), n = moveTime[0].size();
            vector<int> dx = {0,-1,0,1};
            vector<int> dy = {-1,0,1,0};
            vector<vector<int>> visited(m,vector<int>(n,INT_MAX));
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    
            pq.push({0,0,0,0}); // Each Search State has = {Time Taken till now, State(1 or 2), X-position, Y-Position}
            visited[0][0] = 0;
    
            while (!pq.empty()) {

                int l = pq.size();
    
                for (int i=0;i<l;i++) {
    
                    int time = pq.top()[0], state = pq.top()[1], x = pq.top()[2], y = pq.top()[3]; 
                    pq.pop();
    
                    if (x == m-1 and y == n-1) { return time; }
    
                    int minWait = INT_MAX;
                    bool repeat = false;
    
                    for (int i=0;i<4;i++) {
                        if (x+dx[i] >= 0 and y+dy[i] >= 0 and x+dx[i] < m and y+dy[i] < n) {
                            if (visited[x+dx[i]][y+dy[i]] > (time+1)) {
                                if (time >= moveTime[x+dx[i]][y+dy[i]]) { 
                                    visited[x+dx[i]][y+dy[i]] = time+1;
                                    pq.push({time+(1+state),(!state),x+dx[i],y+dy[i]}); 
                                }
                                else { 
                                    minWait = min(minWait,moveTime[x+dx[i]][y+dy[i]]-time); 
                                    repeat = true;
                                }
                            }
                        }
                    }
    
                    if (repeat) { pq.push({time+minWait,(state),x,y}); }
                }
            }
    
            return -1;
        }
};
  
        