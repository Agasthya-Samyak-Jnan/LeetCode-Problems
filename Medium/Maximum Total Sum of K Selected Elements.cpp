#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
// Difficulty : Medium

/* SORTING + GREEDY 
   - Multiplying and then adding numbers is always better than just adding numbers, given all numbers > 0. 
   - Always choose highest numbers for highest multiplier value, to get maximum sum. Use sorting to order by highest number first.
*/
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        int n = nums.size(), i = 0;
        long long sum = 0;

        sort(nums.begin(),nums.end(),[](int& a, int& b){ return a>b; }); // Highest number first, descending order sorting.

        while (k) {
            if (mul > 0) {
                sum += (long long)nums[i]*mul;
                mul--;
            }
            else { sum += nums[i]; }
            i++;
            k--;
        }

        return sum;
    }
};