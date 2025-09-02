#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/interval-list-intersections/
// Difficulty : Medium 

/* 
    LINE SWEEP IDEA USING TWO POINTERS 
    A :  |       |       |       |       |
    B :  |      |        |        |      |
*/

class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i = 0, j = 0, m = firstList.size(), n = secondList.size(), start, end;
        vector<vector<int>> intersectionList;

        while (i<m and j<n) {
            start = max(firstList[i][0],secondList[j][0]), end = min(firstList[i][1],secondList[j][1]);
            auto intersection = (start<=end) ? vector<int>{start,end} : vector<int>{};
            if (!intersection.empty()) { intersectionList.push_back(intersection); }
            if (firstList[i][1] < secondList[j][1]) { i++; }
            else  { j++; }
        }

        return intersectionList;
    }
};