#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/keys-and-rooms/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            
            int n = rooms.size(), rooms_visited = 0;
            queue<int> q;
            vector<int> visited(n,0);
    
            // You are in Room 0. You start from it hence its visited.
            q.push(0);
            visited[0] = 1;
            
            // While you have Keys of Unvisited Rooms remaining.
            while (!q.empty()) {
                // Enter a room if you have its key - If room is in queue, it means you have its key.
                int curr_room = q.front(); q.pop();
    
                // Count How many Rooms Visited.
                rooms_visited++;
                // If you visited all 'n' rooms.
                if (rooms_visited == n) { return true; }
    
                // For all Room Keys found in this current room you are inside,
                // Keep Keys of only those rooms you haven't visited yet - Push Room Numbers to Queue.
                for (int reachable_room : rooms[curr_room]) {
                    if (!visited[reachable_room]) {
                        q.push(reachable_room);
                        visited[reachable_room] = 1;
                    }
                }
    
            }
    
            return false; 
        }
};

/* DEPTH-FIRST SEARCH (ITERATIVE) */
class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            
            int n = rooms.size(), rooms_visited = 0;
            stack<int> s;
            vector<int> visited(n,0);
    
            s.push(0);
            visited[0] = 1;
            
    
            while (!s.empty()) {
                // Enter a room if you have its key - If room is in queue, it means you have its key.
                int curr_room = s.top(); s.pop();
    
                // Count How many Rooms Visited.
                rooms_visited++;
                // If you visited all 'n' rooms.
                if (rooms_visited == n) { return true; }
    
                // For all Room Keys found in this current room you are inside,
                // Keep Keys of only those rooms you haven't visited yet - Push Room Numbers to Queue.
                for (int reachable_room : rooms[curr_room]) {
                    if (!visited[reachable_room]) {
                        s.push(reachable_room);
                        visited[reachable_room] = 1;
                    }
                }
    
            }
    
            return false; 
        }
};

/* DEPTH-FIRST SEARCH (RECURSIVE) */
class Solution {
    public:
        unordered_map<int,int> visited;
        int rooms_visited = 0;
    
        bool canVisitAllRooms(vector<vector<int>>& rooms, int curr_room = 0) {
    
            visited[curr_room] = 1;
            rooms_visited++;
    
            for (int reachable_room : rooms[curr_room]) {
                if (!visited[reachable_room]) {
                    canVisitAllRooms(rooms,reachable_room);
                }
            }
    
            return (rooms_visited == rooms.size());
        }
};