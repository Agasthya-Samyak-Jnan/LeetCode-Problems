#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-the-number-of-good-subarrays/
// Difficulty : Medium

/* SLIDING WINDOW + RUNNING HASH TABLE (CAN ALSO BE SOLVED BY PREFIX SUM METHOD BUT IS TOO INEFFICIENT) */
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
    
            int i = 0, j = 0, pairs = 0, n = nums.size();
            long long subarrays = 0;
            unordered_map<int,int> freq; // To count occurence of each number in current subarray.
    
            while (j<n) {
                freq[nums[j]]++;
                pairs += freq[nums[j]] - 1; // New number will form a pair with each of its previous occurences.
                while (i<j and pairs >= k) {  
                    subarrays += n-j; // All Subarrays from current 'i' till 'n' will all contain this subarray, hence at least 'k' equal pairs - NOT just 1 subarray from 'i' to 'j'.
                    freq[nums[i]]--;
                    if (freq[nums[i]]) { pairs -= freq[nums[i]]; } // Decreases the number of equal pairs by remaining amount of same numbers, since each of them formed a pair with number before.
                    i++;
                }
                j++;
            }
            
            return subarrays;
        }
};