#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Diffculty : Easy

/* Use Counting Sort Whenever there is LIMITED NUMBER OF ITEMS TO SORT ! - Time Complexity : O(n) Linear */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int sorter[101];
        vector<int> expected;
        int maximum = 0;
        int n = heights.size();
        int unexpected = 0;
        
        memset(sorter,0,sizeof(sorter)); // Set all Values of SORTER array to 0. - for Counting.
        
        // Counting Sort:
        // Since Numbers are only from 1 to 100, Sort by Counting Occurence of each Number.
        for (int i=0;i<n;i++) {
            sorter[heights[i]]++;
            maximum = max(maximum,heights[i]);
        }
        
        // Create a Sorted Array (This is how students had to stand for photo in question)
        for (int i=0;i<=maximum;i++) {
            while (sorter[i]) {
                expected.push_back(i);
                sorter[i]--;
            }
        }
        
        /* Now compare given array and sorted array and count positions 
        that have different heights */
        for (int i=0;i<n;i++) {
            if (heights[i] != expected[i]) { unexpected++; }
        }
        
        return unexpected;        
    }
};