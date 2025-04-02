#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/data-stream-as-disjoint-intervals/
// Difficulty : Hard

/* INTENDED AND BEST SOLUTION IS BASED ON BINARY SEARCH */

/* USING SORTING - ORDERED SET */
class SummaryRanges {
    public:
        set<int> s;
    
        SummaryRanges() {}
        
        void addNum(int value) { s.insert(value); }
        
        vector<vector<int>> getIntervals() {
    
            if (s.empty()) { return {}; }
    
            vector<vector<int>> ans;
            int start = *s.begin(), end = start-1;
    
            for (int i : s) {
                if (i != end+1) {
                    ans.push_back({start,end});
                    start = i;
                    end = i;
                }
                else { end = i; }
            }
    
            ans.push_back({start,end});
    
            return ans;
        }
};
