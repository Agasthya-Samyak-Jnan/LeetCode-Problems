#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty : Medium


/* INTENDED SOLUTION : BINARY SEARCH FOR COMPLEMENT VALUE OF NUMS[i] with respect to TARGET. */
class Solution {
public:
    int search(vector<int>& a, int low, int high, int key) {
        
        int mid;

        while (low < high) {
            mid = (low+high)/2;
            if (a[mid] == key) { return mid; }
            if (a[mid] > key) { high = mid; }
            else { low = mid + 1; }
        }
        
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        
        for (int i=0;i<n-1;i++) {
            int j = search(nums,i,n,target-nums[i]);
            if (j != -1) { return {i+1,j+1}; }
        }
        
        return {};
    }
};

/* BEST SOLUTION : HASH TABLE - STORE COMPLEMENT OF EACH NUMBER WITH RESPECT TO TARGET */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for (int i=0;i<n;i++) {
            if (mp[nums[i]]) { return {mp[nums[i]],i+1}; }
            else { mp[target-nums[i]] = i+1; }
        }
        
        return {};
    }
};

// TESTER CODE
int main () {

    Solution a;
    vector<int> nums = {2,3,4};
    vector<int> ans = a.twoSum(nums,6);

    cout<<ans[0]<<","<<ans[1]<<"\n";

}