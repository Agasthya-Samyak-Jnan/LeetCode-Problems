#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/daily-temperatures/
// Difficulty : Medium

/* BRUTE FORCE */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n = temps.size();
        vector<int> ans(n,0);

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (temps[j] > temps[i]) { ans[i] = j-i; break; }
            }
        }

        return ans;
    }
};

/* USING MONOTONIC STACK TO TRACK ALL TEMPERATURES THAT WERE COLDER THAN CURRENT TEMPERATURE. */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n = temps.size();
        vector<int> ans(n,0);
        stack<int> s;

        for (int i=0;i<n;i++) {
            if (!s.empty() and temps[s.top()] < temps[i]) {
                while (!s.empty() and temps[s.top()] < temps[i]) {
                    ans[s.top()] = i - s.top();
                    s.pop();
                }
            }
            s.push(i);
        }

        return ans;
    }
};