#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-memory-allocator/
// Difficulty : Medium

/* HASH TABLE + SIMULATION */
class Allocator {
public:
    vector<int> memory;
    unordered_map<int,vector<pair<int,int>>> mp;
    
    int n;
    
    Allocator(int n) {
        this->n = n;
        memory = vector<int>(n,0);
    }
    
    int allocate(int size, int mID) {
        
        int i=0,j;
        
        while (i<n) {
            
            j = i;       
            while (i<n && memory[i] == 0 && size > i-j) { i++; }
            
            // Allocate the contiguous memory block mID of "size" size.
            if (size == i-j) {
                mp[mID].push_back({j,i});
                while (j<i) { 
                    memory[j] = mID; 
                    j++; 
                }
                // Give the starting location of this memory block.
                return mp[mID].back().first;
            }
            
            // Continue to search for Free Blocks
            i++;
        }
        
        // Free Consecutive Blocks of "size" size NOT FOUND.
        return -1;
    }
    
    int free(int mID) {
        
        int deallocated_units = 0;
        
        for (auto range : mp[mID]) {
            for (int loc=range.first;loc<range.second;loc++) {
                memory[loc] = 0; 
                deallocated_units++;
            }
        }
        
        mp[mID] = {};
        
        return deallocated_units;
    }
};
