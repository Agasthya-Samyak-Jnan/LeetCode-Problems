#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
// Difficulty : Easy 

/* BRUTE FORCE */
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            
            int n = nums.size(), pairs = 0;
    
            for (int i=0;i<n;i++) {
                for (int j=i+1;j<n;j++) {
                    if (nums[i] == nums[j] and (i*j)%k == 0) { pairs++; }
                }
            }
    
            return pairs;
        }
};

/* 
    PYTHON3 VERSION
    
    class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:

        pairs = 0

        for i in range(0,len(nums)) :
            for j in range(i+1,len(nums)) :
                if (nums[i] == nums[j]) and (i*j)%k == 0 :
                    pairs += 1

        return pairs
*/