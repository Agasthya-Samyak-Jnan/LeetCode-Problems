#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Difficulty : Medium

/* Application of FLOYD-WARSHALL'S ALL PAIRS SHORTEST PATHS ALGORTIHM - DYNAMIC PROGRAMMING */
/* Create Shortest Possible Path between all pair of vertices to know all possible neighbouring cities of every City,
   Considering Every City as Intermediate City in the PATH between Every Pair of Cities.
*/

/* Time Complexity : O(n^3) = [(n^3)/2 + (n^2)/2] + [(n^2)] + [Edges] , Space Complexity : O(n^2) = [(n^2)] + constant */
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>g(n,vector<int>(n,10001));
        int leastReachable = n;
        int minCity = 0;
        
        // O(E) - Buidling Adjacency Matrix from Edges-List - Undirected Graph => g[i][j] = g[j][i]
        for (auto i : edges) { g[i[0]][i[1]] = g[i[1]][i[0]] = i[2]; }
        
        /* Floyd-Warshall Algorithm to Compute all Point-to-Point Shortest Paths and
           forming all possible paths between cities. */
        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                /* Undirected Graph Hence Check only g[i][j] , NO need to check g[j][i] */
                for (int j=i+1;j<n;j++) { 
                        g[i][j] = g[j][i] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    
        // Calculate Number of Neighbouring Cities for each City Under Threshold Distance.
        // Then Check if its Minimum Number of Neighbours among all Cities and Update Accordingly.
        for (int i=0;i<n;i++) {
            int numCities = 0;
            for (int j=0;j<n;j++) {
                if ( g[i][j] <= distanceThreshold && i != j) { numCities++; }
            }
            if (numCities <= leastReachable) {
                leastReachable = numCities;
                minCity = i;
            }
        }
        
        return minCity;
    }
};
    