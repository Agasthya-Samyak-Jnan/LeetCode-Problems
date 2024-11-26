#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-triangle-number/
// Difficulty : Medium 

/* BRUTE FORCE : TC = O(N^3)  */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        
        for (int i=0;i<n-2;i++) {
            if (nums[i] == 0) { continue; }
            for (int j=i+1;j<n-1;j++) {
                if (nums[j] == 0) { continue; }
                for (int k=j+1;k<n;k++) {
                    if (nums[k] == 0) { continue; }
                    if (nums[i]+nums[j] > nums[k] && nums[j]+nums[k] > nums[i] && nums[i]+nums[k] > nums[j]) { ans++; }
                }
            }
        }
        
        return ans;
    }
};

/* SORTING + BINARY SEARCH : TC = O(N^2*log(N)) */
class Solution {
public:
    int binary_search (vector<int>& a, int low, int high, int target) {   
        
        while (low <= high) {
            int mid = (low + high)/2;
            if (a[mid] >= target) { high = mid - 1; }
            else { low = mid + 1; }
        }
        
        return low;
    }
    
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n-2;i++) {
            
            if (nums[i] == 0) { continue; }
            
            int k = i+2;
            
            for (int j=i+1;j<n-1;j++) {
                k = binary_search(nums,k,n-1,nums[i]+nums[j]);
                ans += k - j - 1;
            }
            
        }
        
        return ans;
    }
};

/* SORTING + OPTIMIZED LINEAR SEARCH : TC = O(N^2) */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n-2;i++) {
            int k = i+2;
            for (int j=i+1;j<n-1 && nums[i] != 0;j++) {
                while (k<n && nums[i]+nums[j] > nums[k]) { k++; }
                ans += k-(j+1);
            }
        }
        
        return ans;
    }
};