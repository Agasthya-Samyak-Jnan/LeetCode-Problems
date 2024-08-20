#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :
// Difficulty ; Easy

/* EXACT SIMULATION INCLUDING X AND Y COORDINATES. */
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        int x = 0, y = 0;
        
        for (auto c : commands) { 
            
            if (c == "LEFT") { y -= 1; }
            
            if (c == "RIGHT") { y += 1; }

            if (c == "UP") { x -= 1; }

            if (c == "DOWN") { x += 1; }

        }
        
        //cout<<x<<" "<<y<<"\n"; To Print Coords if you need them.
        
        return x*n + y;
        
    }
};

/* OPTIMISED SIMULATION */

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        int pos = 0;
        
        for (auto c : commands) { 
            
            if (c == "LEFT") { pos--; }
            
            if (c == "RIGHT") { pos++; }

            if (c == "UP") { pos -= n; }

            if (c == "DOWN") { pos += n; }

        }
        
        return pos;
        
    }
};