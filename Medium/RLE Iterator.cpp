#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rle-iterator/
// Difficulty : Medium

class RLEIterator {
public:
    vector<int> encoded;
    int i,n;
    
    RLEIterator(vector<int>& encoded_arr) {
        encoded = encoded_arr;
        i = 0;
        n = encoded.size();
    }
    
    int next(int k) {
        
        while (1) { 
            if (i>=n) { return -1; }
            if (k <= encoded[i]) { encoded[i] -= k; break; }
            else { k -= encoded[i]; i += 2; }
        }
        
        return encoded[i+1];
    }
};

