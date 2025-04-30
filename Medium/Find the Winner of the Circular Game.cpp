#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Difficulty : Medium

/* QUEUE + SIMULATION : JUST PLAY THE GAME DIRECTLY LOL ! */
class Solution {
    public:
        int findTheWinner(int n, int k) {
    
            queue<int> q;
    
            for (int i=1;i<=n;i++) { q.push(i); }
    
            while (q.size() > 1) {
                for (int i=0;i<k-1;i++) { 
                    q.push(q.front());
                    q.pop();
                }
                q.pop();
            }
            
            return q.front();
        }
};
