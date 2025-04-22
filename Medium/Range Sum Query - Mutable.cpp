#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-sum-query-mutable/
// Difficulty : Medium

/* SEGMENT TREES AND DIVIDE-CONQUER FOR RANGED QUERIES */

/* DIVIDE AND CONQUER BASED DATA STRUCTURE */
/* Segment Tree API */
class SegmentTree {
    public:
        // t = Array that logically represents Segment Tree, arr = Original Array
        vector<int> t;
        int n;
    
        SegmentTree (vector<int>& arr) {    
            n = arr.size();
            t = vector<int>(4*n);
            build(0,0,n-1,arr);
        }
    
        // Build Segment Tree from Given Array - O(N) Time, O(2N) Space - Divide and Conquer ideology.
        int build (int i, int start, int end, vector<int>& a) {
            
            if (start < end) {
                int mid = (start+end)/2, left = 2*i+1, right = 2*i+2;
                t[left] = build(left,start,mid,a); 
                t[right] = build(right,mid+1,end,a);  
                return t[i] = t[left] + t[right];
            }
    
            return t[i] = a[start];
        }
    
        // Sum of Range = [left,right] (both inclusive) - O(logN) Time, O(logN) Space.
        int sumRange (int left, int right) {
            return sum(0,left,right,0,n-1);
        }
        int sum (int i, int left, int right, int start, int end) {
            if (right < start or end < left) { return 0; } // Current Range[start,end] does is NOT a part our Range[left,right]
            if (left <= start and end <= right) { return t[i]; } // Current Range[start,end]  is FULLY a part of our Range[left,right]
            int mid = (start+end)/2;
            // Sum up the Ranges on LEFT and RIGHT of current Range[start,end] that are parts of our Range[left,right]
            return sum(2*i+1,left,right,start,mid) + sum(2*i+2,left,right,mid+1,end); // Current Range[start,end]  is PARTIALLY a part of our Range[left,right]
        }
    
        // Update Value - O(logN) Time, O(1) Space.
        void set (int idx, int value) {
            update(0,idx,value,0,n-1);
        }
        void update (int i, int idx, int value, int start, int end) {
            
            // Reached the Value of the Array to be Updated. Change it and Go Back.
            if (start == end) { t[i] = value; return; }
            
            // Find Midpoint to decide direction.
            int mid = (start+end)/2, left = 2*i+1, right = 2*i+2;
            
            // Binary Search Logic - Less than Mid is Left, otherwise number is on Right.
            if (idx <= mid) { update(left,idx,value,start,mid); }
            else { update(right,idx,value,mid+1,end); }
            
            // *AFTER* Updation of Ranges that FORM THIS Range[start,end], update THIS range.
            t[i] = t[left] + t[right];
        }
};

class NumArray {
public:
    SegmentTree* s;

    NumArray(vector<int>& nums) {
        s = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        s->set(index,val);
    }
    
    int sumRange(int left, int right) {
        return s->sumRange(left,right);
    }
};