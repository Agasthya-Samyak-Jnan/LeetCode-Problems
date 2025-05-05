#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/3sum/
// Difficulty : Medium 

/* GRAPH THEORY : VERTICES WITH MAXIMAL DEGREES CAN GIVE THE BEST RANK AND +1 RANK IF THEY ARE NOT CONNECTED TO EACH OTHER. */
class Solution {
    public:
        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    
            if (roads.empty()) { return 0; }
    
            int rank = 0;
            vector<vector<int>> g(n+1,vector<int>(n+1,0));
            vector<int> degree(n+1,0);
    
            for (auto p : roads) {
                g[p[0]][p[1]] = 1; 
                g[p[1]][p[0]] = 1;
                degree[p[0]]++;
                degree[p[1]]++;
            }
    
            for (int i=0;i<n;i++) {
                for (int j=i+1;j<n;j++) {
                    rank = max(rank,degree[i]+degree[j]-g[i][j]);
                }
            }
    
            return rank;
        }
    };