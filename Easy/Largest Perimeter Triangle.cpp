#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/largest-perimeter-triangle/
// Difficulty : Easy

/* SORTING + GREEDY */
class Solution {
    public:
        int largestPerimeter(vector<int>& sides) {
    
            int n = sides.size();
            
            sort(sides.begin(),sides.end()); 
    
            for (int i=n-1;i>=2;i--) {
                if (sides[i-2]+sides[i-1] > sides[i]) {
                    return sides[i-2]+sides[i-1]+sides[i];
                }
            }
    
            return 0;
        }
};