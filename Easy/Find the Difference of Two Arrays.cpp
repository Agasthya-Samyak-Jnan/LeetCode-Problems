#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :https://leetcode.com/problems/find-the-difference-of-two-arrays/
// Difficulty : Easy

/* HASH SET */
class Solution {
    public:
        vector<vector<int>> findDifference (vector<int>& n1, vector<int>& n2) {
            
            unordered_set s1(n1.begin(),n1.end()), s2(n2.begin(),n2.end());
    
            vector<int> a1,a2;
    
            for (int i : s1) {
                if (s2.find(i) == s2.end()) { a1.push_back(i); }
            }
    
            for (int i : s2) {
                if (s1.find(i) == s1.end()) { a2.push_back(i); }
            }
    
            return {a1,a2};
        }
};