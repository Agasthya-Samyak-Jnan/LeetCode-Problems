#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/open-the-lock/
// Difficulty : Medium 

/* 
    1. HASH TABLE (FOR BANNED STATES OF LOCKS + VISITED STATES OF LOCKS)
    2. BREADTH-FIRST SEARCH (FOR MINIMUM TURNS TO ARRIVE AT A STATE OF LOCKS)
*/

class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            
            unordered_map<string,int> banned;
            unordered_map<string,int> visited;
            queue<string> q;
    
            int turns = 0;
            for (auto& state : deadends) { banned[state] = 1; }
            q.push("0000");
            visited["0000"] = 1;
    
            while (!q.empty()) {
    
                int l = q.size();
    
                for (int k=0;k<l;k++) {
    
                    string state = q.front(); q.pop();
                    if (state == target) { return turns; } // IF LOCKS MATCH THE TARGET STATE OF LOCKS, RETURN TURNS TAKEN.
                    if (banned[state]) { continue; } // DEADEND STATES TO BE IGNORED.
                    
                    // ONE SLOT BACKWARD OR ONE SLOT FORWARD ROTATION ON EACH OF 4 LOCKS
                    for (int i=0;i<4;i++) {

                        // Forward Rotation
                        if (state[i] == '9') { 
                            state[i] = '0'; // ROTATE LOCK FORWARD
                            if (!visited[state]) { q.push(state); visited[state] = 1; } // ADD TO CHECK FOR THIS ROTATED STATE
                            state[i] = '9'; // REVERT BACK TO ORIGINAL STATE TO CHECK FOR BACKWARD ROTATION FROM SAME STATE
                        }
                        else { 
                            state[i]++; // ROTATE LOCK FORWARD
                            if (!visited[state]) { q.push(state); visited[state] = 1; } // ADD TO CHECK FOR THIS ROTATED STATE
                            state[i]--; // REVERT BACK TO ORIGINAL STATE TO CHECK FOR BACKWARD ROTATION FROM SAME STATE
                        }
    
                        // Backward Rotation
                        if (state[i] == '0') {
                            state[i] = '9'; // ROTATE LOCK BACKWARD
                            if (!visited[state]) { q.push(state); visited[state] = 1; } // ADD TO CHECK FOR THIS ROTATED STATE
                            state[i] = '0'; // REVERT BACK TO ORIGINAL STATE TO CHECK FOR ROTATION ON ANOTHER LOCK FROM SAME STATE
                        }
                        else {
                            state[i]--; // ROTATE LOCK BACKWARD
                            if (!visited[state]) { q.push(state); visited[state] = 1; } // ADD TO CHECK FOR THIS ROTATED STATE
                            state[i]++; // REVERT BACK TO ORIGINAL STATE TO CHECK FOR ROTATION ON ANOTHER LOCK FROM SAME STATE
                        }
                    }
                }
    
                turns++; // EACH LEVEL REPRESENTS ALL POSSIBLE STATES YOU CAN GO TO FROM CURRENT STATE OF LOCKS BY ROTATING ONE SLOT ON ANY ONE LOCK.
                         // HENCE, YOU ARE FINDING IF YOU CAN REACH TARGET STATE FOR EVERY SINGLE TURN, NOT SKIPPING ANY, AND AT ANY POINT, NUMBER OF TURNS IS MINIMUM.
            }
    
            return -1;
        }
};

/* BETTER IMPLEMENTATION OF ABOVE */
class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            
            unordered_map<string,int> banned;
            unordered_map<string,int> visited;
            queue<string> q;
            vector<int> direction = {+1,-1};
            string curr_state, nxt_state;
    
            int turns = 0;
            for (auto& state : deadends) { banned[state] = 1; }
            q.push("0000");
            visited["0000"] = 1;
    
            while (!q.empty()) {
    
                int l = q.size();
    
                for (int k=0;k<l;k++) {
    
                    curr_state = q.front(); q.pop();
                    if (curr_state == target) { return turns; }
                    if (banned[curr_state]) { continue; }

                    for (int i=0;i<4;i++) {
                        for (auto rotation : direction) {

                            nxt_state = curr_state;
                            nxt_state[i] = '0' + (curr_state[i] - '0' + rotation + 10) % 10;

                            if (!visited[nxt_state]) {
                                q.push(nxt_state);
                                visited[nxt_state] = 1;
                            }
                        }

                    }

                }
    
                turns++;
            }
    
            return -1;
        }
};