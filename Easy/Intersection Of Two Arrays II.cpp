#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/intersection-of-two-arrays-ii/?envType=daily-question&envId=2024-07-02
// Difficulty : Easy

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> small=nums2,big=nums1;
        if (nums1.size() < nums2.size()) { small = nums1; big = nums2; }
        int n = big.size();
        
        for (int i=0;i<n;i++) {    
            mp[big[i]]++;
        }
    
        n = small.size();
        big.clear();
        
        for (int i=0;i<n;i++) {
            if (mp[small[i]] >= 1) { big.push_back(small[i]); mp[small[i]]--; } }
            return big;
    }
        
};