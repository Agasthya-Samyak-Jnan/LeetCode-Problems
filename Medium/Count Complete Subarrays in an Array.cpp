#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-complete-subarrays-in-an-array/
// Difficulty : Medium

/* SLIDING WINDOW + RUNNING HASH TABLE */
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
    
            int n = nums.size(), i = 0, j = -1, completeSubarrays = 0;
            unordered_map<int,int> mp;
    
            for (auto num : nums) { mp[num]++; }
    
            int unique_elements = mp.size();
            mp.clear();
    
            while (j<n) {
    
                // cout<<i<<" "<<j<<"\n";
    
                if (mp.size() == unique_elements) {
                    completeSubarrays += n-j;
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) { mp.erase(nums[i]); }
                    i++;
                }
                else {
                    j++;
                    if (j<n) { mp[nums[j]]++; }
                }
            }
            
            return completeSubarrays;
        }
};



/* 
    PYTHON3 VERSION
    
    class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:

        n = len(nums)
        mp = defaultdict(int)
        for num in nums :
            mp[num] += 1

        i = 0
        j = -1
        completeSubarrays = 0
        unique_elements = len(mp)
        mp = defaultdict(int)

        while j<n :
            if len(mp) == unique_elements :
                completeSubarrays += n-j
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0 :
                    del mp[nums[i]]
                i += 1
            
            else :
                j += 1
                if j<n :
                    mp[nums[j]] += 1
    
        return completeSubarrays
    
*/