#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
// Difficulty : Medium

/* 
    MAXIMIZE nums[i] and nums[k], MINIMIZE nums[j] in [ (nums[i] - nums[j]) * nums[k] ] to get Highest Value.
    For every Index 'j' , find MAXIMUM number before it (i<j) and MAXIMUM number after it (k>j), then calculate value.
*/
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            
            int n = nums.size();
            vector<int> pre_max(n), post_max(n);
            long long curr_val, max_val = INT_MIN;
    
            pre_max[0] = INT_MIN;
            post_max[n-1] = INT_MIN;
    
            for (int i=1;i<n;i++) {
                pre_max[i] = max(pre_max[i-1],nums[i-1]);
                post_max[(n-1)-i] = max(post_max[(n-1)-i+1],nums[(n-1)-i+1]);
            }
    
            for (int i=1;i<n-1;i++) {
                curr_val = (long long)(pre_max[i]-nums[i])*(long long)post_max[i];
                max_val = max(max_val,curr_val);
            }
            
            return (max_val < 0) ? 0 : max_val;
        }
};                                                                                                            