#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-intervals/
// Difficulty : Medium

// Custom Comparing Function that says Sorting Function to Sort by Interval End Values in Descending Order.
bool comparator (const vector<int>& a,const vector<int>& b) {
    return a[1] > b[1];
}

// Consider Farthest Interval End First and Try to merge all Intervals whose ends come after the start of this interval.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        int start,end,n = intervals.size();


        sort(intervals.begin(),intervals.end(),comparator);

        for (int i=0;i<n;i++) {
            start = intervals[i][0];
            end = intervals[i][1];

            while (i<n-1 and intervals[i+1][1] >= start) {
                start = min(start,intervals[i+1][0]);
                i++;
            }

            ans.push_back({start,end});
        }

        return ans;
    }
};