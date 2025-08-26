#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/unit-conversion-i/
// Difficulty : Medium 

/* 
    NOTE : 
        USING DYNAMICALLY MEMORY ALLOCATED DATA STRUCTURES LIKE UNORDERED_MAP , VECTORS COSTS MORE MEMORY AND TIME THAN
        USING STATICALLY ALLOCATED DATA STRUCTURES LIKE PAIRS, INT[], etc.
        BE CAREFUL OF USAGE AND PERFORMANCE REQUIREMENTS WHILE IMPLEMENTING PROGRAMS FOR CONSTRAINED ENVIRONMENTS. 
*/

/* GRAPH MODELLING OF PROBLEM - BUILD A GRAPH OF UNIT TO UNIT WITH CONVERSION FACTOR AS EDGE WEIGHT CONNECTING TWO UNITS */

/* BREADTH-FIRST SEARCH */
/* IT WILL NEVER HAPPEN DUE TO PROBLEM'S NATURE BUT DOES REDUNDANT RECOMPUTATIONS IF MULTIPLE UNIT CONVERSION COMBINATIONS LEAD TO A SINGLE UNIT */
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        
        int n = conversions.size() + 1;
        long long mod = 1e9 + 7;
        vector<vector<pair<int,int>>> g(n);
        vector<int> ans(n,1);

        for (auto c : conversions) { g[c[0]].push_back({c[1],c[2]}); }

        queue<pair<int,long long>> q;
        q.push({0,1});

        while(!q.empty()) {

            pair<int,long long> curr = q.front(); q.pop();

            for (auto conversion : g[curr.first]) {
                ans[conversion.first] = (curr.second*conversion.second) % mod;
                q.push({conversion.first,ans[conversion.first]});
            }

        }

        return ans;
    }
};

/* BREADTH-FIRST SEARCH TOPOLOGICAL SORT - KAHN'S ALGORITHM - OVERKILL AND NOT NEEDED BUT A MORE CAREFUL SOLUTION */
/* AVOID REDUNDANT RECOMPUTATIONS BY FIRST CALUCATING ALL DEPENDENCIES FOR EACH UNIT BEFORE COMPUTING IT */
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        
        int n = conversions.size() + 1;
        const int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> g(n);
        vector<int> ans(n,1);
        vector<int> indegree(n,0);

        for (auto c : conversions) { 
            g[c[0]].push_back({c[1],c[2]}); 
            indegree[c[1]]++;
        }

        queue<pair<int,long long>> q;
        q.push({0,ans[0]});

        while(!q.empty()) {

            pair<int,long long> curr = q.front(); q.pop();

            for (auto conversion : g[curr.first]) {
                indegree[conversion.first]--;
                if (indegree[conversion.first] == 0) {
                    if (ans[conversion.first] == 1) {
                        ans[conversion.first] = (curr.second*conversion.second) % mod;
                        q.push({conversion.first,ans[conversion.first]}); 
                    } 
                }
            }

        }

        return ans;
    }
};