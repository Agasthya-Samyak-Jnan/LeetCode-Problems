#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-boomerangs/
// Difficulty : Medium 

/* HASH TABLE SOLUTION + BASIC MATHS */
class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int n = points.size(),ans = 0, dist;
        unordered_map<int,int> mp;
        
        for (int i=0;i<n;i++) {
            
            int x1 = points[i][0], y1 = points[i][1];
            
            // Memorise number of points from point 'i' at distance 'dist' in table.
            for (int j=0;j<n;j++) {
                if (i==j) { continue; }
                int x2 = points[j][0], y2 = points[j][1];
                dist = pow(x2-x1,2) + pow(y2-y1,2);
                mp[dist]++;
            }
            
            // Order Matters According to Question , so all combinations included.
            // Calculate boomerangs that can be formed with each 'dist'.
            for (auto m : mp) { ans += (m.second)*(m.second-1); }
                
            mp.clear();
        }
        
        return ans;
    }
};