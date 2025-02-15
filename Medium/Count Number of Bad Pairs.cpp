#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-number-of-bad-pairs/
// Difficulty : Medium

/* BRUTE FORCE SOLUTION */
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
    
            long long ans = 0;
            int n = nums.size();
    
            for (int i=0;i<n-1;i++) {
                for (int j=i+1;j<n;j++) {
                    if (j-i != nums[j]-nums[i]) { ans++; }
                }
            }
            
            return ans;
        }
};

/* HASH TABLE SOLUTION */
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
    
            long long n = nums.size();
            long long ans = (n*(n-1))/2;
            unordered_map<long long,long long> mp;
    
            for (int i=0;i<n;i++) { mp[nums[i]-i]++; }
            for (auto& i : mp) {
                if (i.second > 1) { ans -= (i.second*(i.second-1))/2; }
            }
            
            return ans;
        }
};

/* PYTHON3 VERSION 

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:

        n = len(nums)
        ans = (n*(n-1))//2
        mp = defaultdict(int)

        for i in range(0,n):
            mp[nums[i]-i] += 1

        for i in mp.values() :
            if i > 1 :
                ans -= (i*(i-1))//2 
        
        return ans
*/