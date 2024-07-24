#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-the-jumbled-numbers/?envType=daily-question&envId=2024-07-24
// Difficulty : Medium 


/* Hash Mapping + Sorting - Time Complexity : O(N*logN) , Space Complexity : O(N) */
class Solution {
public:
    vector<int> mp;
    
    int mapper(int a) {
        if (a == 0) { return mp[0]; }
        int temp = 0;
        int radix = pow(10,(int)log10(a));
        while (radix>0) {
             temp += mp[a/radix]*radix;
             a %= radix;
             radix /= 10;
        }
        return temp;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        mp = mapping;
        int n = nums.size();
        vector<pair<int,int>> temp;
        vector<int> ans;
        
        for (int i=0;i<n;i++) { temp.push_back(make_pair(mapper(nums[i]),i)); }
        
        sort(temp.begin(),temp.end());
        
        for (int i=0;i<n;i++) { ans.push_back(nums[temp[i].second]); }
        
        return ans;
    }
};