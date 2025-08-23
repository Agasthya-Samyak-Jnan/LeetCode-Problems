#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/fruits-into-baskets-ii/
// Difficulty : Easy 

/* SIMULATION USING ORDERED SET */
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        set<int> available;
        int n = baskets.size(), unplaced = 0;

        for (int i=0;i<n;i++) { available.insert(i); }
        
        for (int fruit_count : fruits) {
            bool placed = false; 
            for (int basket : available) {
                if (baskets[basket] >= fruit_count) { available.erase(basket); placed = true; break; }
            }
            if (!placed) { unplaced++; }
        }
        
        return unplaced;
    }
};