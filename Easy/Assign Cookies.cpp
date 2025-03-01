#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/assign-cookies/
// Difficulty : Easy

/* SORTING + TWO POINTERS + GREEDY */
class Solution {
    public:
        int findContentChildren(vector<int>& children, vector<int>& cookie) {
    
            int happy_children = 0;
            int i = 0, j = 0, n = children.size(), m = cookie.size();
            
            sort(cookie.begin(),cookie.end());
            sort(children.begin(),children.end());
    
            while (i<m and j<n) {
                if (cookie[i] >= children[j]) { 
                    happy_children++;
                    i++;
                    j++;
                }
                else { i++; } 
            }
            
            return happy_children;
        }
};