#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty : Medium

/* Hash Table Method  T : O(n)  S : O(n) */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) { return nums[i]; }
        }
        return -1;
    }
};

/* Best Solution : Marker Method -  T : O(n) S : O(1) */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++) {
            int j = abs(nums[i]); // Since numbers in range [1,n], no out of bounds will occur.
            if (nums[j] < 0) { return j; } // If we are at 'j'th number, and its marked negative already,
                                              // that means we found it before current occurence. 
                                              // 'j' is the duplicate number.
            nums[j] = -nums[j];  // Mark 'j' has occured by marking 'j'th number as negative of itself.   
        }                        // DONT MARK ZERO AS IT WRONGLY CAUSES NON DUPLICATE NUMBERS TO BE MARKED AS ZERO.
        return -1; 
    }
};