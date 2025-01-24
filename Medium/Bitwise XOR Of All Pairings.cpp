#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/bitwise-xor-of-all-pairings
// Difficulty : Medium

/* 
    XOR Property : 
        Applying XOR Odd Number of times on same number gives that number itself. 
        Applying XOR Even Number of times on same number gives Zero.
    
    Analyze that if an array is of even size, each number in other array would be applied with XOR even number of times.
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size(), ans = 0;

        if (n1&1 ^ n2&1) {
            nums1 = n1&1 ? nums2 : nums1;
            for (auto& i : nums1) { ans ^= i; }
        }
        else if (n1&1) {
            for (auto& i : nums1) { ans ^= i; }
            for (auto& i : nums2) { ans ^= i; }
        }

        return ans;
    }   
};