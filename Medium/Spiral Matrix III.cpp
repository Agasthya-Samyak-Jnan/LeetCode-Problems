#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/spiral-matrix-iii/
// Difficulty: Medium


/* Best Solution : Time Complexity O(N^2) - Direction Changing Vector Method */
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int m, int n, int rStart, int cStart) {
        
          vector<int> dy = {0,1,0,-1}; // Direction Definitions
          vector<int> dx = {1,0,-1,0}; // Direction Defintions
          int r = rStart, c = cStart;  // To Track Position Values 
          int drn = 0;                 // To Change Directions using "dx" and "dy"
          int max_moves = 1;           // To Maintain Spiral Size to avoid Repeating
          vector<vector<int>> ans;     // Answer Set
        
          ans.push_back({rStart,cStart}); // Push Starting Positions
        
          while (ans.size() < m*n) {
              // max_moves Specifies Increasing size of Spirals till which traversal should run.
              for (int i=0;i<max_moves;i++) {
                  // Move in Direction Specified by "drn" and "dx" and "dy"
                  // drn: 0 = Left, 1 = Down, 2 = Right, 3 = Up
                  r += dy[drn];
                  c += dx[drn];
                  // Check to NOT Add Out-Of-Bounds Positions to the Answer Set.
                  if (r>=0 && r<m && c>=0 && c<n) { ans.push_back({r,c}); }
              }
              //Increase Size of Spirals for every 2 direction change, or else positions will repeat.
              if (drn&1) { max_moves++; }
              // Change Direction by Adding 1. If direction exceeds 4, limit it to be below 4 using Mod.
              drn = (drn+1)%4; 
          }
        return ans;
    }
          
};


/* Brute Force : HIGHLY INEFFICENT , NOT RECOMMENDED BUT SEE IT FOR SIMPLER UNDERSTANDING */
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int m, int n, int rStart, int cStart) {
          int left = cStart, right = cStart, top = rStart, bottom = rStart;
          vector<vector<int>> ans;
          vector<int> temp;
          int i;
          
          temp = {rStart,cStart};
          ans.push_back(temp);
          temp.clear();
        
          while (ans.size()<(m*n))  {
              // Move Right
              if (right < n-1) { right++; } else { right = n-1; }
              i = left+1;
              while (i <= right) {
                  temp.push_back(top);
                  temp.push_back(i);
                  if (ans.size() >= (m*n)) { break; }
                  if (find(ans.begin(),ans.end(),temp) == ans.end()) { ans.push_back(temp); }
                  temp.clear();
                  i++;
              }
              // Move Down
              if (bottom < m-1) { bottom++; } else { bottom = m-1; }
              i = top+1;
              while (i <= bottom) {
                  temp.push_back(i);
                  temp.push_back(right);
                  if (ans.size() >= (m*n)) { break; }
                  if (find(ans.begin(),ans.end(),temp) == ans.end()) { ans.push_back(temp); }
                  temp.clear();
                  i++;           
              }
              // Move Left
              if (left > 0) { left--; } else { left = 0; }
              i = right-1;
              while (i >= left) {
                  temp.push_back(bottom);
                  temp.push_back(i);
                  if (ans.size() >= (m*n)) { break; }
                  if (find(ans.begin(),ans.end(),temp) == ans.end()) { ans.push_back(temp); }
                  temp.clear();
                  i--;
              }
              // Move Up
              if (top > 0) { top--; } else { top = 0; }
              i = bottom-1;
              while (i >= top) {
                  temp.push_back(i);
                  temp.push_back(left);
                  if (ans.size() >= (m*n)) { break; }
                  if (find(ans.begin(),ans.end(),temp) == ans.end()) { ans.push_back(temp); }
                  temp.clear();
                  i--;
              }
          }
        return ans;
    }
};