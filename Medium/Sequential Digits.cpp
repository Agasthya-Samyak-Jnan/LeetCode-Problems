#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sequential-digits/
// Difficulty : Medium

/* JUST GENERATE ALL SEQUENTIAL DIGITS NUMBERS AND PICK THOSE IN RANGE */
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        int ld = log10(low)+1, hd = log10(high)+1, num, base;
        vector<int> nums;

        for(int d=ld;d<=hd;d++) {
            for (int i=1;i<=(10-d);i++) {
                num = 0;
                base = pow(10,d-1);
                for (int j=i;j<=(i+d-1);j++) {
                    num += j*base;
                    base /= 10;
                }
                if (num < low) { continue; }
                if (num > high) { return nums; }
                nums.push_back(num); 
            }
        }
        
        return nums;
    }
};