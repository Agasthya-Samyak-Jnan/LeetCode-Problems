#include<bits/stdc++.h>

using namespace std;

//Link to the Problem: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Difficulty: Easy

/* SUBSETS CAN BE GENERATED RECURSIVELY OR ITERATIVELY. (HERE BELOW ITS ITERATIVE) */
/* BACKTRACKING SOLUTION TAKES O(2^N) TIME. */
/* BIT MANIPULATION SOLUTION TAKES O(N) TIME. */

/* BACKTRACKING - GENERATE ALL SUBSETS, STORE THEM AND THEN FIND XOR TOTAL OF EACH SUBSET AND SUM THEM UP. */
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
    
            vector<vector<int>> subsets = {{}};
            vector<vector<int>> temp;
            int sum = 0;
            
            for (auto num : nums) {
                temp = subsets;
                for (auto subset : subsets) {
                    subset.push_back(num);
                    temp.push_back(subset);
                }
                subsets = temp;
            }
    
            for (auto& subset : subsets) {
                int XOR_Total = 0;
                for (auto& num : subset) {
                    XOR_Total ^= num;
                }
                sum += XOR_Total;
            }
    
            return sum;
        }
};

/* OPTIMIZED BACKTRACKING - CALCULATE XOR TOTAL AND SUM ON-THE-GO WHILE GENERATING SUBSETS, NO NEED TO STORE SUBSETS. */
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
    
            vector<int> subsets = {0};
            int sum = 0;
            
            for (auto num : nums) {
                int n = subsets.size();
                for (int i=0;i<n;i++) {
                    subsets.push_back(subsets[i]^num);
                    sum += subsets[i]^num;
                }
            }
    
            return sum;
        }
};

/* BIT MANIPULATION - COUNT BITS THAT ARE SET IN AT LEAST ONE NUMBER IN THE ARRAY. PUT ALL SET BITS TO ANSWER STARTING FROM MOST SIGNIFICANT BIT.*/
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int sum = 0;
            // Capture each bit that is set in any of the elements
            for (int num : nums) { sum |= num; }
            // Multiply by the number of subset XOR totals that will have each bit set
            return sum << (nums.size() - 1);
        }
};