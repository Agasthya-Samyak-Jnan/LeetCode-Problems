#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/next-permutation/
// Difficulty : Medium 

/* COMBINATORICS AND LEXICOGRAAPHICAL ORDERING */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int I = -1, J = -1, n = nums.size();

        for (int i=0;i<n-1;i++) {
            if (nums[i] < nums[i+1]) { I = i; }
        }
        
        if (I == -1) { sort(nums.begin(),nums.end()); }
        else {
            for (int j=0;j<n;j++) {
                if (nums[j] > nums[I]) { J = j; }
            }
            swap(nums[I],nums[J]);
            reverse(nums.begin()+I+1,nums.end());
        }
    }
};

/* Using C++ Standard Library Function */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};