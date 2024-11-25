#include<bits/stdc++.h>

using namespace std; 

// Link to the Problem : https://leetcode.com/problems/sliding-puzzle/
// Difficulty : Hard

/* BREADTH-FIRST SEARCH + SERIALIZATION OF MATRIX */
class Solution {
public:
    queue<pair<int,string>> q;
    unordered_map<string,int> visited;
    
    void addMove (int i, int j, string& b) {
        swap(b[i],b[j]);
        if (!visited[b]) { q.push({j,b}); visited[b] = 1; }
        swap(b[i],b[j]);
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string b;
        int i,moves = 0;
        
        // Serialize initial Board State into String
        for (int j=0;j<2;j++) {
            for (int k=0;k<3;k++) {
                if (board[j][k] == 0) { i = 3*j + k; }
                b += to_string(board[j][k]);
            }
        }
        
        q.push({i,b});
        visited[b] = 1;
        
        // Explore all Reachable Board States by One Move from Current Board State.
        while (!q.empty()) {
            
            int l = q.size();
            for (int j=0;j<l;j++) {
                
                i = q.front().first;
                b = q.front().second;
                q.pop();
                
                // If solved return number of Moves.
                if (b == "123450") { return moves; }
                
                if (i <= 2) {
                    if (i != 0) { addMove(i,i-1,b); }
                    addMove(i,i+3,b);
                    if (i != 2) { addMove(i,i+1,b); }
                    
                }
                else {
                    if (i != 3) { addMove(i,i-1,b); }
                    addMove(i,i-3,b);
                    if (i != 5) { addMove(i,i+1,b); }
                }
                   
            }
            
            // Each Level represents all Board States reached from Initial Board State in "number of levels" moves.
            moves++;
        }
        
        // If it can't be solved , queue will eventually be empty and come to this point of execution.
        return -1; 
    }
};