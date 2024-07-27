#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-cost-to-convert-string-i/
// Difficulty : Medium

/* Floyd-Warshall Algorithm Application - FIND ALL POSSIBLE CONVERSIONS MINIMUM COST AND THEN CONVERT THE STRING. */
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = original.size(), m = source.length();
        long long minCost = 0;
        char maxChar = 'a';
        
        // Build Cost Adjacency Matrix for Conversion Costs.
        vector<vector<int>> gcost(26,vector<int>(26,1e9));
        for (int i=0;i<n;i++) {
            gcost[original[i]-'a'][changed[i]-'a'] = min(cost[i],gcost[original[i]-'a'][changed[i]-'a']);
            maxChar = max(maxChar,original[i]);
            maxChar = max(maxChar,changed[i]);
        }
        
        n = maxChar-'a';
        
        // Apply Floyd-Warshall to Calculate ALL CONVERSIONS MINIMUM COSTS.
        for (int k=0;k<=n;k++) {
            for (int i=0;i<=n;i++) {
                for (int j=0;j<=n;j++) {
                    gcost[i][j] = min(gcost[i][j],gcost[i][k]+gcost[k][j]);
                }
            }
        }
        
        // Calculate COST incurred for Conversion by referring to MINIMUM COST TABLE WE BUILT.
        for (int i=0;i<m;i++) {
            if (source[i] == target[i]) { continue; }
            if ( gcost[source[i]-'a'][target[i]-'a'] >= 1e9 ) { return -1; }
            minCost += gcost[source[i]-'a'][target[i]-'a'];
        }
        
        return minCost;
        
    }
};