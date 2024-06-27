#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-center-of-star-graph/
// Difficulty : Easy

/* Time Complexity : O(1) - One Line Solution */
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0]==edges[1][0]||edges[0][0]==edges[1][1])?edges[0][0]:edges[0][1];
    }
};