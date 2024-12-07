#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/h-index/
// Difficulty : Medium 

/* COUNTING SORT AND FREQUENCY OF NUMBERS */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int cs[1001] = {0}, mn = citations[0], mx = citations[0], H = 0, papers = 0;
        
        for (auto i : citations) {
            cs[i]++;
            mn = min(mn,i);
            mx = max(mx,i);
        }
     
        for (int i=mx;i>=mn;i--) {
            papers += cs[i];
            if (papers >= i) { return i; }
        }  
        
        return papers;
    }
};