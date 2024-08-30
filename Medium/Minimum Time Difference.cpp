#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-time-difference/
// Difficulty : Medium

/* Solution 1 */
class Solution {
public:
    
    int toMin (string a) {
        return stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
    }
    
    int findMinDifference(vector<string>& tp) {
        
        sort(tp.begin(),tp.end());
        
        int minimum = INT_MAX, n = tp.size();
        
        for (int i=1;i<n;i++) { 
           int a = 1440+toMin(tp[i]), b = 1440+toMin(tp[i-1]);
           minimum = min(minimum,a-b); 
        }
        
        minimum = min(minimum,1440 + toMin(tp[0]) - toMin(tp[n-1]));
        
        
        return minimum;
    }
};

/* Solution 2 */
class Solution {
public:
    
    int toMin (string a) {
        return stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
    }
    
    int findMinDifference(vector<string>& tp) {
        
        int ans = INT_MAX,n = tp.size();
        vector<int> t;
        
        for (auto i : tp) { t.push_back(toMin(i)); }
        
        sort(t.begin(),t.end());
        
        for (int i=1;i<n;i++) { ans = min(ans,t[i]-t[i-1]); }
        
        ans = min(ans,1440+t[0]-t[n-1]);
        
        return ans;
    }
};