#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-nice-subarray/
// Difficulty : Medium 

/* PROPERTIES OF BITWISE 'AND' - '&' , BITWISE 'XOR' - '^' AND ADDITION '+'. */
// XOR SUM == ADDITION SUM => NO COMMON BITS. 
// AND OF ALL PAIRS = 0 ONLY IF THERE ARE NO COMMON BITS BETWEEN NUMBERS.
// FIND SUBARRAY BY MAINTAINING WINDOW OF NUMBERS HAVING UNCOMMON BITS BY MAINTAINING THIER XOR SUM.
// IF (XOR_SUM OF ALL CURRENT NUMBERS WITH UNCOMMON BITS) AND (NEXT NUMBER) = 0, 
// THEN, ITS 'AND' WITH EACH NUMBER IN CURRENT WINDOW OF NUMBERS SHOULD BE 0, 
// BECAUSE XOR_SUM REPRESENTS UNION OF ALL UNCOMMON BITS OF ALL NUMBERS INCLUDED IN CURRENT NICE SUBARRAY.

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            
            int n = nums.size(), i = 0, j = 1, xor_sum = nums[0], sub_size = 1;
    
            while (j<n) {
    
                while ((xor_sum & nums[j]) != 0) {
                    xor_sum ^= nums[i];
                    i++;
                }
                
                xor_sum ^= nums[j];
                sub_size = max(sub_size,j-i+1);
    
                j++;

            } 
    
            return sub_size;
        }
};