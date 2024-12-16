#include<bits/stdc++.h>

using namespace std;
 
// Link to the Problem : https://leetcode.com/problems/water-and-jug-problem/
// Difficulty : Medium

// There is also a Mathematical Formula based Solution for this Problem which obviously runs faster and NOT intuitive to get idea of within short time.
// Math Based Solution is related GCD of Jug Capacities and Target.

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> visited;
    int X,Y,T;
    
    bool dfs (int x, int y) {
        
        // We checked for all operations from this State of Jugs previously. Don't Check again.
        if (visited[x][y]) { return false; }
        
        // Entered this State of Jugs just now.
        visited[x][y] = 1;
        
        // Target Amount of Water acquired in Jugs - Instantly return True.
        if (x + y == T) { return true; }
        
        // Fill Jug 'x'
        if (x != X) { if (dfs(X,y)) { return true; } }
        
        // Empty Jug 'x'
        if (x != 0) { if (dfs(0,y)) { return true; } }
        
        // Fill Jug 'y'
        if (y != Y) { if (dfs(x,Y)) { return true; } }
        
        // Empty Jug 'y'
        if (y != 0) { if (dfs(x,0)) { return true; } }
        
        // Pour from 'x' to 'y'
        if (X-x <= y) { if (dfs(X,y-(X-x))) { return true; } }
        else { if (dfs(x+y,0)) { return true; } }
        
        // Pour from 'y' to 'x'
        if (Y-y <= x) { if (dfs(x-(Y-y),Y)) { return true; } }
        else { if (dfs(0,x+y)) { return true; } }
        
        // Target Amount of Water couldn't be made from any operations from here. Go Back.
        return false;
    }
    
    bool canMeasureWater(int x, int y, int target) {
        
        visited = vector<vector<int>>(x+1,vector<int>(y+1,0));
        X = x, Y = y; T = target;
        
        // Start with Empty Jugs
        return dfs(0,0);
    }
};

/* PYTHON3 VERSION - DEPTH-FIRST SEARCH

class Solution:
    
    def __init__ (self) :
        self.X = 0
        self.Y = 0
        self.T = 0
        self.visited = defaultdict(tuple)
        
    def dfs (self, x: int, y: int) :
        
        # We checked for all operations from this State of Jugs previously. Don't Check again.
        if (x,y) in self.visited :
            return False
        
        #
        self.visited[(x,y)] = 1
        
        # Target Amount of Water acquired in Jugs - Instantly return True.
        if x+y == self.T :
            return True
        
        
        # Fill Jug 'x'
        if x != self.X :
            if self.dfs(self.X,y) :
                return True
        
        # Empty Jug 'x'
        if x != 0 :
            if self.dfs(0,y) :
                return True
         
        # Fill Jug 'y'
        if y != self.Y :
            if self.dfs(x,self.Y) :
                return True
        
        # Empty Jug 'y'
        if x != self.X :
            if self.dfs(x,0) :
                return True
        
        # Pour from 'x' to 'y'
        if self.X-x <= y :
            if self.dfs(self.X,y-(self.X-x)) :
                return True
        else :
            if self.dfs(x+y,0) :
                return True
        
        # Pour from 'y' to 'x'
        if self.Y-y <= x :
            if self.dfs(x-(self.Y-y),self.Y) :
                return True
        else :
            if self.dfs(0,x+y) :
                return True
        
        # Target Amount of Water couldn't be made from any operations from here. Go Back.
        return False
        
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        
        self.X = x
        self.Y = y
        self.T = target
        
        # Start with Empty Jugs
        return self.dfs(0,0)

*/

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    bool canMeasureWater(int X, int Y, int target) {
        
        vector<vector<int>> visited = vector<vector<int>>(X+1,vector<int>(Y+1,0));
        queue<vector<int>> states;
        
        // Start with Empty Jugs.
        states.push({0,0});
        
        // While you have states of Jugs remaining to Explore.
        while (!states.empty()) {
            
            // Get a State to explore.
            int x = states.front()[0], y = states.front()[1]; states.pop();
            
            // We checked for all operations from this State of Jugs previously. Don't Check again.
            if (visited[x][y]) { continue; }
            
            // Entered this State of Jugs just now.
            visited[x][y] = 1;
            
            // Target Amount of Water acquired in Jugs - Instantly return True.
            if (x + y == target) { return true; } 
            
            // Fill Jug 'x'
            if (x != X) { states.push({X,y}); }
        
            // Empty Jug 'x'
            if (x != 0) { states.push({0,y}); }
        
            // Fill Jug 'y'
            if (y != Y) { states.push({x,Y}); }
        
            // Empty Jug 'y'
            if (y != 0) { states.push({x,0}); }
        
            // Pour from 'x' to 'y'
            if (X-x <= y) { states.push({X,y-(X-x)}); }
            else { states.push({x+y,0}); }
        
            // Pour from 'y' to 'x'
            if (Y-y <= x) { states.push({x-(Y-y),Y}); }
            else { states.push({0,x+y}); }
        }
        
        // No possibilities found.
        return false;
    }
};
