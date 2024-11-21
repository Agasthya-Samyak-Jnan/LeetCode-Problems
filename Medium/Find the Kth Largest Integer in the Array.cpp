#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
// Difficulty : Medium 

/* QUICKSELECT ALGORITHM AND UNDERSTANDING THE DIFFERENCE BETWEEN LEXICOGRAPHICAL AND NUMERICAL ORDERING */


/* FIRST BRUTE FORCE SOLUTION : 
    1. Convert all strings to numbers.
    2. Sort them. (Normal or Reverse ordered)
    3. Return nums[n-k] (normally sorted) otherwise nums[k] (for reverse sorted order).

    * This won't work because some testcases have numbers with 50-100 digits !
    * We can avoid sorting by using QUICKSELECT ALGORITHM.
*/

/* 1. TRY TO MIMIC NUMERICAL ORDER IN LEXICAL ORDERING ITSELF BY MAKING ALL STRINGS OF SAME LENGTH,
      WHILE NOT CHANGING LEXICAL VALUE OF EACH STRING - DO THIS BY ADDING ZEROES BEHIND EACH STRING UNTIL,
      THEY ALL ARE OF SAME LENGTH - LENGTH OF LONGEST STRING IN ARRAY. - "HIGHLY TIME INEFFICIENT - 1000+ ms"
*/
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        int max_len = INT_MIN, n = nums.size();
        
        for (auto& i : nums) { max_len = max(max_len,static_cast<int>(i.length())); }
        
        for (auto& i : nums) {
            int k = max_len - i.length();
            while (k) {
                i = "0" + i;
                k--;
            }
        }
        
        nth_element(nums.begin(),nums.begin()+n-k,nums.end());
        
        int i=0;
        while (nums[n-k][i] == '0' && i<(nums[n-k].length()-1)) { i++; }
        
        return nums[n-k].substr(i,nums[n-k].length()-i+1);
    }
};

/* 2. DEFINE YOUR CUSTOM COMPARATOR FOR ORDERING STRINGS THE WAY YOU DID IN ABOVE SOLUTION - "7-10ms" */
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        int n = nums.size();
        
        // Defined Own Comparator and applied it to Library Function (Lambda Function)
        auto numero_lexic_comparator = [] (string& a, string &b) -> bool {
            int al = a.length(), bl = b.length();
            // If lemgths of strings are not equal , Shorter string = Smaller number !
            if (al != bl) { return al < bl; }
            return a < b; // Otherwise same as Lexciographical Order.
        };
        
        nth_element(nums.begin(),nums.begin()+n-k,nums.end(),numero_lexic_comparator);
        
        return nums[n-k];
    }
};