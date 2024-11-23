#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-in-mountain-array/
// Difficulty : Hard

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/* USING BINARY SEARCH TO YOUR NEEDS and CONTROLLING INTERACTIONS WITH EXTERNAL APIs */

class Solution {
public:
    
    // Binary Search to Find Peak Element.
    int findPeakElement(MountainArray &m) {
        
        int n = m.length(), low = 0, high = n-1, mid,prev,next, _mid, _prev, _next;
        
        while (low <= high) {
            
            mid = (low + high)/2;
            prev = mid-1 < 0 ? 0 : mid-1;
            next = mid+1 > n-1 ? n-1 : mid+1;
            
            _mid = m.get(mid);
            _prev = m.get(prev);
            _next = m.get(next);
            
            if (_prev <= _mid && _mid <= _next) { low = mid + 1; }
            else if (_prev >= _mid && _mid >= _next) { high = mid - 1; }
            else { return mid; }
            
        }
        
        return mid;
    }
    
    // Same Old Idea of Binary Search but this can change its direction based on "reverse" parameter.
    int binary_search (MountainArray &m, int low, int high, int target, bool reverse) {
        
        int mid = (low + high) / 2, _mid = m.get(mid);
        
        if (_mid == target) { return mid; }
            
        if (low >= high) { return -1; }
        
        if (!reverse) {
            if (_mid > target) { return binary_search(m,low,mid,target,reverse); }
            else { return binary_search(m,mid+1,high,target,reverse); }  
        }
        
        else {
            if (_mid > target) { return binary_search(m,mid+1,high,target,reverse); }
            else { return binary_search(m,low,mid,target,reverse); }
        }
        
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        // Find the Point where Sorted Order of Array Reverses its Direction (Peak of Mountain Array).
        int peak = findPeakElement(mountainArr), n = mountainArr.length();
        
        // Do a Binary Search for "target" in Left and Right of "peak" of array. 
        
        // Left Half is Increasing (Normally Sorted) - Do normal Binary Search.
        int ans = binary_search(mountainArr,0,peak,target,false);
        
        // Right Half is Decreasing (Reverse Sorted) - Do Reversed Binary Search.
        if (ans == -1) { ans = binary_search(mountainArr,peak+1,n-1,target,true); }
        
        return ans;
        
    }
};

/* BINARY SEARCH + CACHING API CALLS FOR BETTER PERFORMANCE (IF API CALLS ARE WAY TOO EXPENSIVE IN TERMS OF TIME )*/

class Solution {
public:
    
    unordered_map<int,int> mp;
    MountainArray* m;
    
    Solution () { m = nullptr; }
    
    int arr (int index) {
        return mp.find(index) == mp.end() ? mp[index] = m->get(index) : mp[index];
    }
    
    // Binary Search to Find Peak Element.
    int findPeakElement() {
        
        int n = m->length(), low = 0, high = n-1, mid,prev,next, _mid, _prev, _next;
        
        while (low <= high) {
            
            mid = (low + high)/2;
            prev = mid-1 < 0 ? 0 : mid-1;
            next = mid+1 > n-1 ? n-1 : mid+1;
            
            _mid = arr(mid);
            _prev = arr(prev);
            _next = arr(next);
            
            if (_prev <= _mid && _mid <= _next) { low = mid + 1; }
            else if (_prev >= _mid && _mid >= _next) { high = mid - 1; }
            else { return mid; }
            
        }
        
        return mid;
    }
    
    // Same Old Idea of Binary Search but this can change its direction based on "reverse" parameter.
    int binary_search (int low, int high, int target, bool reverse) {
        
        int mid = (low + high) / 2, _mid = arr(mid);
        
        if (_mid == target) { return mid; }
            
        if (low >= high) { return -1; }
        
        if (!reverse) {
            if (_mid > target) { return binary_search(low,mid,target,reverse); }
            else { return binary_search(mid+1,high,target,reverse); }  
        }
        
        else {
            if (_mid > target) { return binary_search(mid+1,high,target,reverse); }
            else { return binary_search(low,mid,target,reverse); }
        }
        
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        // Find the Point where Sorted Order of Array Reverses its Direction (Peak of Mountain Array).
        m = &mountainArr;
        int peak = findPeakElement(), n = mountainArr.length();
        
        // Do a Binary Search for "target" in Left and Right of "peak" of array. 
        
        // Left Half is Increasing (Normally Sorted) - Do normal Binary Search.
        int ans = binary_search(0,peak,target,false);
        
        // Right Half is Decreasing (Reverse Sorted) - Do Reversed Binary Search.
        if (ans == -1) { ans = binary_search(peak+1,n-1,target,true); }
        
        return ans;
        
    }
};