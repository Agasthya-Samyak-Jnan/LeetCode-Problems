#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Difficulty : Medium 

/* Number Slots for Nodes must be exact. */
class Solution {
public:
    bool isValidSerialization(string p) {
        
        int i = 0, n = p.size(), N = 1;
        
        while (i<n) {
            
            // If Slot is NOT available, serialization is wrong.
            if (!N) { return false; }
            
            string temp;
            while (i<n && p[i] != ',') { temp += p[i++]; }
            i++;
            
            // Null Pointer or Dead End Ocuppies a Slot
            if (temp == "#") { N--; }
            // New Node occupies One Slot and Creates Two More Slots.
            else { 
                // Ocuppy a Slot
                N--; 
                // Create Two More Slots (Left and Right)
                N += 2; 
            }
        }
        
        // No Extra Slots should remain in serialization.
        return N == 0;
    }
};