#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Difficulty : Medium

/* Reservoir Sampling Problem */
class Solution {
public:
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
    }
    
    vector<int> pick() {
        int total_area = 0;
        int area = 0;
        vector<int> selected;
        for (auto i : rects) {
            area = (i[2]-i[0]+1)*(i[3]-i[1]+1);
            total_area += area;
            if (rand()%total_area < area) { selected = i; }
        }
        int x = selected[0] + rand()%(selected[2]-selected[0]+1);
        int y = selected[1] + rand()%(selected[3]-selected[1]+1);
        return {x,y};
    }
};
